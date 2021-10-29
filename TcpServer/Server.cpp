#include "Server.h"
#include <iostream>


Server::Server(int port) : port(port), webHandler("TcpServer\\public")
{
	listener = {};
	init() != 0 ? exit(1) : void();

}

Server::~Server()
{
	closesocket(listener);
	WSACleanup();

}

void Server::run()
{
	//GET / HTTP/1.1
	std::cout << "Listening on 127.0.0.1:" << port << std::endl;
	while (true)
	{
		sockaddr_in client{};
		int clientSize = sizeof(client);
		SOCKET clientSocket = accept(listener, (sockaddr*)&client, &clientSize);

		char host[NI_MAXHOST];		//client remote name
		char service[NI_MAXHOST];	//service i.e port the client is connect on


		ZeroMemory(host, NI_MAXHOST);
		ZeroMemory(service, NI_MAXHOST);

		if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0) {
			std::cout << host << " connected on port " << service << std::endl;
		}
		else {
			inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
			std::cout << host << " connected on port " << ntohs(client.sin_port) << std::endl;
		}

		ZeroMemory(buf, 4096);
		int bytesReceived = recv(clientSocket, buf, 4096, 0);
		Request req{};
		req.CreateRequest(buf);
		if (bytesReceived > 0) {

			std::cout << buf << std::endl;

			Response resp = webHandler.handleResponse(req);


			std::string stringResp = resp.send();
			int len = stringResp.size();
			send(clientSocket, stringResp.c_str(), len, 0);

		}
		closesocket(clientSocket);



	}
}

int Server::init()
{
	WSADATA wsData{};
	WORD ver = MAKEWORD(2, 2);
	int wsOk = WSAStartup(ver, &wsData);
	if (wsOk != 0)
	{
		std::cout << "Cant initialize win socket!" << std::endl;
		return 1;
	}
	listener = socket(AF_INET, SOCK_STREAM, 0);
	if (listener == INVALID_SOCKET)
	{
		std::cout << "Cant create socket!" << std::endl;
		return 1;
	}
	//bind the ip address
	sockaddr_in hint{};
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	hint.sin_addr.S_un.S_addr = INADDR_ANY;

	bind(listener, (sockaddr*)&hint, sizeof(hint));

	//tell to listening
	listen(listener, SOMAXCONN);

	return 0;
}
