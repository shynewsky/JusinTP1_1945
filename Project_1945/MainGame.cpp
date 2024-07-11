#include "pch.h"
#include "MainGame.h"
#include "AbstractFactory.h"

CMainGame::CMainGame() : m_bIsPause(false), m_bIsPlay(true), m_hDC(nullptr), m_iScore(0), m_bIsTitle(true), m_StageLevel(1), m_checkTime(0), m_checkWordCount(0), 
						m_checkJusinTime(0), m_bJusin(false)
{
	m_vecScore.reserve(10);
	ZeroMemory(m_iScoreArray, sizeof(m_iScoreArray));
	srand(time(NULL));
}

CMainGame::~CMainGame()
{
	Release();
}

void		CMainGame::Initialize()
{
	m_bIsPause = false;
	m_hDC = GetDC(g_hWnd);

	CObj* pPlayer = CAbstractFactory<CPlayer>::CreateObj();
	static_cast<CPlayer*>(pPlayer)->Set_BulletList(&m_pObjList[OBJ_BULLET]);
	static_cast<CPlayer*>(pPlayer)->SetEnemyList(&m_pObjList[OBJ_ENEMY]);
	static_cast<CPlayer*>(pPlayer)->SetBossList(&m_pObjList[OBJ_BOSS]);
	m_pObjList[OBJ_PLAYER].push_back(pPlayer);
	Load_Score();

}

int			CMainGame::Update()
{
	if (!m_bIsTitle)
	{
		//점수 증가 및 제한
		if (m_iScore >= 999999)
		{
			m_iScore = 9999999;
		}

		for (size_t i = 0; i < OBJ_END; ++i)
		{
			for (auto iter = m_pObjList[i].begin();
				iter != m_pObjList[i].end(); )
			{
				int		iResult = (*iter)->Update();

				if (OBJ_DEAD == iResult)
				{
					if ((*iter)->Get_ObjId() == OBJ_PLAYER)
					{
						Save_Score();
						m_bIsPlay = false;
						CEnemyStage::Initialize();
					}

					if ((*iter)->Get_ObjId() == OBJ_ENEMY)
					{
						m_iScore += static_cast<CEnemy*>(*iter)->Get_Score();
						Generate_Item();
					}

					if ((*iter)->Get_ObjId() == OBJ_BOSS)
					{
						m_bJusin = true;
					}

					Safe_Delete<CObj*>(*iter);
					iter = m_pObjList[i].erase(iter);
				}
				else
				{
					++iter;
				}
			}

		}
	
		for (list<CObj*>::iterator iter = m_pObjList[OBJ_ENEMY].begin(); iter != m_pObjList[OBJ_ENEMY].end(); ++iter)
		{
			if(m_pObjList[OBJ_PLAYER].begin() != m_pObjList[OBJ_PLAYER].end())
			{
				(*iter)->SetTarget(m_pObjList[OBJ_PLAYER].back());
			}
		}

		Stage();

		if (m_bJusin && m_bIsPlay && m_pObjList[OBJ_BULLET].size() > 0)
		{
			m_pObjList[OBJ_ENEMY].clear();
			Jusin();
		}

		CCollisionMgr::Collision_Rect(m_pObjList[OBJ_ITEM], m_pObjList[OBJ_PLAYER]);

		CCollisionMgr::Collision_Rect(m_pObjList[OBJ_ENEMY], m_pObjList[OBJ_PLAYER]);
		CCollisionMgr::Collision_Rect(m_pObjList[OBJ_ENEMY], m_pObjList[OBJ_BULLET]);
		CCollisionMgr::Collision_Sphere(m_pObjList[OBJ_ENEMY], m_pObjList[OBJ_BULLET]);

		CCollisionMgr::Collision_Sphere(m_pObjList[OBJ_PLAYER], m_pObjList[OBJ_BULLET]);
		CCollisionMgr::Collision_Sphere(m_pObjList[OBJ_PLAYER], m_pObjList[OBJ_ENEMY]);

		CCollisionMgr::Collision_Rect(m_pObjList[OBJ_BOSS], m_pObjList[OBJ_PLAYER]);
		CCollisionMgr::Collision_Sphere(m_pObjList[OBJ_BOSS], m_pObjList[OBJ_BULLET]);
	}

	return m_bIsPlay;
}

void		CMainGame::Late_Update()
{
	if (!m_bIsTitle)
	{
		for (size_t i = 0; i < OBJ_END; ++i)
		{
			for (auto& iter : m_pObjList[i])
			{
				iter->Late_Update();
			}
		}
	}

	if (m_pObjList[OBJ_BULLET].size() <= 0 && m_bJusin == true )
		m_bIsPlay = false;
}

