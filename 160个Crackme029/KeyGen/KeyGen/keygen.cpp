#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	char username[20] = { 0 };
	char result[20] = { 0 };
	char key[20] = { 0 };
	printf("�������û��� ����Ϊȫ��д:");

	scanf_s("%s", username, 20);
	int usernameLength = strlen(username);
	if (usernameLength <= 5)
	{
		printf("�û������ȱ������5");
	}
	//�����м���
	for (int i=0;i<usernameLength;i++)
	{
		username[i] ^= i+1;
		result[i] = username[i];
	}

	//���ݽ������ע����

	for (int i = 10; i < usernameLength+10; i++)
	{
		result[i-10] ^= i;
		key[i-10] = result[i-10];
	}

	printf("%s\n", key);
	system("pause");
	return 0;
}