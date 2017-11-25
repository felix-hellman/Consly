#!/bin/bash

python -c 'print("A"*4096 + " " + "A"*4096)' > t1 #Large buffer test
./tester $(<t1) > r1
diff t1 r1 > /dev/null 2>&1
rm -rf t1 r1