void		CMainGame::Render()
{
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);

	if (!m_bIsTitle)
	{
		for (size_t i = 0; i < OBJ_END; ++i)
		{
			for (auto& iter : m_pObjList[i])
				iter->Render(m_hDC);
		}

		// 점수 글귀 출력
		TCHAR sScore[32];
		wsprintf(sScore, L"SCORE : %d", m_iScore);
		TextOut(m_hDC, 5, 5, sScore, lstrlen(sScore));

		TCHAR	szBuff[32];
		wsprintfW(szBuff, L"Level : %d", ((unsigned int)m_StageLevel));
		SetWindowText(g_hWnd, szBuff);

		//게임 오버 글귀 출력
		if (!m_bIsPlay)
		{
			Render_GameOver();
		}
	}
	else
		Render_Title();
}

void		CMainGame::Release()
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for_each(m_pObjList[i].begin(), m_pObjList[i].end(), Safe_Delete<CObj*>);
		m_pObjList[i].clear();
	}

	ReleaseDC(g_hWnd, m_hDC);
}

void CMainGame::Stage()
{
	// 양새하 추가 --> 스테이지가 끝나면 다음 스테이지로 넘어가는 코드
	switch (m_StageLevel) {
	case 1:
		if (!CEnemyStage::Stage1(m_pObjList[OBJ_ENEMY], m_pObjList[OBJ_BULLET], m_pObjList[OBJ_PLAYER]))
		{
			m_StageLevel++;
			CEnemyStage::Set_Num(1);
		}
		break;
	case 2:
		if (!CEnemyStage::Stage2(m_pObjList[OBJ_ENEMY], m_pObjList[OBJ_BULLET], m_pObjList[OBJ_PLAYER]))
		{
			m_StageLevel++;
			CEnemyStage::Set_Num(1);
		}
		break;
	case 3:
		if (!CEnemyStage::Stage3(m_pObjList[OBJ_ENEMY], m_pObjList[OBJ_BULLET], m_pObjList[OBJ_PLAYER]))
		{
			m_StageLevel=4;
			CEnemyStage::Set_Num(1);
		}
		break;
	case 4:
		if (!CEnemyStage::Boss(m_pObjList[OBJ_BOSS], m_pObjList[OBJ_BULLET], m_pObjList[OBJ_PLAYER]))
		{
  			m_StageLevel++; 
  			CEnemyStage::Set_Num(1);
		}
	default: break;
	}
}

void      CMainGame::Generate_Item()
{
	auto& enemyList = m_pObjList[OBJ_ENEMY];

	for (auto iter = enemyList.begin(); iter != enemyList.end(); ++iter)
	{
		CObj* pEnemy = *iter;

		if (pEnemy->Get_IsDead())
		{
			// 아이템 생성 확률
			if (rand() % 10 > 4)
			{
				continue;
			}

			int randItemIndex = rand() % 100; // 아이템 종류 랜덤 결정 수정

			CObj* pItem = nullptr;

			if (randItemIndex < 50)
			{
				pItem = CAbstractFactory<CPowerItem>::CreateObj();
			}
			else if (randItemIndex < 70)
			{
				pItem = CAbstractFactory<CLifeItem>::CreateObj();
			}
			else if (randItemIndex < 90)
			{
				pItem = CAbstractFactory<CInvincibleItem>::CreateObj();
			}
			else
			{
				pItem = CAbstractFactory<CBombItem>::CreateObj();
			}

			pItem->Set_Pos(pEnemy->Get_Info().fX, pEnemy->Get_Info().fY);

			CObj* pPlayer = m_pObjList[OBJ_PLAYER].front();
			static_cast<CItem*>(pItem)->Set_Player(pPlayer);

			m_pObjList[OBJ_ITEM].push_back(pItem);
		}
	}
}


//타이틀 출력
void CMainGame::Render_Title()
{
	HFONT hFont = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, TEXT("Arial"));
	HFONT hOldFont = (HFONT)SelectObject(m_hDC, hFont);

	TCHAR sGameOver[32] = L"1945";
	RECT rcGameOver{ (LONG)(WINCX * 0.5 - 200),(LONG)(WINCY * 0.5 - 200),(LONG)(WINCX * 0.5 + 200) ,(LONG)(WINCY * 0.5) };
	DrawText(m_hDC, sGameOver, lstrlen(sGameOver), &rcGameOver, DT_CENTER);

	hFont = CreateFont(25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, TEXT("Arial"));
	SelectObject(m_hDC, hFont);

	TCHAR sRestart[32] = L"Press the 'Enter' Key to Start ";
	RECT rcRestart{ (LONG)(WINCX * 0.5 - 200),(LONG)(WINCY * 0.5 + 100),(LONG)(WINCX * 0.5 + 200) ,(LONG)(WINCY * 0.5 + 500) };
	DrawText(m_hDC, sRestart, lstrlen(sRestart), &rcRestart, DT_CENTER);

	Render_ScoreRecord();

	SelectObject(m_hDC, hOldFont);
	DeleteObject(hFont);
}

