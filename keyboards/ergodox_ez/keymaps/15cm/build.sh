#!/bin/bash

buf=$(mktemp)

if [ "$#" -ne 1 ]; then
  echo "Usage(in the same dir with keymap.c): $0 new-keymap-source-dir" >&2
  exit 1
fi

f_keymap="$1/keymap.c"
f_config="$1/config.h"

sed -i 's/KC_F24/_KC_PWD/' "$f_keymap"
awk '/PROGMEM keymaps/ {exit} {print}' keymap.c > $buf
awk 'BEGIN {state=0} /PROGMEM keymaps/ {state=1} {if(state==1) print} /};/ {if(state==1) exit}' "$f_keymap" >> $buf
awk 'BEGIN {state=0} {if(state==2) print} /PROGMEM keymaps/ {state=1} /};/ {if(state==1) state=2}' keymap.c >> $buf
cp $f_config ./

mv $buf keymap.c
