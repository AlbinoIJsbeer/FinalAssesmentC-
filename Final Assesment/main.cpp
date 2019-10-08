#include <iostream>
#include <SFML/Graphics.hpp>

int main() 
{	
	sf::RenderWindow window(sf::VideoMode(1024, 512), "Ponkerman!");

	sf::RectangleShape attack(sf::Vector2f(128.0f, 64.0f));
	attack.setFillColor(sf::Color::Red);
	attack.setPosition(0.0f, 448.0f);

	sf::RectangleShape heal(sf::Vector2f(128.0f, 64.0f));
	heal.setFillColor(sf::Color::Blue);
	heal.setPosition(attack.getPosition().x + attack.getSize().x, attack.getPosition().y);

	sf::Vector2i mousePos;
	bool Mousepressed = false;

	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}

		if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			
			mousePos = sf::Mouse::getPosition(window);
			if(Mousepressed)
			{
				continue;
			}
			else if(!Mousepressed)
			{ 
				if(mousePos.x > attack.getPosition().x && mousePos.x < attack.getPosition().x + attack.getSize().x
				   && mousePos.y > attack.getPosition().y && mousePos.y < attack.getPosition().y + attack.getSize().y)
				{
					std::cout << "You attacked!\n";
				} else if(mousePos.x > heal.getPosition().x && mousePos.x < heal.getPosition().x + heal.getSize().x
						  && mousePos.y > heal.getPosition().y && mousePos.y < heal.getPosition().y + heal.getSize().y)
				{
					std::cout << "You healed!\n";
				}
				Mousepressed = true;
			}
			continue;
		}

		Mousepressed = false;
		window.clear();
		window.draw(attack);
		window.draw(heal);
		window.display();
	}

	return 0;
	
}