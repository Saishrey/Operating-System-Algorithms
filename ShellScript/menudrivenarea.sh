#!/bin/bash

while :
do
    echo "1. Area of circle"
    echo "2. Area of Triangle"
    echo "3. Circumference of circle"
    echo "4. Exit"
    echo -n "Make your choice: "
    read choice

    case $choice in
    1) echo "Choice 1: Area of circle"
       read -p "Enter radius: " radius

       area=$(($radius*$radius*22/7))

       echo "Area = $area"
       echo -e "\n\n";;

    2) echo "Choice 2: Area of triangle"
       read -p "Enter base: " base
       read -p "Enter height: " height

       area=$(($base*$height/2))

       echo "Area = $area"
       echo -e "\n\n";;

    3) echo "Choice 3: Circumference of circle"
       read -p "Enter radius: " radius

       cir=$(($radius*2*22/7))

       echo "Circumference = $cir"
       echo -e "\n\n";;
    
    4) exit;;
    *) echo -e "Invalid option.\n\n";;
    esac 
done
