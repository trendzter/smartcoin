// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //
    static MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of
        (         0, uint256("0x142d2acd2480363e89fad37be56ff3b8993dd8da2be2525d75b02e202b0467a7"))
        (      1000, uint256("0xd8d586d8e99ecdff7d9bcc412e1b8f301e2c5641768b537801e9a7f0619297d6"))
        (      5000, uint256("0x36d7906d0a017742edd6e7eae6cff069832165398ac9ef73fe712d2adaf944f9"))
        (     10000, uint256("0x12b0fee6a4a6324a1c3a0f94bfc4cdc3c373a90d680209042dbb612b4349616a"))
        (     20000, uint256("0x5f8af1dba6066444622b80f73a747ed63c22b18807d5ad689a4dc161c8bcbaf4"))
        (     28000, uint256("0x5dfcad35cc89f908dbcf7615ed7789f553620f84f3ede4e039ae4e6e7cebd759"))
        (     50000, uint256("0x375b8ea412c58e1e1f47cb95c9dbbd4bf5428fcf00267361a380a23c16c32cfc"))
        (     100000, uint256("0x0c0628dc3b5df07c22fff9ace256b83e9b6c8c7c664b49b2ab5d3b2e485efb7e"))
        (     110000, uint256("0x26830291007047043cdf88eecb82e53295e240bf50fc91dcb2fcbc0fa9ac9caa"))
        (     120000, uint256("0x47ef2d5eece2e369f1f9f3f5cfe02edf9c4a47a6916b0c07d34ec3e0e521119b"))
        (     130000, uint256("0x1260c931c38e127cce3b7aa54ca7e0ac841ed9bbef5481913996baa598cef9c6"))
        (     140000, uint256("0x675b1bc380d5827ecb4ccde96e8566c055e6022d70bdddf794a3bb626ee9ec5a"))
        ;

    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;
        return hash == i->second;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;
        return mapCheckpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }
}
