#include<bits/stdc++.h>

using namespace std;

int a[10][10], travelled[10], n, cost = 0;

void takeInput()
{
    int i, j;

    cout << "Enter the number of satellites : ";
    cin >> n;

    cout << "\nEnter the Cost Matrix\n";

    for (i = 0; i < n; i++)
    {
        cout << "\nEnter time (rows in the matrix) : " << i + 1 << "\n";

        for (j = 0; j < n; j++)
            cin >> a[i][j];

        travelled[i] = 0;
    }

    cout << "\n\nThe cost list is:";

    for (i = 0; i < n; i++)
    {
        cout << "\n";

        for (j = 0; j < n; j++)
            cout << "\t" << a[i][j];
    }
}

int least(int c)
{
    int i, nc = 999;
    int min = 999, kmin;

    for (i = 0; i < n; i++)
    {
        if ((a[c][i] != 0) && (travelled[i] == 0))
            if (a[c][i] + a[i][c] < min)
            {
                min = a[i][0] + a[c][i];
                kmin = a[c][i];
                nc = i;
            }
    }

    if (min != 999)
        cost += kmin;

    return nc;
}

void minimum_cost(int object)
{
    int i, nobject;

    travelled[object] = 1;

    cout << object + 1 << "--->";
    nobject = least(object);

    if (nobject == 999)
    {
        nobject = 0;
        cout << nobject + 1;
        cost += a[object][nobject];

        return;
    }

    minimum_cost(nobject);
}

int main()
{
    takeInput();

    cout << "\n\nThe Path is:\n";
    minimum_cost(0); 

    cout << "\n\nMinimum cost is " << cost;

    return 0;
}