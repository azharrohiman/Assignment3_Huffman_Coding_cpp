#include <stdio.h> // pre-processor directives
#include <string>      // insert the header files
#include <iostream>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include "HuffmanTree.h"
#include "HuffmanNode.h"
#include "help.h"

using namespace RHMMUH005;
using namespace std; // makes code easier to read

int main(int argc, char *argv[])  // command line args
{

	if (argc < 3) {
		cout << "Please provide the names of the input and output files" << endl;
		return 0;
	}

	//string inputFile = argv[1] + ".txt";
	string inputFile = argv[1];
	unordered_map<char, int> Map;

	HuffmanTree huffmanTree;
	string in = getCharFreq(inputFile, Map);

	huffmanTree.buildTree(Map);

	unordered_map<char, string> map;

	const HuffmanNode& root = *(huffmanTree.root);

	huffmanTree.buildCodeTable(root, "", map);

	string outputFile = (string)argv[2] + ".hdr";
	ofstream out(outputFile, ios::out);

	out << map.size() << "\n";
	for (auto i = map.begin(); i != map.end(); ++i) {
		cout << (i->first) << " " << (i->second) << endl;
		out << (i->first) << " " << (i->second) << "\n";
	}

	out.close();
	string compressedData = compressData(in, map);

	ofstream myCompressedFile;
	myCompressedFile.open("compressed.txt");
	myCompressedFile << compressedData;
	myCompressedFile.close();

	return 0;                         // return code; 0 = OK
}

// methods to compress data

