#include "Bor.h"
#include <string>
#include <iostream>

vertex::vertex()
{
	for (int i = 0; i < ALPHABET_SIZE; ++i)
	{
		next[i] = nullptr;
	}
	strings_amount = 0;
}

void add_string(std::string& line, vertex* root)
{
	vertex* current = root;
	int n = line.length();
	for (int i = 0; i < n; ++i)
	{
		int symbol = line[i] - 'a';
		if (current->next[symbol] == nullptr)
		{
			current->next[symbol] = new vertex();
		}
		current = current->next[symbol];
	}
	current->strings_amount++;

}

void delete_string(std::string& line, vertex* root)
{
	vertex* current = root;
	int n = line.length();
	for (int i = 0; i < n; ++i)
	{
		current = current->next[line[i] - 'a'];
		if (current == nullptr)
		{
			return;
		}
	}
	current->strings_amount--;
}

bool has_a_string(std::string& line, vertex* root)
{
	vertex* current = root;
	int n = line.length();
	for (int i = 0; i < n; ++i)
	{
		current = current->next[line[i] - 'a'];
		if (current == nullptr)
		{
			return false;
		}
	}
	return current->strings_amount > 0;
}

std::string output = "";

void output_all_strings(vertex* current)
{
	for (int i = 0; i < current->strings_amount; ++i)
	{
		std::cout << output << "\n";
	}
	for (int i = 0; i < ALPHABET_SIZE; ++i)
	{
		if (current->next[i] != nullptr)
		{
			output.push_back('a' + i);
			output_all_strings(current->next[i]);
			output.pop_back();
		}
	}
}

void clear_output()
{
	output = "";
}