#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	std::string projectName;
	if (argc > 1) {
		projectName = argv[1];
	} else {
		while (projectName.empty()) {
			system("clear");
			std::cout << "Please enter the name for the project" << '\n';
			std::cin >> projectName;
		}
	}
	std::ofstream CMakeLists("CMakeLists.txt");

	CMakeLists << "cmake_minimum_required(VERSION 3.25)\n\n";

	CMakeLists << "project(" << projectName << " LANGUAGES C CXX)\n\n";

	CMakeLists << "set(CMAKE_CXX_STANDARD 20)\n";
	CMakeLists << "set(CMAKE_CXX_STANDARD_REQUIRED ON)\n";
	CMakeLists << "set(CMAKE_EXPORT_COMPILE_COMMANDS ON)\n\n";

	CMakeLists << "add_executable(${PROJECT_NAME} src/main.cpp)\n\n";

	CMakeLists << "target_include_directories(${PROJECT_NAME} PUBLIC "
				  "\"${CMAKE_CURRENT_SOURCE_DIR}/include\")";

	CMakeLists.close();
	system("mkdir build");
	system("mkdir src");
	system("mkdir include");

	std::ofstream main("src/main.cpp");
	main << "#include <iostream>\n\n";
	main << "int main() {\n"
		 << "int x;\n"
		 << "return 0;\n"
		 << "}";
	main.close();

	std::system("cmake -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON");

	return 0;
}
