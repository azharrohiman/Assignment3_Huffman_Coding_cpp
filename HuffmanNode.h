// HuffmanNode.h - header file: this should be included in any source file that needs database() functions

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>

namespace RHMMUH005 {
	class HuffmanNode {

	private: // private members

		//HuffmanNode* zero; // 0 (left) subtree (NULL if empty)
		//HuffmanNode* one;  // 1 (right) subtree (NULL if empty)
		char character;
		int charFrequency;

	public: // public members

		std::shared_ptr<HuffmanNode> left, right; // left & right nodes

		HuffmanNode();	// default constructor
		HuffmanNode(char character, int frequency);

		~HuffmanNode();	// destructor

		// copy constructor
		HuffmanNode(const HuffmanNode& node);

		// move constructor
		HuffmanNode(HuffmanNode&& node);

		// less than operator
		bool operator<(const HuffmanNode& node) const;

		// assignment operator
		HuffmanNode& operator = (const HuffmanNode& node);

		// move assignment operator
		HuffmanNode& operator = (HuffmanNode&& node);

		char getCharacter() const;
		int getCharFrequency() const;
		void setCharFrequency();

	};
}

#endif
