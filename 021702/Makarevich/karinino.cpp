#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

using namespace std;

int main()
{
    FILE* fp;
    fp = fopen("input.txt", "r");
    int n;
    fscanf(fp, "%d", &n);
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &(a[i]));
    }
    Tree bereza(a, n);
    bereza.build_tree(1, 0, n - 1);
    int type, x, l, r;
    fscanf(fp, "%d%d", &l, &r);
        fscanf(fp, "%d", &type);
        if (type == 1)
        {
            fp = fopen("D:/tiit/karinino\)/output.txt", "w");
            int sum = bereza.query_tree(1, 0, n - 1, l, r);
            if (sum == 6) printf("Test passed!\n");
            else printf("Test failed!\n");
            fprintf(fp, "%d", sum);
        }
        else if (type == 2)
        {
            fscanf(fp, "%d", &x);
            fp = fopen("D:/tiit/karinino\)/output.txt", "w");
            bereza.update_tree(1, 0, n - 1, l, r, x);
            fprintf (fp, " CHANGE completed ");
        }
    delete[]a;
    fclose(fp);
    return 0;
}
