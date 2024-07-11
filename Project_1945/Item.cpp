#include "pch.h"
#include "Item.h"

CItem::CItem()
	: m_pEnemy(nullptr)
	, m_pPlayer(nullptr)
	, m_bExpired(false)
	, m_dwCreatedTickCount(GetTickCount())
{
}

CItem::~CItem()
{
	Release();
}

void CItem::Initialize()
{
	m_fXSpeed = -3.f; // 처음 생성 시 왼쪽 대각선으로 이동
	m_fYSpeed = -3.f; // 처음 생성 시 왼쪽 대각선으로 이동

	Set_Pos(100, 100); // Initialize() 이후, 외부(Enemy)에서 자신의 좌표 값으로 호출해줘야 함
	Set_Size(10, 30);  // 얘는 고정값이니 여기가 맞나..?

	m_eObjId = OBJ_ITEM;
}

int CItem::Update()
{
	if (m_bDead)
	{
		return OBJ_DEAD;
	}
	
	DWORD dwElapsedTickCount = GetTickCount() - m_dwCreatedTickCount;

	if (dwElapsedTickCount > MAX_TICK_COUNT)
	{
		m_bExpired = true;
	}

	m_tObjInfo.fX += m_fXSpeed;
	m_tObjInfo.fY += m_fYSpeed;

	// 여기다가 수업시간에 배운 대각선 이동 속도조절 적용해야 할 듯..?

	__super::Update_Pos();

	return OBJ_NOEVENT;
}

void CItem::Late_Update()
{
	bool bCollision = false;
	                                  
	if (m_tRect.left <= 0
		|| m_tRect.right >= WINCX)
	{
		m_fXSpeed *= -1.f;
		bCollision = true;
	}
	
	if (m_tRect.top <= 0
		|| m_tRect.bottom >= WINCY)
	{
		m_fYSpeed *= -1.f;
		bCollision = true;
	}
	
	if (m_bExpired && bCollision) // 경과 Tick이 MAX_TICK_COUNT 이상 && 마지막 벽 충돌 시 소멸
	{
		m_bDead = true;
	}
}

void CItem::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CItem::Release()
{
}
