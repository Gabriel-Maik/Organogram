#pragma once

#include <string>
#include <vector>
#include "TreeNode.h"

class Tree
{
public:
	Tree(int** numData, std::string** textData, int size);
	Tree(const Tree& toCopy) = delete;
	Tree operator= (const Tree& toCopy) = delete;
	~Tree();
	void display(); //display entire tree
private:
	int size;
	TreeNode root;
	TreeNode** tree = nullptr;
};

