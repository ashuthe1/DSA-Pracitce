//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
typedef long long ll;
long long int no_of_subarrays(int n, vector<int> &arr) {
    ll ans = 0, c = 0;
    arr.push_back(1);
    for(int i = 0; i <= n; i++)
    {
        if(arr[i] == 0) c++;
        else{
            ans += (c * 1LL * (c+1))/2;
            c = 0;
        }
    }
    return ans;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << no_of_subarrays(n, arr) << endl;
    }
}

// } Driver Code Ends