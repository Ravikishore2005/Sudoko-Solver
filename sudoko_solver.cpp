#include<bits/stdc++.h>
using namespace std;

bool issafe(vector<vector<char>>& board,int row,int cols,char dig){
    //horizontal
    for(int j=0;j<9;j++){
        if(board[row][j]==dig){
            return false;
        }
    }

    //vertical
    for(int i=0;i<9;i++){
        if(board[i][cols]==dig){
            return false;
        }
    }

    //grid
    int srow=(row/3)*3;
    int scol=(cols/3)*3;

    for(int i=srow;i<=srow+2;i++){
        for(int j=scol;j<=scol+2;j++){
            if(board[i][j]==dig){
                return false;
            }
        }
    }
    return true;
}

bool helper(vector<vector<char>>& board,int row,int cols){
    if(row==9){
        return true;
    }

    int nextrow=row,nextcol=cols+1;
    if(nextcol==9){
        nextrow=row+1;
        nextcol=0;
    }
    if(board[row][cols]!='.'){
        return helper(board,nextrow,nextcol);
    }

    for(char dig='1';dig<='9';dig++){
        if(issafe(board,row,cols,dig)){
            board[row][cols]=dig;
            if(helper(board,row,cols)){
                return true;
            }
            board[row][cols]='.';
        }
    }
    return false;
}

void solvesudoku(vector<vector<char>>& board){
    helper(board,0,0);
}

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    solvesudoku(board);

    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
