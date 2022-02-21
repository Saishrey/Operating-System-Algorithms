#!/bin/bash
read -p "Enter Celcius value: "  celcius

fahren=$(($celcius*9/5+32))

echo "$celcius C = $fahren F"
