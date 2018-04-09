// database.h - header file: this should be included in any source file that needs database() functions

#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <queue>
#include <unordered_map>
#include "HuffmanNode.h"

namespace RHMMUH005 {
	class HuffmanTree {

	public: // public members
		shared_ptr<HuffmanNode> root;

		HuffmanTree();	// default constructor
		~HuffmanTree();	// destructor

		// methods to compress data

		// build the Huffman tree
		void buildTree(unordered_map<char, int>& Map);
		void code(const HuffmanNode& A, string prefix, unodered_map<char, string>& map);

	};
}

#endif
