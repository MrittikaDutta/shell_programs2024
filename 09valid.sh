#!/bin/bash
echo "Enter your username:"
read username

if id "$username" &>/dev/null; then
  echo "User $username exists"
else
  echo "User $username does not exist"
fi