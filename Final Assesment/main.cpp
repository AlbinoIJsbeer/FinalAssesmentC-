#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "Button.h"
#include "Menu.h"

int main() 
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Ponkerman!", sf::Style::Titlebar | sf::Style::Close);
	bool isPaused = false;
	window.setFramerateLimit(60);
	window.requestFocus();
	

	Menu menu(window.getSize().x, window.getSize().y);

	sf::Texture sTextures[2];
	sf::Sprite sSprites[2];
	bool issTexture1 = true;
	if(!sTextures[0].loadFromFile("digarette.png") || !sTextures[1].loadFromFile("tuirtle.png"))
	{
		return -1;
	}  if(sTextures[0].loadFromFile("digarette.png"))
	{
		std::cout << "Digarette Locked and Loaded! \n";
		sSprites[0].setTexture(sTextures[0]);
		sSprites[0].setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));
		sSprites[0].setOrigin(sf::Vector2f(sSprites[0].getTextureRect().width / 2, sSprites[0].getTextureRect().height / 2));

	} if(sTextures[1].loadFromFile("tuirtle.png"))
	{
		std::cout << "Tuirtle Locked and Loaded! \n";
		sSprites[1].setTexture(sTextures[1]);
		sSprites[1].setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));
		sSprites[1].setOrigin(sf::Vector2f(sSprites[1].getTextureRect().width / 2, sSprites[1].getTextureRect().height / 2));

	}
	
	Button AttackButton(sf::Vector2f(128, 64), sf::Vector2f(0, window.getSize().y - 64), sf::Color::Red);
	Button HealButton(sf::Vector2f(128, 64), sf::Vector2f(AttackButton.getPosition().x + 128, window.getSize().y - 64), sf::Color::Blue);	

	sf::Vector2i mousePos;


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
				case sf::Event::KeyPressed:
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					{
						window.close();
					}
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
					{
						issTexture1 = true;
					}
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::F2))
					{
						issTexture1 = false;
					}
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
				case sf::Event::LostFocus:
					isPaused = true;
					std::cout << "Game is Paused!\n";
					break;
				case sf::Event::GainedFocus:
					isPaused = false;
					std::cout << "Game has been Resumed!\n";
					break;
			}

			for(int i = 0; i < 2; i++)
			{
				sSprites[i].setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));
			}
			
		}

		
		if(!isPaused)
		{
			window.clear();

			//AttackButton.DrawButton(window);
			//HealButton.DrawButton(window);
			//if(issTexture1)
			//{
			//	window.draw(sSprites[0]);
			//} else if(!issTexture1)
			//{
			//	window.draw(sSprites[1]);
			//}
			menu.draw(window);
			window.display();
		}

	}

	return 0;
	
}