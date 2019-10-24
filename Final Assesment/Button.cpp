#include "Button.h"

Button::Button()
{
}

Button::Button(sf::Vector2f size, sf::Vector2f position, sf::Color color)
{

	bSize = size;
	bPosition = position;
	bColor = color;
	bRectangle.setSize(bSize);
	bRectangle.setPosition(bPosition);
	bRectangle.setFillColor(bColor);
	
}

Button::~Button()
{

}


void Button::DrawButton(sf::RenderWindow& window)
{
	window.draw(bRectangle);
}


bool Button::checkClick(sf::RenderWindow& window)
{
	mousePos = sf::Mouse::getPosition(window);
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if(mousePos.x > getPos().x && mousePos.y > getPos().y
			   && mousePos.x < getPos().x + getSize().x && mousePos.y < getPos().y + getSize().y)
			{
		    ///////////////////////////////////////////Debug Info////////////////////////////////////////
			///	/*std::cout << "Coords: " << getPosition().x << ", " << getPosition().y << std::endl;///
			///	std::cout << "Size: " << getSize().x << ", " << getSize().y << std::endl;			 ///
			///	std::cout << "Mouse Coords: " << mousePos.x << ", " << mousePos.y << std::endl;*/	 ///
			////////////////////////////////////////////////////////////////////////////////////////////
				return true;
			} else
			{
				return false;
			}

		} else
		{
			return false;
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