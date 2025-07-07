echo "enter password:"
read p
l="${#p}"
if [[ $l -ge 8 && "$p" =~ [a-z] && "$p" =~ [A-Z] && "$p" =~ [0-9] ]]; then
    echo "strong"
else
    echo "weak"
fi