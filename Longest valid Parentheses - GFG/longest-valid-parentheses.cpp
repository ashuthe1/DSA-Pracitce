//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string &s){
        int n = s.size(),open = 0, close = 0, ans = 0;
        stack<pair<char,int>>st;
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++)
        {
            char e = s[i];
            if(e == '(') open++;
            else close++;
            
            if(s[i] == '(') st.push({'(',i});
            
            if(e == ')' && !st.empty())
            {
                v.push_back({st.top().second,i});
                st.pop();
            }
        }
        
        sort(v.begin(),v.end());
        int l = v.size() - 1;
        for(int i = 0; i < l; i++)
        {
            if(v[i+1].first >= v[i].first && v[i+1].second <= v[i].second)
            {
                // cout << "yes\n";
                v[i+1].second = v[i].second;
                v[i+1].first = v[i].first;
            }
            if(v[i].second == v[i+1].first - 1)
            {
                // cout << "yes\n";
                v[i+1].first = v[i].first;
            }
            // else if()
        }
        // for(int i = 0; i < v.size(); i++)
        // {
        //     cout << v[i].first << " " << v[i].second << endl;
        // }
        for(int i = 0; i < v.size(); i++) ans = max(ans, v[i].second - v[i].first + 1);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends