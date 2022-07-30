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
		int enemySpeed;			//�����ƶ��ٶ�
		double enemySpeed2;		//�����ƶ��ٶ�
		int enemySpeed3;		//�����ƶ��ٶ�
		int ex, ey;				//��������
		int aim_x, aim_y;		//����׷��Ŀ��
		int standbyArea;		//��������
		CAnimation e;
		void Navigation();		//Ѱ·�㷨
	};
}

