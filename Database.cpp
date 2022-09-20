#include "Database.h"

Database::Database(std::string _fileName)
{
	fileName = _fileName;
	loadFromFile();
	makeTree();
}

Database::~Database()
{
	for (int i = 0; i < numOfLines; i++)
	{
		delete[] numData[i];
		delete[] textData[i];
	}
	delete[] numData;
	delete[] textData;
	delete hierarchy;
	
}

//display hierarchical structure and wait for user
void Database::display() 
{
	if (hierarchy != nullptr) hierarchy->display();
	std::cout << std::endl << "Press any key to continue...";
	(void)_getch();
}

void Database::loadFromFile()
{
	std::ifstream file;
	file.open(fileName, std::ifstream::in);
	if (!file.good()) throw std::exception("Error occured during opening file");
	while (file.good())
	{
		std::string line;
		getline(file, line);
		numOfLines++;
	}
	numData = new int* [numOfLines];
	textData = new std::string* [numOfLines];
	for (int i = 0; i < numOfLines; i++)
	{
		numData[i] = new int[numDataSize];
		textData[i] = new std::string[textDataSize];
	}
	file.seekg(0, std::ifstream::beg);
	file.clear();
	for (int i = 0; i < numOfLines; i++)
	{
		std::string line;
		for (int j = 0; j < numDataSize; j++)
		{
			getline(file, line, ',');
			numData[i][j] = stoi(line);
		}
		for (int j = 0; j < textDataSize - 1; j++)
		{
			getline(file, line, ',');
			textData[i][j] = line;
		}
		getline(file, line);
		textData[i][textDataSize - 1] = line;
	}
	file.close(); 
}

//create hierarchical structure as tree
void Database::makeTree()
{
	hierarchy = new Tree(numData, textData, numOfLines);
}
