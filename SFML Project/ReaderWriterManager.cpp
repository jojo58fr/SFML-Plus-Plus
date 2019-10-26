#include "ReaderWriterManager.h"

namespace Game
{
	void ReaderWriterManager::WriteFile(string filePath, string fileContent)
	{
		try
		{
			// Will hold file contents.
			stringstream contents;

			// Open the file for the shortest time possible.
			{
				ofstream file(filePath);

				// Make sure we have something to read.
				if (!file.is_open()) {
					throw (exception("Could not open file."));
				}

				file << fileContent;

				file.close();
			}
		}
		catch (const exception & error)
		{
			cerr << error.what() << endl;
		}
	}

	string ReaderWriterManager::ReadFile(string filePath)
	{
		string result = "";

		try
		{
			// Will hold file contents.
			stringstream contents;

			// Open the file for the shortest time possible.
			{
				ifstream file(filePath);

				// Make sure we have something to read.
				if (!file.is_open()) {
					throw (exception("Could not open file."));
				}

				// Copy contents "as efficiently as possible".
				contents << file.rdbuf();

				file.close();
			}

			result = contents.str();
		}
		catch (const exception & error)
		{
			cerr << error.what() << endl;
		}

		return result;
	}
}

