//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool func(int u, vector<vector<int>>&v, int n, int m, vector<int>&match, vector<bool>&used)
    {
        for(int job = 0; job < m; job++)
        {
            if(v[u][job] && !used[job])
            {
                used[job] = true;
                if(match[job] == -1 || (func(match[job],v,n,m,match,used)))
                {
                    match[job] = u;
                    return true;
                }
            }
        }
        return false;
    }
    int maximumMatch(vector<vector<int>>&v){
        int n = v.size(), m = v[0].size(), ans = 0;
        vector<int>match(m,-1);
    
        for(int i = 0; i < n; i++)
        {
            vector<bool>used(m,false);
            if(func(i,v,n,m,match,used)) ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>G(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> G[i][j];
		}
		Solution obj;
		int ans = obj.maximumMatch(G);
		cout << ans << "\n";    
	}
	return 0;
}
// } Driver Code Ends