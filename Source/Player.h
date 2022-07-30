#pragma once
#include "Attack.h"
namespace game_framework {
	class Player
	{
	public:
		Player();
		~Player();
		void Initialize();
		int GetX1();					//����ͼƬ�����Ͻ�X����
		int GetX2();					//����ͼƬ�����Ͻ�X����
		int GetY1();					//����ͼƬ�����Ͻ�Y����
		int GetY2();					//����ͼƬ�����½�Y����
		void LoadBitmap();				//����ͼƬ
		void OnMove();					//����
		void OnShow();					//��ӡ����Ļ��
		void SetMovingDonw(bool flag);	//���ռ��̴���Ŀ�������
		void SetMovingUp(bool flag);	//��������
		void SetMovingLeft(bool flag);
		void SetMovingRight(bool flag);
		void SetAttack(bool flag);
		bool GetAttack();
	private:
		CAnimation playOrigin, playWalkDonw, playWalkUp, playWalkLeft, playWalkRight;
		bool is_D, is_U, is_R, is_L, is_A;	//��ȡ�ƶ�״̬���ж�ֵ
		int x, y;				//x�������Ͻ�x���� x1����ͼƬ�����Ͻ�x���� y����ͼƬ�����Ͻ�y���� y1����ͼƬ�����½�y����
		bool is_FU, is_FR, is_FL, is_FD;		//�ӵ�����
		Attack a;

	};
}

