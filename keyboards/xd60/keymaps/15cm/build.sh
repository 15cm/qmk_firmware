#!/bin/sudo /bin/bash

LIMIT=10
THREADS="-j 4"
KEYBOARD=xd60
KMAP=15cm

function wait_bootloader {
  echo "Waiting for Bootloader..."
  local STARTTIME=$(date +"%s")
  local REMIND=0
  local EXEC="sudo dfu-programmer"
  local TARGET=atmega32u4
  while true
  do
    $EXEC $TARGET get > /dev/null 2>&1
    [ $? -eq 0 ] && break
    ENDTIME=$(date +"%s")
    DURATION=$(($ENDTIME-$STARTTIME))
    if [ $REMIND -eq 0 -a $DURATION -gt $LIMIT ]
    then
      echo "Did you forget to press the reset button?"
      REMIND=1
    fi
    sleep 1
  done
}
# make clean
cd ../../../..
make KEYBOARD=${KEYBOARD} KEYMAP=${KMAP} ${THREADS}
if [[ $? -eq 0 ]]
then
  echo "please trigger flashing!"
  wait_bootloader
  make KEYBOARD=${KEYBOARD} KEYMAP=${KMAP} dfu ${THREADS}
else
  echo "make failed"
  exit 77
fi
