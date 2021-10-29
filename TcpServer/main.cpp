#include "Server.h"
#include "QueryString.h"




int main() {

	//Server server(8080);
	//server.run();
	QueryString q{};
	char query[] = "a=1&b=2&c=3";
	q.createQueryString(query);
	return 0;
}