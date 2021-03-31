#include "BIBLIO.h"

using namespace std;
// Driver program 
int main()
{
	string str;
	cin >> str;

	vector<int>suffixArr = buildSuffixArray(str, str.length());
	int n = suffixArr.size();
	int i = 0, j = 0, k = 0;
	cout << "Suffix Array : \n";
	for (i; i<str.length(); i++)
	{
		cout << suffixArr[i];
	}
	
	vector<int>lcp = kasai(str, suffixArr);

	cout << "\nLCP Array : \n";
	for (j; j < str.length(); j++)
	{
		cout << lcp[j];
	}
	cout <<endl <<  minLexRotation(str) << endl;
}