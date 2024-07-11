#include "pch.h"
#include "EnemyStage.h"
#include "EnemyPattern.h"
#include "MainGame.h"
int CEnemyStage::num = 1;
int CEnemyStage::iCountE = 0;
DWORD CEnemyStage::dwTime = GetTickCount();

void CEnemyStage::Initialize()
{
	CEnemyStage::num = 1;
	CEnemyStage::iCountE = 0;
}

// 더러운 코드 주의
bool CEnemyStage::Stage1(list<CObj*>& _Enemy, list<CObj*>& _Bullet, list<CObj*>& _Player) {

	switch (num) {
	case 1: if (dwTime + 1800 < GetTickCount()) { CEnemyPattern::EnemyA1(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 2: if (dwTime + 1800 < GetTickCount()) { CEnemyPattern::EnemyC2(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 3: if (dwTime + 1800 < GetTickCount()) { CEnemyPattern::EnemyB2(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 4: if (dwTime + 1800 < GetTickCount()) { CEnemyPattern::EnemyB3(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 5: if (dwTime + 1800 < GetTickCount()) { CEnemyPattern::EnemyC1(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 6: if (dwTime + 1800 < GetTickCount()) { CEnemyPattern::EnemyA2(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 7: if (dwTime + 1800 < GetTickCount()) { CEnemyPattern::EnemyB2(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 8: if (dwTime + 1800 < GetTickCount()) { CEnemyPattern::EnemyA1(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 9: if (dwTime + 1800 < GetTickCount()) { CEnemyPattern::EnemyD2(_Enemy, _Bullet, _Player); dwTime = GetTickCount(); num++; } return true; break;
	case 10: if (dwTime + 1800 < GetTickCount()) { CEnemyPattern::EnemyC2(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return false; break;
	default: break;
	}
}
bool CEnemyStage::Stage2(list<CObj*>& _Enemy, list<CObj*>& _Bullet, list<CObj*>& _Player) {

	switch (num) {
	case 1: if (dwTime + 1200 < GetTickCount()) { CEnemyPattern::EnemyB3(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 2: if (dwTime + 1200 < GetTickCount()) { CEnemyPattern::EnemyA3(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 3: if (dwTime + 1200 < GetTickCount()) { CEnemyPattern::EnemyB1(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 4: if (dwTime + 1200 < GetTickCount()) { CEnemyPattern::EnemyA1(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 5: if (dwTime + 1200 < GetTickCount()) { CEnemyPattern::EnemyD2(_Enemy, _Bullet, _Player); dwTime = GetTickCount(); num++; } return true; break;
	case 6: if (dwTime + 1200 < GetTickCount()) { CEnemyPattern::EnemyB3(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 7: if (dwTime + 1200 < GetTickCount()) { CEnemyPattern::EnemyA2(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 8: if (dwTime + 1200 < GetTickCount()) { CEnemyPattern::EnemyD1(_Enemy, _Bullet, _Player); dwTime = GetTickCount(); num++; } return true; break;
	case 9: if (dwTime + 1200 < GetTickCount()) { CEnemyPattern::EnemyA1(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 10: if (dwTime + 1200 < GetTickCount()) { CEnemyPattern::EnemyD1(_Enemy, _Bullet, _Player); dwTime = GetTickCount(); num++; } return true; break;
	case 11: if (dwTime + 1200 < GetTickCount()) { CEnemyPattern::EnemyD1(_Enemy, _Bullet, _Player); dwTime = GetTickCount(); num++; } return true; break;
	case 12: if (dwTime + 1200 < GetTickCount()) { CEnemyPattern::EnemyA2(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 13: if (dwTime + 1200 < GetTickCount()) { CEnemyPattern::EnemyD1(_Enemy, _Bullet, _Player); dwTime = GetTickCount(); num++; } return true; break;
	case 14: if (dwTime + 1200 < GetTickCount()) { CEnemyPattern::EnemyC1(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 15: if (dwTime + 1200 < GetTickCount()) { CEnemyPattern::EnemyB2(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 16: if (dwTime + 1200 < GetTickCount()) { CEnemyPattern::EnemyA2(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 17: if (dwTime + 1200 < GetTickCount()) { CEnemyPattern::EnemyC1(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 18: if (dwTime + 1200 < GetTickCount()) { CEnemyPattern::EnemyD2(_Enemy, _Bullet, _Player); dwTime = GetTickCount(); num++; } return true; break;
	case 19: if (dwTime + 1200 < GetTickCount()) { CEnemyPattern::EnemyA1(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 20: if (dwTime + 1200 < GetTickCount()) { CEnemyPattern::EnemyB3(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return false; break;
	default: break;
	}
}
bool CEnemyStage::Stage3(list<CObj*>& _Enemy, list<CObj*>& _Bullet, list<CObj*>& _Player) {

	switch (num) {
	case 1: if (dwTime + 300 < GetTickCount()) { if (iCountE < 5) { CEnemyPattern::EnemyE1(_Enemy, _Bullet); dwTime = GetTickCount(); iCountE++; return true; } else { num++; return true; } break; }
	case 2: if (dwTime + 1000 < GetTickCount()) { CEnemyPattern::EnemyB3(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 3: if (dwTime + 1000 < GetTickCount()) { CEnemyPattern::EnemyA3(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 4: if (dwTime + 1000 < GetTickCount()) { CEnemyPattern::EnemyD1(_Enemy, _Bullet, _Player); dwTime = GetTickCount(); num++; } return true; break;
	case 5: if (dwTime + 1000 < GetTickCount()) { CEnemyPattern::EnemyA1(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 6: if (dwTime + 1000 < GetTickCount()) { CEnemyPattern::EnemyC2(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 7: if (dwTime + 1000 < GetTickCount()) { CEnemyPattern::EnemyD2(_Enemy, _Bullet, _Player); dwTime = GetTickCount(); num++; } return true; break;
	case 8: if (dwTime + 300 < GetTickCount()) { if (iCountE < 5) { CEnemyPattern::EnemyE1(_Enemy, _Bullet); dwTime = GetTickCount(); iCountE++; return true; } else { num++; return true; } break; }
	case 9: if (dwTime + 1000 < GetTickCount()) { CEnemyPattern::EnemyA1(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 10: if (dwTime + 1000 < GetTickCount()) { CEnemyPattern::EnemyC1(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 11: if (dwTime + 1000 < GetTickCount()) { CEnemyPattern::EnemyB1(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 12: if (dwTime + 1000 < GetTickCount()) { CEnemyPattern::EnemyD2(_Enemy, _Bullet, _Player); dwTime = GetTickCount(); num++; } return true; break;
	case 13: if (dwTime + 1000 < GetTickCount()) { CEnemyPattern::EnemyB2(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 14: if (dwTime + 300 < GetTickCount()) { if (iCountE < 5) { CEnemyPattern::EnemyE1(_Enemy, _Bullet); dwTime = GetTickCount(); iCountE++; return true; } else { num++; return true; } break; }
	case 15: if (dwTime + 1000 < GetTickCount()) { CEnemyPattern::EnemyB3(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 16: if (dwTime + 1000 < GetTickCount()) { CEnemyPattern::EnemyC1(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 17: if (dwTime + 1000 < GetTickCount()) { CEnemyPattern::EnemyD1(_Enemy, _Bullet, _Player); dwTime = GetTickCount(); num++; } return true; break;
	case 18: if (dwTime + 1000 < GetTickCount()) { CEnemyPattern::EnemyB2(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 19: if (dwTime + 1000 < GetTickCount()) { CEnemyPattern::EnemyA2(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return true; break;
	case 20: if (dwTime + 1000 < GetTickCount()) { CEnemyPattern::EnemyA1(_Enemy, _Bullet); dwTime = GetTickCount(); num++; } return false; break;
	default: break;
	}
}

// 보스 스테이지
bool CEnemyStage::Boss(list<CObj*>& _Enemy, list<CObj*>& _Bullet, list<CObj*>& _Player)
{
	CEnemyPattern::Boss(_Enemy, _Bullet);
	dwTime = GetTickCount();
	return false;
}