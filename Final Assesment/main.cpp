#include <iostream>

int main() 
{	
	char name[15];
	char username[30];
	std::cout << "Type your name please: \n";
	std::cin >> name;
	std::cout << "Type your username please: \n";
	std::cin >> username;
	std::cout << "Hello " << name << ", AKA: " << username << "\n";
	return 0;
}