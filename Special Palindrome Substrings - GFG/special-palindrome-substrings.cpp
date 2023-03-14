//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
#define deb(...)
class Solution{
    //Complete the function and return minimum number of operations
    public:
    int makePal(string &s, int l, int r)
    {
        int n = s.size(), c = 0;
        for(int i = 0; i < n/2; i++)
        {
            if(s[i] != s[n-i-1])
            {
                if(i >= l && i <= r && n-i-1 >= l && n-i-1 <= r) return 1e4;
                else c++;
            }
        }
        return c;
    }
    int specialPalindrome(string s1, string s2)
    {
        int n = s1.size(), m = s2.size(), ans = 1e4;
        string pre = "";
        for(int i = 0; i <= n-m; i++)
        {
            string cur = pre;
            for(int j = 0; j < m; j++) cur += s2[j];
            for(int j = i+m; j < n; j++) cur += s1[j];
            int additional = 0;
            for(int j = i; j <= i + m - 1; j++) if(cur[j] != s1[j]) additional++;
            int cost = makePal(cur, i, i+m-1) + additional;
            ans = min(ans, cost);

            pre += s1[i];
        }
        if(ans >= 1e4) return -1;
        return ans;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        Solution obj;
        int ans = obj.specialPalindrome(s1,s2);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends