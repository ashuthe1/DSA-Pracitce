//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string a, string b) {
    int n = (int)a.size(), m = (int)b.size(),ans = 1e8;

    for(int k = 0; k < n; k++)
    {
        int i = k, j = 0, cur = 1;
        bool ok =true;
        while(j < m)
        {
            if(a[i] != b[j])
            {
                ok = false;
                break;
            }
            i++,j++;
            if(i == n && j != m){
                i = 0;
                cur++;
            }
        }
        if(ok) ans = min(ans,cur);
    }
    if(ans == 1e8) return -1;
    return ans;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends