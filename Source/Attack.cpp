#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "gamelib.h"
#include "Attack.h"
namespace game_framework {
	Attack::Attack()
	{
		Initialize();
	}
	Attack::~Attack()
	{
	}
	void Attack::Initialize()
	{
		bulletCount = 1;
		bulletSpeed = 8;
		is_A = is_Show = false;
		is_FU = is_FR = is_FL = false;
		is_FD = true;
	}
	void Attack::LoadBitmap()
	{
		char* filename0 = ".\\Bitmaps\\attack\\a1.bmp";
		char* filename1[15] = { ".\\Bitmaps\\attack\\a1.bmp",".\\Bitmaps\\attack\\a2.bmp",".\\Bitmaps\\attack\\a3.bmp",
								".\\Bitmaps\\attack\\a4.bmp",".\\Bitmaps\\attack\\a5.bmp",".\\Bitmaps\\attack\\a6.bmp",
								".\\Bitmaps\\attack\\a7.bmp",".\\Bitmaps\\attack\\a8.bmp", ".\\Bitmaps\\attack\\a9.bmp",
								".\\Bitmaps\\attack\\a10.bmp",".\\Bitmaps\\attack\\a11.bmp",".\\Bitmaps\\attack\\a12.bmp",
								".\\Bitmaps\\attack\\a13.bmp",".\\Bitmaps\\attack\\a14.bmp",".\\Bitmaps\\attack\\a15.bmp" };
		bullet.LoadBitmap(filename0, RGB(109, 33, 115));
		for (int i = 0; i < 15; i++)
		{
			bulletShow.AddBitmap(filename1[i], RGB(109, 33, 115));
		}
	}
	void Attack::OnMove()
	{
		if (is_A)
		{
			attackDirection();
		}
	}
	void Attack::OnShow()
	{
		bulletShow.SetDelayCount(1);
		bulletShow.SetTopLeft(px, py);
		bulletShow.OnShow();
	}
	void Attack::SetAttack(bool flag)
	{
		is_A = flag;
	}
	void Attack::SetAttackDirection(bool flag, bool flag2, bool flag3, bool flag4)
	{
		is_FU = flag;
		is_FD = flag2;
		is_FL = flag3;
		is_FR = flag4;
	}
	bool Attack::GetAttack()
	{
		return is_A;
	}
	void Attack::SetX(int x)
	{
		px = x;
		dis_x = px + 200;
		dis_x2 = px - 200;
	}
	void Attack::SetY(int y)
	{
		py = y;
		dis_y = py + 200;
		dis_y2 = py - 200;
	}
	void Attack::attackDirection()
	{
		if (is_FU)
		{
			for (int i = 0; i < bulletSpeed; i++)
			{
				if (py <=dis_y2)
				{
					continue;
				}
				else
				{
					py -= 1;
					bullet.SetTopLeft(px, py);
					bullet.ShowBitmap();
				}
			}
			if (py<dis_y2 + 30 && py>dis_y2)
			{
				px += 2;
			}
			if (py <= dis_y2)
			{
				bulletShow.OnMove();
				if (bulletShow.IsFinalBitmap())
				{
					is_A = false;
				}
			}
		}
		else if (is_FD)
		{
			for (int i = 0; i < bulletSpeed; i++)
			{
				if (py>=dis_y)
				{
					continue;
				}
				else
				{
					py += 1;
					bullet.SetTopLeft(px, py);
					bullet.ShowBitmap();
				}
			}
			if (py>dis_y-30&&py<dis_y)
			{
				px -= 2;
			}
			if (py>=dis_y)
			{
				bulletShow.OnMove();
				if (bulletShow.IsFinalBitmap())
				{
					is_A = false;
				}
			}
		}
		else if (is_FL)
		{
			for (int i = 0; i < bulletSpeed; i++)
			{
				if (px<=dis_x2)
				{
					continue;
				}
				else
				{
					px -= 1;
					bullet.SetTopLeft(px, py);
					bullet.ShowBitmap();
				}
			}
			if (px<dis_x2+30&&px>dis_x2)
			{
				py += 2;
			}
			if (px<=dis_x2)
			{
				bulletShow.OnMove();
				if (bulletShow.IsFinalBitmap())
				{
					is_A = false;
				}
			}
		}
		else if (is_FR)
		{
			for (int i = 0; i < bulletSpeed; i++)
			{
				if (px>=dis_x)
				{
					continue;
				}
				else
				{
					px += 1;
					bullet.SetTopLeft(px, py);
					bullet.ShowBitmap();
				}
			}
			if (px>dis_x-30&&px<dis_x)
			{
				py += 2;
			}
			if (px>=dis_x)
			{
				bulletShow.OnMove();
				if (bulletShow.IsFinalBitmap())
				{
					is_A = false;
				}
			}
		}
	}
}