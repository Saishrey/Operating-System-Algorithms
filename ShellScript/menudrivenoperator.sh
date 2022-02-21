#!/bin/bash

echo "Enter two numbers: "
read num1
read num2

while :
do
    echo "1. Add(+)"
    echo "2. Subtract(-)"
    echo "3. Multiply(*)"
    echo "4. Divide(/)"
    echo "5. Exit"
    echo "Enter your choice: "

    read choice
    
    result=0

    case $choice in
    1)  echo "Choice 1: Add"
        result=$(($num1+$num2))
        echo "$num1 + $num2 = $result"
        echo -e "\n\n";;
    2)  echo "Choice 2: Subtract"
        result=$(($num1-$num2))
        echo "$num1 - $num2 = $result"
        echo -e "\n\n";;
    3)  echo "Choice 2: Multiply"
        result=$(($num1*$num2))
        echo "$num1 * $num2 = $result"
        echo -e "\n\n";;
    4)  echo "Choice 2: Divide"
        result=$(($num1/$num2))
        echo "$num1 / $num2 = $result"
        echo -e "\n\n";;
    5) exit;;
    *) echo "Invalid option!\n\n";;
    esac
done