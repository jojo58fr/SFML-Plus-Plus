#include "ConfigurationManager.h"

namespace Game
{

	ConfigurationManager::ConfigurationManager(string filePath)
	{
		this->filePath = filePath;

		//Read configuration file
		stringstream contents;
		contents << ReaderWriterManager::ReadFile(this->filePath);

		//Read Key/Value of a config file
		string line;
		while (getline(contents, line))
		{
			istringstream is_line(line);
			string key;


			if (getline(contents, key, '='))
			{
				string value;
				if (getline(contents, value))
				{
					//cout << key + " | " + value;

					size_t found = value.find("\"");

					if (found != std::string::npos)
					{
						value = value.substr(1, value.size() - 2);
					}

					configValues.insert({ key, value });
				}
			}
		}



	}

	string ConfigurationManager::GetValue(string key)
	{
		return configValues.at(key);
	}

	void ConfigurationManager::SetValue(string key, string value)
	{
		int sizeMap = (int)configValues.size();

		configValues.insert({ key, value });

		if (sizeMap == configValues.size())
		{
			configValues[key] = value;
		}
	}

	void ConfigurationManager::SaveFile()
	{
		string parsingText = "";

		for (map<string, string>::iterator it = configValues.begin(); it != configValues.end(); ++it)
		{
			parsingText += it->first + " = " + it->second;

			if (it != configValues.end())
			{
				parsingText += "\n";
			}

		}

		ReaderWriterManager::WriteFile(this->filePath, parsingText);
	}

	bool ConfigurationManager::isKeyExist(string key)
	{
		bool result = false;

		if (configValues.find(key) == configValues.end()) {
			result = true;
		}

		return result;
	}

}
