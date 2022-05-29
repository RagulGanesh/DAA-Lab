#include<bits/stdc++.h> 
using namespace std;
#define N 10
  
void printSolution(int board[N][N]) 
{ 
    static int k = 1; 
    cout<<k<<"-\n"; 
    k++;
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
            cout<<board[i][j]<<" ";  
            cout<<"\n";
    } 
     
    cout<<"\n";
} 
  
bool isSafe(int board[N][N], int row, int col) 
{ 
    int i, j; 
  

    for (i = 0; i < col; i++) 
        if (board[row][i]) 
            return false; 
  

    for (i=row, j=col; i>=0 && j>=0; i--, j--) 
        if (board[i][j]) 
            return false; 
  

    for (i=row, j=col; j>=0 && i<N; i++, j--) 
        if (board[i][j]) 
            return false; 
  
    return true; 
} 
  

bool solveNQUtil(int board[N][N], int col) 
{ 

    if (col >= N) 
    { 
        printSolution(board); 
        return true; 
    } 
  

    bool res = false; 
    for (int i = 0; i < N; i++) 
    { 

        if ( isSafe(board, i, col) ) 
        { 

            board[i][col] = 1; 
  

            res = solveNQUtil(board, col + 1) || res; 
  

            board[i][col] = 0; // BACKTRACK 
        } 
    } 
  

    return res; 
} 
  

void solveNQ() 
{ 
    int board[N][N]; 
    memset(board, 0, sizeof(board)); 
  
    if (solveNQUtil(board, 0) == false) 
    { 
        printf("Solution does not exist"); 
        return ; 
    } 
  
    return ; 
} 
  
// driver program to test above function 
int main() 
{ 
    solveNQ(); 
    return 0; 
} 