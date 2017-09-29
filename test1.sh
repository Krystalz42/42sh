#!/usr/bin/env ksh
echo "S: PID $$  PPID $PPID"
sh test.sh A | sh test.sh B | sh test.sh C
