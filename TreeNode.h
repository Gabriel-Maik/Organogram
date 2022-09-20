#define textDataSize 8
#define numDataSize 2
#pragma once

#include <iostream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class TreeNode
{
public:
	TreeNode();
	TreeNode(int* _numData, std::string* _textData);
	TreeNode(const TreeNode& toCopy) = delete;
	TreeNode operator= (const TreeNode& toCopy) = delete;
	~TreeNode();
	void displayTree(std::string& beginning = std::string("")); //display tree assuming that this TreeNode is root
	void displayLine(std::string& beginning = std::string("")); //display information about this TreeNode
	friend bool compChildren(TreeNode* i, TreeNode* j); //compare by ID
	void addChild(TreeNode* newChild);
	int getID();
private:
	int nodeNumData[numDataSize];
	std::string nodeTextData[textDataSize];
	std::vector<TreeNode*> children;
};

