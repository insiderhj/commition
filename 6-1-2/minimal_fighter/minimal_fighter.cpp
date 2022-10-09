#include "minimal_fighter.h"

int MinimalFighter::hp()
{
	return mHp;
}

int MinimalFighter::power()
{
	return mPower;
}

FighterStatus MinimalFighter::status()
{
	return mStatus;
}

void MinimalFighter::setHp(int _hp)
{
	mHp = _hp;
}

void MinimalFighter::hit(MinimalFighter *_enemy)
{
	_enemy->mHp -= mPower;
	mHp -= _enemy->mPower;
	if (mHp <= 0) mStatus = Dead;
	if (_enemy->mHp <= 0) _enemy->mStatus = Dead;
}

void MinimalFighter::attack(MinimalFighter *_enemy)
{
	_enemy->mHp -= mPower;
	mPower = 0;
	if (_enemy->mHp <= 0) _enemy->mStatus = Dead;
}

void MinimalFighter::fight(MinimalFighter *_enemy)
{
	while (mStatus == Alive && _enemy->mStatus == Alive)
		hit(_enemy);
}
