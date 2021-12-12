#include "Brick.h"

void Brick::SetBrick(float x, float y)
{
	shape.setPosition(x, y);
	shape.setSize({ brickWidth,brickHeight });
	shape.setOrigin(brickWidth / 2.f, brickHeight / 2.f);
	shape.setFillColor(Color::Red);
}

float Brick::x()
{
	return shape.getPosition().x;
}

float Brick::y()
{
	return shape.getPosition().y;
}

float Brick::left()
{
	return x() - shape.getSize().x / 2.f;
}

float Brick::right()
{
	return x() + shape.getSize().x / 2.f;
}

float Brick::top()
{
	return y() - shape.getSize().y / 2.f;
}

float Brick::bottom()
{
	return y() + shape.getSize().y / 2.f;
}
