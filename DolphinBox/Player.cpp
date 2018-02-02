#include "stdafx.h"
#include "Player.h"


Player::Player(void)
{
	m_baseChain.AddMovAddr(0x70459014);
	m_baseChain.AddMovAddr(0x5c);
	m_baseChain.AddMovAddr(0x1d4);

	blood.AddChain(&m_baseChain);
	blood.AddMovAddr(0x4);
	blood.AddMovAddr(0x27dc);
	blood.GetEndValue();
}


Player::~Player(void)
{
}
