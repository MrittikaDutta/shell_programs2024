#!/bin/bash
for (( i=1; i<=4; i++ ))
do
  for (( j=1; j<=i; j++ ))
  do
    echo -n "*"
  done
  echo
done

#!/bin/bash
n=1
for (( i=1; i<=4; i++ ))
do
  for (( j=1; j<=i; j++ ))
  do
    echo -n "$n "
    n=$((n + 1))
  done
  echo
done