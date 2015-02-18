SmartCoin (SMC)
==============
Website: http://smartcoin.cc  
Bitcointalk: https://bitcointalk.org/index.php?topic=675821.0  
Blockchain: http://smc-explorer.lavastorm.net  
Wallet: https://github.com/psionin/smartcoin/releases/download/0.9.1/smartcoin-0.9.1.zip


SmartCoin Attributes
--------------------
PoW Algorithm: Scrypt / X11 after July 24  
Block Interval: 30 seconds / 2 minutes after July 24  
Difficulty Retarget: every block (DigiShield)  
Subsidy Distribution: 64 from block 1K to 200K, 32 from 200K to 300K, 16 with yearly halving after 300K  
Total Coin Supply: ~24.5 million coins


License
-------
Copyright (c) 2009-2014 Bitcoin, Litecoin, SmartCoin Developers  
SmartCoin is released under the terms of the MIT license. See `COPYING` for more information or see http://opensource.org/licenses/MIT.


Source Code
-----------
The master branch should have the latest stable release code.


Build Instructions
------------------
###### Linux  
To build on Linux, first make sure you have the necessary dependencies
```
apt-get update && apt-get upgrade
apt-get install ntp git build-essential libssl-dev libdb-dev libdb++-dev libboost-all-dev libqrencode-dev

wget http://miniupnp.free.fr/files/download.php?file=miniupnpc-1.8.tar.gz && tar -zxf download.php\?file\=miniupnpc-1.8.tar.gz && cd miniupnpc-1.8/
make && make install && cd .. && rm -rf miniupnpc-1.8 download.php\?file\=miniupnpc-1.8.tar.gz
```
Get the source code
```
git clone https://github.com/psionin/smartcoin
```
And go into the directory
```
cd smartcoin
```
Change ownership for a leveldb file so that it can build
```
chmod 755 src/leveldb/build_detect_platform  
```
Compile and move smartcoind
```
cd src
make -f makefile.unix USE_UPNP=1 USE_IPV6=1
strip smartcoind
mv smartcoind ../..
```


###### Windows  
See \doc\build-msw.txt

###### OS X  
See \doc\build-osx.txt

