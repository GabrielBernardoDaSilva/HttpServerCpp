
#pragma once
#include <WS2tcpip.h>

class Server
{
public:
	Server(int port);
	~Server();

	void run();
private:
	SOCKET listener;
	int init();
	char buf[4096];
	int port;

};

