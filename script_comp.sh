#!/bin/bash

filename=.blabla000
filename2=.blabla001

touch $filename
touch $filename2
i=1
while [[ i -le 1000 ]]
do
A=($(seq -255 500 | sort -R | head -n 500))
$1 "${A[@]}" | wc -l | awk '{if ($1 > 5500) printf("%d ***************************\n", $1); else print $1 }' >> $filename
$1 "${A[@]}" | ./checker_Mac "${A[@]}" >> $filename
$2 "${A[@]}" | wc -l | awk '{if ($1 > 5500) printf("%d ***************************\n", $1); else print $1 }' >> $filename2
$2 "${A[@]}" | ./checker_Mac "${A[@]}" >> $filename2
(( i += 1 ))
done


KO=$(cat $filename | grep -c KO)
MR=$(cat $filename | grep '*')
cat $filename | grep -v OK | awk '{print $1}' > .blabla0001


rm -f $filename
filename=.blabla0001
sum=0
count=0
min=
max=

#read each line from the file and calculate the sum, count, min, and max
while IFS= read -r line; do
    #check if the line is a valid number
    if [[ "$line" =~ ^[0-9]+$ ]]; then
        sum=$((sum + line))
        count=$((count + 1))

        #update min and max
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

#check if any valid numbers were found
if [ "$count" -eq 0 ]; then
    echo "Error: No valid numbers found in the file."
    exit 1
fi

#calculate the average
average=$(bc <<< "scale=2; $sum / $count")

rm -f $filename
echo "1"
echo "KO: $KO"
#echo "Sum: $sum"
echo "Count: $count"
echo "Min: $min"
echo "Average: $average"
echo "Max: $max"

KO2=$(cat $filename2 | grep -c KO)
cat $filename2 | grep -v OK | awk '{print $1}' > .blabla0002
rm -f $filename2
filename2=.blabla0002
sum=0
count=0
min=
max=

#read each line from the file and calculate the sum, count, min, and max
while IFS= read -r line; do
    #check if the line is a valid number
    if [[ "$line" =~ ^[0-9]+$ ]]; then
        sum=$((sum + line))
        count=$((count + 1))

        #update min and max
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

#check if any valid numbers were found
if [ "$count" -eq 0 ]; then
    echo "Error: No valid numbers found in the file."
    exit 1
fi

#calculate the average
average=$(bc <<< "scale=2; $sum / $count")

rm -f $filename2
echo "
2"
echo "KO: $KO"
#echo "Sum: $sum"
echo "Count: $count"
echo "Min: $min"
echo "Average: $average"
echo "Max: $max"


