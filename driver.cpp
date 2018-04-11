#include <stdio.h> // pre-processor directives
#include <string>      // insert the header files
#include <iostream>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include "HuffmanTree.h"
#include "HuffmanNode.h"
#include <bitset>

using namespace RHMMUH005;
using namespace std; // makes code easier to read

std::string compressData(std::string input, std::unordered_map<char, std::string>& map);

std::string getCharFreq(std::string inputFile, std::unordered_map<char, int>& Map);

int main(int argc, char *argv[])  // command line args
{

	if (argc < 3) {
		cout << "Please provide the names of the input and output files" << endl;
		return 0;
	}

	//string inputFile = (string)argv[1] + ".txt";
	string inputFile = string(argv[1]);
	unordered_map<char, int> Map;

	string in = getCharFreq(inputFile, Map);
	cout << in << endl;

	HuffmanTree huffmanTree;
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

	/*
	for (int i = 0; i < in.size(); i++) {
		cout << map[in.at(i)] << endl;
	}
	*/
	
	string compressedData = compressData(in, map);

	bitset<sizeof(unsigned long) * 8 > bits(compressedData);
	unsigned long binary_value = bits.to_ulong();

	ofstream myCompressedFile;
	myCompressedFile.open("compressed.txt");

	myCompressedFile.write((const char*)&binary_value, sizeof(unsigned long));
	/*
	ofstream myCompressedFile;
	myCompressedFile.open("compressed.txt");
	myCompressedFile << compressedData;
	myCompressedFile.close();
	*/
	return 0;                         // return code; 0 = OK
}

// methods to compress data


std::string compressData(std::string input, std::unordered_map<char, std::string>& map) {
	std::string output = "";

	for (int i = 0; i < input.size(); i++) {
		output += map[input.at(i)];
		//cout << map[input.at(i)] << endl;
	}

	return output;
}

std::string getCharFreq(std::string inputFile, std::unordered_map<char, int>& Map) {
	string input = "";
	ifstream in(inputFile, ios::in);

	if (in.is_open()) {
		char character;
		while (!in.eof()) {
			in.get(character);
			if (character != '\n') {

				/*
				Map[character] += 1;
				*/

				if (Map.count(character) > 0) {
					Map[character] += 1;
				}
				else {
					Map[character] = 1;
				}
				input += character;
			}
		}
		in.close();
	}
	else {
		std::cout << "Error. Input file couldn't be opened" << std::endl;
	}

	return input;
}

