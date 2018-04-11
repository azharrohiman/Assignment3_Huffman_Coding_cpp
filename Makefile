CC=g++

huffencode: HuffmanNode.o HuffmanTree.o driver.o
	$(CC) driver.o HuffmanNode.o HuffmanTree.o -o huffencode

HuffmanNode.o: HuffmanNode.cpp HuffmanNode.h
	$(CC) -c HuffmanNode.cpp

HuffmanTree.o: HuffmanTree.cpp HuffmanTree.h
	$(CC) -c HuffmanTree.cpp

driver.o: driver.cpp
	$(CC) -c driver.cpp

clean:
	rm -rf *.o huffencode
