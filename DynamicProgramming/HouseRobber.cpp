#include<bits/stdc++.h>
using namespace std;
//below is the memo solution
class SolutionMemoized {
public:
    int solve(vector<int>& dp, vector<int>& nums, int i){
        if(i<0) return 0;
        if(i==0) return nums[i];
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max(solve(dp,nums,i-1),nums[i]+solve(dp,nums,i-2));
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+2, -1);
        return solve(dp,nums,nums.size()-1);
    }
};
//below is the tabulation solution
class SolutionTabulation {
public:

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, 0);
        if(nums.size()>=1)
        dp[0]=nums[0];
        if(nums.size()>=2)
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        return dp[nums.size()-1];

    }
};