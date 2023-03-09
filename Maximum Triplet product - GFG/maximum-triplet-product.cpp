//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    typedef long long ll;
    long long maxTripletProduct(long long v[], int n)
    {
    	sort(v, v+n);
    	ll p1 = v[0]*v[1];
    	ll p2 = v[n-3]*v[n-2];
    	
    	return max(v[n-1] * max(p1,p2), v[n-1]*v[n-2]*v[n-3]);
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends