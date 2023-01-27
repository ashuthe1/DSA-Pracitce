//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    typedef long long ll;
    vector<int> subarraySum(vector<int>v, int n, long long s)
    {
        int i = 0, j = 1;
        ll sum = v[i];
        
        while(i < j || j <= n)
        {
            if(j == n && sum < s) break;
            
            if(i < j && sum == s)
            {
                return {i+1,j};
            }
            else if(sum < s && j < n)
            {
                sum += v[j];
                j++;
                
                if(sum == s && i+1 <= j)
                {

                    return {i+1,j};
                }
            }
            else{
                sum -= v[i];
                i++;
                
                if(sum == s && i+1 <= j)
                {
                    return {i+1,j};
                }
            }
        }
        return {-1};
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
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends