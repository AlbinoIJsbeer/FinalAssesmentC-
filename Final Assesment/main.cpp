#include <iostream>
#include <SFML/Graphics.hpp>
#include "Button.h"

int main() 
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Ponkerman!", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);

	
	Button AttackButton(sf::Vector2f(128, 64), sf::Vector2f(0, window.getSize().y - 64), sf::Color::Red);
	Button HealButton(sf::Vector2f(128, 64), sf::Vector2f(AttackButton.getPosition().x + 128, window.getSize().y - 64), sf::Color::Blue);


	sf::Vector2i mousePos;
	bool Mousepressed = false;
	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
				
			switch(event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::MouseButtonPressed:
					if(AttackButton.checkClick(window))
					{
						if(rand() % 100 < 85)
						{
							std::cout << "Attacked!\n";
						} else
						{
							std::cout << "Missed the attack!\n";
						}
						
					} else if(HealButton.checkClick(window))
					{
						if(rand() % 100 < 40)
						{
							std::cout << "Healed!\n";
						} else
						{
							std::cout << "Failed to heal!\n";
						}
					}
					break;
			}
			
		}
		
		

		
		window.clear();
		AttackButton.DrawButton(window);
		HealButton.DrawButton(window);
		window.display();
	}

	return 0;
	
}