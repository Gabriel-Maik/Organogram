#pragma once

#include <string>
#include <fstream>
#include <exception>
#include <conio.h>
#include "Tree.h"

class Database
{
public:
	Database(std::string _fileName);
	Database(const Database& toCopy) = delete;
	Database operator= (const Database& toCopy) = delete;
	~Database();
	void display(); //display hierarchical structure
private:
	void loadFromFile();
	void makeTree(); //create hierarchical structure as tree
	std::string fileName;
	int numOfLines;
	int** numData;
	std::string** textData;
	Tree* hierarchy;
};

