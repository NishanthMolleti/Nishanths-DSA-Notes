#include<bits/stdc++.h>
using namespace std;
// below is the memoized solution
class SolutionMemoized {
public:
    int solve(vector<int>& dp,int n){
        if(n==1) return 1;
        if(n==2) return 2;
        if(dp[n]!=0) return dp[n];
        return dp[n]=solve(dp,n-1)+solve(dp,n-2); 
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        return solve(dp,n);
    }
};
//below is the tabulated solution
class SolutionTabulation {
public:
    int climbStairs(int n) {
        vector<int> dp(n+2,0);
        dp[1]=1;
        dp[2]=2;
        if(n<=2) return dp[n];
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }

};
// sc: O(N), tc: O(N)