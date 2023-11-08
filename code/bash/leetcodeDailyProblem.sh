#!/bin/bash

# Set the URL of the daily problem
url="https://leetcode.com/problems/daily-challenge/"

dir=${HOME}/.leetcode/daily_desc

if [[ ! -e "$dir" ]]; then
	mkdir -p "$dir"
fi

# Set the path to the output file
output_file="${dir}/ltc$(date +20%y%m%d).html"

# Use curl to download the page content
curl -s "$url" >"$output_file"

# Print a success message
echo "Daily problem description saved to $output_file"
