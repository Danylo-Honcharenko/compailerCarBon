#include "compailerCarbon.h"

// constructor
Checkerr::Checkerr(string programSourceCode)
{
	this->programSourceCode = programSourceCode;
}

// methods
int Checkerr::standardStructure()
{	
	funcDesignation = "fn Main()";
	pathToOutFile = "./out/main.cpp";
	toCompailCPP = "clang++ ./out/main.cpp -o ./out/main.exe";

	size_t serc = programSourceCode.find(funcDesignation);
	if (serc != string::npos)
	{
		fstream CkeckCPP(pathToOutFile);
		if (CkeckCPP.is_open())
		{
			while (getline(CkeckCPP, line))
			{
				cout << line << endl;
				ckeckFileCPP = true;
			}

			if (!ckeckFileCPP)
			{
				fstream WriteCPP(pathToOutFile);
				WriteCPP << "#include <iostream>\n\n";
				WriteCPP << "int main() {\n";
				WriteCPP << "\tauto s = \"Hello world!\";\n";
				WriteCPP << "\tstd::cout << s << std::endl;\n";
				WriteCPP << "\treturn 0;\n";
				WriteCPP << "}\n";
				WriteCPP.close();
			}
		}
		else
		{
			throw "File is not open";
		}
		CkeckCPP.close();
	}
	else
	{
		throw "Program entry point missing";
	}
	return 0;
}

int Checkerr::packages()
{
	// packages
	return 0;
}

int Checkerr::variables()
{
	// variables
	return 0;
}

int Checkerr::functions()
{
	// functions
	return 0;
}