//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    typedef long long ll;
    long long solve(int X,int Y,string s){
        string a = "pr", b = "rp";
        if(Y  > X){
            swap(X, Y);
            swap(a, b);
        }
        ll n = s.size(), ans = 0;
        stack<char>st;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == a[1] && !st.empty() && st.top() == a[0])
            {
                ans += X;
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string rem = "";
        while(!st.empty()) rem += st.top(), st.pop();
        // cout << rem;
        reverse(rem.begin(), rem.end());
        n = rem.size();
        for(int i = 0; i < n; i++)
        {
            if(rem[i] == b[1] && !st.empty() && st.top() == b[0])
            {
                ans += Y;
                st.pop();
            }
            else{
                st.push(rem[i]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends