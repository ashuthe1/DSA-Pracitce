//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
int dp[1000010];
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int func(int i, int included, int *arr, int n)
	{
	    if(i >= n) return 0;
	    
	    if(dp[i] != -1) return dp[i];
	    int ans = 0;
	    ans = max(ans,func(i+2,0,arr,n)+arr[i]);
	    ans = max(ans,func(i+1,0,arr,n));
	    
	    return dp[i] = ans;
	}
	int findMaxSum(int *arr, int n) {
	    memset(dp,-1,sizeof(dp));
	    return func(0,0,arr,n);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends