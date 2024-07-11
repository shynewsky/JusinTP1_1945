#pragma once
#include "pch.h"
#include "EnemyPattern.h"
#include "Boss.h"

CEnemyPattern::CEnemyPattern()
{
}
CEnemyPattern::	~CEnemyPattern() {}

// 중형비행기
void CEnemyPattern::EnemyA1(list<CObj*>& _Enemy, list<CObj*>& _Bullet) // 가운데 하나
{
	CObj* pEnemy = CAbstractFactory<CEnemyA>::CreateObj(250, -50);
	static_cast<CEnemy*>(pEnemy)->Set_BulletList(&_Bullet);
	//m_pObjList[OBJ_ENEMY].push_back(pEnemy);
	_Enemy.push_back(pEnemy);
}
void CEnemyPattern::EnemyA2(list<CObj*>& _Enemy, list<CObj*>& _Bullet)  // 둘
{
	CObj* pEnemy = CAbstractFactory<CEnemyA>::CreateObj(170, -50);
	static_cast<CEnemy*>(pEnemy)->Set_BulletList(&_Bullet);
	_Enemy.push_back(pEnemy);
}
void CEnemyPattern::EnemyA3(list<CObj*>& _Enemy, list<CObj*>& _Bullet) // 셋
{
	CObj* pEnemy = CAbstractFactory<CEnemyA>::CreateObj(100, -50);
	static_cast<CEnemy*>(pEnemy)->Set_BulletList(&_Bullet);
	_Enemy.push_back(pEnemy);

	CObj* pEnemy1 = CAbstractFactory<CEnemyA>::CreateObj(250, -50);
	static_cast<CEnemy*>(pEnemy1)->Set_BulletList(&_Bullet);
	_Enemy.push_back(pEnemy1);

	CObj* pEnemy2 = CAbstractFactory<CEnemyA>::CreateObj(400, -50);
	static_cast<CEnemy*>(pEnemy2)->Set_BulletList(&_Bullet);
	_Enemy.push_back(pEnemy2);
}

// 폭탄
void CEnemyPattern::EnemyB1(list<CObj*>& _Enemy, list<CObj*>& _Bullet) // 왼쪽 하나
{
	CObj* pEnemy = CAbstractFactory<CEnemyB>::CreateObj(100, -50);
	static_cast<CEnemy*>(pEnemy)->Set_BulletList(&_Bullet);
	_Enemy.push_back(pEnemy);
}
void CEnemyPattern::EnemyB2(list<CObj*>& _Enemy, list<CObj*>& _Bullet) // 오른쪽 하나
{
	CObj* pEnemy = CAbstractFactory<CEnemyB>::CreateObj(400, -50);
	static_cast<CEnemy*>(pEnemy)->Set_BulletList(&_Bullet);
	_Enemy.push_back(pEnemy);
}
void CEnemyPattern::EnemyB3(list<CObj*>& _Enemy, list<CObj*>& _Bullet)  // 둘
{
	CObj* pEnemy = CAbstractFactory<CEnemyB>::CreateObj(100, -50);
	static_cast<CEnemy*>(pEnemy)->Set_BulletList(&_Bullet);
	_Enemy.push_back(pEnemy);

	CObj* pEnemy1 = CAbstractFactory<CEnemyB>::CreateObj(400, -50);
	static_cast<CEnemy*>(pEnemy1)->Set_BulletList(&_Bullet);
	_Enemy.push_back(pEnemy1);
}

// 대형 비행기
void CEnemyPattern::EnemyC1(list<CObj*>& _Enemy, list<CObj*>& _Bullet) // 가운데 하나
{
	CObj* pEnemy = CAbstractFactory<CEnemyC>::CreateObj(250, -50);
	static_cast<CEnemy*>(pEnemy)->Set_BulletList(&_Bullet);
	_Enemy.push_back(pEnemy);
}
void CEnemyPattern::EnemyC2(list<CObj*>& _Enemy, list<CObj*>& _Bullet) // 둘
{
	CObj* pEnemy = CAbstractFactory<CEnemyC>::CreateObj(150, -50);
	static_cast<CEnemy*>(pEnemy)->Set_BulletList(&_Bullet);
	_Enemy.push_back(pEnemy);

	CObj* pEnemy1 = CAbstractFactory<CEnemyC>::CreateObj(350, -50);
	static_cast<CEnemy*>(pEnemy1)->Set_BulletList(&_Bullet);
	_Enemy.push_back(pEnemy1);
}

// 헬리콥터
void CEnemyPattern::EnemyD1(list<CObj*>& _Enemy, list<CObj*>& _Bullet, list<CObj*>& _Player) // 좌하단
{
	CObj* pEnemy = CAbstractFactory<CEnemyD>::CreateObj(-50, 550);
	static_cast<CEnemy*>(pEnemy)->Set_CopyPlayer(&_Player);
	static_cast<CEnemy*>(pEnemy)->Set_BulletList(&_Bullet);
	_Enemy.push_back(pEnemy);
}
void CEnemyPattern::EnemyD2(list<CObj*>& _Enemy, list<CObj*>& _Bullet, list<CObj*>& _Player) // 우하단
{
	CObj* pEnemy = CAbstractFactory<CEnemyD>::CreateObj(550, 550);
	static_cast<CEnemy*>(pEnemy)->Set_CopyPlayer(&_Player);
	static_cast<CEnemy*>(pEnemy)->Set_BulletList(&_Bullet);
	_Enemy.push_back(pEnemy);
}

// 소형비행기
void CEnemyPattern::EnemyE1(list<CObj*>& _Enemy, list<CObj*>& _Bullet) // 좌반원
{
	CObj* pEnemy = CAbstractFactory<CEnemyE>::CreateObj();
	static_cast<CEnemy*>(pEnemy)->Set_BulletList(&_Bullet);
	_Enemy.push_back(pEnemy);
}

// 보스
void CEnemyPattern::Boss(list<CObj*>& _Enemy, list<CObj*>& _Bullet) // T자 경로
{
	CObj* pEnemy = CAbstractFactory<CBoss>::CreateObj(250, -50);
	static_cast<CEnemy*>(pEnemy)->Set_BulletList(&_Bullet);
	_Enemy.push_back(pEnemy);
}
