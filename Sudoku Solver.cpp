#include<iostream>
#include<cmath>
using namespace std;

bool isSafe(int mat[][9], int i, int j, int no, int n){
    for(int k = 0; k<n; k++){
        if(mat[k][j] == no || mat[i][k] == no){
            return false;
        }
    }

    //check for subgrid
    int sx = (i/3)*3;
    int sy = (j/3)*3;

    for(int x = sx; x< sx + 3; x++){
        for(int y = sy; y < sy + 3; y++){
            if(mat[x][y] == no){
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int mat[][9], int i, int j, int n){
    //base case
    if(i==n){
        //print solution and return
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout<<mat[i][j]<<" ";
        }
        cout << endl;
    }
        return true;
    }

    //rec case
    if(j==n){
        return solveSudoku(mat,i+1,0,n);
    }

    //slip the prefilled cell
    if(mat[i][j]!=0){
        return solveSudoku(mat,i,j+1,n);
    }

    //cell to be filled - tru all possibilities
    for(int no=1; no<=n; no++){
        if(isSafe(mat,i,j,no,n)){
            mat[i][j] = no;
            bool solveSubproblem = solveSudoku(mat, i, j+1, n);
            if(solveSubproblem == true){
                return true;
            }
        }
    }

    //If no optiion works
    mat[i][j] = 0;
    return false;

}

int main(){
    int n = 9;
    int mat[9][9] = 
    {{},{},{}, {}, {}, {},{},{},{}};

    if(!solveSudoku(mat,0,0,n)){
        cout << "No solutiion"<<endl;
    }
    return 0;
}
