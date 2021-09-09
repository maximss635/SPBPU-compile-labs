for file in `find TestCases/nano`
do
	echo 'Compile "'$file'"...'
	./cmake-build-debug/Compile $file 
	echo ""
done

