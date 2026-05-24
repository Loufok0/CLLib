#include "CLLib.hpp"

CLI::CLI()
{
	_maxCommandLen = 0;
}

CLI::CLI(const CLI &other)
{
	_functions = other._functions;
	_descriptions = other._descriptions;
	_maxCommandLen = other._maxCommandLen;
}

CLI& CLI::operator =(const CLI &other)
{
	_functions = other._functions;
	_descriptions = other._descriptions;
	_maxCommandLen = other._maxCommandLen;
	return (*this);
}

CLI::~CLI()
{
	_descriptions.clear();
	_functions.clear();
}

int CLI::help()
{
	std::cout << "====================================================================================================" << std::endl;
	std::cout << "| Help page:                                                                                       |" << std::endl;
	std::cout << "|                                                                                                  |" << std::endl;
	std::cout << "| Type h to show this page                                                                         |" << std::endl;
	std::cout << "|                                                                                                  |" << std::endl;

	for (auto it = _descriptions.begin(); it != _descriptions.end(); ++it)
	{
		printInfo(it->first, it->second, 100);
	}

	std::cout << "|                                                                                                  |" << std::endl;
	std::cout << "====================================================================================================" << std::endl;
	return (SUCCESS);
}

void CLI::printInfo(std::string command, std::string desc, size_t total_width)
{
	size_t command_len = command.size();

	size_t available = total_width - command_len - 6;

	size_t i = 0;
	bool first_line = true;

	while (i < desc.size())
	{
		if (first_line)
		{
			std::cout << "| " << command << ": ";
			first_line = false;
		}
		else
		{
			std::cout << "| ";

			for (size_t j = 0; j < command_len - 2; ++j)
				std::cout << ' ';
		}

		size_t count = 0;

		while (i < desc.size() && count < available)
		{
			std::cout << desc[i];
			++i;
			++count;
		}

		while (count < available)
		{
			std::cout << ' ';
			++count;
		}

		std::cout << " |" << std::endl;
	}

	if (desc.empty())
	{
		std::cout << command;

		for (size_t j = 0; j < available; ++j)
			std::cout << ' ';

		std::cout << " |" << std::endl;
	}
}

int CLI::addCommand(std::string command, std::function<int()> function)
{
	if (_functions.find(command) != _functions.end())
		return (ALREADY_EXIST);

	if (command.size() > _maxCommandLen)
		_maxCommandLen = command.size();
	_functions.insert({command, function});
	return (SUCCESS);
}

int CLI::addDescription(std::string command, std::string desc)
{
	if (_functions.find(command) == _functions.end())
		return (COMMAND_DOES_NOT_EXIST);
	if (_descriptions.find(command) != _descriptions.end())
		return (ALREADY_EXIST);

	_descriptions.insert({command, desc});
	return (SUCCESS);
}

void	sa(int sig)
{
	(void)sig;
	std::cout << std::endl << "To quit, just type 'q' and enter" << std::endl;
}

int CLI::readCommand(std::string prompt)
{
	signal(SIGINT, sa);
	signal(SIGQUIT, sa);
	signal(SIGPIPE, sa);
	

	std::string input;
	
	std::cout << prompt;
	
	if (!std::getline(std::cin, input))
		return (FAIL);
	
	if (input.empty())
		return (SUCCESS);
	
	std::map<std::string,
		std::function<int()>>::iterator it;
	
	it = _functions.find(input);
	
	if (it == _functions.end())
	{
		if (input == "h")
			return (help());
		if (input == "q")
			return (QUIT);
		std::cout << "Unknown command: " << input << std::endl;
		return (COMMAND_DOES_NOT_EXIST);
	}
	
	return (it->second());
}

