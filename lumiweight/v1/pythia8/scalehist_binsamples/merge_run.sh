#!/bin/bash

python merge.py
rm addfile.root
rm add.sh
echo 'hadd addfile.root' > xx.sh
ls PY*.root >> xx.sh
tr '\r\n' ' ' < xx.sh >> add.sh 
chmod 755 add.sh
./add.sh
rm xx.sh 
