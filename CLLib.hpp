#pragma once

//====================(INCLUDES)============================//

#include "colors.hpp"
#include <signal.h>
#include <iostream>
#include <string>
#include <map>
#include <functional>

//====================(DEFINES)=============================//

#define QUIT 2
#define SUCCESS 1
#define FAIL 0
#define ALREADY_EXIST -1
#define COMMAND_DOES_NOT_EXIST -2

//====================(STRUCTS)=============================//

//====================(DECLARATIONS)========================//

class CLI
{
	private:
		size_t _maxCommandLen;
		std::map<std::string, std::function<int()>> _functions;
		std::map<std::string, std::string> _descriptions;

	public:
		CLI();
		CLI(const CLI &other);
		CLI& operator =(const CLI &other);
		~CLI();

		int		help();
		int		addCommand(std::string command, std::function<int()> function);
		int		addDescription(std::string command, std::string desc);
		void	printInfo(std::string str, size_t len, size_t command_len);
		void	printInfo(std::string command, std::string desc, size_t total_width);
		int		readCommand(std::string prompt);

};

