#include <fstream>
#include <filesystem>
#include <Shlwapi.h>
#include <sstream>

#include "WebHandler.h"
#include "Method.h"
#include "StatusCode.h"




WebHandler::~WebHandler()
{

}

WebHandler::WebHandler(const char* path) :physicalFilesPath(path)
{

}

Response WebHandler::handleResponse(const Request& req)
{

	if (req.getMethod() == Method::GET)
	{
		if (req.getPath() == "/")
			return Response(StatusCode::Ok, readFile("index.html"));
		else if (req.getPath() == "/hello")
			return Response(StatusCode::Ok, "<h1>Hello Hello Page</h1>");
		else if (req.getPath().find(".css") != std::string::npos)
			return Response(StatusCode::Ok, readFile(req.getPath()));
		else
			return Response(StatusCode::NotFound, "");
	}
	else
		return Response(StatusCode::NotFound, "");

}


std::string WebHandler::readFile(std::string filePath)
{
	std::ostringstream oss{};
	oss << SOLUTION_DIR;
	oss << this->physicalFilesPath;
	oss << "\\";
	oss << filePath;
	std::string a;
	//D:\Programs\Cpp\HttpServerCpp\TcpServer\public\index.html
	const std::filesystem::path absPath = oss.str();
	if (absPath.string().find(SOLUTION_DIR) != std::string::npos) {
		std::ifstream file(absPath.string());
		if (file)
		{
			char testByteOrderMark[4] = { 0 };
			std::stringstream buffer{};
			buffer << file.rdbuf();
			buffer.read(testByteOrderMark, 3);
			
			file.close();
			auto strCheck = buffer.str();
			if (strcmp(testByteOrderMark, "\xEF\xBB\xBF") == 0)
				return strCheck.substr(3, strCheck.size());
			else
				return strCheck;

		}
		else {
			return "";
		}
	}

	return "";
}
