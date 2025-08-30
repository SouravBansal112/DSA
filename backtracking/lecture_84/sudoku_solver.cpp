#include<bits/stdc++.h>
using namespace std;

bool pos(int row,int col,int k, vector<vector<int>> &sudoku){
    for(int i=0; i<9 ; i++){
        if(sudoku[row][i]==k || sudoku[i][col]==k || sudoku[3*(row/3) + i/3][3*(col/3) + i%3]==k){
            return false;
        }
    }
    return true;
}



bool solve(int row, int col, vector<vector<int>> &sudoku){

    for(int i=row; i<9 ; i++){
        for(int j=0; j<9 ; j++){
            if(sudoku[i][j]==0){
                for(int k=1 ; k<10 ; k++){
                    if(pos(i,j,k,sudoku)){
                        sudoku[i][j]=k;
                        if(solve(i,j,sudoku)){
                            return true;
                        }
                        sudoku[i][j]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool solve(int row, int col, vector<vector<int>> &sudoku) {
    if (row == 9) return true;  // Finished all rows

    // Move to next row if we reach end of current row
    if (col == 9) return solve(row + 1, 0, sudoku);

    // Skip filled cells
    if (sudoku[row][col] != 0) return solve(row, col + 1, sudoku);

    for (int k = 1; k <= 9; k++) {
        if (pos(row, col, k, sudoku)) {
            sudoku[row][col] = k;
            if (solve(row, col + 1, sudoku)) return true;
            sudoku[row][col] = 0;
        }
    }

    return false;
}

void solveSudoku(vector<vector<int>>& sudoku)
{
    solve(0,0,sudoku);
}
