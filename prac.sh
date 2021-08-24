! /usr/bin/bash

read -p "Enter your name please: " IN_NAME
if [ "$IN_NAME" == "foo" ] ;then
    echo "Hi $IN_NAME"
elif [ "$IN_NAME" == "bar" ] 
then
    echo "$IN_NAME, hi bar!"
else
    echo "$IN_NAME, you are not XD"
fi

read -p "Love or Hate? Y/N: " ANS
case "$ANS" in 
    [yY] | [yY][eE][sS]) # case 1
        echo "Love it is!" #do this
        ;;
    [nN] | [nN][oO]) # case 2
        echo "Hate it is!" # do that
        ;; # break statement
    *) # end of cases
        echo "Please enter either yes/no (y/n)" # default (if no cases are true)
        ;;
esac # end case

echo "done"
