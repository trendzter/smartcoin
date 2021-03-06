SmartCoin (SMC)
===========
### Info
SmartCoin is a fork of the Litecoin project that includes significant differences from the original code. Most noticably the block rewards are different, 51.2 million versus 84 million (LiteCoin). Block reward halfing is also changed. All of the SmartCoins are expected to be mined within 8 months.
### Compiling
#### OS X
SmartCoin is configured to be compiled through Homebrew on OS X.
Simply run `brew install boost openssl berkeley-db4 miniupnpc qt` and then `brew link berkeley-db4 --force && brew link openssl --force`
Then `cd src/` and compile using `makefile.osx` by running `make -f makefile.osx USE_UPNP=-` you should now get a functional smartcoind. Don't forget to `strip smartcoin` to lower the filesize!

For QT builds, make sure you have `qmake` in your path and run `qmake "USE_UPNP=-" smartcoin-qt.pro`.
After that, run `make` and a fully functional QT wallet will be generated.