//게임 오버 출력
void CMainGame::Render_GameOver()
{
	HFONT hFont = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, TEXT("Arial"));
	HFONT hOldFont = (HFONT)SelectObject(m_hDC, hFont);

	TCHAR sGameOver[32] = L"GameOver";
	RECT rcGameOver{ (LONG)(WINCX * 0.5 - 200),(LONG)(WINCY * 0.5 - 200),(LONG)(WINCX * 0.5 + 200) ,(LONG)(WINCY * 0.5) };
	DrawText(m_hDC, sGameOver, lstrlen(sGameOver), &rcGameOver, DT_CENTER);

	hFont = CreateFont(25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, TEXT("Arial"));
	SelectObject(m_hDC, hFont);

	TCHAR sScoreT[32] = L"Score   : ";
	RECT rcScoreT{ (LONG)(WINCX * 0.5 - 90) ,(LONG)(WINCY * 0.5),(LONG)(WINCX * 0.5)  ,(LONG)(WINCY * 0.5 + 100) };
	DrawText(m_hDC, sScoreT, lstrlen(sScoreT), &rcScoreT, DT_CENTER);

	TCHAR sScore[32];
	_itow_s<32>(m_iScore, (sScore), 10);
	RECT rcScore{ (LONG)(WINCX * 0.5) ,(LONG)(WINCY * 0.5),(LONG)(WINCX * 0.5 + 50) ,(LONG)(WINCY * 0.5 + 100) };
	DrawText(m_hDC, sScore, lstrlen(sScore), &rcScore, DT_CENTER);

	TCHAR sRestart[32] = L"Press the 'R' Key to Title ";
	RECT rcRestart{ (LONG)(WINCX * 0.5 - 190),(LONG)(WINCY * 0.5 + 100),(LONG)(WINCX * 0.5 + 200) ,(LONG)(WINCY * 0.5 + 500) };
	DrawText(m_hDC, sRestart, lstrlen(sRestart), &rcRestart, DT_CENTER);

	SelectObject(m_hDC, hOldFont);
	DeleteObject(hFont);
}

void CMainGame::Render_ScoreRecord()
{
	HFONT hFont = CreateFont(25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, TEXT("Arial"));
	HFONT hOldFont = (HFONT)SelectObject(m_hDC, hFont);

	TCHAR sScore[32]=L"점수 랭킹";
	RECT rcScoreT{ (LONG)(WINCX * 0.5 - 200),(LONG)(WINCY * 0.5 - 130),(LONG)(WINCX * 0.5 + 200) ,(LONG)(WINCY * 0.5) };
	DrawText(m_hDC, sScore, lstrlen(sScore), &rcScoreT, DT_CENTER);

	hFont = CreateFont(15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, TEXT("Arial"));
	SelectObject(m_hDC, hFont);
	for (int i = 0; i < 10; ++i)
	{
		TCHAR sScore[32];
		wsprintf(sScore, L"%d", m_iScoreArray[i]);
		RECT rcScore{ (LONG)(WINCX * 0.5 - 200),(LONG)((WINCY * 0.5 - 100) + (i * 15)),(LONG)(WINCX * 0.5 + 200) ,(LONG)((WINCY * 0.5 + -100) + (i * 15 + 15)) };

		DrawText(m_hDC, sScore, lstrlen(sScore), &rcScore, DT_CENTER);
	}

	SelectObject(m_hDC, hOldFont);
	DeleteObject(hFont);
}

void CMainGame::Load_Score()
{
	FILE* pLoadFile = NULL;

	errno_t	err = fopen_s(&pLoadFile, "../Save.txt", "rb");

	if (0 == err)
	{
		fread(m_iScoreArray, sizeof(int), 10, pLoadFile);

		fclose(pLoadFile);
	}
}

void CMainGame::Save_Score()
{
	m_vecScore.clear();
	for (int i = 0; i < 10; ++i)
	{
		m_vecScore.push_back(m_iScoreArray[i]);
	}
	m_vecScore.push_back(m_iScore);
	sort(m_vecScore.begin(), m_vecScore.end(),greater<int>());
	m_vecScore.pop_back();

	int i = 0;
	for (auto Score : m_vecScore)
	{
		m_iScoreArray[i++] = Score;
	}

	FILE* pSaveFile = NULL;
	errno_t	err = fopen_s(&pSaveFile, "../Save.txt", "wb");

	if (0 == err)
	{
		fwrite(m_iScoreArray, sizeof(m_iScoreArray), 1, pSaveFile);

		fclose(pSaveFile);
	}
}


