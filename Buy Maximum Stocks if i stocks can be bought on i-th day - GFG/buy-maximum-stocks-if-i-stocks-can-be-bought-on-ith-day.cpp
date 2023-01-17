//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

bool cmp(pair<int,int>&a, pair<int,int>&b)
{
    if(a.first > b.first) return false;
    else if(a.first < b.first) return true;
    else{
        return(a.second > b.second);
    }
}
class Solution {
public:
    int buyMaximumProducts(int n, int k, int p[])
    {
        vector<pair<int,int>>v;
        for(int i = 0; i < n; i++)
            v.push_back({p[i],i+1});
    
        sort(v.begin(),v.end(),cmp);
        int ans = 0, i = 0;
        while(k > 0 && i < n)
        {
            int stocks = v[i].second, price = v[i].first,quantity;
            if(k < price) break;
            
            quantity = min(stocks,k/price);
            k -= quantity*price;
            ans += quantity;
            
            i++;
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
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends