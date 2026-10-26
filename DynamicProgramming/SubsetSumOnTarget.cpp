#include<bits/stdc++.h>
using namespace std;
//this is incomplete
bool f(int i,vector<int>& arr,int t,vector<int>& dp){
    if(t==0) return true;
    if(i==0) return arr[0]==t;
    bool nt=f(i-1,arr,t,dp);
    bool ta=false;
    if(arr[i]<=t)
        ta=f(i-1,arr,t-arr[i],dp);
    return dp[i]=nt||ta;
}
bool subsettok(vector<int>& arr, int k){
    vector<int> dp(arr.size(),-1);
    return f(arr.size()-1,arr,k,dp);
}