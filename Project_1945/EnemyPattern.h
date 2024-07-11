#pragma once
#include "MainGame.h"

// 양새하 추가
class CEnemyPattern
{
	//private:
	//	static DWORD m_dwTime;

public:
	CEnemyPattern();
	~CEnemyPattern();

public:
	static void				SetTarget(CObj* _target) { m_pTarget = _target; }

public:
	// 리스트에 직접 원소추가하는 것이므로 원본을 전달해야한다

		// 중형비행기
	static void EnemyA1(list<CObj*>& _Enemy, list<CObj*>& _Bullet); // 가운데 하나
	static void EnemyA2(list<CObj*>& _Enemy, list<CObj*>& _Bullet); // 둘
	static void EnemyA3(list<CObj*>& _Enemy, list<CObj*>& _Bullet); // 셋
	// 폭탄
	static void EnemyB1(list<CObj*>& _Enemy, list<CObj*>& _Bullet); // 왼쪽 하나
	static void EnemyB2(list<CObj*>& _Enemy, list<CObj*>& _Bullet); // 오른쪽 하나
	static void EnemyB3(list<CObj*>& _Enemy, list<CObj*>& _Bullet); // 둘
	// 대형 비행기
	static void EnemyC1(list<CObj*>& _Enemy, list<CObj*>& _Bullet); // 가운데 하나
	static void EnemyC2(list<CObj*>& _Enemy, list<CObj*>& _Bullet); // 둘
	// 헬리콥터
	static void EnemyD1(list<CObj*>& _Enemy, list<CObj*>& _Bullet, list<CObj*>& _Player); // 좌하단
	static void EnemyD2(list<CObj*>& _Enemy, list<CObj*>& _Bullet, list<CObj*>& _Player); // 우하단
	// 소형비행기
	static void EnemyE1(list<CObj*>& _Enemy, list<CObj*>& _Bullet); // 좌반원
	// 보스
	static void Boss(list<CObj*>& _Enemy, list<CObj*>& _Bullet); // T자 경로

private :
	static CObj* m_pTarget;
};