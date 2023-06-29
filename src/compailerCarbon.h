#pragma once

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <chrono>
#include <lib/fmt/include/fmt/format.h>

using namespace std;
using namespace chrono;

int panelFu(string paramConsole);
int compile();
void error(string errorText);

class Checkerr 
{
protected:
	string str;
	string funcDesignation;
	string pathToCPP;
	string line;
	bool ckeckFileCPP = false;

	const char* toCompailCPP;

public:
	Checkerr(string str);
	// methods prototypes 
	int standardStructure();
	int packages();
	int variables();
	int functions();
};

