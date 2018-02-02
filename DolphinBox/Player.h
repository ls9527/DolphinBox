#pragma once
#include "AyaProp.h"
class Player
{
private:
	AyaChain m_baseChain;
public:
	Player(void);
	~Player(void);
public:
	AyaProp blood;
	AyaProp blue;
	AyaProp x;
	AyaProp y;
	
};

