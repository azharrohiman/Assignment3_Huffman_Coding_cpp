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
		character = '\0';
		charFrequency = 0;
	}

	// constructor
	HuffmanNode::HuffmanNode(char c, int f) {
		character = c;
		charFrequency = f;
	}

	// destructor
	HuffmanNode::~HuffmanNode() {
		right = nullptr;
		left = nullptr;
	}

	// copy constructor
	HuffmanNode::HuffmanNode(const HuffmanNode& otherNode) {
		character = otherNode.getCharacter();
		charFrequency = otherNode.getCharFrequency();
		left = otherNode.left;
		right = otherNode.right;
	}

	// move constructor
	HuffmanNode::HuffmanNode(HuffmanNode&& otherNode) {
		character = otherNode.getCharacter();
		charFrequency = otherNode.getCharFrequency();
		left = otherNode.left;
		right = otherNode.right;
		otherNode.left = nullptr;
		otherNode.right = nullptr;
		otherNode.charFrequency = 0;
	}

	// assignment operator
	HuffmanNode& HuffmanNode::operator=(const HuffmanNode& otherNode) {
		if (this == &otherNode) {
			return *this;
		}

		character = otherNode.getCharacter();
		charFrequency = otherNode.getCharFrequency();
		left = otherNode.left;
		right = otherNode.right;
	}

	// move assignment operator
	HuffmanNode& HuffmanNode::operator=(HuffmanNode&& otherNode) {
		if (this == &otherNode) {
			return *this;
		}

		character = otherNode.getCharacter();
		charFrequency = otherNode.getCharFrequency();
		left = otherNode.left;
		right = otherNode.right;

		otherNode.right = nullptr;
		otherNode.left  = nullptr;
		otherNode.charFrequency = 0;

		return *this;
	}

	// less than operator
	bool HuffmanNode::operator<(const HuffmanNode& otherNode) const {
		return (otherNode.getCharFrequency() < HuffmanNode::charFrequency);
	}

	char HuffmanNode::getCharacter() const {
		return character;
	}

	void HuffmanNode::setCharFrequency() {
		charFrequency = (*left).getCharFrequency() + (*right).getCharFrequency();
	}

	int HuffmanNode::getCharFrequency() const {
		return charFrequency;
	}
};


