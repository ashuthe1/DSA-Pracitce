//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minCost(vector<vector<int>> &v, int n) 
    {
        vector<vector<int>>dp(n+2,vector<int>(4,0));
        // dp[i][j] -> minimum cost to paint till ith wall if ith wall is painted as j color
        for(int i = 0; i < n; i++)
        {
            if(i == 0)
            {
                for(int j = 0; j < 3; j++)
                dp[0][j] = v[0][j];
            }
            else{
                for(int j = 0; j < 3; j++)
                {
                    if(j == 0) dp[i][0] = min(dp[i-1][1],dp[i-1][2])+v[i][0];
                    else if(j == 1) dp[i][1] = min(dp[i-1][0],dp[i-1][2])+v[i][1];
                    else dp[i][2] = min(dp[i-1][0],dp[i-1][1])+v[i][2];
                }
            }
        }
        return min({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
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