#! /usr/bin/bash
#read -p "Enter your name please: " IN_NAME
#if [ "$IN_NAME" == "foo" ] ;then
    #echo "Hi $IN_NAME"
#elif [ "$IN_NAME" == "bar" ] 
#then
    #echo "$IN_NAME, hi bar!"
#else
    #echo "$IN_NAME, you are not XD"
#fi

#read -p "Love or Hate? Y/N: " ANS
#case "$ANS" in 
    #[yY] | [yY][eE][sS]) # case 1
        #echo "Love it is!" #do this
        #;;
    #[nN] | [nN][oO]) # case 2
        #echo "Hate it is!" # do that
        #;; # break statement
    #*) # end of cases
        #echo "Please enter either yes/no (y/n)" # default (if no cases are true)
        #;;

#esac # end case

#TNAME=$(ls) # need brackets to iterate over a command.
#for NAME in $TNAME; do
    #echo "Hello, $NAME"
#done

#echo "done"

#NUM = 1

#while [[ "$NUM" -le 20 ]]; do
    #echo "$NUM"
    #((NUM++))
#done

#for i in {0..30}; do 
    #echo "$i"
#done

#for ((i=1; i < 10; ++i)); do 
    #if ((i%2==0)); then
        #echo "$i"
    #else 
        #echo "--"
    #fi 
#done

#echo "done"

ARR=("$@") # unlimited space array

echo ${ARR[1]} # echo 'x' content of the array

echo $# # echo the length of the array
