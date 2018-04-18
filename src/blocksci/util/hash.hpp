//
//  hash.hpp
//  blocksci_devel
//
//  Created by Harry Kalodner on 3/10/17.
//  Copyright © 2017 Harry Kalodner. All rights reserved.
//

#ifndef hash_hpp
#define hash_hpp

#include <blocksci/blocksci_export.h>
#include <cstdint>
#include <functional>

namespace blocksci {
    class uint256;
    class uint160;
}

template <class T>
inline void BLOCKSCI_EXPORT hash_combine(std::size_t &seed, const T& v) {
    std::hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}

blocksci::uint256 BLOCKSCI_EXPORT sha256(const uint8_t *data, size_t len);
blocksci::uint256 BLOCKSCI_EXPORT sha256(const unsigned char *begin, const unsigned char *end);
blocksci::uint256 BLOCKSCI_EXPORT doubleSha256(const char *data, uint64_t len);
blocksci::uint160 BLOCKSCI_EXPORT ripemd160(const char *data, uint64_t len);
blocksci::uint160 BLOCKSCI_EXPORT hash160(const void *data, uint64_t len);

bool BLOCKSCI_EXPORT base58_sha256(void *digest, const void *data, size_t datasz);

#endif /* hash_hpp */
