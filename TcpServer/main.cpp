#pragma once
#include "Server.h"
#include "Request.h"





int main() {
	//GET / index HTTP / 1.1
	//Server server(8080);
	//server.run();
	Request request;
	request.CreateRequest("GET /index?a=1 HTTP/1.1\r\n\r\n");
	return 0;
}