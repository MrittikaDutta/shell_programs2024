echo "enter n:"
read n
f=1
for ((i=0;i<n;i++))
do
    for ((j=0;j<i;j++))
    do
    echo -n "$f"
    f=$((f+1))
    done
    echo
done