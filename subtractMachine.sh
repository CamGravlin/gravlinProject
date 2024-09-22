#!/bin/bash

# Takes two numbers that aren't equal, finds the difference, and counts down the
# difference to one
# Takes two command line inputs, num1 and num2
# Example invocation: ./subtractMachine 3 8

# Assign the command line arguments to variables
num1=$1
num2=$2

# Check if the numbers are equal
if [ "$num1" -eq "$num2" ]; then
echo "The numbers cannot be equal."
exit 1
fi

# 1. Subtract the smaller from the larger and print the difference
if [ "$num1" -gt "$num2" ]; then
echo "$num1 is larger than $num2"
difference=$((num1 - num2))
   else
      echo "$num2 is larger than $num1"
      difference=$((num2 - num1))
fi

echo "Difference: $difference"

# 2. Count down from the difference to 1 and print each count
echo "Countdown from $difference to 1:"
for ((i = difference; i >= 1; i--)); do
  echo "$i"
done

