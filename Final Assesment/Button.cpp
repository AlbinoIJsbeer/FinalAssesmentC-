#include "Button.h"

Button::Button()
{
	mousePressed = false;
}

Button::Button(sf::Vector2f size, sf::Vector2f position, sf::Color color)
{
	bSize = size;
	bPosition = position;
	bColor = color;
	sf::RectangleShape bRectangle;
}

Button::~Button()
{

}

void Button::CreateButton()
{
	bRectangle.setSize(bSize);
	bRectangle.setPosition(bPosition);
	bRectangle.setFillColor(bColor);
	
}

void Button::DrawButton(sf::RenderWindow& window)
{
	window.draw(bRectangle);
}


bool Button::checkClick(sf::RenderWindow & window)
{
	mousePos = sf::Mouse::getPosition(window);
	mousePressed = false;
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if(mousePressed)
		{
			return false;
		} else if(!mousePressed)
		{
			if(mousePos.x > getPosition().x && mousePos.x < getPosition().x + getSize().x
			   && mousePos.y > getPosition().y && mousePos.y < getPosition().y + getSize().y)
			{
				return true;
			} else
			{
				return false;
			}
		}
	}
}

sf::RectangleShape Button::getShape() const
{
	return bRectangle;
}

void Button::setSize(sf::Vector2f _size)
{
	bRectangle.setSize(_size);
}

void Button::setPos(sf::Vector2f _position)
{
	bRectangle.setPosition(_position);
}

void Button::setColor(sf::Color _color)
{
	bRectangle.setFillColor(_color);
}

sf::Vector2f Button::getSize() const
{
	return bRectangle.getSize();
}

sf::Vector2f Button::getPos() const
{
	return bRectangle.getPosition();
}

sf::Color Button::getColor() const
{
	return bRectangle.getFillColor();
}