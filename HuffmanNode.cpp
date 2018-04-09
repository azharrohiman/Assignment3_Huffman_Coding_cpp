// VolImage.cpp - implementation file for database() functions

#include "HuffmanNode.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
// for testing
#include <vector>
#include <memory>

using namespace RHMMUH005;
using namespace std;

namespace RHMMUH005 {

	// default constructor
	HuffmanNode::HuffmanNode() {
		HuffmanNode::character = '\0';
		HuffmanNode::charFrequency = 0;
	}

	HuffmanNode::HuffmanNode(char c, int f) {
		HuffmanNode::character = c;
		HuffmanNode::charFrequency = f;
	}

	// destructor
	HuffmanNode::~HuffmanNode() {
		HuffmanNode::right = nullptr;
		HuffmanNode::left = nullptr;
	}

	// copy constructor
	HuffmanNode::HuffmanNode(const HuffmanNode& otherNode) {
		HuffmanNode::character = otherNode.getCharacter();
		HuffmanNode::charFrequency = otherNode.getCharFrequency();
		HuffmanNode::left = otherNode.left;
		HuffmanNode::right = otherNode.right;
	}

	// move constructor
	HuffmanCode::HuffmanCode(HuffmanCode&& otherNode) {
		HuffmanCode::character = otherNode.getCharacter();
		HuffmanNode::charFrequency = otherNode.getCharFrequency();
		HuffmanNode::left = otherNode.left;
		HuffmanNode::right = otherNode.right;
		otherNode.left = nullptr;
		otherNode.right = nullptr
		otherNode.charFrequency = 0;
	}

	// assignment operator
	HuffmanNode& HuffmanNode::operator=(const HuffmanNode& otherNode) {
		if (this == &otherNode) {
			return *this;
		}

		HuffmanNode::character = otherNode.getCharacter();
		HuffmanNode::charFrequency = otherNode.getCharFrequency();
		HuffmanNode::left = otherNode.left;
		HuffmanNode::right = otherNode.right;
	}

	// move assignment operator
	HuffmanNode& HuffmanNode::operator=(HuffmanNode&& otherNode) {
		if (this == &N) {
			return *this;
		}

		HuffmanNode::character = otherNode.getCharacter();
		HuffmanNode::charFrequency = otherNode.getCharFrequency();
		HuffmanNode::left = otherNode.left;
		HuffmanNode::right = otherNode.right;

		otherNode.right = nullptr;
		otherNode.left  = nullptr;
		otherNode.charFrequency = 0;

		return *this;
	}

	// less than operator
	bool HuffmanCode::operator<(const HuffmanNode& otherNode) const {
		return (otherNode.getCharFrequency() < HuffmanCode::charFrequency);
	}

	char HuffmanNode::getCharacter() const {
		return HuffmanCode::character;
	}

	void HuffmanNode::setCharFrequency() {
		HuffmanNode::charFrequency = (HuffmanNode::*left).getCharFrequency() + (HuffmanNode::*right).getCharFrequency();
	}

	int HuffmanNode::getCharFrequency() const {
		return HuffmanNode::charFrequency;
	}
};

/*
int main(int argc, char* argv[]) {

	VolImage volObj;

	if (argc == 2) {
		if (volObj.VolImage::readImages(argv[1])) {
			int numberOfImages;
			vector<string> tokens;
			string word;
			string fileName = (string)argv[1] + "/MRI.data";
			ifstream file(fileName);

			if (!file) {
				return false;
			}

			while (getline(file, word, ' ')) {
				tokens.push_back(word);
			}

			numberOfImages = atoi(tokens.back().c_str());
			cout << "Number of images: " << numberOfImages << endl;
			cout << "Number of bytes required: " << volObj.VolImage::volImageSize() << endl;
		}
		return 0;
	}

	string baseName = argv[1];

	if (!volObj.VolImage::readImages(baseName)) {
		cout << "Couldn't open file" << endl;
	}
	else {
		cout << "Reading images..." << endl;
	}

	if (argc == 5) {
		int sliceID = atoi(argv[3]);
		mkdir("output", ACCESSPERMS);
		cout << "Extracting Slice " << argv[3] << endl;
		volObj.VolImage::extract(sliceID, argv[4]);
	}

	if (argc == 6) {
		int sliceI = atoi(argv[3]);
		int sliceJ = atoi(argv[4]);
		cout << "Computing difference map between " << argv[3] << " and " << argv[4] << endl;
		volObj.VolImage::diffmap(sliceI, sliceJ, argv[5]);
	}

	return 0;
}
*/
