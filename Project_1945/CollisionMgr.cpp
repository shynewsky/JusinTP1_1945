#include "pch.h"
#include "CollisionMgr.h"
#include "Player.h"
#include "Item.h"
#include "Enemy.h"

CCollisionMgr::CCollisionMgr()
{
}


CCollisionMgr::~CCollisionMgr()
{
}

void CCollisionMgr::Collision_Rect(const list<CObj*> _Dst, const list<CObj*> _Src)
{
	RECT	rcRect{};

	for (auto& Dst : _Dst)
	{
		for (auto& Src : _Src)
		{
			if (IntersectRect(&rcRect, &(Dst->Get_Rect()), &(Src->Get_Rect())))
			{
				//아이템 충돌
				if (Dst->Get_ObjId() == OBJ_ITEM )
				{
					if (Src->Get_ObjId() == OBJ_PLAYER)
					{
						static_cast<CItem*>(Dst)->Apply_Ability();
						Dst->Set_Dead();
					}
				}

				//플레이어와  적 충돌
				if (Dst->Get_ObjId() == OBJ_ENEMY)
				{
					if (Src->Get_ObjId() == OBJ_PLAYER)
					{
						//무적상태가 아니고 플레이어가 플레이중이면
						if (!static_cast<CPlayer*>(Src)->Get_Invincible() && static_cast<CPlayer*>(Src)->Get_PlayerState() == PLAYING)
						{
							if (static_cast<CPlayer*>(Src)->Get_PlayerState() == PLAYING)
							{
								Dst->Set_Dead();
								static_cast<CPlayer*>(Src)->Damaged_Player();
							}
						}
					}
				}

				//플레이어와  적 충돌
				if (Dst->Get_ObjId() == OBJ_BOSS)
				{
					if (Src->Get_ObjId() == OBJ_PLAYER)
					{
						//무적상태가 아니고 플레이어가 플레이중이면
						if (!static_cast<CPlayer*>(Src)->Get_Invincible() && static_cast<CPlayer*>(Src)->Get_PlayerState() == PLAYING)
						{
							static_cast<CPlayer*>(Src)->Damaged_Player();
						}
					}
				}
			}
		}
	}
}

void CCollisionMgr::Collision_Sphere(list<CObj*> _Dst, list<CObj*> _Src)
{
	for (auto& Dst : _Dst)
	{
		for (auto& Src : _Src)
		{
			if (Check_Sphere(Dst, Src))
			{
				//플레이어총알과 적
				if (Dst->Get_ObjId() == OBJ_ENEMY || Dst->Get_ObjId() == OBJ_BOSS)
				{
					if (Src->Get_ObjId() == OBJ_BULLET && static_cast<CBullet*>(Src)->GetIdentity())
					{
						static_cast<CEnemy*>(Dst)->Damaged(static_cast<CBullet*>(Src)->Get_Damage());
						Src->Set_Dead();
					}
				}
			}

			if (Dst->Get_ObjId() == OBJ_PLAYER)
			{
				//폭발 아이템
				if ((Src->Get_ObjId() == OBJ_BULLET && !static_cast<CBullet*>(Src)->GetIdentity()) || Src->Get_ObjId() == OBJ_ENEMY)
				{
					if (static_cast<CPlayer*>(Dst)->Get_IsBomb())
					{
						if (Check_Sphere(static_cast<CPlayer*>(Dst)->Get_BombInfo(), Src))
							Src->Set_Dead(); 
					}
				}

				//플레이어와 적 총알
				if (Src->Get_ObjId() == OBJ_BULLET && !static_cast<CBullet*>(Src)->GetIdentity())
				{
					if (!static_cast<CPlayer*>(Dst)->Get_Invincible() && static_cast<CPlayer*>(Dst)->Get_PlayerState() == PLAYING)
					{
						if (Check_Sphere(Dst, Src))
						{
							if (!static_cast<CPlayer*>(Dst)->Get_Invincible() && static_cast<CPlayer*>(Dst)->Get_PlayerState() == PLAYING)
							{
								if (static_cast<CBullet*>(Src)->Get_IsJusin())
								{
									Dst->Set_Dead();
								}
								else
								{
									static_cast<CPlayer*>(Dst)->Damaged_Player();
								}
								Src->Set_Dead();
							}
						}
					}
				}
					
			}
		}
	}
}

bool CCollisionMgr::Check_Sphere(CObj * pDst, CObj * pSrc)
{
	float	fWidth  = abs(pDst->Get_Info().fX - pSrc->Get_Info().fX);
	float	fHeight	= abs(pDst->Get_Info().fY - pSrc->Get_Info().fY);

	float	fDiagonal = sqrt(fWidth * fWidth + fHeight  * fHeight);

	float	fRadius = (pDst->Get_Info().fCX + pSrc->Get_Info().fCX) * 0.5f;
		
	return fRadius >= fDiagonal;
}

bool CCollisionMgr::Check_Sphere(OBJINFO tDst, CObj* pSrc)
{
	float	fWidth = abs(tDst.fX - pSrc->Get_Info().fX);
	float	fHeight = abs(tDst.fY - pSrc->Get_Info().fY);

	float	fDiagonal = sqrt(fWidth * fWidth + fHeight * fHeight);

	float	fRadius = (tDst.fCX + pSrc->Get_Info().fCX) * 0.5f;
	return fRadius >= fDiagonal;;
}


