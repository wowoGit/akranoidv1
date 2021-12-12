#include "Ball.h"

Ball::Ball(float x, float y, int BallVel)
{
	BallVelocity = BallVel;
	shape.setPosition(x, y);
	shape.setRadius(ballRad);
	shape.setFillColor(Color::Yellow);
	shape.setOrigin(ballRad / 2, ballRad / 2);

}

void Ball::update()
{
	shape.move(velocity);

}

void Ball::wallCollision(double ballVel)
{
	BallVelocity = ballVel;
	if (right() >= GameFieldWidth - BORDERSIZE) velocity.x = -BallVelocity;
	else if (left() <= 0 + BORDERSIZE)
	{
		velocity.x = BallVelocity;
	}
	else if (top() <= 0 + BORDERSIZE)
	{
		velocity.y = BallVelocity;
	}
}

bool Ball::isOut()
{
	if (bottom() >= GameFieldHeight - BORDERSIZE)
	{
		return true;
	}
	return false;
}

 void Ball::ResetPosition(Paddle* paddle)
{
	shape.setPosition(paddle->x(), paddle->top() - ballRad);
}

 float Ball::x()
{
	return  shape.getPosition().x; 
}

 float Ball::y()
{
	return  shape.getPosition().y;
}

 float Ball::top()
{
	return  shape.getPosition().y - shape.getRadius();
}

 float Ball::bottom()
{
	return  shape.getPosition().y + shape.getRadius();
}

 float Ball::left()
{
	return  shape.getPosition().x - shape.getRadius();
}

 float Ball::right()
{
	return  shape.getPosition().x + shape.getRadius();
}
