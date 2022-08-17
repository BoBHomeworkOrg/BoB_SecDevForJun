#include "pch.h"
const WORD portN = 33481;
SOCKET listenSocket;

struct ST_WSA_INITIALIZER
{
	ST_WSA_INITIALIZER(void)
	{
		WSAData wsaData;
		WSAStartup(MAKEWORD(2, 2), &wsaData);
	}
	~ST_WSA_INITIALIZER(void)
	{
		WSACleanup();
	}
};
static ST_WSA_INITIALIZER g_WsaInitializer;


DWORD WINAPI ThreadServer(void* pContext)
{
	DWORD& dwTaskProcess = *(DWORD*)pContext;
	listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	sockaddr_in service;
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = INADDR_ANY;
	service.sin_port = htons(portN);
	bind(listenSocket, (sockaddr*)&service, sizeof(service));
	listen(listenSocket, 10);

	sockaddr_in remoteinfo = { 0, };
	int nInfoLen = (int)sizeof(remoteinfo);
	SOCKET connectionSock;

	while (INVALID_SOCKET != (connectionSock = accept(listenSocket,
		(sockaddr*)&remoteinfo, &nInfoLen)))
	{
		char sbuf[1500 + 1];
		int nReadSIze = recv(connectionSock, sbuf, 1500, 0);
		sbuf[nReadSIze] = '\0';

		printf("Server recved: %s\n", sbuf);
		send(connectionSock, sbuf, nReadSIze, 0);
		shutdown(connectionSock, SD_BOTH);
		closesocket(connectionSock);
	}

	return 0;
}

DWORD WINAPI ThreadClient(void* pContext)
{
	DWORD& dwTaskProcess = *(DWORD*)pContext;
	SOCKET clientSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	sockaddr_in remote;
	remote.sin_family = AF_INET;
	remote.sin_addr.S_un.S_un_b = {10, 1, 1, 130};
	remote.sin_port = htons(portN);
	if (0 != connect(clientSock, (sockaddr*)&remote, sizeof(remote)))
		return -1;

	const char* Message = "Hello world";
	send(clientSock, Message, strlen(Message), 0);

	char rbuf[100];
	int rReadSIze = recv(clientSock, rbuf, 100, 0);
	rbuf[rReadSIze] = '\0';

	printf("Client recved: %s\n", rbuf);
	closesocket(clientSock);
	return 0;
}

int main(void)
{
	HANDLE hThreadS = CreateThread(nullptr, 0, ThreadServer, nullptr, 0, nullptr);
	HANDLE hThreadC = CreateThread(nullptr, 0, ThreadClient, nullptr, 0, nullptr);
	DWORD dwRetC = WaitForSingleObject(hThreadC, INFINITE);
	closesocket(listenSocket);
	DWORD dwRetS = WaitForSingleObject(hThreadS, INFINITE);

	CloseHandle(hThreadS);
	CloseHandle(hThreadC);
	return 0;
}