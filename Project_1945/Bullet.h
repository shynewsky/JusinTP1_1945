#pragma once
#include "Obj.h"

class CBullet : public CObj
{
private:
	DIRECTION	m_dr;
	int			m_iBulletLevel;
	bool		m_bIdentity;		// 플레이어 몬스터 총알 판별용. 참: player , 거짓: enemy.
	bool		m_crash;		// 충돌 판별
	bool		m_bJusin;

	int			m_damage;
	float		m_fAngle_1;
	float       m_fCeta;

public:
	CBullet();
	virtual ~CBullet();

public:
	DIRECTION			GetDirection() { return m_dr; }
	bool				GetIdentity() { return m_bIdentity; }
	bool				Get_IsJusin() { return m_bJusin; }
	virtual void		Set_Pos(float _x, float _y) override
	{
		m_tObjInfo.fX = _x;
		m_tObjInfo.fY = _y - 20;
	}
	void				Set_Identity(bool _identity) { m_bIdentity = _identity; }
	int					Get_Damage() { return m_damage; }

public:
	virtual void		Initialize()	override;
	virtual int			Update()		override;
	virtual void		Late_Update()	override;
	virtual void		Render(HDC hDC) override;
	virtual void		Release()		override;


	void				SetBulletData(int _bulletRank, DIRECTION _dr);
	void				SetEnemyBullet();
	void				SetFollowBullet();
	void				SetBossBullet(float _fCeta);
	void				SetJusinBullet();
	CObj*				CheckShortestDistance(list<CObj*> _targetList);
};

