#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "mygame.h"

namespace game_framework {

	CGameStateInit::CGameStateInit(CGame *g)
	: CGameState(g)
	{
	}

	void CGameStateInit::OnInit()
	{
		ShowInitProgress(0);
		Sleep(300);	
	}

	void CGameStateInit::OnBeginState()
	{
	}

	void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_ESC = 27;
		const char KEY_SPACE = ' ';
		if (nChar == KEY_SPACE)
			GotoGameState(GAME_STATE_RUN);	
		else if (nChar == KEY_ESC)	
			PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE,0,0);	
	}

	void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
	{
		GotoGameState(GAME_STATE_RUN);
	}

	void CGameStateInit::OnShow()
	{
		CDC *pDC = CDDraw::GetBackCDC();
		CFont f,*fp;
		f.CreatePointFont(160,"Times New Roman");
		fp=pDC->SelectObject(&f);
		pDC->SetBkColor(RGB(0,0,0));
		pDC->SetTextColor(RGB(255,255,0));
		pDC->TextOut(5,485,"Please click mouse or press SPACE to begin.");
		pDC->TextOut(5,395,"Press Ctrl-F to switch in between window mode and full screen mode.");
		if (ENABLE_GAME_PAUSE)
			pDC->TextOut(5,425,"Press Ctrl-Q to pause the Game.");
		pDC->TextOut(5,455,"Press Alt-F4 or ESC to Quit.");
		pDC->SelectObject(fp);
		CDDraw::ReleaseBackCDC();
	}								

	CGameStateOver::CGameStateOver(CGame *g)
	: CGameState(g)
	{
	}

	void CGameStateOver::OnMove()
	{
		counter--;
		if (counter < 0)
			GotoGameState(GAME_STATE_INIT);
	}

	void CGameStateOver::OnBeginState()
	{
		counter = 30 * 5;
	}

	void CGameStateOver::OnInit()
	{
		ShowInitProgress(66);
		Sleep(300);
		ShowInitProgress(100);
	}

	void CGameStateOver::OnShow()
	{
		CDC *pDC = CDDraw::GetBackCDC();
		CFont f,*fp;
		f.CreatePointFont(160,"Times New Roman");
		fp=pDC->SelectObject(&f);
		pDC->SetBkColor(RGB(0,0,0));
		pDC->SetTextColor(RGB(255,255,0));
		char str[80];
		sprintf(str, "Game Over ! (%d)", counter / 30);
		pDC->TextOut(240,210,str);
		pDC->SelectObject(fp);
		CDDraw::ReleaseBackCDC();
	}


	CGameStateRun::CGameStateRun(CGame *g)
	: CGameState(g), NUMBALLS(28)
	{
	
	}

	CGameStateRun::~CGameStateRun()
	{
	
	}

	void CGameStateRun::OnBeginState()
	{	
		ISAAC.LoadBitmap();
	}

	void CGameStateRun::OnMove()
	{
		ISAAC.OnMove();
	}

	void CGameStateRun::OnInit()
	{
		ShowInitProgress(33);
		ShowInitProgress(50);
		Sleep(300);
	
	}

	void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x25;
		const char KEY_UP = 0x26;
		const char KEY_RIGHT = 0x27;
		const char KEY_DOWN = 0x28;
		const char KEY_SPACE = VK_SPACE;

		const char KEY_W = 'W';
		const char KEY_A = 'A';
		const char KEY_S = 'S';
		const char KEY_D = 'D';

		if (nChar == KEY_A)
		{
			ISAAC.SetMovingLeft(true);
		}
		if (nChar == KEY_D)
		{
			ISAAC.SetMovingRight(true);
		}
		if (nChar == KEY_W)
		{
			ISAAC.SetMovingUp(true);
		}
		if (nChar == KEY_S)
		{
			ISAAC.SetMovingDonw(true);
		}
		if (nChar== KEY_SPACE)
		{
			if (!ISAAC.GetAttack())
			{
				ISAAC.SetAttack(true);
			}
		}
	}

	void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT  = 0x25;
		const char KEY_UP    = 0x26;
		const char KEY_RIGHT = 0x27;
		const char KEY_DOWN  = 0x28;
		const char KEY_SPACE = VK_SPACE;

		const char KEY_W = 'W';
		const char KEY_A = 'A';
		const char KEY_S = 'S';
		const char KEY_D = 'D';
		if (nChar == KEY_A)
		{
			ISAAC.SetMovingLeft(false);
		}
		if (nChar == KEY_D)
		{
			ISAAC.SetMovingRight(false);
		}
		if (nChar == KEY_W)
		{
			ISAAC.SetMovingUp(false);
		}
		if (nChar == KEY_S)
		{
			ISAAC.SetMovingDonw(false);
		}
	}

	void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)
	{
	
	}

	void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)
	{
	}

	void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)
	{

	}

	void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)
	{
	}

	void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)
	{
	}

	void CGameStateRun::OnShow()
	{
		ISAAC.OnShow();
	}
}