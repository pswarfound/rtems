#!/bin/sh
/opt/project/rtems/git/rtems/kernel/rtems-4.11.3/configure  --target=arm-rtems4.11 --prefix=`pwd` --disable-posix --disable-itron --disable-cxx --disable-networking --enable-rtemsbsp="stm32f4"
