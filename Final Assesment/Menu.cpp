#include <iostream>

#include "Menu.h"

Menu::Menu(float width, float height)
{
	if(!font.loadFromFile("arial.tff"))
	{
		std::cout << "Could not load Font file!" << std::endl;
		//error
	}

	text[0].setFont(font);
	text[0].setFillColor(sf::Color::Red);
	text[0].setString("Play");
	text[0].setPosition(sf::Vector2f(width / 2, height/ (MAX_NUMBER_OF_ITEMS + 1)));

	text[1].setFont(font);
	text[1].setFillColor(sf::Color::Red);
	text[1].setString("Exit");
	text[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1)));
}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
	for(int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(text[i]);
	}
}