#!/bin/sh

while true
do
	./test.sh 1 500 | awk '/Total/ { print $2 " " $3 }' > .total
	if [ "$(awk '{ print $2 }' < .total)" = "(KO)" ]; then
		tput setaf 1
	elif [ "$(awk '{ print $1 }' < .total)" -gt 5500 ]; then
		tput setaf 3
	else
		tput sgr0
	fi
	cat .total
done
