#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#ifndef BUTTON_H
#define BUTTON_H

class Button : public sf::RectangleShape
{
public:
	//Default constructor
	Button();

	//Overload constructor
	Button(sf::Vector2f, sf::Vector2f, sf::Color);

	//Destructor
	~Button();

	//Accessor Functions
	sf::Vector2f getSize() const;
		// getSize - returns size of the button
	sf::Vector2f getPos() const;
		// getPos - returns position of the button
	sf::Color getColor() const;
		//getColor - return color of the button
	sf::RectangleShape getShape() const;
		//getShape - get the rectangleShape of the button
	//Mutator Functions
	void setSize(sf::Vector2f);
		//setSize - sets size of the button
	void setPos(sf::Vector2f);
		//setPos - sets position of the button
	void setColor(sf::Color);
		//setColor - sets color of the button

	void DrawButton(sf::RenderWindow&);
	bool checkClick(sf::RenderWindow&);

private:
	sf::Vector2f bSize;
	sf::Vector2f bPosition;
	sf::Color bColor;
	sf::RectangleShape bRectangle;
	sf::Vector2i mousePos;

	
};

#endif

