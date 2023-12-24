#!/bin/bash

filename=.blabla000ttt
filename2=.blabla001ttt
# filename3=.blabla003ttt

touch $filename
touch $filename2
# touch $filename3
i=1
while [[ i -le 10000 ]]
do
A=($(seq -500 500 | sort -R | head -n 100))
$1 "${A[@]}" | wc -l | awk '{if ($1 > 5500) printf("%d ***************************\n", $1); else print $1 }' >> $filename
$1 "${A[@]}" | ./checker_Mac "${A[@]}" >> $filename
$2 "${A[@]}" | wc -l | awk '{if ($1 > 5500) printf("%d ***************************\n", $1); else print $1 }' >> $filename2
$2 "${A[@]}" | ./checker_Mac "${A[@]}" >> $filename2
# $3 "${A[@]}" | wc -l | awk '{if ($1 > 5500) printf("%d ***************************\n", $1); else print $1 }' >> $filename3
# $3 "${A[@]}" | ./checker_Mac "${A[@]}" >> $filename3
(( i += 1 ))
done


KO=$(cat $filename | grep -c KO)
MR=$(cat $filename | grep '*')
cat $filename | grep -v OK | awk '{print $1}' > .blabla0001ttt


rm -f $filename
filename=.blabla0001ttt
sum=0
count=0
min=
max=

while IFS= read -r line; do
    if [[ "$line" =~ ^[0-9]+$ ]]; then
        sum=$((sum + line))
        count=$((count + 1))

        if [ -z "$min" ] || [ "$line" -lt "$min" ]; then
            min=$line
        fi

        if [ -z "$max" ] || [ "$line" -gt "$max" ]; then
            max=$line
        fi
    else
        echo "Warning: Skipping invalid number on line '$line'"
    fi
done < "$filename"

if [ "$count" -eq 0 ]; then
    echo "Error: No valid numbers found in the file."
    exit 1
fi

average=$(( $sum / $count ))

rm -f $filename
echo "1"
echo "KO: $KO"
echo "Count: $count"
echo "Min: $min"
echo "Average: $average"
echo "Max: $max"

KO2=$(cat $filename2 | grep -c KO)
cat $filename2 | grep -v OK | awk '{print $1}' > .blabla0002ttt
rm -f $filename2
filename2=.blabla0002ttt
sum=0
count=0
min=
max=

while IFS= read -r line; do
    if [[ "$line" =~ ^[0-9]+$ ]]; then
        sum=$((sum + line))
        count=$((count + 1))

        if [ -z "$min" ] || [ "$line" -lt "$min" ]; then
            min=$line
        fi

        if [ -z "$max" ] || [ "$line" -gt "$max" ]; then
            max=$line
        fi
    else
        echo "Warning: Skipping invalid number on line '$line'"
    fi
done < "$filename2"

if [ "$count" -eq 0 ]; then
    echo "Error: No valid numbers found in the file."
    exit 1
fi

average=$(( $sum / $count ))

rm -f $filename2
echo "
2"
echo "KO: $KO"
echo "Count: $count"
echo "Min: $min"
echo "Average: $average"
echo "Max: $max"





# KO2=$(cat $filename3 | grep -c KO)
# cat $filename3 | grep -v OK | awk '{print $1}' > .blabla0004ttt
# rm -f $filename3
# filename3=.blabla0004ttt
# sum=0
# count=0
# min=
# max=

# while IFS= read -r line; do
#     if [[ "$line" =~ ^[0-9]+$ ]]; then
#         sum=$((sum + line))
#         count=$((count + 1))

#         if [ -z "$min" ] || [ "$line" -lt "$min" ]; then
#             min=$line
#         fi

#         if [ -z "$max" ] || [ "$line" -gt "$max" ]; then
#             max=$line
#         fi
#     else
#         echo "Warning: Skipping invalid number on line '$line'"
#     fi
# done < "$filename3"

# if [ "$count" -eq 0 ]; then
#     echo "Error: No valid numbers found in the file."
#     exit 1
# fi

# average=$(( $sum / $count ))

# rm -f $filename3
# echo "
# 2"
# echo "KO: $KO"
# echo "Count: $count"
# echo "Min: $min"
# echo "Average: $average"
# echo "Max: $max"