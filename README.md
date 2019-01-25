# cgminer-hash
#set environment
source ~/ti-processor-sdk-linux-am335x-evm-04.01.00.06/linux-devkit/environment-setup

#new system
sudo apt-get install autoconf automake libtool
sudo apt-get install libffi-dev
#end

make distclean

rm compat/jansson-2.9/jansson_private_config.h.in
rm config.h.in

./autogen.sh

cp configured configure
cp Makefile.ind Makefile.in
cp config.h.ind config.h.in

//default: T2 hash, simplex mode spi
./configure --enable-bitmine_A1 --without-curses --host=arm-linux-gnueabi --build=x86_64-pc-linux-gnu
./configure --enable-bitmine_T2 --without-curses --host=arm-linux-gnueabi --build=x86_64-pc-linux-gnu CPPFLAGS=-I./compat/jansson-2.9/src

make -j2
