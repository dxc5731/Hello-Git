#!/bin/bash
declare -i res=0
while read line;do res+=$line;done <data
echo $res >result.json


