for entry in "testing/Macrojava/"*
do
	./P1 < "$entry" > "myout/$entry"
done

for entry in "myout/testing/Macrojava/"* 
do
	javac "$entry"
done
