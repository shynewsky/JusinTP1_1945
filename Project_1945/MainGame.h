#pragma once
#include "Define.h"
#include "Player.h"

#include "EnemyA.h"
#include "EnemyB.h"
#include "EnemyC.h"
#include "EnemyD.h"
#include "EnemyE.h"
#include "EnemyStage.h"


#include "PowerItem.h"
#include "BombItem.h"
#include "LifeItem.h"
#include "InvincibleItem.h"

#include "AbstractFactory.h"
#include "CollisionMgr.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	bool			Get_Pause() { return m_bIsPause; }
	void			Set_Pause() { m_bIsPause = !m_bIsPause; }
	bool			Get_IsPlay() { return m_bIsPlay; }
	void			Set_IsPlay() { m_bIsPlay = !m_bIsPlay; }
	bool			Get_IsTitle() { return m_bIsTitle; }
	void			Start_Play() { m_bIsTitle = false; m_bIsPlay = true; }

public:
	void			Initialize();
	int				Update();
	void			Late_Update();
	void			Render();
	void			Release();

public:
	void			Stage();
	void			Generate_Item();
	void			Render_Title();
	void			Render_GameOver();
	void			Render_ScoreRecord();

	void			Load_Score();
	void			Save_Score();

	void			Jusin();
	void			FirstDrop();
	void			SecondDrop();
	void			ThirdDrop();
	void			ForthDrop();
	void			FifthDrop();

private:
	HDC				m_hDC;
	list<CObj*>		m_pObjList[OBJ_END];
	vector<int>		m_vecScore;

	int				m_iScore;
	int				m_iScoreArray[10];
	int				m_StageLevel;
	bool			m_bIsPlay;
	bool			m_bIsPause;
	bool			m_bIsTitle;
	bool			m_bJusin;
	// 테스트용 총알 리스트
	list<CObj*>		m_bulletList;
	// 총알 발사 간격 용 카운트
	size_t			m_checkTime;
	// 몇번째 함수인지(쥬신 출력할 때)
	int				m_checkWordCount;
	size_t			m_checkJusinTime;
};

