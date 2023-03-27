//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dp[101][101][101];
    int func(int prev, int g, int rem, int &N, int &K)
    {
        if(g == K && rem == 0) return 1;
        if(g == K || rem == 0) return 0;
        
        if(dp[prev][g][rem] != -1) return dp[prev][g][rem];
        int ans = 0;
        for(int ele = prev; ele <= rem; ele++)
            ans += func(ele, g+1, rem - ele, N, K);
            
        return dp[prev][g][rem] = ans;
    }
    int countWaystoDivide(int N, int K) {
        memset(dp, -1, sizeof(dp));
        return func(1,0,N, N, K);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends