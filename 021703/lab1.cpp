#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include "quadtree.h"

using namespace std;

derevo a;
matr b;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int Number;
    cin >> Number;

    if (Number == 1)
    {
        cin >> b.n;
        int x = b.n;

        for (int i = 1; i <= b.n; i++)
            for (int j = 1; j <= b.n; j++)
                cin >> b.y[i][j];



        a = tree(b);

        cout << a.k << endl;
        for (int i = 0; i <= a.k; i++)
            for (int j = 0; j < a.x[i].size(); j++)
                cout << i << " " << a.x[i][j] << " " << a.c[i][j] << endl;
    }
    else
    {
        int m;
        cin >> a.n >> a.k;

        for (int i = 0; i < a.k; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            a.x[x].push_back(y);
            a.c[x].push_back(z);
        }

        b = matrica(a);

        for (int i = 1; i <= b.n; i++)
        {
            for (int j = 1; j <= b.n; j++)
                cout << b.y[i][j] << " ";
            cout << "\n";
        }

    }

    return 0;
}
