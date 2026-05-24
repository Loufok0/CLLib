#include "CLLib.hpp"

int welcome()
{
	std::cout << "======================================" << std::endl;
	std::cout << "|     !!! Welcome to my prog !!!     |" << std::endl;
	std::cout << "|                                    |" << std::endl;
	std::cout << "| Type h to show the help page       |" << std::endl;
	std::cout << "======================================" << std::endl;
	return (1);
}

int say_hello()
{
	std::cout << "======================================" << std::endl;
	std::cout << "|    helloooooooooooooooooooooooo    |" << std::endl;
	std::cout << "======================================" << std::endl;
	return (1);
}



int main(int ac, char **av)
{


	CLI C;
	C.addCommand("w", welcome);
	C.addCommand("sh", say_hello);
	// C.addDescription(*(new std::string("a")), "Welcome users!");// leaks
	C.addDescription("w", "Welcome users!");
	C.addDescription("sh", "say hello!");
	C.help();

	while (true)
	{
		int ret = C.readCommand(">>> ");
		if (!ret || ret == QUIT)
			break;
	}

	return (0);
	(void)ac;
	(void)av;
}

