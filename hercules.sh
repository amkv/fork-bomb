#!/bin/zsh

NAME="manger"
SEC=5

# UNIX signals
# Illegal Instruction
SIGILL=4
# Trace/Breakpoint Trap
SIGTRAP=5
# Bus Error
SIGBUS=10
# Segmentation Fault
SIGSEGV=11
# Terminated
SIGTERM=15

# run the manger
echo "1. run $NAME in the background &"
./$NAME &
echo "$NAME runned"

# wait 3 second
echo "2. waiting $SEC seconds"
sleep $SEC

# kill processes
echo "3. killing the processes"
pkill -$SIGILL podargos
pkill -$SIGILL ruins
pkill -$SIGTRAP lampon
pkill -$SIGBUS xanthos
pkill -$SIGBUS "\-bash"
pkill -$SIGSEGV deinos
pkill -$SIGSEGV "crap.*\.poo"
pkill yes
echo "3.1 podagros killed"
echo "3.2 riuns killed"
echo "3.3 lampon killed"
echo "3.4 xanthos killed"
echo "3.5 -bash killed"
echo "3.6 deinos killed"
echo "3.7 crap*.poo killed"
echo "3.8 yes killed"
echo "done"

# clean the folder
echo "4. clean the folder"
find . -name "crap*" -delete

# show current processes
echo "5. show current processes"
sleep 1
ps
