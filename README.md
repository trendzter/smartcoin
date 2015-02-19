![SMC Logo](http://i60.tinypic.com/nvxreo.png)
<h5> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; [smartcoin.cc](http://smartcoin.cc) &nbsp;&nbsp; [bitcointalk](https://bitcointalk.org/index.php?topic=675821.0) &nbsp;&nbsp; [explorer](http://smc-explorer.lavastorm.net) &nbsp;&nbsp; [wallet-win32](http://www.filedropper.com/smartcoin-091)<h5>
<br>

SmartCoin Attributes
--------------------
PoW Algorithm: X11  
Block Interval: 2 minutes  
Difficulty Retarget: DarkGravityWave3  
Block Subsidy: 16 SMC  
Total Coin Supply: ~24.5 million coins


License
-------
Copyright © 2009-2015 Bitcoin, Litecoin, and SmartCoin Developers. SmartCoin is released under the terms of the [MIT license](http://opensource.org/licenses/MIT).


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
