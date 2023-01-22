//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int solve(int n, int k, vector<int> &arr) 
    {
        vector<int>div;
        int sum = 0, ans = 0;
        for(int e : arr) sum += e;
    
        for(int i = 1; i*i <= sum; i++)
        {
            if(sum%i == 0)
            {
                div.push_back(i);
                if(sum/i != i) div.push_back(sum/i);
            }
        }
        // deb2(sum,div)
        // sort(div.begin(),div.end());
        for(int i = 1; i < n; i++) arr[i] += arr[i-1];
        
        for(int i = 0; i < (int)div.size(); i++)
        {
            int cur = 0;
            for(int e : arr) if(e%div[i] == 0) cur++;
            if(cur >= k) ans = max(ans,div[i]);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> arr(N);
        Array::input(arr,N);
        
        Solution obj;
        int res = obj.solve(N, K, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends