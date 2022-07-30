#pragma once
#include "Attack.h"
namespace game_framework {
	class Player
	{
	public:
		Player();
		~Player();
		void Initialize();
		int GetX1();					//人物图片的左上角X坐标
		int GetX2();					//人物图片的右上角X坐标
		int GetY1();					//人物图片的左上角Y坐标
		int GetY2();					//人物图片的左下角Y坐标
		void LoadBitmap();				//加载图片
		void OnMove();					//播放
		void OnShow();					//打印到屏幕上
		void SetMovingDonw(bool flag);	//接收键盘传输的控制命令
		void SetMovingUp(bool flag);	//上下左右
		void SetMovingLeft(bool flag);
		void SetMovingRight(bool flag);
		void SetAttack(bool flag);
		bool GetAttack();
	private:
		CAnimation playOrigin, playWalkDonw, playWalkUp, playWalkLeft, playWalkRight;
		bool is_D, is_U, is_R, is_L, is_A;	//获取移动状态的判断值
		int x, y;				//x人物左上角x坐标 x1人物图片的右上角x坐标 y人物图片的左上角y坐标 y1人物图片的左下角y坐标
		bool is_FU, is_FR, is_FL, is_FD;		//子弹朝向
		Attack a;

	};
}

