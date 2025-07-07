#!/bin/bash
echo "Enter a password:"
read password

len="${#password}"
if [[ $len -ge 8 && "$password" =~ [A-Z] && "$password" =~ [a-z] && "$password" =~ [0-9] ]]; then
  echo "Password is strong"
else
  echo "Password is weak"
fi
