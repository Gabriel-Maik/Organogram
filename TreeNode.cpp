#include "TreeNode.h"

//compare by ID
bool compChildren(TreeNode* i, TreeNode* j)
{
	return (i->getID() < j->getID());
}

TreeNode::TreeNode()
{
	for (int i = 0; i < numDataSize; i++)
	{
		nodeNumData[i] = 0;
	}
	for (int i = 0; i < textDataSize; i++)
	{
		nodeTextData[i] = "";
	}
}

TreeNode::TreeNode(int* _numData, std::string* _textData)
{
	for (int i = 0; i < numDataSize; i++)
	{
		nodeNumData[i] = _numData[i];
	}
	for (int i = 0; i < textDataSize; i++)
	{
		nodeTextData[i] = _textData[i];
	}
}

TreeNode::~TreeNode()
{
}

//display tree assuming that this TreeNode is root
void TreeNode::displayTree(std::string& beginning)
{
	std::string beginning2;
	if (beginning.size()==0)
	{
		beginning2 = " -> ";
	}
	else
	{
		beginning2 = "   " + beginning;
	}
	for (int i = 0; i < (int)children.size(); i++)
	{
		children.at(i)->displayLine(beginning);
		children.at(i)->displayTree(beginning2);
	}
}

//display information about this TreeNode
void TreeNode::displayLine(std::string& beginning)
{
	std::cout << beginning << nodeTextData[0] << " " << nodeTextData[1] << ", " << nodeTextData[2] << ", " << nodeTextData[4] << std::endl;
}

void TreeNode::addChild(TreeNode* newChild)
{
	children.push_back(newChild);
	std::sort(children.begin(), children.end(), compChildren);
}

int TreeNode::getID()
{
	return nodeNumData[0];
}