#pragma once
namespace game_framework {
	class Attack
	{
	public:
		Attack();
		~Attack();
		void Initialize();		//初始化函数
		void LoadBitmap();		//图片加载
		void OnMove();		//动画、图片加载
		void OnShow();		//动画播放
		void SetAttack(bool flag);		//设置子弹是否处于攻击状态
		void SetAttackDirection(bool flag, bool flag2, bool flag3, bool flag4);		//设置子弹朝向
		bool GetAttack();		//获取是否处于攻击状态
		void SetX(int x);		//设置子弹位置，下同
		void SetY(int y);
	private:
		int bulletSpeed;		//子弹速度
		int bulletCount;		//子弹数量、暂时可能用不到后面会用到
		int px, py;		//子弹初始位置(因为从人物位置获取所以用px(player))
		int dis_x, dis_x2, dis_y, dis_y2;		//子弹飞行距离
		bool is_A, is_Show;			//是否处于子弹发射状态，以及子弹是否处于结尾动画播放
		bool is_FU, is_FR, is_FL, is_FD;		//子弹朝向
		CMovingBitmap bullet;		//子弹初始状态
		CAnimation bulletShow;		//子弹结束动画
		void attackDirection();		//控制子弹发射方向
	};
}
