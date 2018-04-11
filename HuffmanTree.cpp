// database.h - header file: this should be included in any source file that needs database() functions

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <queue>
#include <unordered_map>
#include "HuffmanNode.h"
#include "HuffmanTree.h"
using namespace std;

typedef bool(*ptr)(const RHMMUH005::HuffmanNode&, const RHMMUH005::HuffmanNode&);

bool compare(const RHMMUH005::HuffmanNode& a, const RHMMUH005::HuffmanNode& b) {
	if (a < b) {
		return true;
 	}
	else {
		return false;
	}
}

RHMMUH005::HuffmanTree::~HuffmanTree() {
	root = nullptr;
}

void RHMMUH005::HuffmanTree::buildTree(unordered_map<char, int>& Map) {
	priority_queue<HuffmanNode, vector<HuffmanNode>, ptr> pq(compare);

	for (auto it = Map.begin(); it != Map.end(); ++it) {
		HuffmanNode node(it->first, it->second);
		pq.push(node);
	}

	while (pq.size() > 1) {
		HuffmanNode nodeSet;
		nodeSet.left = make_shared<HuffmanNode>(pq.top());
		pq.pop();
		nodeSet.right = make_shared<HuffmanNode>(pq.top());
		pq.pop();
		nodeSet.setCharFrequency();
		pq.push(nodeSet);
	}

	root = make_shared<HuffmanNode>(pq.top());
	pq.pop();
}

void RHMMUH005::HuffmanTree::buildCodeTable(const RHMMUH005::HuffmanNode& node, string prefix, unordered_map<char, string>& map) {
	if (node.getCharacter() != '\0') {
		map[node.getCharacter()] = prefix;
	}

	else {
		buildCodeTable(*(node.left), prefix+"0", map);
		buildCodeTable(*(node.right), prefix+"1", map);
	}
}


