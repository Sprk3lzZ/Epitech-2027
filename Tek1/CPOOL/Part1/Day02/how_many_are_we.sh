#!/bin/bash
if [ $# -eq 0 ]
then
	wc -l
else
	cut -d ";" -f3 | grep -i $1 | wc -l
fi
