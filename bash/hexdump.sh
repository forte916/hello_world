#!/bin/sh


if [ $# -ne 4 ]
then
	echo "Usage: $0 <source> <start> <end> <width>" 1>&2
	exit 2
fi


SOURCE="$1"
START="$2"
 END="$3"
 WIDTH="$4"
 LENGTH=`expr $END - $START`


 hexdump -s $START -n $LENGTH -e $WIDTH'/1 "%02X "' -e '" : "' -e '"%_p"' -e '"\n"' $SOURCE

