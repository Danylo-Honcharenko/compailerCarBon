#include "compailerCarbon.h"

int panelFu(string paramConsole)
{

	if (paramConsole == "version" || paramConsole == "-v")
	{
		cout << "Version 1.0 / Made by Etherd\n";
	}
	else if (paramConsole == "cls")
	{
		system("cls");
	}
	else if (paramConsole == "compilation" || paramConsole == "-c")
	{
		compile();
	}
	else if (paramConsole == "exit")
	{
		exit(0);
	}
	else
	{
		error("Command not found!");
	}

	return 0;
}