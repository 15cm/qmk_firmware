#!/bin/bash

buf=$(mktemp)
f_keymap=keymap.c

if [ "$#" -ne 1 ]; then
  echo "Usage(in the same dir with keymap.c): $0 new-keymap-path" >&2
  exit 1
fi

awk '/PROGMEM keymaps/ {exit} {print}' keymap.c > $buf
awk 'BEGIN {state=0} /PROGMEM keymaps/ {state=1} {if(state==1) print} /};/ {if(state==1) exit}' "$1" >> $buf
awk 'BEGIN {state=0} {if(state==2) print} /PROGMEM keymaps/ {state=1} /};/ {if(state==1) state=2}' keymap.c >> $buf

mv $buf keymap.c
