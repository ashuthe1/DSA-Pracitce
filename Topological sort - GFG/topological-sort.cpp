//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<vector<int>>adj;
    vector<int>inDegree, topo;
    vector<bool>vis;
    stack<int>st;
    void topologicalSortDFS(int node)
    {
        vis[node] = 1;
        for(int child : adj[node])
        {
            if(!vis[child]) topologicalSortDFS(child);
        }
        st.push(node);
    }
    void topologicalSortBFS(int n)
    {
        queue<int>q;
        for(int i = 0; i < n; i++)
        {
            if(inDegree[i] == 0) q.push(i);
        }
    
        while(!q.empty())
        {
            int node = q.front(); q.pop();
            topo.push_back(node);
    
            for(int child : adj[node])
            {
                inDegree[child]--;
                if(inDegree[child] == 0) q.push(child);
            }
        }
    }
    vector<int> topoSort(int V, vector<int> g[]) 
    {
        adj.clear(); adj.resize(V);
        vis.clear(); vis.resize(V, false);
        inDegree.clear(); inDegree.resize(V,0);
    
        for(int i = 0; i < V; i++)
        {
            for(int child : g[i])
            {
                adj[i].push_back(child);
                inDegree[child]++;
            }
        }
    
        // for(int i = 0; i < V; i++)
        // {
        //     if(!vis[i]) topologicalSortDFS(i);
        // }
        topologicalSortBFS(V);
        // while(!st.empty()) topo.push_back(st.top());
        return topo;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends