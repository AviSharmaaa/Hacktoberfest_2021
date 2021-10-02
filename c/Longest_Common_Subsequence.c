#include <stdio.h>
#include <string.h>

int i, j, first, n, c[20][20];
char a[20], f[20], b[20][20];

void print(int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == 'c')
    {
        print(i - 1, j - 1);
        printf("%c", a[i - 1]);
    }
    else if (b[i][j] == 'u')
        print(i - 1, j);
    else
        print(i, j - 1);
}

void lcs()
{
    first = strlen(a);
    n = strlen(f);
    for (i = 0; i <= first; i++)
        c[i][0] = 0;
    for (i = 0; i <= n; i++)
        c[0][i] = 0;

    for (i = 1; i <= first; i++)
        for (j = 1; j <= n; j++)
        {
            if (a[i - 1] == f[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'c';
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'u';
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'l';
            }
        }
}
int firstain()
{
    printf("Enter the first string:");
    scanf("%s", a);
    printf("Enter the second string:");
    scanf("%s", f);
    printf("\nThe Longest Cofirstfirston Subsequence is: ");
    lcs();
    print(first, n);
    return 0;
}
