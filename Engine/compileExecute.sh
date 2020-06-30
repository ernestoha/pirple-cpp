file=a.out
last_modified=`stat -c "%Y" $file`

gcc main.cpp -lstdc++

if [ $((`stat -c "%Y" $file`-$last_modified)) -eq 0 ]; then 
     echo "** ERROR ** CHECK AND COMPILE AGAIN ** "; 
else 
	clear
	./$file
fi

#gcc main.cpp -lstdc++
#./a.out

