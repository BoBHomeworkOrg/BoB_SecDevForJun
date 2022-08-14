#include <Windows.h>
#include <stdio.h>

void PrintOutBinary(unsigned char cByte)
{
	for (int i = 7; 0 <= i; i--)
		printf("%c", (cByte >> i) & 0b000000001? '1' : '0');
}

void Query(int nVirtKey)
{
	unsigned short nState = GetKeyState(nVirtKey);
	PrintOutBinary(nState >> 8);
	printf(" ");
	PrintOutBinary(nState & 0xFF);
	printf("\n");

}

int main()
{
	while (true)
	{
		Sleep(50);
		Query('A');
	}
	return 0;
}
}