#include "GameScene.h"

GameScene::GameScene(RenderWindow* _window, SceneManager* _sm, SoundManager* MySound, Options* _options)
{
	srand(time(NULL));
	lvls[0] = FirstLevel;
	lvls[1] = SecondLevel;
	lvls[2] = ThirdLevel;
	sm = _sm;
	bricks = nullptr;
	hud = new HUD;
	MySoundManager = MySound;
	window = _window;
	options = _options;
	int health = 3;
	BrickAmount = 0;
	BallVelocity = 0;
}

GameScene::~GameScene()
{
	delete ball;
	delete paddle;
	delete[] bricks;
	delete hud;

	delete MySoundManager;
	delete window;
}

bool GameScene::Collision(Ball* ball, Paddle* paddle)
{
	double hitzone = paddleWidth / 3;
	double normalizer = 0.045;
	if (isColliding(*paddle, *ball))
	{
		double magnitude = abs(paddle->x() - ball->x());
		ball->velocity.y = -BallVelocity;
		if (paddle->left() + hitzone >= ball->x())
		{
			BallVelocity = options->GetCurrentSpeed() + magnitude * normalizer;
			ball->velocity.x = BallVelocity;

		}
		else if (paddle->right() - hitzone <= ball->x())
		{
			BallVelocity = options->GetCurrentSpeed() + magnitude * normalizer;
			ball->velocity.x = -BallVelocity;
		}
		else
		{
			ball->BallVelocity = options->GetCurrentSpeed();
		}
		return true;
	}
	return false;
}

bool GameScene::Collision(Ball* ball, Brick& brick)
{
	if (isColliding(*ball, brick))
	{
		brick.isdestroyed = true;


		float CollisionFromLeft = ball->right() - brick.left();
		float CollisionFromRight = ball->left() - brick.right();
		float CollisionFromTop = ball->bottom() - brick.top();
		float CollisionFromBot = ball->top() - brick.bottom();

		bool BallFromLeft(abs(CollisionFromLeft) < abs(CollisionFromRight));
		bool BallFromTop(abs(CollisionFromTop) < abs(CollisionFromBot));

		float CollisionAxisX(BallFromLeft ? CollisionFromLeft : CollisionFromRight);
		float CollisionAxisY(BallFromTop ? CollisionFromTop : CollisionFromBot);


		if (abs(CollisionAxisX) < abs(CollisionAxisY))
		{
			ball->velocity.x = BallFromLeft ? -BallVelocity : BallVelocity;
		}
		else
		{
			ball->velocity.y = BallFromTop ? -BallVelocity : BallVelocity;
		}

		return true;
	}
	return false;
}

Brick* GameScene::DeleteBrick(Brick* bricks, int& BrickAmount)
{
	Brick* temp = new Brick[BrickAmount - 1];
	for (int i = 0, j = 0; i < BrickAmount; i++)
	{
		if (!bricks[i].isdestroyed)
		{
			temp[j] = bricks[i];
			j++;
		}
	}
	BrickAmount--;
	delete[] bricks;
	return temp;
}


