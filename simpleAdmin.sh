#!/bin/bash

# Creates new directory in working directory, creates second directory in first
# directory created, creates a text file in the second directory with "Hello
# World" in it, creates soft link to second directory
# Takes 4 command line inputs; dir 1 name, dir 2 name, txt filename, link name
# Example invocation: ./simpleAdmin.sh dir1 dir2 message.txt linkName

# Create the first directory in the current working directory 
mkdir "$1"
echo "Directory '$1' created."

# Create the second directory inside the first directory created
mkdir "$1/$2"
echo "Sub-directory '$2' created inside '$1'."

# Using redirection, create a text file using the third argument as
# the name, write “Hello World!” to it, and save it in the directory created in item 2.
echo "Hello World!" > "$1/$2/$3"
echo "File '$3' created with content 'Hello World!' inside '$1/$2'."

# Create a soft link from the working directory to the sub-directory
# created in item 2 using the fourth argument as the name of the link.
ln -s "$1/$2" "$4"
echo "Soft link '$4' created pointing to '$1/$2'."

