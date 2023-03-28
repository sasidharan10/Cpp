#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    bool isSafe(int row, int col, vector<string>board, int n)
    {
        int duprow=row;
        int dupcol=col;

        //left upper
        while(row>=0 && col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            col--;
            row--;
        }

        //left
        row=duprow;
        col=dupcol;
        while(col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            col--;
        }

        //left lower
        row=duprow;
        col=dupcol;
        while(row<n && col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            col--;
            row++;
        }
        return true;
    }
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }

        for(int row=0; row<n; row++)
        {
            if(isSafe(row, col, board, n))
            {
                board[row][col]='Q';
                solve(col+1, board, ans, n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        // if()
        string temp(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=temp;
        }
        vector<vector<string>> ans;
        solve(0, board, ans, n);
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<string>>ans;
    int n=4;
    ans=s.solveNQueens(n);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cout<<ans[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        cout<<endl;
    }
    return 0;
}