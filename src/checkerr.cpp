#include "compailerCarbon.h";

// constructor
Checkerr::Checkerr(string str)
{
	this->str = str;
}

// methods
int Checkerr::standardStructure()
{	
	funcDesignation = "fn Main()";
	pathToCPP = "./out/main.cpp";
	toCompailCPP = "clang++ ./out/main.cpp -o ./out/main.exe";

	int status = 0;

	size_t serc = str.find(funcDesignation);
	if (serc != string::npos)
	{
		fstream CkeckCPP(pathToCPP);
		if (CkeckCPP.is_open())
		{
			while (getline(CkeckCPP, line))
			{
				cout << line << endl;
				ckeckFileCPP = true;
			}

			if (!ckeckFileCPP)
			{
				fstream WriteCPP(pathToCPP);
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
			error("File is not open!");
			status = 1;
		}
		CkeckCPP.close();
		/*system(toCompailCPP);*/
	}
	else
	{
		error("Program entry point missing!");
		status = 1;
	}
	return status;
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