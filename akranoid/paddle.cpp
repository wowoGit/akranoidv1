#include "paddle.h"

Paddle::Paddle(float x, float y)
{
	shape.setPosition(x, y);
	shape.setSize({ paddleWidth,paddleHeight });
	shape.setOrigin({ paddleWidth / 2.f,paddleHeight / 2.f });
	shape.setFillColor(Color::Blue);
	padtexture.loadFromFile("paddle.png");
	shape.setTexture(&padtexture);
}

void Paddle::update()
{
	shape.move(velocity);
	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && left() > 0)
	{
		velocity.x = -paddleVelocity;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && right() < GameFieldWidth)
	{
		velocity.x = paddleVelocity;
	}
	else
	{
		velocity.x = 0;
	}
}

float Paddle::x()
{
	return shape.getPosition().x;
}

float Paddle::y()
{
	return shape.getPosition().y;
}

float Paddle::left()
{
	return x() - shape.getSize().x / 2.f;
}

float Paddle::right()
{
	return x() + shape.getSize().x / 2.f;
}

float Paddle::top()
{
	return y() - shape.getSize().y / 2.f;
}

float Paddle::bottom()
{
	return y() + shape.getSize().y / 2.f;
}
