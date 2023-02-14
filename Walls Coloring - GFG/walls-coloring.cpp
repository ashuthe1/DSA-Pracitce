//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    vector<vector<int>>dp;
    int func(int i, int k, vector<vector<int>> &v, int n)
    {
        if(i == n) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        int ans = INT_MAX;
        if(k == 0)
        {
            ans = min(ans,func(i+1,1,v,n)+v[i][0]);
            ans = min(ans,func(i+1,2,v,n)+v[i][1]);
            ans = min(ans,func(i+1,3,v,n)+v[i][2]);
        }
        else if(k == 1)
        {
            ans = min(ans,func(i+1,2,v,n)+v[i][1]);
            ans = min(ans,func(i+1,3,v,n)+v[i][2]);
        }
        else if(k == 2)
        {
            ans = min(ans,func(i+1,1,v,n)+v[i][0]);
            ans = min(ans,func(i+1,3,v,n)+v[i][2]);
        }
        else{
            ans = min(ans,func(i+1,1,v,n)+v[i][0]);
            ans = min(ans,func(i+1,2,v,n)+v[i][1]);
        }
        return dp[i][k] =  ans;
    }
    int minCost(vector<vector<int>> &colors, int N) 
    {
        dp.resize(N+1,vector<int>(4,-1));
        return func(0,0,colors,N);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends