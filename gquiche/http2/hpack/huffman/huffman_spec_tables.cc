// Copyright (c) 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "gquiche/http2/hpack/huffman/huffman_spec_tables.h"

namespace http2 {

// clang-format off
// static
const uint8_t HuffmanSpecTables::kCodeLengths[] = {
    13, 23, 28, 28, 28, 28, 28, 28,  //   0 -   7
    28, 24, 30, 28, 28, 30, 28, 28,  //   8 -  15
    28, 28, 28, 28, 28, 28, 30, 28,  //  16 -  23
    28, 28, 28, 28, 28, 28, 28, 28,  //  24 -  31
     6, 10, 10, 12, 13,  6,  8, 11,  //  32 -  39
    10, 10,  8, 11,  8,  6,  6,  6,  //  40 -  47
     5,  5,  5,  6,  6,  6,  6,  6,  //  48 -  55
     6,  6,  7,  8, 15,  6, 12, 10,  //  56 -  63
    13,  6,  7,  7,  7,  7,  7,  7,  //  64 -  71
     7,  7,  7,  7,  7,  7,  7,  7,  //  72 -  79
     7,  7,  7,  7,  7,  7,  7,  7,  //  80 -  87
     8,  7,  8, 13, 19, 13, 14,  6,  //  88 -  95
    15,  5,  6,  5,  6,  5,  6,  6,  //  96 - 103
     6,  5,  7,  7,  6,  6,  6,  5,  // 104 - 111
     6,  7,  6,  5,  5,  6,  7,  7,  // 112 - 119
     7,  7,  7, 15, 11, 14, 13, 28,  // 120 - 127
    20, 22, 20, 20, 22, 22, 22, 23,  // 128 - 135
    22, 23, 23, 23, 23, 23, 24, 23,  // 136 - 143
    24, 24, 22, 23, 24, 23, 23, 23,  // 144 - 151
    23, 21, 22, 23, 22, 23, 23, 24,  // 152 - 159
    22, 21, 20, 22, 22, 23, 23, 21,  // 160 - 167
    23, 22, 22, 24, 21, 22, 23, 23,  // 168 - 175
    21, 21, 22, 21, 23, 22, 23, 23,  // 176 - 183
    20, 22, 22, 22, 23, 22, 22, 23,  // 184 - 191
    26, 26, 20, 19, 22, 23, 22, 25,  // 192 - 199
    26, 26, 26, 27, 27, 26, 24, 25,  // 200 - 207
    19, 21, 26, 27, 27, 26, 27, 24,  // 208 - 215
    21, 21, 26, 26, 28, 27, 27, 27,  // 216 - 223
    20, 24, 20, 21, 22, 21, 21, 23,  // 224 - 231
    22, 22, 25, 25, 24, 24, 26, 23,  // 232 - 239
    26, 27, 26, 26, 27, 27, 27, 27,  // 240 - 247
    27, 28, 27, 27, 27, 27, 27, 26,  // 248 - 255
    30,                              // 256
};

// The encoding of each symbol, left justified (as printed), which means that
// the first bit of the encoding is the high-order bit of the uint32.
// static
const uint32_t HuffmanSpecTables::kLeftCodes[] = {
    0b11111111110000000000000000000000,  // 0x00
    0b11111111111111111011000000000000,  // 0x01
    0b11111111111111111111111000100000,  // 0x02
    0b11111111111111111111111000110000,  // 0x03
    0b11111111111111111111111001000000,  // 0x04
    0b11111111111111111111111001010000,  // 0x05
    0b11111111111111111111111001100000,  // 0x06
    0b11111111111111111111111001110000,  // 0x07
    0b11111111111111111111111010000000,  // 0x08
    0b11111111111111111110101000000000,  // 0x09
    0b11111111111111111111111111110000,  // 0x0a
    0b11111111111111111111111010010000,  // 0x0b
    0b11111111111111111111111010100000,  // 0x0c
    0b11111111111111111111111111110100,  // 0x0d
    0b11111111111111111111111010110000,  // 0x0e
    0b11111111111111111111111011000000,  // 0x0f
    0b11111111111111111111111011010000,  // 0x10
    0b11111111111111111111111011100000,  // 0x11
    0b11111111111111111111111011110000,  // 0x12
    0b11111111111111111111111100000000,  // 0x13
    0b11111111111111111111111100010000,  // 0x14
    0b11111111111111111111111100100000,  // 0x15
    0b11111111111111111111111111111000,  // 0x16
    0b11111111111111111111111100110000,  // 0x17
    0b11111111111111111111111101000000,  // 0x18
    0b11111111111111111111111101010000,  // 0x19
    0b11111111111111111111111101100000,  // 0x1a
    0b11111111111111111111111101110000,  // 0x1b
    0b11111111111111111111111110000000,  // 0x1c
    0b11111111111111111111111110010000,  // 0x1d
    0b11111111111111111111111110100000,  // 0x1e
    0b11111111111111111111111110110000,  // 0x1f
    0b01010000000000000000000000000000,  // 0x20
    0b11111110000000000000000000000000,  // '!'
    0b11111110010000000000000000000000,  // '\"'
    0b11111111101000000000000000000000,  // '#'
    0b11111111110010000000000000000000,  // '$'
    0b01010100000000000000000000000000,  // '%'
    0b11111000000000000000000000000000,  // '&'
    0b11111111010000000000000000000000,  // '\''
    0b11111110100000000000000000000000,  // '('
    0b11111110110000000000000000000000,  // ')'
    0b11111001000000000000000000000000,  // '*'
    0b11111111011000000000000000000000,  // '+'
    0b11111010000000000000000000000000,  // ','
    0b01011000000000000000000000000000,  // '-'
    0b01011100000000000000000000000000,  // '.'
    0b01100000000000000000000000000000,  // '/'
    0b00000000000000000000000000000000,  // '0'
    0b00001000000000000000000000000000,  // '1'
    0b00010000000000000000000000000000,  // '2'
    0b01100100000000000000000000000000,  // '3'
    0b01101000000000000000000000000000,  // '4'
    0b01101100000000000000000000000000,  // '5'
    0b01110000000000000000000000000000,  // '6'
    0b01110100000000000000000000000000,  // '7'
    0b01111000000000000000000000000000,  // '8'
    0b01111100000000000000000000000000,  // '9'
    0b10111000000000000000000000000000,  // ':'
    0b11111011000000000000000000000000,  // ';'
    0b11111111111110000000000000000000,  // '<'
    0b10000000000000000000000000000000,  // '='
    0b11111111101100000000000000000000,  // '>'
    0b11111111000000000000000000000000,  // '?'
    0b11111111110100000000000000000000,  // '@'
    0b10000100000000000000000000000000,  // 'A'
    0b10111010000000000000000000000000,  // 'B'
    0b10111100000000000000000000000000,  // 'C'
    0b10111110000000000000000000000000,  // 'D'
    0b11000000000000000000000000000000,  // 'E'
    0b11000010000000000000000000000000,  // 'F'
    0b11000100000000000000000000000000,  // 'G'
    0b11000110000000000000000000000000,  // 'H'
    0b11001000000000000000000000000000,  // 'I'
    0b11001010000000000000000000000000,  // 'J'
    0b11001100000000000000000000000000,  // 'K'
    0b11001110000000000000000000000000,  // 'L'
    0b11010000000000000000000000000000,  // 'M'
    0b11010010000000000000000000000000,  // 'N'
    0b11010100000000000000000000000000,  // 'O'
    0b11010110000000000000000000000000,  // 'P'
    0b11011000000000000000000000000000,  // 'Q'
    0b11011010000000000000000000000000,  // 'R'
    0b11011100000000000000000000000000,  // 'S'
    0b11011110000000000000000000000000,  // 'T'
    0b11100000000000000000000000000000,  // 'U'
    0b11100010000000000000000000000000,  // 'V'
    0b11100100000000000000000000000000,  // 'W'
    0b11111100000000000000000000000000,  // 'X'
    0b11100110000000000000000000000000,  // 'Y'
    0b11111101000000000000000000000000,  // 'Z'
    0b11111111110110000000000000000000,  // '['
    0b11111111111111100000000000000000,  // '\\'
    0b11111111111000000000000000000000,  // ']'
    0b11111111111100000000000000000000,  // '^'
    0b10001000000000000000000000000000,  // '_'
    0b11111111111110100000000000000000,  // '`'
    0b00011000000000000000000000000000,  // 'a'
    0b10001100000000000000000000000000,  // 'b'
    0b00100000000000000000000000000000,  // 'c'
    0b10010000000000000000000000000000,  // 'd'
    0b00101000000000000000000000000000,  // 'e'
    0b10010100000000000000000000000000,  // 'f'
    0b10011000000000000000000000000000,  // 'g'
    0b10011100000000000000000000000000,  // 'h'
    0b00110000000000000000000000000000,  // 'i'
    0b11101000000000000000000000000000,  // 'j'
    0b11101010000000000000000000000000,  // 'k'
    0b10100000000000000000000000000000,  // 'l'
    0b10100100000000000000000000000000,  // 'm'
    0b10101000000000000000000000000000,  // 'n'
    0b00111000000000000000000000000000,  // 'o'
    0b10101100000000000000000000000000,  // 'p'
    0b11101100000000000000000000000000,  // 'q'
    0b10110000000000000000000000000000,  // 'r'
    0b01000000000000000000000000000000,  // 's'
    0b01001000000000000000000000000000,  // 't'
    0b10110100000000000000000000000000,  // 'u'
    0b11101110000000000000000000000000,  // 'v'
    0b11110000000000000000000000000000,  // 'w'
    0b11110010000000000000000000000000,  // 'x'
    0b11110100000000000000000000000000,  // 'y'
    0b11110110000000000000000000000000,  // 'z'
    0b11111111111111000000000000000000,  // '{'
    0b11111111100000000000000000000000,  // '|'
    0b11111111111101000000000000000000,  // '}'
    0b11111111111010000000000000000000,  // '~'
    0b11111111111111111111111111000000,  // 0x7f
    0b11111111111111100110000000000000,  // 0x80
    0b11111111111111110100100000000000,  // 0x81
    0b11111111111111100111000000000000,  // 0x82
    0b11111111111111101000000000000000,  // 0x83
    0b11111111111111110100110000000000,  // 0x84
    0b11111111111111110101000000000000,  // 0x85
    0b11111111111111110101010000000000,  // 0x86
    0b11111111111111111011001000000000,  // 0x87
    0b11111111111111110101100000000000,  // 0x88
    0b11111111111111111011010000000000,  // 0x89
    0b11111111111111111011011000000000,  // 0x8a
    0b11111111111111111011100000000000,  // 0x8b
    0b11111111111111111011101000000000,  // 0x8c
    0b11111111111111111011110000000000,  // 0x8d
    0b11111111111111111110101100000000,  // 0x8e
    0b11111111111111111011111000000000,  // 0x8f
    0b11111111111111111110110000000000,  // 0x90
    0b11111111111111111110110100000000,  // 0x91
    0b11111111111111110101110000000000,  // 0x92
    0b11111111111111111100000000000000,  // 0x93
    0b11111111111111111110111000000000,  // 0x94
    0b11111111111111111100001000000000,  // 0x95
    0b11111111111111111100010000000000,  // 0x96
    0b11111111111111111100011000000000,  // 0x97
    0b11111111111111111100100000000000,  // 0x98
    0b11111111111111101110000000000000,  // 0x99
    0b11111111111111110110000000000000,  // 0x9a
    0b11111111111111111100101000000000,  // 0x9b
    0b11111111111111110110010000000000,  // 0x9c
    0b11111111111111111100110000000000,  // 0x9d
    0b11111111111111111100111000000000,  // 0x9e
    0b11111111111111111110111100000000,  // 0x9f
    0b11111111111111110110100000000000,  // 0xa0
    0b11111111111111101110100000000000,  // 0xa1
    0b11111111111111101001000000000000,  // 0xa2
    0b11111111111111110110110000000000,  // 0xa3
    0b11111111111111110111000000000000,  // 0xa4
    0b11111111111111111101000000000000,  // 0xa5
    0b11111111111111111101001000000000,  // 0xa6
    0b11111111111111101111000000000000,  // 0xa7
    0b11111111111111111101010000000000,  // 0xa8
    0b11111111111111110111010000000000,  // 0xa9
    0b11111111111111110111100000000000,  // 0xaa
    0b11111111111111111111000000000000,  // 0xab
    0b11111111111111101111100000000000,  // 0xac
    0b11111111111111110111110000000000,  // 0xad
    0b11111111111111111101011000000000,  // 0xae
    0b11111111111111111101100000000000,  // 0xaf
    0b11111111111111110000000000000000,  // 0xb0
    0b11111111111111110000100000000000,  // 0xb1
    0b11111111111111111000000000000000,  // 0xb2
    0b11111111111111110001000000000000,  // 0xb3
    0b11111111111111111101101000000000,  // 0xb4
    0b11111111111111111000010000000000,  // 0xb5
    0b11111111111111111101110000000000,  // 0xb6
    0b11111111111111111101111000000000,  // 0xb7
    0b11111111111111101010000000000000,  // 0xb8
    0b11111111111111111000100000000000,  // 0xb9
    0b11111111111111111000110000000000,  // 0xba
    0b11111111111111111001000000000000,  // 0xbb
    0b11111111111111111110000000000000,  // 0xbc
    0b11111111111111111001010000000000,  // 0xbd
    0b11111111111111111001100000000000,  // 0xbe
    0b11111111111111111110001000000000,  // 0xbf
    0b11111111111111111111100000000000,  // 0xc0
    0b11111111111111111111100001000000,  // 0xc1
    0b11111111111111101011000000000000,  // 0xc2
    0b11111111111111100010000000000000,  // 0xc3
    0b11111111111111111001110000000000,  // 0xc4
    0b11111111111111111110010000000000,  // 0xc5
    0b11111111111111111010000000000000,  // 0xc6
    0b11111111111111111111011000000000,  // 0xc7
    0b11111111111111111111100010000000,  // 0xc8
    0b11111111111111111111100011000000,  // 0xc9
    0b11111111111111111111100100000000,  // 0xca
    0b11111111111111111111101111000000,  // 0xcb
    0b11111111111111111111101111100000,  // 0xcc
    0b11111111111111111111100101000000,  // 0xcd
    0b11111111111111111111000100000000,  // 0xce
    0b11111111111111111111011010000000,  // 0xcf
    0b11111111111111100100000000000000,  // 0xd0
    0b11111111111111110001100000000000,  // 0xd1
    0b11111111111111111111100110000000,  // 0xd2
    0b11111111111111111111110000000000,  // 0xd3
    0b11111111111111111111110000100000,  // 0xd4
    0b11111111111111111111100111000000,  // 0xd5
    0b11111111111111111111110001000000,  // 0xd6
    0b11111111111111111111001000000000,  // 0xd7
    0b11111111111111110010000000000000,  // 0xd8
    0b11111111111111110010100000000000,  // 0xd9
    0b11111111111111111111101000000000,  // 0xda
    0b11111111111111111111101001000000,  // 0xdb
    0b11111111111111111111111111010000,  // 0xdc
    0b11111111111111111111110001100000,  // 0xdd
    0b11111111111111111111110010000000,  // 0xde
    0b11111111111111111111110010100000,  // 0xdf
    0b11111111111111101100000000000000,  // 0xe0
    0b11111111111111111111001100000000,  // 0xe1
    0b11111111111111101101000000000000,  // 0xe2
    0b11111111111111110011000000000000,  // 0xe3
    0b11111111111111111010010000000000,  // 0xe4
    0b11111111111111110011100000000000,  // 0xe5
    0b11111111111111110100000000000000,  // 0xe6
    0b11111111111111111110011000000000,  // 0xe7
    0b11111111111111111010100000000000,  // 0xe8
    0b11111111111111111010110000000000,  // 0xe9
    0b11111111111111111111011100000000,  // 0xea
    0b11111111111111111111011110000000,  // 0xeb
    0b11111111111111111111010000000000,  // 0xec
    0b11111111111111111111010100000000,  // 0xed
    0b11111111111111111111101010000000,  // 0xee
    0b11111111111111111110100000000000,  // 0xef
    0b11111111111111111111101011000000,  // 0xf0
    0b11111111111111111111110011000000,  // 0xf1
    0b11111111111111111111101100000000,  // 0xf2
    0b11111111111111111111101101000000,  // 0xf3
    0b11111111111111111111110011100000,  // 0xf4
    0b11111111111111111111110100000000,  // 0xf5
    0b11111111111111111111110100100000,  // 0xf6
    0b11111111111111111111110101000000,  // 0xf7
    0b11111111111111111111110101100000,  // 0xf8
    0b11111111111111111111111111100000,  // 0xf9
    0b11111111111111111111110110000000,  // 0xfa
    0b11111111111111111111110110100000,  // 0xfb
    0b11111111111111111111110111000000,  // 0xfc
    0b11111111111111111111110111100000,  // 0xfd
    0b11111111111111111111111000000000,  // 0xfe
    0b11111111111111111111101110000000,  // 0xff
    0b11111111111111111111111111111100,  // 0x100
};

// static
const uint32_t HuffmanSpecTables::kRightCodes[] = {
    0b00000000000000000001111111111000,  // 0x00
    0b00000000011111111111111111011000,  // 0x01
    0b00001111111111111111111111100010,  // 0x02
    0b00001111111111111111111111100011,  // 0x03
    0b00001111111111111111111111100100,  // 0x04
    0b00001111111111111111111111100101,  // 0x05
    0b00001111111111111111111111100110,  // 0x06
    0b00001111111111111111111111100111,  // 0x07
    0b00001111111111111111111111101000,  // 0x08
    0b00000000111111111111111111101010,  // 0x09
    0b00111111111111111111111111111100,  // 0x0a
    0b00001111111111111111111111101001,  // 0x0b
    0b00001111111111111111111111101010,  // 0x0c
    0b00111111111111111111111111111101,  // 0x0d
    0b00001111111111111111111111101011,  // 0x0e
    0b00001111111111111111111111101100,  // 0x0f
    0b00001111111111111111111111101101,  // 0x10
    0b00001111111111111111111111101110,  // 0x11
    0b00001111111111111111111111101111,  // 0x12
    0b00001111111111111111111111110000,  // 0x13
    0b00001111111111111111111111110001,  // 0x14
    0b00001111111111111111111111110010,  // 0x15
    0b00111111111111111111111111111110,  // 0x16
    0b00001111111111111111111111110011,  // 0x17
    0b00001111111111111111111111110100,  // 0x18
    0b00001111111111111111111111110101,  // 0x19
    0b00001111111111111111111111110110,  // 0x1a
    0b00001111111111111111111111110111,  // 0x1b
    0b00001111111111111111111111111000,  // 0x1c
    0b00001111111111111111111111111001,  // 0x1d
    0b00001111111111111111111111111010,  // 0x1e
    0b00001111111111111111111111111011,  // 0x1f
    0b00000000000000000000000000010100,  // 0x20
    0b00000000000000000000001111111000,  // '!'
    0b00000000000000000000001111111001,  // '\"'
    0b00000000000000000000111111111010,  // '#'
    0b00000000000000000001111111111001,  // '$'
    0b00000000000000000000000000010101,  // '%'
    0b00000000000000000000000011111000,  // '&'
    0b00000000000000000000011111111010,  // '\''
    0b00000000000000000000001111111010,  // '('
    0b00000000000000000000001111111011,  // ')'
    0b00000000000000000000000011111001,  // '*'
    0b00000000000000000000011111111011,  // '+'
    0b00000000000000000000000011111010,  // ','
    0b00000000000000000000000000010110,  // '-'
    0b00000000000000000000000000010111,  // '.'
    0b00000000000000000000000000011000,  // '/'
    0b00000000000000000000000000000000,  // '0'
    0b00000000000000000000000000000001,  // '1'
    0b00000000000000000000000000000010,  // '2'
    0b00000000000000000000000000011001,  // '3'
    0b00000000000000000000000000011010,  // '4'
    0b00000000000000000000000000011011,  // '5'
    0b00000000000000000000000000011100,  // '6'
    0b00000000000000000000000000011101,  // '7'
    0b00000000000000000000000000011110,  // '8'
    0b00000000000000000000000000011111,  // '9'
    0b00000000000000000000000001011100,  // ':'
    0b00000000000000000000000011111011,  // ';'
    0b00000000000000000111111111111100,  // '<'
    0b00000000000000000000000000100000,  // '='
    0b00000000000000000000111111111011,  // '>'
    0b00000000000000000000001111111100,  // '?'
    0b00000000000000000001111111111010,  // '@'
    0b00000000000000000000000000100001,  // 'A'
    0b00000000000000000000000001011101,  // 'B'
    0b00000000000000000000000001011110,  // 'C'
    0b00000000000000000000000001011111,  // 'D'
    0b00000000000000000000000001100000,  // 'E'
    0b00000000000000000000000001100001,  // 'F'
    0b00000000000000000000000001100010,  // 'G'
    0b00000000000000000000000001100011,  // 'H'
    0b00000000000000000000000001100100,  // 'I'
    0b00000000000000000000000001100101,  // 'J'
    0b00000000000000000000000001100110,  // 'K'
    0b00000000000000000000000001100111,  // 'L'
    0b00000000000000000000000001101000,  // 'M'
    0b00000000000000000000000001101001,  // 'N'
    0b00000000000000000000000001101010,  // 'O'
    0b00000000000000000000000001101011,  // 'P'
    0b00000000000000000000000001101100,  // 'Q'
    0b00000000000000000000000001101101,  // 'R'
    0b00000000000000000000000001101110,  // 'S'
    0b00000000000000000000000001101111,  // 'T'
    0b00000000000000000000000001110000,  // 'U'
    0b00000000000000000000000001110001,  // 'V'
    0b00000000000000000000000001110010,  // 'W'
    0b00000000000000000000000011111100,  // 'X'
    0b00000000000000000000000001110011,  // 'Y'
    0b00000000000000000000000011111101,  // 'Z'
    0b00000000000000000001111111111011,  // '['
    0b00000000000001111111111111110000,  // '\\'
    0b00000000000000000001111111111100,  // ']'
    0b00000000000000000011111111111100,  // '^'
    0b00000000000000000000000000100010,  // '_'
    0b00000000000000000111111111111101,  // '`'
    0b00000000000000000000000000000011,  // 'a'
    0b00000000000000000000000000100011,  // 'b'
    0b00000000000000000000000000000100,  // 'c'
    0b00000000000000000000000000100100,  // 'd'
    0b00000000000000000000000000000101,  // 'e'
    0b00000000000000000000000000100101,  // 'f'
    0b00000000000000000000000000100110,  // 'g'
    0b00000000000000000000000000100111,  // 'h'
    0b00000000000000000000000000000110,  // 'i'
    0b00000000000000000000000001110100,  // 'j'
    0b00000000000000000000000001110101,  // 'k'
    0b00000000000000000000000000101000,  // 'l'
    0b00000000000000000000000000101001,  // 'm'
    0b00000000000000000000000000101010,  // 'n'
    0b00000000000000000000000000000111,  // 'o'
    0b00000000000000000000000000101011,  // 'p'
    0b00000000000000000000000001110110,  // 'q'
    0b00000000000000000000000000101100,  // 'r'
    0b00000000000000000000000000001000,  // 's'
    0b00000000000000000000000000001001,  // 't'
    0b00000000000000000000000000101101,  // 'u'
    0b00000000000000000000000001110111,  // 'v'
    0b00000000000000000000000001111000,  // 'w'
    0b00000000000000000000000001111001,  // 'x'
    0b00000000000000000000000001111010,  // 'y'
    0b00000000000000000000000001111011,  // 'z'
    0b00000000000000000111111111111110,  // '{'
    0b00000000000000000000011111111100,  // '|'
    0b00000000000000000011111111111101,  // '}'
    0b00000000000000000001111111111101,  // '~'
    0b00001111111111111111111111111100,  // 0x7f
    0b00000000000011111111111111100110,  // 0x80
    0b00000000001111111111111111010010,  // 0x81
    0b00000000000011111111111111100111,  // 0x82
    0b00000000000011111111111111101000,  // 0x83
    0b00000000001111111111111111010011,  // 0x84
    0b00000000001111111111111111010100,  // 0x85
    0b00000000001111111111111111010101,  // 0x86
    0b00000000011111111111111111011001,  // 0x87
    0b00000000001111111111111111010110,  // 0x88
    0b00000000011111111111111111011010,  // 0x89
    0b00000000011111111111111111011011,  // 0x8a
    0b00000000011111111111111111011100,  // 0x8b
    0b00000000011111111111111111011101,  // 0x8c
    0b00000000011111111111111111011110,  // 0x8d
    0b00000000111111111111111111101011,  // 0x8e
    0b00000000011111111111111111011111,  // 0x8f
    0b00000000111111111111111111101100,  // 0x90
    0b00000000111111111111111111101101,  // 0x91
    0b00000000001111111111111111010111,  // 0x92
    0b00000000011111111111111111100000,  // 0x93
    0b00000000111111111111111111101110,  // 0x94
    0b00000000011111111111111111100001,  // 0x95
    0b00000000011111111111111111100010,  // 0x96
    0b00000000011111111111111111100011,  // 0x97
    0b00000000011111111111111111100100,  // 0x98
    0b00000000000111111111111111011100,  // 0x99
    0b00000000001111111111111111011000,  // 0x9a
    0b00000000011111111111111111100101,  // 0x9b
    0b00000000001111111111111111011001,  // 0x9c
    0b00000000011111111111111111100110,  // 0x9d
    0b00000000011111111111111111100111,  // 0x9e
    0b00000000111111111111111111101111,  // 0x9f
    0b00000000001111111111111111011010,  // 0xa0
    0b00000000000111111111111111011101,  // 0xa1
    0b00000000000011111111111111101001,  // 0xa2
    0b00000000001111111111111111011011,  // 0xa3
    0b00000000001111111111111111011100,  // 0xa4
    0b00000000011111111111111111101000,  // 0xa5
    0b00000000011111111111111111101001,  // 0xa6
    0b00000000000111111111111111011110,  // 0xa7
    0b00000000011111111111111111101010,  // 0xa8
    0b00000000001111111111111111011101,  // 0xa9
    0b00000000001111111111111111011110,  // 0xaa
    0b00000000111111111111111111110000,  // 0xab
    0b00000000000111111111111111011111,  // 0xac
    0b00000000001111111111111111011111,  // 0xad
    0b00000000011111111111111111101011,  // 0xae
    0b00000000011111111111111111101100,  // 0xaf
    0b00000000000111111111111111100000,  // 0xb0
    0b00000000000111111111111111100001,  // 0xb1
    0b00000000001111111111111111100000,  // 0xb2
    0b00000000000111111111111111100010,  // 0xb3
    0b00000000011111111111111111101101,  // 0xb4
    0b00000000001111111111111111100001,  // 0xb5
    0b00000000011111111111111111101110,  // 0xb6
    0b00000000011111111111111111101111,  // 0xb7
    0b00000000000011111111111111101010,  // 0xb8
    0b00000000001111111111111111100010,  // 0xb9
    0b00000000001111111111111111100011,  // 0xba
    0b00000000001111111111111111100100,  // 0xbb
    0b00000000011111111111111111110000,  // 0xbc
    0b00000000001111111111111111100101,  // 0xbd
    0b00000000001111111111111111100110,  // 0xbe
    0b00000000011111111111111111110001,  // 0xbf
    0b00000011111111111111111111100000,  // 0xc0
    0b00000011111111111111111111100001,  // 0xc1
    0b00000000000011111111111111101011,  // 0xc2
    0b00000000000001111111111111110001,  // 0xc3
    0b00000000001111111111111111100111,  // 0xc4
    0b00000000011111111111111111110010,  // 0xc5
    0b00000000001111111111111111101000,  // 0xc6
    0b00000001111111111111111111101100,  // 0xc7
    0b00000011111111111111111111100010,  // 0xc8
    0b00000011111111111111111111100011,  // 0xc9
    0b00000011111111111111111111100100,  // 0xca
    0b00000111111111111111111111011110,  // 0xcb
    0b00000111111111111111111111011111,  // 0xcc
    0b00000011111111111111111111100101,  // 0xcd
    0b00000000111111111111111111110001,  // 0xce
    0b00000001111111111111111111101101,  // 0xcf
    0b00000000000001111111111111110010,  // 0xd0
    0b00000000000111111111111111100011,  // 0xd1
    0b00000011111111111111111111100110,  // 0xd2
    0b00000111111111111111111111100000,  // 0xd3
    0b00000111111111111111111111100001,  // 0xd4
    0b00000011111111111111111111100111,  // 0xd5
    0b00000111111111111111111111100010,  // 0xd6
    0b00000000111111111111111111110010,  // 0xd7
    0b00000000000111111111111111100100,  // 0xd8
    0b00000000000111111111111111100101,  // 0xd9
    0b00000011111111111111111111101000,  // 0xda
    0b00000011111111111111111111101001,  // 0xdb
    0b00001111111111111111111111111101,  // 0xdc
    0b00000111111111111111111111100011,  // 0xdd
    0b00000111111111111111111111100100,  // 0xde
    0b00000111111111111111111111100101,  // 0xdf
    0b00000000000011111111111111101100,  // 0xe0
    0b00000000111111111111111111110011,  // 0xe1
    0b00000000000011111111111111101101,  // 0xe2
    0b00000000000111111111111111100110,  // 0xe3
    0b00000000001111111111111111101001,  // 0xe4
    0b00000000000111111111111111100111,  // 0xe5
    0b00000000000111111111111111101000,  // 0xe6
    0b00000000011111111111111111110011,  // 0xe7
    0b00000000001111111111111111101010,  // 0xe8
    0b00000000001111111111111111101011,  // 0xe9
    0b00000001111111111111111111101110,  // 0xea
    0b00000001111111111111111111101111,  // 0xeb
    0b00000000111111111111111111110100,  // 0xec
    0b00000000111111111111111111110101,  // 0xed
    0b00000011111111111111111111101010,  // 0xee
    0b00000000011111111111111111110100,  // 0xef
    0b00000011111111111111111111101011,  // 0xf0
    0b00000111111111111111111111100110,  // 0xf1
    0b00000011111111111111111111101100,  // 0xf2
    0b00000011111111111111111111101101,  // 0xf3
    0b00000111111111111111111111100111,  // 0xf4
    0b00000111111111111111111111101000,  // 0xf5
    0b00000111111111111111111111101001,  // 0xf6
    0b00000111111111111111111111101010,  // 0xf7
    0b00000111111111111111111111101011,  // 0xf8
    0b00001111111111111111111111111110,  // 0xf9
    0b00000111111111111111111111101100,  // 0xfa
    0b00000111111111111111111111101101,  // 0xfb
    0b00000111111111111111111111101110,  // 0xfc
    0b00000111111111111111111111101111,  // 0xfd
    0b00000111111111111111111111110000,  // 0xfe
    0b00000011111111111111111111101110,  // 0xff
    0b00111111111111111111111111111111,  // 0x100
};
// clang-format off

}  // namespace http2
