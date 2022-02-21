#!/bin/bash

while :
do
    echo "+----------------MENU----------------+"
    echo "|  1  | Display files with its type  |"
    echo "|  2  | Display todays date          |"
    echo "|  3  | Display Users of this system |"
    echo "|  4  | Exit                         |"
    echo "+------------------------------------+"
    echo -n "Enter your choice: "

    read choice

    case $choice in
    1)  echo "Choice 1: Files in this directory are: "
        ls
        echo -e "\n\n";;
    2)  echo "Choice 2: Todays date is: "
        date
        echo -e "\n\n";;
    3)  echo "Choice 3: Users in this system are: "
        who
        echo -e "\n\n";;
    4)  exit;;
    *)  echo -e "Invalid option.\n\n";;
esac
done
