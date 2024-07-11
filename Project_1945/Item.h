#pragma once

#include "Obj.h"

class CItem abstract
	: public CObj
{
public:
	CItem();
	virtual ~CItem()		override;

public:
	void Initialize()		override;
	int	 Update()			override;
	void Late_Update()		override;
	void Render(HDC hDC)	override;
	void Release()			override;
	virtual void Apply_Ability() PURE;

public:
	inline void Set_Player(CObj* _pPlayer) { m_pPlayer = _pPlayer; }
	inline void Set_Enemy(CObj* _pEnemy) { m_pEnemy = _pEnemy; }
	
protected:
	CObj* m_pEnemy;				// 얘는 없어도 될 것 같긴한데..
	CObj* m_pPlayer;
	bool  m_bExpired;			// 아이템 수명이 만료됬는지 여부
	DWORD m_dwCreatedTickCount; // 아이템 생성 시기

private:
	static const int MAX_TICK_COUNT = 10000; // 아이템 수명
};

