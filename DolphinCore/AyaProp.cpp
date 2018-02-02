#include "stdafx.h"
#include "AyaProp.h"


AyaProp::AyaProp(void)
{
}


AyaProp::~AyaProp(void)
{
}

void AyaProp::AddMovAddr(UINT addr)
{
	m_chain.AddMovAddr(addr);
}

void AyaProp::AddLeaAddr(UINT addr)
{
	m_chain.AddLeaAddr(addr);
}

POINTER AyaProp::GetEndValue()
{
	int value = 0;
	for(auto iter = m_vec.begin();iter<m_vec.end();iter++){
		value +=(*iter)->GetEndValue(value);
	}
	return m_chain.GetEndValue(value);
}

POINTER AyaProp::GetValue(int index)
{
	int value = 0;
	
	for(auto iter = m_vec.begin();iter<m_vec.end();iter++){
		
		index -= (*iter)->GetChainSize();
		if(index>=0){
			value +=(*iter)->GetEndValue(value);
			
		}
		else{
			return (*iter)->GetValue(index,value);
		}
	}
	value = m_chain.GetValue(index);
	index -= m_chain.GetChainSize()-1;
	if(index<=0){
		return value;
	}
	return m_chain.GetEndValue();
}

void AyaProp::AddChain(AyaChain *ayaChain)
{
	m_vec.push_back(ayaChain);
}

AyaChain::AyaChain(void)
{

}



UINT AyaChain::GetChainSize()
{
	return vec.size();
}

void AyaChain::AddMovAddr(UINT addr)
{
	vec.push_back(Addr(addr,ADDR_MOV));
}

void AyaChain::AddLeaAddr(UINT addr)
{
	vec.push_back(Addr(addr,ADDR_LEA));
}

POINTER AyaChain::GetEndValue(UINT baseAddr)
{
	int value = baseAddr;
	for(auto iter = vec.begin();iter<vec.end();iter++){
		if((*iter).type == 0){
			value = *(int*)((*iter).addr+value);
		}else if((*iter).type == 1){
			value += (*iter).addr;
		}
	}
	return value;
}

POINTER AyaChain::GetValue(int index,UINT baseAddr)
{
	int tempIndex = 0;
	int value = baseAddr;
	for(auto iter = vec.begin();iter<vec.end();iter++){
		if((*iter).type == 0){
			value = *(int*)((*iter).addr+value);
		}else if((*iter).type == 1){
			value += (*iter).addr;
		}
		if(index == tempIndex){
			break;
		}
		tempIndex++;
	}
/*
	if(index != tempIndex){
		return 0;
	}
*/
	return value;
}
