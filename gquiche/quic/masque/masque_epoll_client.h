// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef QUICHE_QUIC_MASQUE_MASQUE_EPOLL_CLIENT_H_
#define QUICHE_QUIC_MASQUE_MASQUE_EPOLL_CLIENT_H_

#include "gquiche/quic/masque/masque_client_session.h"
#include "gquiche/quic/masque/masque_utils.h"
#include "gquiche/quic/platform/api/quic_export.h"
#include "gquiche/quic/tools/quic_client.h"

namespace quic {

// QUIC client that implements MASQUE.
class QUIC_NO_EXPORT MasqueEpollClient : public QuicClient,
                                         public MasqueClientSession::Owner {
 public:
  // Constructs a MasqueEpollClient, performs a synchronous DNS lookup.
  static std::unique_ptr<MasqueEpollClient> Create(
      const std::string& host,
      int port,
      MasqueMode masque_mode,
      QuicEpollServer* epoll_server,
      std::unique_ptr<ProofVerifier> proof_verifier);

  // From QuicClient.
  std::unique_ptr<QuicSession> CreateQuicClientSession(
      const ParsedQuicVersionVector& supported_versions,
      QuicConnection* connection) override;

  // Client session for this client.
  MasqueClientSession* masque_client_session();

  // Convenience accessor for the underlying connection ID.
  QuicConnectionId connection_id();

  // Send a MASQUE client connection ID unregister command to the server.
  void UnregisterClientConnectionId(
      QuicConnectionId client_connection_id) override;

  MasqueMode masque_mode() const { return masque_mode_; }

 private:
  // Constructor is private, use Create() instead.
  MasqueEpollClient(QuicSocketAddress server_address,
                    const QuicServerId& server_id,
                    MasqueMode masque_mode,
                    QuicEpollServer* epoll_server,
                    std::unique_ptr<ProofVerifier> proof_verifier,
                    const std::string& authority);

  // Disallow copy and assign.
  MasqueEpollClient(const MasqueEpollClient&) = delete;
  MasqueEpollClient& operator=(const MasqueEpollClient&) = delete;

  MasqueMode masque_mode_;
  std::string authority_;
};

}  // namespace quic

#endif  // QUICHE_QUIC_MASQUE_MASQUE_EPOLL_CLIENT_H_
