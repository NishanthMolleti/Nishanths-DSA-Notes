#include<bits/stdc++.h>
using namespace std;
//below is the memoized solution
class SolutionMemoized {
public:
    int solve(vector<vector<int>>& dp, vector<vector<int>>& grid,int i,int j,int m,int n){
        if(i>=m||j>=n) return INT_MAX;
        if(i==m-1&&j==n-1) return grid[m-1][n-1];
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=grid[i][j]+min(solve(dp,grid,i+1,j,m,n),solve(dp,grid,i,j+1,m,n));
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return solve(dp,grid,0,0,grid.size(),grid[0].size());
    }
};