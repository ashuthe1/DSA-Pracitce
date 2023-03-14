//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
        int n;
        vector<vector<int>> dp;
        int func(int i, int j, vector<int>&v)
        {
            if(i > j) return 0;
            
            if(dp[i][j] != -1) return dp[i][j];
            int ans = INT_MIN;
            for(int k = i; k <= j; k++)
            {
                int res = v[i-1] * v[k] * v[j+1];
                ans = max(ans, func(i, k-1, v) + func(k+1, j, v) + res);
            }
            return dp[i][j] = ans;
            // return ans;
        }
        int maxCoins(int N, vector <int> &a)
        {
            n = N;
            dp.clear(); dp.resize(N+2, vector<int>(N+2, -1));
            a.insert(a.begin(), 1);
            a.push_back(1);
            return func(1,N, a);
        }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends