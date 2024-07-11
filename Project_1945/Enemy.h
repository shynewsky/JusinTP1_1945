#pragma once
#include "Obj.h"
#include "Bullet.h"
#include "AbstractFactory.h"

// EnemyA,B,C,D,E를 리스트로 만들어 출력하는 Render를 만들기 위한 부모
class CEnemy : public CObj
{
public:
	CEnemy() : m_iHp(0), m_Score(0), dwTime(GetTickCount()) {}
	virtual ~CEnemy() {}

public:
	void				Damaged(int _iDamage) { CEnemy::m_iHp -= _iDamage; }
	int					Get_Score() { return m_Score; }
	void				Set_BulletList(list<CObj*>* _pBullet) { m_pBulletList = _pBullet; }
	void				Set_CopyPlayer(list<CObj*>* _pPlayer) { m_pCopyPlayer = _pPlayer; }


public:
	virtual void		Initialize();
	virtual int			Update();
	virtual void		Late_Update();
	virtual void		Render(HDC hDC);
	virtual void		Release();

public:
	
	void				Create_Bullet_Normal();
	void				Create_Bullet_Follow();
	void				Create_Bullet_Boss();

protected:
	DWORD				dwTime;
	int					m_iMaxHp;
	int					m_iHp;
	int					m_Score;
	list<CObj*>*		m_pBulletList;
	list<CObj*>*		m_pCopyPlayer;
};