// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef QUICHE_QUIC_TEST_TOOLS_SIMULATOR_QUIC_ENDPOINT_H_
#define QUICHE_QUIC_TEST_TOOLS_SIMULATOR_QUIC_ENDPOINT_H_

#include "absl/strings/string_view.h"
#include "gquiche/quic/core/crypto/null_decrypter.h"
#include "gquiche/quic/core/crypto/null_encrypter.h"
#include "gquiche/quic/core/quic_connection.h"
#include "gquiche/quic/core/quic_default_packet_writer.h"
#include "gquiche/quic/core/quic_packets.h"
#include "gquiche/quic/core/quic_stream_frame_data_producer.h"
#include "gquiche/quic/core/quic_trace_visitor.h"
#include "gquiche/quic/platform/api/quic_containers.h"
#include "gquiche/quic/test_tools/simple_session_notifier.h"
#include "gquiche/quic/test_tools/simulator/link.h"
#include "gquiche/quic/test_tools/simulator/queue.h"
#include "gquiche/quic/test_tools/simulator/quic_endpoint_base.h"

namespace quic {
namespace simulator {

// A QUIC connection endpoint.  Wraps around QuicConnection.  In order to
// initiate a transfer, the caller has to call AddBytesToTransfer().  The data
// transferred is always the same and is always transferred on a single stream.
// The endpoint receives all packets addressed to it, and verifies that the data
// received is what it's supposed to be.
class QuicEndpoint : public QuicEndpointBase,
                     public QuicConnectionVisitorInterface,
                     public SessionNotifierInterface {
 public:
  QuicEndpoint(Simulator* simulator,
               std::string name,
               std::string peer_name,
               Perspective perspective,
               QuicConnectionId connection_id);

  QuicByteCount bytes_to_transfer() const;
  QuicByteCount bytes_transferred() const;
  QuicByteCount bytes_received() const;
  inline bool wrong_data_received() const { return wrong_data_received_; }

  // Send |bytes| bytes.  Initiates the transfer if one is not already in
  // progress.
  void AddBytesToTransfer(QuicByteCount bytes);

  // Begin QuicConnectionVisitorInterface implementation.
  void OnStreamFrame(const QuicStreamFrame& frame) override;
  void OnCryptoFrame(const QuicCryptoFrame& frame) override;
  void OnCanWrite() override;
  bool SendProbingData() override;
  bool ValidateStatelessReset(
      const quic::QuicSocketAddress& /*self_address*/,
      const quic::QuicSocketAddress& /*peer_address*/) override {
    return true;
  }
  bool WillingAndAbleToWrite() const override;
  bool ShouldKeepConnectionAlive() const override;

  std::string GetStreamsInfoForLogging() const override { return ""; }
  void OnWindowUpdateFrame(const QuicWindowUpdateFrame& /*frame*/) override {}
  void OnBlockedFrame(const QuicBlockedFrame& /*frame*/) override {}
  void OnRstStream(const QuicRstStreamFrame& /*frame*/) override {}
  void OnGoAway(const QuicGoAwayFrame& /*frame*/) override {}
  void OnMessageReceived(absl::string_view /*message*/) override {}
  void OnHandshakeDoneReceived() override {}
  void OnNewTokenReceived(absl::string_view /*token*/) override {}
  void OnConnectionClosed(const QuicConnectionCloseFrame& /*frame*/,
                          ConnectionCloseSource /*source*/) override {}
  void OnWriteBlocked() override {}
  void OnSuccessfulVersionNegotiation(
      const ParsedQuicVersion& /*version*/) override {}
  void OnPacketReceived(const QuicSocketAddress& /*self_address*/,
                        const QuicSocketAddress& /*peer_address*/,
                        bool /*is_connectivity_probe*/) override {}
  void OnCongestionWindowChange(QuicTime /*now*/) override {}
  void OnConnectionMigration(AddressChangeType /*type*/) override {}
  void OnPathDegrading() override {}
  void OnForwardProgressMadeAfterPathDegrading() override {}
  void OnAckNeedsRetransmittableFrame() override {}
  void SendAckFrequency(const QuicAckFrequencyFrame& /*frame*/) override {}
  void SendNewConnectionId(const QuicNewConnectionIdFrame& /*frame*/) override {
  }
  void SendRetireConnectionId(uint64_t /*sequence_number*/) override {}
  void OnServerConnectionIdIssued(
      const QuicConnectionId& /*server_connection_id*/) override {}
  void OnServerConnectionIdRetired(
      const QuicConnectionId& /*server_connection_id*/) override {}
  bool AllowSelfAddressChange() const override;
  HandshakeState GetHandshakeState() const override;
  bool OnMaxStreamsFrame(const QuicMaxStreamsFrame& /*frame*/) override {
    return true;
  }
  bool OnStreamsBlockedFrame(
      const QuicStreamsBlockedFrame& /*frame*/) override {
    return true;
  }
  void OnStopSendingFrame(const QuicStopSendingFrame& /*frame*/) override {}
  void OnPacketDecrypted(EncryptionLevel /*level*/) override {}
  void OnOneRttPacketAcknowledged() override {}
  void OnHandshakePacketSent() override {}
  void OnKeyUpdate(KeyUpdateReason /*reason*/) override {}
  std::unique_ptr<QuicDecrypter> AdvanceKeysAndCreateCurrentOneRttDecrypter()
      override {
    return nullptr;
  }
  std::unique_ptr<QuicEncrypter> CreateCurrentOneRttEncrypter() override {
    return nullptr;
  }
  void BeforeConnectionCloseSent() override {}
  bool ValidateToken(absl::string_view /*token*/) const override {
    return true;
  }
  void MaybeSendAddressToken() override {}
  bool IsKnownServerAddress(
      const QuicSocketAddress& /*address*/) const override {
    return false;
  }

  // End QuicConnectionVisitorInterface implementation.

  // Begin SessionNotifierInterface methods:
  bool OnFrameAcked(const QuicFrame& frame,
                    QuicTime::Delta ack_delay_time,
                    QuicTime receive_timestamp) override;
  void OnStreamFrameRetransmitted(const QuicStreamFrame& /*frame*/) override {}
  void OnFrameLost(const QuicFrame& frame) override;
  void RetransmitFrames(const QuicFrames& frames,
                        TransmissionType type) override;
  bool IsFrameOutstanding(const QuicFrame& frame) const override;
  bool HasUnackedCryptoData() const override;
  bool HasUnackedStreamData() const override;
  // End SessionNotifierInterface implementation.

 private:
  // The producer outputs the repetition of the same byte.  That sequence is
  // verified by the receiver.
  class DataProducer : public QuicStreamFrameDataProducer {
   public:
    WriteStreamDataResult WriteStreamData(QuicStreamId id,
                                          QuicStreamOffset offset,
                                          QuicByteCount data_length,
                                          QuicDataWriter* writer) override;
    bool WriteCryptoData(EncryptionLevel level,
                         QuicStreamOffset offset,
                         QuicByteCount data_length,
                         QuicDataWriter* writer) override;
  };

  std::unique_ptr<QuicConnection> CreateConnection(
      Simulator* simulator,
      std::string name,
      std::string peer_name,
      Perspective perspective,
      QuicConnectionId connection_id);

  // Write stream data until |bytes_to_transfer_| is zero or the connection is
  // write-blocked.
  void WriteStreamData();

  DataProducer producer_;

  QuicByteCount bytes_to_transfer_;
  QuicByteCount bytes_transferred_;

  // Set to true if the endpoint receives stream data different from what it
  // expects.
  bool wrong_data_received_;

  // Record of received offsets in the data stream.
  QuicIntervalSet<QuicStreamOffset> offsets_received_;

  std::unique_ptr<test::SimpleSessionNotifier> notifier_;
};

}  // namespace simulator
}  // namespace quic

#endif  // QUICHE_QUIC_TEST_TOOLS_SIMULATOR_QUIC_ENDPOINT_H_
