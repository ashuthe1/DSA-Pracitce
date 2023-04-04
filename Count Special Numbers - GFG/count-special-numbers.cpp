//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int n, vector<int> v) {
        int mx = *max_element(v.begin(), v.end()), ans = 0;
        vector<int>vis(mx+2, 0), fr(mx+2, 0), marked(mx+2, 0);
        for(int i = 0; i < n; i++)
        {
            fr[v[i]]++;
            if(marked[v[i]]) continue;
            marked[v[i]] = 1;
            for(int j = 2*v[i]; j <= mx; j += v[i]) vis[j] = 1;
        }
            
        for(int &e : v) if(vis[e] || fr[e] > 1) ans++;
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends