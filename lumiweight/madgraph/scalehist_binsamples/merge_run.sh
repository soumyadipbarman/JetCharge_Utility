#!/bin/bash

python merge.py
rm MG5_PY8_bin.root
rm add.sh
echo 'hadd MG5_PY8_bin.root' > xx.sh
ls MG*.root >> xx.sh
tr '\r\n' ' ' < xx.sh >> add.sh 
chmod 755 add.sh
./add.sh
rm xx.sh 
