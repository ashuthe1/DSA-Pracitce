//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    typedef long long ll;
    long long maxPossibleValue(int n, vector<int> A, vector<int> B) 
    {
        ll ans = 0, pairs = 0, mi = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            if(B[i] < 2) continue;
            
            pairs += B[i]/2;
            ans += (B[i]/2) * 2LL * (A[i]);
    
            mi = min(mi, (ll)A[i]);
        } 
    
        if(pairs&1) ans -= 2*mi;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends