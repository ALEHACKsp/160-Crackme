#include <iostream>
#include <windows.h>
using namespace std;

int main(void)
{
	CHAR szName[20] = { 0 };
	cout << "Name:";
	cin >> szName;
	DWORD dwNum = 0x58455443;//����ʵ�������ȫ�ֱ���
	for (int i = 0; i < strlen(szName); i++)//�û���ѭ�����DWORD
	{
		void *p = &szName[i];
		_asm
		{
			mov edi, p;
			mov eax, dword ptr[edi];
			add dwNum, eax;
		}
	}
	//////////////////////////////////////////////////////////////////////////
	DWORD dwPass = 0;
	while (1)
	{
		DWORD temp = (dwNum + dwPass) ^ 0x584554;
		temp -= (WORD)((dwNum + dwPass) >> 0x10);
		if (dwPass % 0x100000 == 0)  //����if�����Բ�Ҫֻ�������������������뻹��������
			cout << dwPass << endl;
		if (temp == 0x585426EB)//�������һ���㷨�õ�����ȷ��opcode
			break;
		dwPass++;
	}
	cout << "Pass:" << dwPass << endl;
	system("pause");
}