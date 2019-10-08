#include <iostream>

int main() 
{	
	char name[15];
	std::cout << "Type your name please: \n";
	std::cin >> name;
	std::cout << "Hello " << name << "\n";
	return 0;
}