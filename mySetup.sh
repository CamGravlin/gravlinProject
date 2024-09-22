#!/bin/bash

# This script sets the CPU frequency to 600 MHZ, displays CPU info, displays the
# location of the location variable, and modifies the PATH variable so you can
# run this script in any directory
# No command line inputs are needed
# Example invocation: ./mySetup.sh

# Set the frequency to 600 MHz
echo "Setting CPU frequency to 600 MHz"
sudo cpufreq-set -f 600MHZ

# Display CPU info
echo "CPU information"
cpufreq-info

# Creating variable named location
location="/home/debian"

# Echo value of variable location
echo "Location variable value is: $location"

# Create variable named items and display number of items
items=$(ls | wc -l)
echo "Number of items in the current directory: $items"

# Modify PATH variable to script directory
export PATH=$PATH:/home/debian/

# Save new PATH value to a file
echo $PATH > newPathValue.txt
