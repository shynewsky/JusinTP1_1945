#pragma once
#include "Define.h"

class CObj abstract
{
public:
	CObj();
	virtual ~CObj();

public:
	virtual void		Set_Pos(float _x, float _y)
	{
		m_tObjInfo.fX = _x;
		m_tObjInfo.fY = _y;
	}
	void				Set_Size(float _x, float _y)
	{
		m_tObjInfo.fCX = _x;
		m_tObjInfo.fCY = _y;
	}

	RECT&				Get_Rect() { return m_tRect; }
	OBJINFO				Get_Info() { return m_tObjInfo; }
	virtual void		Set_Dead() { m_bDead = true; }
	bool				Get_IsDead() { return m_bDead; }
	OBJID				Get_ObjId() { return m_eObjId; }

	void				SetTarget(CObj* _target) { m_pTarget = _target; }

public:
	virtual void		Initialize()	PURE;
	virtual int			Update()		PURE;
	virtual void		Late_Update()	PURE;
	virtual void		Render(HDC hDC) PURE;
	virtual void		Release()		PURE;

public:
	void				Update_Pos();

protected:
	OBJINFO				m_tObjInfo;
	RECT				m_tRect;
	float				m_fSpeed;
	float				m_fXSpeed;	//아이템용
	float				m_fYSpeed;	//아이템용
	bool				m_bDead;
	CObj*				m_pTarget;

	OBJID				m_eObjId;
};

