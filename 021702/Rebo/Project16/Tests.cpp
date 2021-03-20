#include"../Project16/DEC.h"
bool test1(deque expected)
{
	deque result;
	result.dt = 0;
	result = push_back(result, 1);
	result = push_back(result, 2);
	return compare(expected, result);
}

bool test2(deque expected)
{
	deque result;
	result.dt = 0;
	result = push_back(result, 1);
	result = push_back(result, 2);
	result = push_back(result, 3);
	pop_front(&result);
	return compare(expected, result);
}

bool test3(deque expected)
{
	deque result;
	result.dt = 0;
	result = push_back(result, 2);
	result = push_back(result, 4);
	pop_front(&result);
	result = push_back(result, 3);
	return compare(expected, result);
}

bool test4(deque expected)
{
	deque result;
	result.dt = 0;
	result = push_back(result, 1);
	result = push_back(result, 4);
	pop_back(&result);
	return compare(expected, result);
}

bool test5(deque expected)
{
	deque result;
	result.dt = 0;
	pop_back(&result);
	return compare(expected, result);
}
bool test6(deque expected)
{
	deque result;
	result.dt = 0;
	int vals[20] = { 5, 5, 2, 1, 7, 2, 7, -8, 6, 1, 6, 9, -1, -2, 0, 5, 7, 1, -5, -8 };
	for (int curr = 0; curr < 20; curr++) result = push_front(result, vals[curr]);
	result = push_back(result, 5);
	result = push_front(result, -1);
	return compare(expected, result);
}
bool test7(deque expected)
{
	deque result;
	result.dt = 0;
	result = push_front(result, 5);
	result = push_front(result, 2);
	result = push_front(result, 1);
	return compare(expected, result);
}
bool test8(deque expected)
{
	deque result;
	result.dt = 0;
	result = push_front(result, 5);
	result = push_front(result, 7);
	result = push_back(result, 3);
	pop_back(&result);
	return compare(expected, result);
}
bool test9(deque expected)
{
	deque result;
	result.dt = 0;
	result = push_back(result, 5);
	result = push_front(result, 6);
	result = push_back(result, 7);
	result = push_front(result, 3);
	result = push_back(result, 6);
	return compare(expected, result);
}
bool test10(deque expected)
{
	deque result;
	result.dt = 0;
	result = push_back(result, 5);
	result = push_back(result, 6);
	result = push_back(result, 7);
	pop_front(&result);
	pop_front(&result);
	pop_front(&result);

	return compare(expected, result);
}
bool test11(deque expected)
{
	deque result;
	result.dt = 0;
	result = push_back(result, 5);
	result = push_back(result, 7);
	result = push_back(result, 6);
	pop_front(&result);
	return compare(expected, result);
}
int main()
{
	deque expected;
	cout << "Test 1 " << endl;
	cout << "Expected result: 1 2 " << endl;
	expected.dt = 2;
	expected.val[0] = 1;
	expected.val[1] = 2;
	cout << test1(expected) << " -Test passed! " << endl;


	cout << "\nTest 2: " << endl;
	cout << "Expected result: 2 3 " << endl;
	expected.dt = 2;
	expected.val[0] = 2;
	expected.val[1] = 3;
	cout << test2(expected) << " -Test passed! " << endl;


	cout << "\nTest 3: " << endl;
	cout << "Expected result: 4 3 " << endl;
	expected.dt = 2;
	expected.val[0] = 4;
	expected.val[1] = 3;
	cout << test3(expected) << " -Test passed! " << endl;


	cout << "\nTest 4: " << endl;
	cout << "Expected result: 1 " << endl;
	expected.dt = 1;
	expected.val[0] = 1;
	cout << test4(expected) << " -Test passed! " << endl;

	cout << "\nTest 5: " << endl;
	expected.dt = 0;
	cout << "Expected: empty" << endl;
	cout << test5(expected) << " -Test passed! " << endl;

	cout << "\nTest 6: " << endl;
	expected.dt = 0;
	int vals[20] = { 5, 5, 2, 1, 7, 2, 7, -8, 6, 1, 6, 9, -1, -2, 0, 5, 7, 1, -5, -8 };
	for (int curr = 0; curr < 20; curr++) expected = push_front(expected, vals[curr]);
	cout << "Error, my deque is empty!" << endl;
	cout << test6(expected) << " -Test passed! " << endl;


	cout << "\nTest 7: " << endl;
	cout << "Expected result: 1 2 5 " << endl;
	expected.dt = 3;
	expected.val[0] = 1;
	expected.val[1] = 2;
	expected.val[2] = 5;
	cout << test7(expected) << " -Test passed! " << endl;

	cout << "\nTest 8: " << endl;
	cout << "Expected result: 5 3 " << endl;
	expected.dt = 2;
	expected.val[0] = 7;
	expected.val[1] = 5;
	cout << test8(expected) << " -Test passed! " << endl;

	cout << "\nTest 9: " << endl;
	cout << "Expected result: 3 6 5 7 6 " << endl;
	expected.dt = 5;
	expected.val[0] = 3;
	expected.val[1] = 6;
	expected.val[2] = 5;
	expected.val[3] = 7;
	expected.val[4] = 6;

	cout << test9(expected) << " -Test passed! " << endl;

	cout << "\nTest 10: " << endl;
	cout << "Expected result: My deque is empty " << endl;
	expected.dt = 0;
	cout << test10(expected) << "-Test passed! " << endl;

	cout << "\nTest 11: " << endl;
	cout << "Expected result: 7 6 " << endl;
	expected.dt = 2;
	expected.val[0] = 7;
	expected.val[1] = 6;
	cout << test11(expected) << " -Test passed! " << endl;


	return 0;


}