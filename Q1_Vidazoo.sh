#! /bin/bash
# Eilon Ashkenazi 24.5.17
# The script checks if today is your birthday

if [ $2 == `date  +"%d/%m/%y"` ];
then
  echo "happy birthday $1"
else
  echo "no gifts for you... NEXT!!!"
fi
