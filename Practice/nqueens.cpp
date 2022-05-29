#include <bits/stdc++.h>
using namespace std;
#define N 4
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }

    cout<<"\n";
}

bool isSafe(int board[N][N],int row,int col){
    int i,j;
    for(i=0;i<N;i++){
        if(board[row][i]){
            return false;
        }
    }

    for(i=row,j=col;i>=0&&j>=0;i--,j--){
        if(board[i][j]){
            return false;
        }
    }
    for(i=row,j=col;i<N&&j>=0;i++,j--){
        if(board[i][j]){
            return false;
        }
    }

    return true;
}
bool solveNQUntil(int board[N][N], int col)
{
    int i, j;
    if (col >= N)
    {
        printSolution(board);
        return true;
    }

    bool res = false;
    for (i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;
            res = solveNQUntil(board, col + 1) || res;
            board[i][col] = 0;
        }
    }

    return res;
}
void solveNQ()
{
    int board[N][N];
    memset(board, 0, sizeof(board));
    if(solveNQUntil(board,0)==false){
        cout<<"No solution\n";
        return;
    }
    return;
}
int main()
{
    solveNQ();
    return 0;
}