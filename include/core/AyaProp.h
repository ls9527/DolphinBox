#pragma once
#ifndef DLL_IMPORT
#define  DLL_EXPORT _declspec(dllexport)
#else if
#define  DLL_EXPORT _declspec(dllimport)
#endif

#include <vector>
using namespace std;

typedef int POINTER ;

#define ADDR_MOV 0
#define ADDR_LEA 1
typedef struct tagAddr{
	UINT addr;//内容
	UINT type;//0 mov值，1 lea地址
	tagAddr(UINT addr,UINT type){
		this->addr = addr;
		this->type = type;
	};
}Addr,*LPAddr;

class DLL_EXPORT AyaChain{
private:
	vector<Addr> vec;

public:
	AyaChain(void);
	//获取链条大小
	UINT GetChainSize();
	//添加值
	void AddMovAddr(UINT addr);
	//添加地址
	void AddLeaAddr(UINT addr);
	//最底层指向的值
	POINTER GetEndValue(UINT baseAddr = 0);
	//获取指定级别指向的值,如果最大保存值存在，并且超过最大保存值就会返回最底层链条的值，否则返回 baseAddr
	POINTER GetValue(int index,UINT baseAddr = 0);
};
class _declspec(dllexport) AyaProp
{
private:
	vector<AyaChain*> m_vec;
	AyaChain m_chain;
public:
	AyaProp(void);
	~AyaProp(void);
public:
	//当前m_chain链条加入mov地址
	void AddMovAddr(UINT addr);
	//当前m_chain链条链条加入lea地址
	void AddLeaAddr(UINT addr);
	//最底层指向的值
	POINTER GetEndValue();
	//获取整体链条中，指定级别的值
	POINTER GetValue(int index);
	//添加一个链条
	void AddChain(AyaChain *ayaChain);
};

