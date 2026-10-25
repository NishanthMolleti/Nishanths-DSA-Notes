#include<bits/stdc++.h>
using namespace std;
//below is a memoized solution
class Solution {
public:
    int solve(vector<vector<int>>& dp, int m,int n, int i,int j){
        if(i==0&&j==0) return 1;
        if(i<0||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=solve(dp,m,n,i-1,j)+solve(dp,m,n,i,j-1);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(dp,m,n,m-1,n-1);
    }
};
//below is a tabulized solution
