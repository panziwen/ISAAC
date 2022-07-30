#pragma once
namespace game_framework{
	class Enemy
	{
	public:
		Enemy();
		~Enemy();
		void Initialize();
		void LoadBitmap();
		void OnMove();
		void OnShow();
		void SetXY(int x, int y);
	private:
		int enemySpeed;			//敌人移动速度
		double enemySpeed2;		//敌人移动速度
		int enemySpeed3;		//敌人移动速度
		int ex, ey;				//敌人坐标
		int aim_x, aim_y;		//敌人追击目标
		int standbyArea;		//待机区域
		CAnimation e;
		void Navigation();		//寻路算法
	};
}

