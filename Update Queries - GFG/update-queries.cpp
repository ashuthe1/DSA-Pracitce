//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int> updateQuery(int n,int q,vector<vector<int>> &Q)
    {
        vector<vector<int>>v(n+2, vector<int>(24, 0));
        for(auto &que : Q)
        {
            int l = que[0], r = que[1], x = que[2];
            for(int bit = 0; bit < 20; bit++)
            {
                if(x&(1 << bit))
                {
                    v[l][bit]++;
                    v[r+1][bit]--;
                }
            }
        }
    
        for(int i = 1; i <= n; i++)
        {
            for(int bit = 0; bit < 20; bit++)
            {
                v[i][bit] += v[i-1][bit];
            }
        }
        // deb(v);
        vector<int>ans;
        for(int i = 1; i <= n; i++)
        {
            int num = 0;
            for(int bit = 0; bit < 20; bit++)
            {
                if(v[i][bit])
                {
                    num |= (1 << bit);
                }
            }
            ans.push_back(num);
        }
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
        int n,q;
        cin>>n>>q;
        vector <vector <int>> u(q,vector <int>(3));
        for(int i=0;i<q;i++)
            cin>>u[i][0]>>u[i][1]>>u[i][2];
        Solution a;
        vector <int> ans=a.updateQuery(n,q,u);//<<endl;
        for(auto j:ans)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends