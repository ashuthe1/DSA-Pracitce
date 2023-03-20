//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isValid(int i, int j, int n, int m)
{
    return (i >= 0 && j >= 0 && i < n && j < m);
}
int shortestXYDist(vector<vector<char>> v, int n, int m) 
{
    queue<pair<int,int>>q;
    vector<vector<int>>dist(n,vector<int>(m,-1));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(v[i][j] == 'X')
            {
                q.push({i,j});
                dist[i][j] = 0;
            }
        }
    }

    while(!q.empty())
    {
        auto top = q.front();
        q.pop();

        int i = top.first, j = top.second;
        // down
        if(isValid(i+1, j, n, m) && dist[i+1][j] == -1)
        {
            dist[i+1][j] = dist[i][j] + 1;
            q.push({i+1, j});
        }
        // up
        if(isValid(i-1, j, n, m) && dist[i-1][j] == -1)
        {
            dist[i-1][j] = dist[i][j] + 1;
            q.push({i-1, j});
        }
        // right
        if(isValid(i, j+1, n, m) && dist[i][j+1] == -1)
        {
            dist[i][j+1] = dist[i][j] + 1;
            q.push({i, j+1});
        }
        //left
        if(isValid(i, j-1, n, m) && dist[i][j-1] == -1)
        {
            dist[i][j-1] = dist[i][j] + 1;
            q.push({i, j-1});
        }
    }

    int ans = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(v[i][j] == 'Y') ans = min(ans, dist[i][j]);
        }
    }
    return ans;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends