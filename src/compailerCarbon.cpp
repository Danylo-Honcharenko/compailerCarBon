#include "compailerCarbon.h"

int createFolder(const char* nameFolder);

int main()
{
	string paramConsole;
	string line;
	string impWord = "locationFile: ./res/main.carbon";
	string fileExtension = "./res/main.carbon";
	string fileOut = "./out/main.cpp";
	string confFileLocal = "./set/cc.conf";
	string choice;

	bool findWord = false;

	const char* nameFolder1 = "res";
	const char* nameFolder2 = "set";
	const char* nameFolder3 = "out";

	fstream ConfigFile(confFileLocal);

	while (getline(ConfigFile, line))
	{
		// find word
		size_t pos = line.find(impWord);
		// "string::npos" - means the word was not found
		if (pos != string::npos)
		{
			cout << "Welcome to CCPanel\n";
			while (true)
			{
				cout << "[CCPanel]> ";
				cin >> paramConsole;
				panelFu(paramConsole);
			}
			findWord = true;
		}
	}

	ConfigFile.close();

	if (!findWord)
	{
		while (true)
		{
			system("cls");
			cout << "Welcome! Let's do an automatic initial setup.\n";
			cout << "(Yes/No?) ";
			cin >> choice;

			if (choice == "Yes")
			{
				// call the create directory function
				createFolder(nameFolder1);
				createFolder(nameFolder2);
				createFolder(nameFolder3);
				// create files
				fstream CreateConfigFile;
				CreateConfigFile.open(confFileLocal, fstream::out);
				fstream CreateMainFile;
				CreateMainFile.open(fileExtension, fstream::out);
				fstream CreateOutFile;
				CreateOutFile.open(fileOut, fstream::out);

				fstream MyWriteFileMain(fileExtension);

				if (MyWriteFileMain.is_open())
				{
					ofstream MyWriteFileConfig(confFileLocal);
					MyWriteFileConfig << "# path to the file to compile\n";
					MyWriteFileConfig << format("locationFile: {}", fileExtension);
					MyWriteFileConfig.close();

					// create date
					auto createDate = system_clock::now();

					ofstream MyWriteFile(fileExtension);
					MyWriteFile << format("# Created {}", createDate) << endl << endl;
					MyWriteFile << "fn Main() -> i32 {\n";
					MyWriteFile << "\tvar s: auto = \"Hello world!\";\n";
					MyWriteFile << "\tPrint(s);\n";
					MyWriteFile << "\treturn 0;\n";
					MyWriteFile << "}";
					MyWriteFile.close();

					system("cls");
					cout << "Ok!";
					system("pause");

					while (true)
					{
						cout << "[CCPanel]> ";
						cin >> paramConsole;
						panelFu(paramConsole);
					}
				}
				else
				{
					error("File is not found!");
					system("pause");
					system("cls");
				}
				MyWriteFileMain.close();
			}
			else if (choice == "No")
			{
				exit(0);
			}
			else {
				system("cls");
				error("Command not found!");
				system("pause");
			}
		}
	}

	return 0;
}

inline int createFolder(const char* nameFolder)
{
	// create directory
	filesystem::create_directory(nameFolder);
	return 0;
}