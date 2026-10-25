#include<bits/stdc++.h>
using namespace std;
//below is the memoization solution
class SolutionMemoization {
public:
    int solve(vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid,int m,int n,int i,int j){
        if(i>=m||j>=n) return 0;
        if(obstacleGrid[i][j]==1) return dp[i][j]=0;
        if(i==m-1&&j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=solve(dp,obstacleGrid,m,n,i+1,j)+solve(dp,obstacleGrid,m,n,i,j+1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(),-1));
        return solve(dp,obstacleGrid,obstacleGrid.size(),obstacleGrid[0].size(),0,0);
    }
};
// below is the tabulation solution
class SolutionTabulation {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(),1));
        for(int i=0;i<obstacleGrid.size();i++){
            for(int j=0;j<obstacleGrid[0].size();j++){
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else if(i==0&&j==0) dp[i][j]=1;
                else{
                int u=0,l=0;
                if(i>0)
                    u=dp[i-1][j];
                if(j>0)
                    l=dp[i][j-1];
                
                dp[i][j]=u+l;
                }
            }
        }
        return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};