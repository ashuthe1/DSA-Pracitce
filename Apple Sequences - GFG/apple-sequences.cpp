//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
int appleSequences(int n, int m, string &s){
    int i = 0, j = 0, orange = 0, ans = 0;
    while(j <= n)
    {
        if(orange <= m)
        {
            ans = max(ans,j-i);
            if(j < n && s[j] == 'O') orange++;
            j++;
        }
        else{
            if(s[i] == 'O') orange--;
            i++;

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
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends