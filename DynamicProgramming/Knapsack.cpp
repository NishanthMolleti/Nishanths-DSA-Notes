#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& dp, const vector<int>& wt, const vector<int>& val,
          int n, int t, int i) {
    if (i == n || t == 0) return 0;          // no items left or no capacity left -> no more value
    if (dp[i][t] != -1) return dp[i][t];     // already solved this (item, capacity) state

    int np = solve(dp, wt, val, n, t, i + 1);        // skip item i, capacity unchanged
    int p = 0;                                       // default: can't take item i
    if (wt[i] <= t)                                  // only take if it fits
        p = val[i] + solve(dp, wt, val, n, t - wt[i], i + 1); // gain value, shrink capacity

    return dp[i][t] = max(p, np);            // memoize at (i, t), not (i, t - wt[i])
}

int knapsack(const vector<int>& wt, const vector<int>& val, int n, int maxW) {
    vector<vector<int>> dp(n, vector<int>(maxW + 1, -1)); // rows: items, cols: capacity 0..maxW
    return solve(dp, wt, val, n, maxW, 0);                // start at item 0 with full capacity
}