#include "pch.h"

#include <iostream>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>

#include "SufLibrary.h"
using namespace std;



struct suffix
{
    int index;
    char* suff;
};

int cmp(struct suffix a, struct suffix b)

{
    return strcmp(a.suff, b.suff) < 0 ? 1 : 0;
}

int* buildSuffixArray(char* txt, int n)
{

    struct suffix suffixes[100];

    for (int i = 0; i < n; i++)

    {

        suffixes[i].index = i;

        suffixes[i].suff = (txt + i);

    }

    sort(suffixes, suffixes + n, cmp);

    int* suffixArr = new int[n];

    for (int i = 0; i < n; i++)

        suffixArr[i] = suffixes[i].index;

    return  suffixArr;
}

void printArr(int arr[], int n)

{

    for (int i = 0; i < n; i++)

        cout << arr[i] << " ";

    cout << endl;

}

void SufAr(char* txt)
{
    int n = strlen(txt);

    int* suffixArr = buildSuffixArray(txt, n);

    printArr(suffixArr, n);

}


string LCSubStr(string X, string Y)
{
    int m = X.length();
    int n = Y.length();
    int result = 0;
    int end;
    int len[2][50];
    int currRow = 0;

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                len[currRow][j] = 0;
            }
            else if (X[i - 1] == Y[j - 1]) {
                len[currRow][j] = len[1 - currRow][j - 1] + 1;
                if (len[currRow][j] > result) {
                    result = len[currRow][j];
                    end = i - 1;
                }
            }
            else {
                len[currRow][j] = 0;
            }
        }
        currRow = 1 - currRow;
    }

    if (result == 0) {
        return "-1";
    }

    return X.substr(end - result + 1, result);
}


void LCP(char* X, char* Y)
{
    LCSubStr(X, Y);
    cout << LCSubStr(X, Y);

}


string min_cyclic_shift(string s)
{
    s += s;
    int n = (int)s.length();
    int i = 0, ans = 0;
    while (i < n / 2)
    {
        ans = i;
        int j = i + 1, k = i;
        while (j < n && s[k] <= s[j])
        {
            if (s[k] < s[j])
                k = i;
            else
                ++k;
            ++j;
        }
        while (i <= k)  i += j - k;
    }
    return s.substr(ans, n / 2);
}

void MCS(char* a)
{
    min_cyclic_shift(a);
    cout << min_cyclic_shift(a);
}



