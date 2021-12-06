#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int n;

bool isSafe(int row,int col, vector<vector<int>> &mat){
    //queen can go in 8 directions, since we are going from left to right there will not be any queens in the
    //right side of the spot where th contol is or col is,and as there would be only 1 queen in a
    //column,therefore top and bootom is also not needed. So we only need to check 3 sides on left;

    //row--col--
    for(int i=row,j=col;i>=0&&j>=0;i--,j--){
        if(mat[i][j]==1) return false;
    }
    //row col--
    for(int i=row,j=col;i>=0&&j>=0;j--){
        if(mat[i][j]==1) return false;
    }
    //row++col--
    for(int i=row,j=col;i<n&&j>=0;i++,j--){
        if(mat[i][j]==1) return false;
    }
    //if it never failed then the position is definently safe
    return true;
    
}
//to print the first possible way
// bool nqueens(int col,vector<vector<int>>&mat){
//     if(col==n){
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++)
//                 cout<<mat[i][j]<<" ";
//                 cout<<endl;
//         }
//         return true;
//     }
//     for(int row=0;row<n;row++){
//         if(isSafe(row,col,mat)){
//             mat[row][col]=1;
//             if(nqueens(col+1,mat)==true){
//                 return true;
//             }
//             mat[row][col]=0;
//         }
//     }
//     return false;
// }


// to print all the posiible ways
void nqueens(int col,vector<vector<int>>&mat){
    if(col==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<mat[i][j]<<" ";
                cout<<endl;
        }
        cout<<endl<<endl;
        return;
    }
    for(int row=0;row<n;row++){
        if(isSafe(row,col,mat)){
            mat[row][col]=1;
            nqueens(col+1,mat);
            // if(nqueens(col+1,mat)==true){
            //     return true;
            // }
            mat[row][col]=0;
        }
    }
    
}

int main(){
    // cin>>n;
    n=4;
    vector<vector<int>>mat(n,vector<int>(n,0));
    nqueens(0,mat);
}