#include "LevelGenerator.h"


	Brick* FirstLevel(Brick* bricks, int& BlockAmount)
	{
		const int rows = 4;
		const int cols = 14;
		BlockAmount = rows * cols;
		Brick* temp = new Brick[BlockAmount];
		int counter = 0;
		for (int y = 0; y < rows; y++)
		{
			for (int x = 0; x < cols; x++)
			{
				temp[counter].SetBrick((x + 2) * (brickWidth + 3) + 22, (y + 3) * (brickHeight + 3));
				counter++;
			}
		}
		delete[] bricks;
		return temp;
	}

	Brick* SecondLevel(Brick* bricks, int& BlockAmount)
	{
		const int rows = 7;
		const int cols = 14;
		BlockAmount = 56;
		Brick* temp = new Brick[BlockAmount];
		int counter = 0;
		for (int y = 0; y < rows; y++)
		{
			for (int x = 0; x < cols - y * 2; x++)
			{
				temp[counter].SetBrick((x + 3) * (brickWidth + 3) + 43 * y, (y + 3) * (brickHeight + 3));
				temp[counter].shape.setFillColor(Color::Green);
				counter++;
			}
		}
		delete[] bricks;
		return temp;
	}

	Brick* ThirdLevel(Brick* bricks, int& BlockAmount)
	{
		const int LevelSize = 47;
		const int gatesizex = 10;
		const int gatesizey = 10;
		BlockAmount = 36;
		Brick* temp = new Brick[BlockAmount];
		int counter = 0;

		for (int y = 0; y < gatesizey; y++)
		{

			if (y == 0 || y == gatesizey - 1)
			{
				for (int z = 0; z < gatesizex; z++)
				{
					temp[counter].SetBrick((z + 4) * (brickWidth + 3) + 22, (y + 2) * (brickHeight + 3));
					temp[counter].shape.setFillColor(Color::Magenta);
					counter++;

				}
			}
			else
			{
				for (int x = 0; x < gatesizex; x++)
				{
					if (x == y || x == gatesizex - y - 1)
					{
						temp[counter].SetBrick((x + 4) * (brickWidth + 3) + 22, (y + 2) * (brickHeight + 3));
						temp[counter].shape.setFillColor(Color::Yellow);
						counter++;
					}
				}

			}

		}
		delete[] bricks;
		return temp;
	}
