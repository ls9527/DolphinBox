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
	UINT addr;//����
	UINT type;//0 movֵ��1 lea��ַ
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
	//��ȡ������С
	UINT GetChainSize();
	//���ֵ
	void AddMovAddr(UINT addr);
	//��ӵ�ַ
	void AddLeaAddr(UINT addr);
	//��ײ�ָ���ֵ
	POINTER GetEndValue(UINT baseAddr = 0);
	//��ȡָ������ָ���ֵ,�����󱣴�ֵ���ڣ����ҳ�����󱣴�ֵ�ͻ᷵����ײ�������ֵ�����򷵻� baseAddr
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
	//��ǰm_chain��������mov��ַ
	void AddMovAddr(UINT addr);
	//��ǰm_chain������������lea��ַ
	void AddLeaAddr(UINT addr);
	//��ײ�ָ���ֵ
	POINTER GetEndValue();
	//��ȡ���������У�ָ�������ֵ
	POINTER GetValue(int index);
	//���һ������
	void AddChain(AyaChain *ayaChain);
};

