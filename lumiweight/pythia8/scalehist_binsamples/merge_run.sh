#!/bin/bash

python merge.py
rm PY8_bin.root
rm add.sh
echo 'hadd PY8_bin.root' > xx.sh
ls PY*.root >> xx.sh
tr '\r\n' ' ' < xx.sh >> add.sh 
chmod 755 add.sh
./add.sh
rm xx.sh 
