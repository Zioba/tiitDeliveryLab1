#pragma once
#ifndef _TESTS_INCLUDED_
#define _TESTS_INCLUDED_

#include <iostream>
#include <fstream>

#include "Table.h"
#include "StringHelp.h"

using std::vector;
using std::string;
using std::ofstream;
using std::ifstream;
using std::ios;

struct Operation
{
	string action;
	vector<string> args;
};

inline void GlobalError(const string& message)
{
	//Platform MessageBox
	exit(-1);
}

inline void RunTest(const string& currentFolder)
{
	ifstream input_fs(currentFolder + "/input.txt");
	if (!input_fs.is_open())
	{
		GlobalError("input_fs is not opened!");
	}

	enum InputMode
	{
		INPUT_MODE_UNKNOWN,
		INPUT_SIZE,
		INPUT_DATA,
		INPUT_OPERATION
	};

	try
	{
		string temp;
		InputMode mode = INPUT_MODE_UNKNOWN;
		vector<int> tableSize;
		Table<int> table;
		Operation operation;


		while (input_fs >> temp)
		{
			if (temp == "Size:")
			{
				mode = INPUT_SIZE;
				continue;
			}
			else if (temp == "Data:")
			{
				//Now we know size
				mode = INPUT_DATA;
				table = Table<int>(tableSize);
				continue;
			}
			else if (temp == "Operation:")
			{
				mode = INPUT_OPERATION;
				continue;
			}

			switch (mode)
			{
			case INPUT_SIZE:
				tableSize.emplace_back(atoi(temp.c_str()));
				break;

			case INPUT_DATA:
				table.insert(atoi(temp.c_str()));
				break;

			case INPUT_OPERATION:
				if (operation.action.empty())
				{
					operation.action = temp;
				}
				else
				{
					operation.args.emplace_back(temp);
				}
				break;

			    default:
				//throw exception("Unknown input data type!");
				break;
			}
		}

		//Execute action
		if (operation.action == "insert" || operation.action == "error_insert")
		{
			for (auto& item : operation.args)
			{
				table.insert(atoi(item.c_str()));
			}
		}
		else if (operation.action == "remove" || operation.action == "error_remove")
		{
			table.remove(ToInt(operation.args.front()), ToInt(operation.args.back()));
		}

		//Print output
		table.print(currentFolder + "/output.txt");

	}
	catch (const std::exception& ex)
	{
		GlobalError(ex.what());
	}
}

#endif