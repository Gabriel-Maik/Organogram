#include <iostream>
#include "Database.h"

int main(int argc, char* argv[])
{
	try
	{
		//load database
		Database organization("companies_data.csv");
		
		//display hierarchical structure
		organization.display();
	}
	catch (std::exception exc)
	{
		std::cout << exc.what();
	}
	return 0;
}
