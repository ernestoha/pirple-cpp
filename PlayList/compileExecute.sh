file=a.out
last_modified=`stat -c "%Y" $file`

clear
echo "** COMPILING... **"; 

gcc main.cpp List_base.cpp Playlist.cpp ListIndex.cpp PlayListParser.cpp TrackParser.cpp -lstdc++

if [ $((`stat -c "%Y" $file`-$last_modified)) -eq 0 ]; then 
	echo "** ERROR ** CHECK AND COMPILE AGAIN **"; 
else
	echo "!! OK !!"; 
	if [ "$1" == "" ]; then
		# echo "Parameter 1 is empty"
		./$file
	fi
fi

#use:
# >compileExecute.sh <- Compile and Execute.
# >conpileExecute.sh noExec <- Only compile, Parameter 1 is not empty.