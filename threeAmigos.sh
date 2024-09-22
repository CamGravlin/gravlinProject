#!/bin/bash

# Accepts four numbers in the command line, sums the first three, finds the
# difference of the first three and the fourth using subtractMachine.sh and
# counts down the difference to one
#Example invocation: ./threeAmigos.sh 5 5 5 4

# Assign command line arguments to variables
num1=$1
num2=$2
num3=$3
num4=$4

# Sum the first three numbers
sum=$((num1 + num2 + num3))
echo "Sum of the first three numbers: $sum"

# Execute subtractMachine.sh with the sum as the first argument and
# the fourth command line argument as the second argument
echo "Executing subtractMachine.sh with arguments: $sum and $num4"
./subtractMachine.sh $sum $num4
        
