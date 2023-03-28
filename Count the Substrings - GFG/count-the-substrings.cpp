//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    bool isLower(char c)
    {
        return (c >= 'a' && c <= 'z');
    }
    int countSubstring(string s)
    {
        int n = s.size(), ans = 0;
        for(int i = 0; i < n; i++)
        {
            int cl = 0, cu = 0;
            for(int j = i; j < n; j++)
            {
                if(isLower(s[j])) cl++;
                else cu++;
                
                if(cl == cu) ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends