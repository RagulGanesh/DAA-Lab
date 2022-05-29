#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, j, min, d, i, k, qq;
    cout << "Enter number of keys : ";
    cin >> n;
    int tn = n + 1;
    int p[tn], q[tn];
    cout << "Enter P array values : ";
    p[0] = 0;
    for (int i = 1; i < tn; i++)
    {
        cin >> p[i];
    }
    cout << "Enter Q array values : ";
    for (int i = 0; i < tn; i++)
    {
        cin >> q[i];
    }
    int w[tn][tn], c[tn][tn], r[tn][tn];
    for (int i = 0; i < tn; i++)
    {
        for (int j = 0; j < tn; j++)
        {
            w[i][j] = 0;
            c[i][j] = 0;
            r[i][j] = 0;
        }
    }
    for (d = 0; d < tn; d++)
    {
        for (i = 0; i < tn - d; i++)
        {
            j = i + d;
            if (i == j)
            {
                w[i][i] = q[i];
                c[i][i] = 0;
                r[i][i] = 0;
            }
            else
            {
                min = INT_MAX;
                w[i][j] = p[j] + q[j] + w[i][j - 1];
                for (k = i+1; k <= j; k++)
                {
                    qq=c[i][k-1]+c[k][j];
                    if (qq < min)
                    {
                        min = qq;
                        r[i][j] = k;
                    }
                }

                c[i][j] = min+w[i][j];
            }
        }
    }

    cout << "Weight Matrix : \n";
    for (int i = 0; i < tn; i++)
    {
        for (int j = 0; j < tn; j++)
        {
            cout << w[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
    cout << "Cost Matrix : \n";
    for (int i = 0; i < tn; i++)
    {
        for (int j = 0; j < tn; j++)
        {
            cout << c[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
    cout << "Root Matrix : \n";
    for (int i = 0; i < tn; i++)
    {
        for (int j = 0; j < tn; j++)
        {
            cout << r[i][j] << "\t";
        }
        cout << "\n";
    }
}