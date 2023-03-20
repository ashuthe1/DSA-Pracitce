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
    vector<pair<int, int>> adj = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int shortestXYDist(vector<vector<char>> v, int n, int m) {
        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(m, -1));
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(v[i][j] == 'X'){
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }
        
        while(!q.empty())
        {
            auto top = q.front();
            q.pop();
            
            for(auto &move : adj)
            {
                int X = top.first + move.first, Y = top.second + move.second;
                if(isValid(X, Y, n, m) && dist[X][Y] == -1){
                    dist[X][Y] = dist[top.first][top.second] + 1;
                    q.push({X, Y});
                }
            }
        }
        int distance = 1e7;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(v[i][j] == 'Y' && dist[i][j] < distance){
                    distance = dist[i][j];
                }
            }
        }
        return distance;
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