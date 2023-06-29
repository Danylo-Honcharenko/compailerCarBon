#include "compailerCarbon.h"

int compile()
{
	string lineCompailFile;
	string line;
	string impWord = "locationFile: ./res/main.carbon";
	string confFileLocal = "./set/cc.conf";

	bool ckeckLetters = false;
	string str;

	fstream ConfigFile(confFileLocal);

	if (ConfigFile.is_open())
	{
		while (getline(ConfigFile, line))
		{
			// looking for the main lines in the configuration file
			size_t pos = line.find(impWord);
			if (pos != string::npos)
			{
				// reverse the found string
				rotate(line.begin(), line.begin() + 14, line.end());
				// remove unwanted part of inverted word
				line.erase(line.end() - 14, line.end());
				// now in the line variable we store the path to the file
				fstream CompFile(line);
				if (CompFile.is_open())
				{
					while (getline(CompFile, lineCompailFile))
					{
						str += lineCompailFile;
						ckeckLetters = true;
					}
					// check if there is an entry in the compiled file
					if (!ckeckLetters)
					{
						error("File is empty, compilation of an empty file is not possible");
					}
				}
				else
				{
					error("File is not found! Check the path to the compiled file in the configuration file");
				}
				CompFile.close();
			}
		}
	}
	else
	{
		error("File is not open!");
	}

	ConfigFile.close();

	Checkerr checkerr(str);
	// call methods for check code
	if (checkerr.standardStructure() == 1)
	{
		cout << "Status: \"standardStructure\" error! 1" << endl;
	}
	checkerr.packages();
	checkerr.variables();
	checkerr.functions();
	// --------------------------

	return 0;
}