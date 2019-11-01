#ifndef READERWRITERMANAGER_H
#define READERWRITERMANAGER_H
#pragma once

#include <string>
#include <exception>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

namespace Game
{
	class ReaderWriterManager
	{
	public:
		static void WriteFile(string filePath, string fileContent);

		static string ReadFile(string filePath);
	private:

	};

}

#endif /* READERWRITERMANAGER_H */

