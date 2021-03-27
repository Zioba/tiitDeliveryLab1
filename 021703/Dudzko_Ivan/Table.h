#pragma once
#ifndef _YOUNG_TABLE_INCLUDED_
#define _YOUNG_TABLE_INCLUDED_

//���������, ��������� �� �������� �����������

#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <fstream>

using std::vector;
using std::string;
using std::ofstream;
using std::fstream;
using std::ios;

using std::swap;

using std::cout;
using std::endl;

using std::exception;

template <class T>
class Table
{
public:
	typedef vector<T*> TableRow;

public:
	Table() = default;
	Table(const vector<int>& partitioning);
	~Table();

	bool insert(const T& value);

	void remove(int row, int column);

	void print(const string& fileName);

private:
	void sort(int currentRow, int currentColumn);

	void clear();

private:
	TableRow* data;
	vector<int> tablePartitioning;
};





template<class T>
inline Table<T>::Table(const vector<int>& partitioning)
{
	for (int i = 1; i < partitioning.size(); i++)
	{
		if (partitioning[i] > partitioning[i - 1])
		{
			//throw exception("Exception: partitioning is uncorrect!");
		}
	}

	tablePartitioning = partitioning;

	data = new TableRow[tablePartitioning.size()];
	for (int i = 0; i < tablePartitioning.size(); i++)
	{
		data[i].resize(tablePartitioning[i]);
		for (auto& el : data[i])
			el = nullptr;
	}
}

template<class T>
inline Table<T>::~Table()
{
	clear();
}

template<class T>
inline bool Table<T>::insert(const T & value)
{
	for (int i = 0; i < tablePartitioning.size(); i++)
	{
		for (int j = 0; j < tablePartitioning[i]; j++)
		{
			if (data[i][j] == nullptr)
			{
				data[i][j] = new T;
				*data[i][j] = value;
				sort(i, j);

				return true;
			}
		}
	}

	return false;
}

template<class T>
inline void Table<T>::remove(int row, int column)
{
	row--;
	column--;

	vector<T> tableValues;
	for (int i = 0; i < tablePartitioning.size(); i++)
	{
		for (int j = 0; j < tablePartitioning[i]; j++)
		{
			if (data[i][j] != nullptr && !(i == row && j == column))
			{
				tableValues.emplace_back(*data[i][j]);
			}
		}
	}

	clear();

	for (auto& value : tableValues)
		insert(value);
}

template<class T>
inline void Table<T>::sort(int currentRow, int currentColumn)
{
	int leftIndex = currentColumn - 1,
		topIndex  = currentRow - 1;

	const int REPLACE_NONE = 0;
	const int REPLACE_LEFT = 1;
	const int REPLACE_TOP = 2;

	int finalReplace = REPLACE_NONE;

	auto currentValue = *data[currentRow][currentColumn];
	if (leftIndex >= 0 || topIndex >= 0)
	{
		//���� �� �� � ����� ������� ����

		T leftValue, topValue;

		if (leftIndex >= 0)
			leftValue = *data[currentRow][leftIndex];
		if (topIndex >= 0)
			topValue = *data[topIndex][currentColumn];

		if (leftIndex >= 0 && topIndex >= 0)
		{
			//���� ���������� �������� � ����� � ������

			if (currentValue > leftValue && currentValue > topValue)
			{
				finalReplace = topValue < leftValue ? REPLACE_TOP : REPLACE_LEFT;
			}
			else if (currentValue > leftValue)
			{
				finalReplace = REPLACE_LEFT;
			}
			else if (currentValue > topValue)
			{
				finalReplace = REPLACE_TOP;
			}
		}
		else if (leftIndex >= 0 && currentValue > leftValue)
		{
			//���� ���� ������ ������� ����� � �� ������ ��������
			finalReplace = REPLACE_LEFT;
		}
		else if (topIndex >= 0 && currentValue > topValue)
		{
			//���� ���� ������ ������� ������ � �� ������ ��������
			finalReplace = REPLACE_TOP;
		}


		if (finalReplace != REPLACE_NONE)
		{
			if (finalReplace == REPLACE_LEFT)
			{
				swap(*data[currentRow][currentColumn], *data[currentRow][leftIndex]);
				sort(currentRow, leftIndex);
			}
			if (finalReplace == REPLACE_TOP)
			{
				swap(*data[currentRow][currentColumn], *data[topIndex][currentColumn]);
				sort(topIndex, currentColumn);
			}
		}
	}

#ifdef DEBUG
	switch (finalReplace)
	{
	case REPLACE_NONE:
		cout << "REPLACE_NONE\n";
		break;

	case REPLACE_LEFT:
		cout << "REPLACE_LEFT\n";
		break;

	case REPLACE_TOP:
		cout << "REPLACE_TOP\n";
		break;
	}
#endif

}

template<class T>
inline void Table<T>::clear()
{
	//Erase Table;
	for (int i = 0; i < tablePartitioning.size(); i++)
	{
		for (int j = 0; j < tablePartitioning[i]; j++)
		{
			if (data[i][j] != nullptr)
			{
				delete data[i][j];
				data[i][j] = nullptr;
			}
		}
	}
}

template<class T>
inline void Table<T>::print(const string& fileName)
{
	fstream fs(fileName, ios::out);
	if (!fs.is_open())
	{
		//throw exception("Cannot open print file!");
	}
	for (int i = 0; i < tablePartitioning.size(); i++)
	{
		bool flag = false;
		for(int j = 0; j < tablePartitioning[i]; j++)
		{
			if (data[i][j] != nullptr)
			{
				fs << *data[i][j] << "\t";
				flag = true;
			}
		}

		if (!flag)
			break;

		fs << endl;
	}
	fs.close();
}


#endif