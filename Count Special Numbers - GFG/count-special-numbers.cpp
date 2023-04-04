//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int n, vector<int> arr) {
        int maxx = INT_MIN, count = 0;
        for(int &e : arr) maxx = max(e, maxx);
        vector<int>freq(maxx+2, 0);
        vector<bool>vis(maxx+2, 0), special(maxx+2, 0);
        
        for(int i = 0; i < n; i++)
        {
            freq[arr[i]]++;
            if(vis[arr[i]]) continue;
            vis[arr[i]] = 1;
            
            for(int j = 2*arr[i]; j <= maxx; j += arr[i]) special[j] = 1;
        }
        
        for(int &e : arr)
        {
            if(freq[e] > 1 || special[e]) count++;
        }
        return count;
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