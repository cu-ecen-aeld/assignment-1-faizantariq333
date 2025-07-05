#!/bin/bash

# Check if exactly two arguments are provided
if [ $# -ne 2 ]; then
  echo "Error: Two arguments required - <full file path> and <string to write>"
  exit 1
fi

writefile="$1"
writestr="$2"

# Extract the directory path from the full file path
dirpath=$(dirname "$writefile")

# Create the directory path if it doesn't exist
mkdir -p "$dirpath"

# Try to write to the file
echo "$writestr" > "$writefile"

# Check if the file was successfully created
if [ $? -ne 0 ]; then
  echo "Error: Could not create or write to file '$writefile'"
  exit 1
fi

exit 0

