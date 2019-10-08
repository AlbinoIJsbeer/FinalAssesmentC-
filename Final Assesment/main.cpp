#include <iostream>
#include <SFML/Graphics.hpp>

int main() 
{	
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
	
	
	
	
	
	
	
	
	/*char name[15];
	char username[30];
	std::cout << "Type your name please: \n";
	std::cin >> name;
	std::cout << "Type your username please: \n";
	std::cin >> username;
	std::cout << "Hello " << name << ", AKA: " << username << "\n";
	return 0;*/
}