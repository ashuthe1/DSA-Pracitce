//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

typedef long long ll;
ll dp[50010][3];
class Solution{   
public:
    ll func(int i, int p, int n, int r[], int g[], int b[])
    {
        if(i == n) return 0;
        
        ll ans = LLONG_MAX;
        if(dp[i][p] != -1) return dp[i][p];
        if(p == 0)
        {
            ans = min(ans,func(i+1,1,n,r,g,b)+g[i]);
            ans = min(ans,func(i+1,2,n,r,g,b)+b[i]);
        }
        else if(p == 1)
        {
            ans = min(ans,func(i+1,0,n,r,g,b)+r[i]);
            ans = min(ans,func(i+1,2,n,r,g,b)+b[i]);
        }
        else{
            ans = min(ans,func(i+1,0,n,r,g,b)+r[i]);
            ans = min(ans,func(i+1,1,n,r,g,b)+g[i]);
        }
        return dp[i][p] = ans;
    }
    void pre()
    {
        for(int i = 0; i < 50010; i++)
        {
            for(int j = 0; j < 3; j++) dp[i][j] = -1;
        }
    }
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        pre();
        ll ans = func(1,0,N,r,g,b)+r[0];
        pre();
        ans = min(ans,func(1,1,N,r,g,b)+g[0]);
        pre();
        ans = min(ans,func(1,2,N,r,g,b)+b[0]);
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends