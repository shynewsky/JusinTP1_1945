#pragma once
#include "Obj.h"
#include "Bullet.h"
#include "AbstractFactory.h"

class CPlayer :
    public CObj
{
public:
    CPlayer();
    virtual ~CPlayer();

public:
    PLAYERINFO&         Get_PlayerInfo() { return m_tPlayerInfo; }
    void                Level_UP() { if (m_tPlayerInfo.iBulletLevel < 4) ++m_tPlayerInfo.iBulletLevel; }
    bool                Get_Invincible() { return m_tPlayerInfo.bIsInvincible; }

    bool                Get_PlayerState() { return m_tPlayerInfo.eState; }
    void                Add_Life() { if (m_tPlayerInfo.iHp < 5) ++m_tPlayerInfo.iHp; }
    void                Set_BulletList(list<CObj*>* _pBullList) { m_bulletList = _pBullList; }
    OBJINFO             Get_BombInfo() { return m_tBombInfo; }
    bool                Get_IsBomb() { return m_bIsBomb; }
    void                Set_IsShoot(bool _bShoot) { m_bIsShoot = _bShoot; }
    void                Add_Bomb() { if (m_iBombCount < 3) ++m_iBombCount; }
    void                SetEnemyList(list<CObj*>* _enemyList) { m_enemyList = _enemyList; }
    void                SetBossList(list<CObj*>* _bossList) { m_bossList = _bossList; }

    void                Set_Invincible() 
    {
        m_tPlayerInfo.bIsInvincible = true;
        m_InvincibleTick = GetTickCount();
        m_BlinkTick = GetTickCount();
    }

public:
    virtual void        Initialize()       override;
    virtual int         Update()           override;
    virtual void        Late_Update()      override;
    virtual void        Render(HDC hDC)    override;
    virtual void        Release()          override;

public:
    void                Move_Player();
    void                Damaged_Player();
    void                Destroy_Player();
    void                Appear_Player();
    void                Invincible_Time();
    void                Create_Bullet();
    void                Use_Bomb();

private:
    PLAYERINFO          m_tPlayerInfo;
    OBJINFO             m_tBombInfo;
    DWORD               m_DestroyTick;
    DWORD               m_InvincibleTick;
    DWORD               m_BlinkTick;
    DWORD               m_BulletTick;
    DWORD               m_BombTick;
    DWORD               m_GuidedTick;

    int                 m_iBombCount;
    float               m_fEffectsize;
    float               m_fStartY;
    bool                m_bIsBomb;
    bool                m_bIsShoot;

    list<CObj*>*		    m_bulletList;
    list<CObj*>*            m_enemyList;
    list<CObj*>*            m_bossList;
};

