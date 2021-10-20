#pragma once
namespace game_framework
{
	class Player
	{
	public:
		void isPMovingDonw(bool flag);
		void isPMovingUp(bool flag);
		void isPMovingRight(bool flag);
		void isPMovingLeft(bool flag);

	private:
		bool isD, isU, isR, isL;
		CAnimation a;
	};
}
