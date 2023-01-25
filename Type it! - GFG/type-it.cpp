//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool equal(string &s)
    {
        int n = s.size();
        if(n%2) return false;
        int i = 0, j = n/2;
        
        while(j < n)
        {
            if(s[i] != s[j]) return false;
            i++,j++;
        }
        return true;
    }
    int minOperation(string &s)
    {
        int n = s.size(), c = 0;
        for(int i = 0; i < n; i++)
        {
            string ex = "";
            ex += s[i];
            for(int j = i+1; j < n; j++)
            {
                ex += s[j];
                if(equal(ex))
                {
                    c = max(c,(j-i)/2);
                }
            }
        }
        if(c == 0) return n;
        return n-c;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends