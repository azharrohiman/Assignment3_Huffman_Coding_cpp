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

using namespace std;

namespace RHMMUH005 {
	class HuffmanTree {

	public: // public members
		shared_ptr<HuffmanNode> root;

		//HuffmanTree();	// default constructor
		~HuffmanTree();	// destructor

		// build the Huffman tree
		void buildTree(unordered_map<char, int>& Map);
		void buildCodeTable(const HuffmanNode& A, string prefix, unordered_map<char, string>& map);

	};
}

#endif
