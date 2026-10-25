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
//below is the Tabulation solution
class SolutionTabulation {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int u=INT_MAX,l=INT_MAX;
                if(i>0) u=dp[i-1][j];
                if(j>0) l=dp[i][j-1];
                if(i==0&&j==0)dp[i][j]=grid[i][j];
                else
                dp[i][j]=grid[i][j]+min(u,l);
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};