#include <bits/stdc++.h>
using namespace std;

void printParenthesis(int i, int j, int n, int* bracket,
                      char& name)
{
    // If only one matrix left in current segment
    if (i == j) {
        cout << name++;
        return;
    }
 
    cout << "(";
 
    // Recursively put brackets around subexpression
    // from i to bracket[i][j].
    // Note that "*((bracket+i*n)+j)" is similar to
    // bracket[i][j]
    printParenthesis(i, *((bracket + i * n) + j), n,
                     bracket, name);
 
    // Recursively put brackets around subexpression
    // from bracket[i][j] + 1 to j.
    printParenthesis(*((bracket + i * n) + j) + 1, j, n,
                     bracket, name);
    cout << ")";
}
int main()
{
    cout << "Enter number of matrices : ";
    int n,tn;
    cin >> n;
    tn=n+1;
    cout << "Enter P array values :";
    int p[tn];
    for (int i = 0; i < tn; i++)
    {
        cin >> p[i];
    }
    int m[tn][tn], s[tn][tn];
    for (int i = 0; i < tn; i++)
    {
        for (int j = 0; j < tn; j++)
        {
            m[i][j] = 0;
            s[i][j] = 0;
        }
    }

    int j, min, q;
    for (int d = 1; d < tn-1 ; d++)
    {
        for (int i = 1; i < tn-d; i++)
        {
            j = i + d;
            min = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < min)
                {
                    min = q;
                    s[i][j] = k;
                }

                m[i][j] = min;
            }
        }
    }

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << m[i][j] << "\t";
        }
        cout << "\n";
    }

    

    cout<<m[1][n];

    char name = 'A';
 
    cout << "Optimal Parenthesization is : ";
    printParenthesis(1, tn - 1, tn, (int*)s, name);
    cout << "nOptimal Cost is : " << m[1][n - 1];
}