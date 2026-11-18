bin/testListLinked: testListLinked.cpp ListLinked.h
	mkdir -p bin
	g++ -o bin/testListLinked testListLinked.cpp

bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp

bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp
   

bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp

bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp

clean:
	rm -r *.o *.gch *.pch bin

testListLinked:
	./bin/testListLinked
testListArray:
	./bin/testListArray
testNode:
	./bin/testNode
