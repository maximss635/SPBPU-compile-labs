for file in `find TestCases/nano`
do
	echo 'Compile "'$file'"...'
	./cmake-build-debug/Compile $file $1
	echo ""
done

