#include "Test.h"

constexpr unsigned int ARGV_TEST_FOLDER_INDEX = 1;

int main(int argc, char const **argv)
{
	if (argc < 2)
		return -1;

	RunTest(argv[ARGV_TEST_FOLDER_INDEX]);

	/*Table<int> table({2, 2});
	table.insert(2);
	table.insert(1);
	table.insert(1);
	table.insert(1);

	table.insert(100);

	table.print("1.txt");*/

	/*table.remove(1, 1);

	table.print();*/

	return 0;
}