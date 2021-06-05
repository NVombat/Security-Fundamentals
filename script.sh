#CALCULATES THE SUM OF N NUMBERS
#Ask user to input value of n
echo ENTER VALUE OF N:
#Read user input
read n

#Use cnt and sum variables to get sum
cnt=0
sum=0

#Run till we reach the value of n
while [ $cnt -ne $n ] 
do
	#Add the numbers and increment cnt
        sum=$((sum+cnt))
        cnt=$((cnt+1))
done
#Add n to the sum 
sum=$((sum+n))
#Print sum
echo "$sum is the sum of all numbers from 0 to $n including $n"