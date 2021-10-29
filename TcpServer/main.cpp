#pragma once
#include "Server.h"

int main() {
	//GET / index HTTP / 1.1
	Server server(8080);
	server.run();
	return 0;
}