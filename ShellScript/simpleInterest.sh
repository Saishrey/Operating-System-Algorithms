#!/bin/bash
read -p "Enter initial Principal balance: " P
read -p "Enter annual interest rate: " r
read -p "Enter time(in years): " t

SI=$(($P*$r*$t/100))
A=$(($P+$SI))

echo "Simple interest: $SI"
echo "Final amount: $A"

