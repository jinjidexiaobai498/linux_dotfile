#!/bin/bash

files=$(find -type f | grep .scd$)
for i in $files; do
	mv $i ${i%.scd}
done
