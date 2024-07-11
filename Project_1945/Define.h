#pragma once

#define WINCX 500
#define WINCY 600

#define PURE = 0

#define			OBJ_NOEVENT		0
#define			OBJ_DEAD		1

extern HWND g_hWnd;

enum OBJID { OBJ_PLAYER, OBJ_ENEMY, OBJ_MOUSE, OBJ_SHIELD, OBJ_ITEM, OBJ_BULLET, OBJ_BOSS, OBJ_END };

enum ITEMTYPE
{
	ITEM_POWER = 0,
	ITEM_LIFE,
	ITEM_INVINCIBLE,
	ITEM_BOMB,
	ITEM_END
};

enum PLAYERSTATE
{
	APPEAR,
	PLAYING,
	DESTROY,
	DEAD,
	PLAYERSTATE_END
};

typedef struct tagObj
{
	float	fX;
	float	fY;

	float	fCX;
	float	fCY;
}OBJINFO;

typedef struct tagPlayerInfo
{
	int iHp;			//체력
	int	iBulletLevel;	//발사할 총알 개수
	bool bIsInvincible;	//무적 상태

	PLAYERSTATE eState;	//플레이어 상태

}PLAYERINFO;


#pragma region 총알 추가
// 총알 나가는 방향
enum DIRECTION
{
	TOP,
	LT,
	RT,
	FOLLOW,
	ENEMYFOLLOW,
	BOTTOM,
	BOSS,
	DIRECTION_END
};

#pragma endregion

template <typename T>
void Safe_Delete(T& p)
{
	if (p)
	{
		delete p;
		p = nullptr;
	}
}

template <typename T>
void Safe_Delete_Array(T& p)
{
	if (p)
	{
		delete[] p;
		p = nullptr;
	}
}