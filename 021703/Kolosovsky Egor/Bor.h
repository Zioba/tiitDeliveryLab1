#pragma once

#include <string>

const int ALPHABET_SIZE = 26;

struct vertex
{
	vertex* next[ALPHABET_SIZE];
	int strings_amount;

	vertex();
};

void add_string(std::string&, vertex*);

void delete_string(std::string&, vertex*);

bool has_a_string(std::string&, vertex*);

void output_all_strings(vertex*);

void clear_output();