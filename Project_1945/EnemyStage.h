#pragma once
#include "EnemyPattern.h"

class CEnemyStage
{	
public:
	static int		num; // switch 문에 들어갈 것
	static int		iCountE; // EnemyE 개수
	static DWORD	dwTime;

public:
	CEnemyStage() {}
	~CEnemyStage() {}

public:
	static void Set_Num(int _num) { num = _num; }

public:
	static void Initialize();
	static bool Stage1(list<CObj*>& _Enemy, list<CObj*>& _Bullet, list<CObj*>& _Player);
	static bool Stage2(list<CObj*>& _Enemy, list<CObj*>& _Bullet, list<CObj*>& _Player);
	static bool Stage3(list<CObj*>& _Enemy, list<CObj*>& _Bullet, list<CObj*>& _Player);
	static bool Boss(list<CObj*>& _Enemy, list<CObj*>& _Bullet, list<CObj*>& _Player);
};
