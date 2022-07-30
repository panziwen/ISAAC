#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "gamelib.h"
#include "Attack.h"
#include "Enemy.h"

namespace game_framework {
	Enemy::Enemy()
	{
		Initialize();
	}
	Enemy::~Enemy()
	{
	}
	void Enemy::Initialize()
	{
		srand((unsigned)time(NULL));
		const int pos_x = 960;
		const int pos_y = 544;
		ex = 50 + rand() % pos_x - 50;
		ey = 50 + rand() % pos_y - 50;
		enemySpeed = 3;
		enemySpeed2 = 2.12;
		enemySpeed3 = 1;
	}
	void Enemy::LoadBitmap()
	{
		char* filename[2] = { ".\\bitmaps\\enemy\\1.bmp" ,".\\bitmaps\\enemy\\2.bmp" };
		for (int i = 0; i < 2; i++)
		{
			e.AddBitmap(filename[i], RGB(109, 33, 115));
		}
	}
	void Enemy::OnMove()
	{
		standbyArea = 1 + rand() % 5;
		e.OnMove();
		Navigation();
	}
	void Enemy::OnShow()
	{
		e.SetDelayCount(3);
		e.SetTopLeft(ex - e.Width() / 2, ey - e.Height() / 2);
		e.OnShow();
	}
	void Enemy::SetXY(int x, int y)
	{
		aim_x = x;
		aim_y = y;
	}
	void Enemy::Navigation()
	{
		if (abs(ex - aim_x) <= 50 || abs(ey - aim_y) <= 50)
		{
			if (ex < aim_x&&ey == aim_y)
			{
				for (int i = 0; i < enemySpeed; i++)
				{
					ex += 1;
				}
			}
			if (ex > aim_x&&ey == aim_y)
			{
				for (int i = 0; i < enemySpeed; i++)
				{
					ex -= 1;
				}
			}
			if (ey < aim_y&&ex == aim_x)
			{
				for (int i = 0; i < enemySpeed; i++)
				{
					ey += 1;
				}
			}
			if (ey > aim_y&&ex == aim_x)
			{
				for (int i = 0; i < enemySpeed; i++)
				{
					ey -= 1;
				}
			}
			if (ex < aim_x&&ey < aim_y)
			{
				for (int i = 0; i < enemySpeed2; i++)
				{
					ex += 1;
					ey += 1;
				}
			}
			if (ex > aim_x&&ey < aim_y)
			{
				for (int i = 0; i < enemySpeed2; i++)
				{
					ex -= 1;
					ey += 1;
				}
			}
			if (ex < aim_x&&ey > aim_y)
			{
				for (int i = 0; i < enemySpeed2; i++)
				{
					ex += 1;
					ey -= 1;
				}
			}
			if (ex > aim_x&&ey > aim_y)
			{
				for (int i = 0; i < enemySpeed2; i++)
				{
					ex -= 1;
					ey -= 1;
				}
			}
		}
		else
		{
			for (int i = 0; i < enemySpeed3; i++)
			{
				if (standbyArea == 1)
				{
					ex += 2;
				}
				if (standbyArea == 2)
				{
					ex -= 2;
				}
				if (standbyArea == 3)
				{
					ey += 2;
				}
				if (standbyArea == 4)
				{
					ey -= 2;
				}
			}
		}
	}
}