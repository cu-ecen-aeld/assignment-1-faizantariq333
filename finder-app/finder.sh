#!/bin/sh


if [ $# -ne 2 ] 
then
	echo "Error: Two arguments are required, file directory path and search string"
	exit 1
else	
	filesdir="$1"
	searchstr="$2"

	if [ ! -d "$filesdir" ]
	then
		echo "Error: '$filesdir' is not a valid directory"
		exit 1
	else
		#counts the number of files and subdirectories
		filecount=$(find "$filesdir" -type f | wc -l)

		#counts the number of matching lines
		matchcount=$(grep -r "$searchstr" "$filesdir" 2>/dev/null | wc -l )

		echo "The number of files are $filecount and the number of matching lines are $matchcount"
	fi

fi


