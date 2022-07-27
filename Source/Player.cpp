#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Player.h"
namespace game_framework {
	Player::Player()
	{
		is_D = is_L = is_R = is_U = false;
		x = y = 50;
	}
	Player::~Player()
	{
	}
	void Player::Initialize()
	{
	}
	int Player::GetX1()
	{
		return x;
	}
	int Player::GetY1()
	{
		return y;
	}
	int Player::GetX2()
	{
		return x1;
	}
	int Player::GetY2()
	{
		return y1;
	}
	void Player::LoadBitmap()
	{
		char * file0 = ".\\bitmaps\\isaac\\isorigin.bmp";

		char * file1[9] = {".\\bitmaps\\isaac\\isd0.bmp",".\\bitmaps\\isaac\\isd1.bmp",".\\bitmaps\\isaac\\isd2.bmp",
							".\\bitmaps\\isaac\\isd3.bmp",".\\bitmaps\\isaac\\isd4.bmp",".\\bitmaps\\isaac\\isd5.bmp",
							".\\bitmaps\\isaac\\isd6.bmp",".\\bitmaps\\isaac\\isd7.bmp",".\\bitmaps\\isaac\\isd8.bmp",};

		char * file2[10] = { ".\\bitmaps\\isaac\\isl1.bmp",".\\bitmaps\\isaac\\isl2.bmp",".\\bitmaps\\isaac\\isl3.bmp",
							".\\bitmaps\\isaac\\isl4.bmp",".\\bitmaps\\isaac\\isl5.bmp",".\\bitmaps\\isaac\\isl6.bmp",
							".\\bitmaps\\isaac\\isl7.bmp",".\\bitmaps\\isaac\\isl8.bmp",".\\bitmaps\\isaac\\isl9.bmp",
							".\\bitmaps\\isaac\\isl10.bmp",};

		char * file3[10] = { ".\\bitmaps\\isaac\\isr1.bmp",".\\bitmaps\\isaac\\isr2.bmp",".\\bitmaps\\isaac\\isr3.bmp",
							".\\bitmaps\\isaac\\isr4.bmp",".\\bitmaps\\isaac\\isr5.bmp",".\\bitmaps\\isaac\\isr6.bmp",
							".\\bitmaps\\isaac\\isr7.bmp",".\\bitmaps\\isaac\\isr8.bmp",".\\bitmaps\\isaac\\isr9.bmp",
							".\\bitmaps\\isaac\\isr10.bmp", };

		char * file4[9] = {".\\bitmaps\\isaac\\isu1.bmp",".\\bitmaps\\isaac\\isu2.bmp",".\\bitmaps\\isaac\\isu3.bmp",
							".\\bitmaps\\isaac\\isu4.bmp",".\\bitmaps\\isaac\\isu5.bmp",".\\bitmaps\\isaac\\isu6.bmp",
							".\\bitmaps\\isaac\\isu7.bmp",".\\bitmaps\\isaac\\isu8.bmp",".\\bitmaps\\isaac\\isu9.bmp",};

		a.LoadBitmap();

		playOrigin.AddBitmap(file0, RGB(109, 33, 115));

		for (int i = 0; i < 9; i++)
		{
			playWalkDonw.AddBitmap(file1[i], RGB(109, 33, 115));
		}
		for (int i = 0; i < 9; i++)
		{
			playWalkUp.AddBitmap(file4[i], RGB(109, 33, 115));
		}
		for (int i = 0; i < 10; i++)
		{
			playWalkRight.AddBitmap(file3[i], RGB(109, 33, 115));
		}
		for (int i = 0; i < 10; i++)
		{
			playWalkLeft.AddBitmap(file2[i], RGB(109, 33, 115));
		}
	}
	void Player::OnMove()
	{
		const int SPEED = 5;
		if (is_D && !is_U && !is_L && !is_R)
		{
			y += SPEED;
			is_FD = true;
			is_FU = is_FR = is_FL = false;
			playWalkDonw.SetDelayCount(2);
			playWalkDonw.OnMove();
		}
		if (!is_D && is_U && !is_L && !is_R)
		{
			y -= SPEED;
			is_FU = true;
			is_FD = is_FR = is_FL = false;
			playWalkUp.SetDelayCount(2);
			playWalkUp.OnMove();
		}
		if (!is_D && !is_U && !is_L && is_R)
		{
			x += SPEED;
			is_FR = true;
			is_FU = is_FD = is_FL = false;
			playWalkRight.SetDelayCount(2);
			playWalkRight.OnMove();
		}
		if (!is_D && !is_U && is_L && !is_R)
		{
			x -= SPEED;
			is_FL = true;
			is_FU = is_FR = is_FD = false;
			playWalkLeft.SetDelayCount(2);
			playWalkLeft.OnMove();
		}
		if (is_R&&is_U)
		{
			x += SPEED;
			y -= SPEED;
			is_FR = true;
			is_FU = is_FD = is_FL = false;
			playWalkRight.SetDelayCount(2);
			playWalkRight.OnMove();
		}
		if (is_R&&is_D)
		{
			x += SPEED;
			y += SPEED;
			is_FR = true;
			is_FU = is_FD = is_FL = false;
			playWalkRight.SetDelayCount(2);
			playWalkRight.OnMove();
		}
		if (is_L&&is_U)
		{
			x -= SPEED;
			y -= SPEED;
			is_FL = true;
			is_FU = is_FD = is_FR = false;
			playWalkLeft.SetDelayCount(2);
			playWalkLeft.OnMove();
		}
		if (is_L&&is_D)
		{
			x -= SPEED;
			y += SPEED;
			is_FL = true;
			is_FU = is_FD = is_FR = false;
			playWalkLeft.SetDelayCount(2);
			playWalkLeft.OnMove();
		}
		if (a.GetAttack())
		{
			a.OnMove();
			if (!a.GetAttack())
			{
				a.SetAttackDirection(is_FU, is_FD, is_FL, is_FR);
			}
		}
	}
	void Player::OnShow()
	{
		playOrigin.SetTopLeft(x, y);
		if (is_D && !is_U && !is_L && !is_R)
		{
			playWalkDonw.SetTopLeft(x,y);
			playWalkDonw.OnShow();
			playOrigin = playWalkDonw;
		}
		if (!is_D && is_U && !is_L && !is_R)
		{
			playWalkUp.SetTopLeft(x, y);
			playWalkUp.OnShow();
			playOrigin = playWalkUp;
		}
		if (!is_D && !is_U && !is_L && is_R)
		{
			playWalkRight.SetTopLeft(x, y);
			playWalkRight.OnShow();
			playOrigin = playWalkRight;
		}
		if (!is_D && !is_U && is_L && !is_R)
		{
			playWalkLeft.SetTopLeft(x, y);
			playWalkLeft.OnShow();
			playOrigin = playWalkLeft;
		}
		if (is_R&&is_U)
		{
			playWalkRight.SetTopLeft(x, y);
			playWalkRight.OnShow();
			playOrigin = playWalkRight;
		}
		if (is_R&&is_D)
		{
			playWalkRight.SetTopLeft(x, y);
			playWalkRight.OnShow();
			playOrigin = playWalkRight;
		}
		if (is_L&&is_U)
		{
			playWalkLeft.SetTopLeft(x, y);
			playWalkLeft.OnShow();
			playOrigin = playWalkLeft;
		}
		if (is_L&&is_D)
		{
			playWalkLeft.SetTopLeft(x, y);
			playWalkLeft.OnShow();
			playOrigin = playWalkLeft;
		}
		else if (!is_D && !is_U && !is_L && !is_R)
		{
			playOrigin.OnShow();
			playOrigin.Reset();
		}
		if (a.GetAttack())
		{
			a.OnShow();
		}
		playOrigin.OnShow();
		playOrigin.Reset();
	}
	void Player::SetMovingDonw(bool flag)
	{
		is_D=flag;
	}
	void Player::SetMovingUp(bool flag)
	{
		is_U = flag;
	}
	void Player::SetMovingLeft(bool flag)
	{
		is_L = flag;
	}
	void Player::SetMovingRight(bool flag)
	{
		is_R = flag;
	}
	void Player::SetAttack(bool flag)
	{
		is_A = flag;
		a.SetAttack(is_A);
		a.SetX((playOrigin.Width() / 2) + x - 37);
		a.SetY((playOrigin.Height() / 2) + y - 35);
	}
	bool Player::GetAttack()
	{
		return a.GetAttack();
	}
}