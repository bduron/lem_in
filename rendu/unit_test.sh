#!/bin/bash

YEL="\033[33m"
GREEN="\033[32m"
RES="\033[0m"
INT_MAX="2147483647"
INT_MIN="-2147483648"

echo -e "\n=============================="
echo -e "== $GREEN""  Lem_in parsing tests$RES   =="
echo -e "==============================\n"

echo -e "$YEL""Test 00: 0 ants$RES"; echo "0" | ./lem_in 
echo -e "\n$YEL""Test 01: -10 ants$RES"; echo "-10" | ./lem_in 
echo -e "\n$YEL""Test 02: INT_MAX ants$RES"; echo "$INT_MAX" | ./lem_in 
echo -e "\n$YEL""Test 03: 10 ants$RES"; echo "10" | ./lem_in 

echo -e "\n$YEL""Test 04: 0 room$RES"; echo "10" | ./lem_in 
echo -e "\n$YEL""Test 05: 0 room, 3 comments$RES";
	echo -e "10\n#comment\n##comment\n###comment\n3-4" | ./lem_in 

