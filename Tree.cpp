#include "Tree.h"

#include <iostream>

Tree::Tree(int** numData, std::string** textData, int _size)
{
	size = _size;

	//make tree root parent of each TreeNode without parent from file
	std::vector<int> withoutParent;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j) continue;
			else if (numData[i][1] == numData[j][0]) break;
			else if (j == size - 1) withoutParent.push_back(i);
		}
	}
	tree = new TreeNode* [size];
	for (int i = 0; i < size; i++)
	{
		tree[i] = new TreeNode(numData[i], textData[i]);
	}
	for (int i = 0; i < (int)withoutParent.size(); i++)
	{
		root.addChild(tree[withoutParent.at(i)]);
	}
	
	//find parents of the remaining nodes
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j) continue;
			else if (numData[i][1] == numData[j][0])
			{
				tree[j]->addChild(tree[i]);
				break;
			}
		}
	}
}

Tree::~Tree()
{
	for (int i = 0; i < size; i++)
	{
		delete tree[i];
	}
	delete[] tree;
}

//display entire tree
void Tree::display()
{
	root.displayTree();
}
