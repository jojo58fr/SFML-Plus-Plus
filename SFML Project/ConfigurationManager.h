#ifndef CONFIGURATIONMANAGER_H
#define CONFIGURATIONMANAGER_H
#pragma once

#include <map>
#include <string>
#include <exception>
#include <iostream>
#include <fstream>
#include <sstream>

#include "ReaderWriterManager.h"

using namespace std;

namespace Game
{

	class ConfigurationManager
	{
	public:
		map<string, string> configValues;
		string filePath;

		ConfigurationManager(string filePath);

		string GetValue(string key);
		void SetValue(string key, string value);
		bool isKeyExist(string key);
		void SaveFile();

	private:

	};

}

#endif /* CONFIGURATIONMANAGER_H */

