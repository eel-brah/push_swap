#!/bin/bash

filename=.blabla000s
filename2=.blabla001s
filename3=.blabla003s
filename4=.blabla007s
filename5=.blabla008s

touch $filename
touch $filename2
touch $filename3
touch $filename4
touch $filename5
i=1
while [[ i -le 1000 ]]
do
A=($(seq -255 500 | sort -R | head -n 100))
$1 "${A[@]}" | wc -l | awk '{if ($1 > 5500) printf("%d ***************************\n", $1); else print $1 }' >> $filename
$1 "${A[@]}" | ./checker_Mac "${A[@]}" >> $filename
$2 "${A[@]}" | wc -l | awk '{if ($1 > 5500) printf("%d ***************************\n", $1); else print $1 }' >> $filename2
$2 "${A[@]}" | ./checker_Mac "${A[@]}" >> $filename2
$3 "${A[@]}" | wc -l | awk '{if ($1 > 5500) printf("%d ***************************\n", $1); else print $1 }' >> $filename3
$3 "${A[@]}" | ./checker_Mac "${A[@]}" >> $filename3

$4 "${A[@]}" | wc -l | awk '{if ($1 > 5500) printf("%d ***************************\n", $1); else print $1 }' >> $filename4
$4 "${A[@]}" | ./checker_Mac "${A[@]}" >> $filename4
$5 "${A[@]}" | wc -l | awk '{if ($1 > 5500) printf("%d ***************************\n", $1); else print $1 }' >> $filename5
$5 "${A[@]}" | ./checker_Mac "${A[@]}" >> $filename5
(( i += 1 ))
done


KO=$(cat $filename | grep -c KO)
MR=$(cat $filename | grep '*')
cat $filename | grep -v OK | awk '{print $1}' > .blabla0001s


rm -f $filename
filename=.blabla0001s
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
cat $filename2 | grep -v OK | awk '{print $1}' > .blabla0002s
rm -f $filename2
filename2=.blabla0002s
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





KO2=$(cat $filename3 | grep -c KO)
cat $filename3 | grep -v OK | awk '{print $1}' > .blabla0004s
rm -f $filename3
filename3=.blabla0004s
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
done < "$filename3"

#check if any valid numbers were found
if [ "$count" -eq 0 ]; then
    echo "Error: No valid numbers found in the file."
    exit 1
fi

#calculate the average
average=$(bc <<< "scale=2; $sum / $count")

rm -f $filename3
echo "
2"
echo "KO: $KO"
#echo "Sum: $sum"
echo "Count: $count"
echo "Min: $min"
echo "Average: $average"
echo "Max: $max"



KO2=$(cat $filename4 | grep -c KO)
cat $filename4 | grep -v OK | awk '{print $1}' > .blabla0009s
rm -f $filename4
filename4=.blabla0009s
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
done < "$filename4"

#check if any valid numbers were found
if [ "$count" -eq 0 ]; then
    echo "Error: No valid numbers found in the file."
    exit 1
fi

#calculate the average
average=$(bc <<< "scale=2; $sum / $count")

rm -f $filename4
echo "
2"
echo "KO: $KO"
#echo "Sum: $sum"
echo "Count: $count"
echo "Min: $min"
echo "Average: $average"
echo "Max: $max"




KO2=$(cat $filename5 | grep -c KO)
cat $filename5 | grep -v OK | awk '{print $1}' > .blabla0004s
rm -f $filename5
filename5=.blabla0004s
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
done < "$filename5"

#check if any valid numbers were found
if [ "$count" -eq 0 ]; then
    echo "Error: No valid numbers found in the file."
    exit 1
fi

#calculate the average
average=$(bc <<< "scale=2; $sum / $count")

rm -f $filename5
echo "
2"
echo "KO: $KO"
#echo "Sum: $sum"
echo "Count: $count"
echo "Min: $min"
echo "Average: $average"
echo "Max: $max"