#pragma region 보스몬스터에 넣기
void CMainGame::Jusin()
{
	if (0 == m_checkWordCount && m_checkJusinTime + 200 < GetTickCount())
	{
		static_cast<CPlayer*>(m_pObjList[OBJ_PLAYER].front())->Set_IsShoot(false);
		FirstDrop();
		m_checkJusinTime = GetTickCount();
		++m_checkWordCount;
	}
	else if (1 == m_checkWordCount && m_checkJusinTime + 200 < GetTickCount())
	{
		SecondDrop();
		m_checkJusinTime = GetTickCount();
		++m_checkWordCount;
	}
	else if (2 == m_checkWordCount && m_checkJusinTime + 200 < GetTickCount())
	{
		ThirdDrop();
		m_checkJusinTime = GetTickCount();
		++m_checkWordCount;
	}
	else if (3 == m_checkWordCount && m_checkJusinTime + 200 < GetTickCount())
	{
		ForthDrop();
		m_checkJusinTime = GetTickCount();
		++m_checkWordCount;
	}
	else if (4 == m_checkWordCount && m_checkJusinTime + 200 < GetTickCount())
	{
		FifthDrop();
		m_checkJusinTime = GetTickCount();
		++m_checkWordCount;
	}

}

void CMainGame::FirstDrop()
{
	int arr[] = { 25, 35, 45,
		125, 135, 145, 155, 165, 175,
		225, 235, 245, 255, 265, 275,
		325, 335, 345, 355, 365, 375,
		415, 425, 475, 485
	};

	for (int i = 0; i < size(arr); ++i)
	{
		m_pObjList[OBJ_BULLET].push_back(CAbstractFactory<CBullet>::CreateObj());
		m_pObjList[OBJ_BULLET].back()->Set_Pos(arr[i], 30);	// 적의 발사 위치 설정
		static_cast<CBullet*>(m_pObjList[OBJ_BULLET].back())->SetJusinBullet();	// 해당 위치에서 아래 방향 일직선으로 발사.
	}
}

void CMainGame::SecondDrop()
{
	int arr[] = { 15, 25, 45, 55,
		115, 125, 175, 185,
		275, 285,
		345, 355,
		415, 425, 465, 475, 485
	};

	for (int i = 0; i < size(arr); ++i)
	{
		m_pObjList[OBJ_BULLET].push_back(CAbstractFactory<CBullet>::CreateObj());
		m_pObjList[OBJ_BULLET].back()->Set_Pos(arr[i], 30);	// 적의 발사 위치 설정
		static_cast<CBullet*>(m_pObjList[OBJ_BULLET].back())->SetJusinBullet();	// 해당 위치에서 아래 방향 일직선으로 발사.
	}
}

void CMainGame::ThirdDrop()
{
	int arr[] = { 45, 55,
		115, 125, 175, 185,
		215, 225, 235, 245 ,255, 265, 275,
		345, 355,
		415, 425, 445, 455, 475, 485
	};

	for (int i = 0; i < size(arr); ++i)
	{
		m_pObjList[OBJ_BULLET].push_back(CAbstractFactory<CBullet>::CreateObj());
		m_pObjList[OBJ_BULLET].back()->Set_Pos(arr[i], 30);	// 적의 발사 위치 설정
		static_cast<CBullet*>(m_pObjList[OBJ_BULLET].back())->SetJusinBullet();	// 해당 위치에서 아래 방향 일직선으로 발사.
	}
}

void CMainGame::ForthDrop()
{
	int arr[] = { 45, 55,
		115, 125, 175, 185,
		215, 225,
		345, 355,
		415, 425, 435, 475, 485
	};

	for (int i = 0; i < size(arr); ++i)
	{
		m_pObjList[OBJ_BULLET].push_back(CAbstractFactory<CBullet>::CreateObj());
		m_pObjList[OBJ_BULLET].back()->Set_Pos(arr[i], 30);	// 적의 발사 위치 설정
		static_cast<CBullet*>(m_pObjList[OBJ_BULLET].back())->SetJusinBullet();	// 해당 위치에서 아래 방향 일직선으로 발사.
	}
}

void CMainGame::FifthDrop()
{
	int arr[] = { 05, 15, 25, 35, 45, 55, 65, 75, 85, 95,
		115, 125, 175, 185,
		225, 235, 245, 255, 265, 275, 285,
		325, 335, 345, 355, 365, 375,
		415, 425, 475, 485
	};

	for (int i = 0; i < size(arr); ++i)
	{
		m_pObjList[OBJ_BULLET].push_back(CAbstractFactory<CBullet>::CreateObj());
		m_pObjList[OBJ_BULLET].back()->Set_Pos(arr[i], 30);	// 적의 발사 위치 설정
		static_cast<CBullet*>(m_pObjList[OBJ_BULLET].back())->SetJusinBullet();	// 해당 위치에서 아래 방향 일직선으로 발사.
	}
	
}
#pragma endregion 보스몬스터에 넣기(쥬신모양)