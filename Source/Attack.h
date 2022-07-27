#pragma once
namespace game_framework {
	class Attack
	{
	public:
		Attack();
		~Attack();
		void Initialize();		//��ʼ������
		void LoadBitmap();		//ͼƬ����
		void OnMove();		//������ͼƬ����
		void OnShow();		//��������
		void SetAttack(bool flag);		//�����ӵ��Ƿ��ڹ���״̬
		void SetAttackDirection(bool flag, bool flag2, bool flag3, bool flag4);		//�����ӵ�����
		bool GetAttack();		//��ȡ�Ƿ��ڹ���״̬
		void SetX(int x);		//�����ӵ�λ�ã���ͬ
		void SetY(int y);
	private:
		int bulletSpeed;		//�ӵ��ٶ�
		int bulletCount;		//�ӵ���������ʱ�����ò���������õ�
		int px, py;		//�ӵ���ʼλ��(��Ϊ������λ�û�ȡ������px(player))
		int dis_x, dis_x2, dis_y, dis_y2;		//�ӵ����о���
		bool is_A, is_Show;			//�Ƿ����ӵ�����״̬���Լ��ӵ��Ƿ��ڽ�β��������
		bool is_FU, is_FR, is_FL, is_FD;		//�ӵ�����
		CMovingBitmap bullet;		//�ӵ���ʼ״̬
		CAnimation bulletShow;		//�ӵ���������
		void attackDirection();		//�����ӵ����䷽��
	};
}
