#!/bin/bash

echo "enter filename"
read filename
if [ -d $filename ];
then
echo "It is a directory"
else
echo "just a file"
fi


