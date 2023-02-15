//{ Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int MaxGcd(int n, int arr[]) { 
        vector<int>isPresent(1e5+2,0);
        for(int i = 0; i < n; i++) isPresent[arr[i]] += 1;
        
        int ans = 1;
        for(int i = 2; i <= 1e5; i++)
        {
            if(isPresent[i]){
                for(int j = i; j <= 1e5; j += i)
                {
                    if(isPresent[j])
                    {
                        if(i == j && isPresent[i] < 2) continue;
                        ans = max(ans,__gcd(i,j));
                    }
                }
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
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.MaxGcd(n, a) << endl;
    
    }
    return 0; 
} 

// } Driver Code Ends