//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int v[], int n) 
    { 
        int lMin[n],rMax[n];
        lMin[0] = v[0], rMax[n-1] = v[n-1];
        
        for(int i = 1; i < n; i++) lMin[i] = min(lMin[i-1],v[i]);
        for(int i = n-2; i >= 0; i--) rMax[i] = max(rMax[i+1],v[i]);
        
        int i = 0, j = 0, ans = 0;
        while(i < n && j < n)
        {
            if(lMin[i] <= rMax[j])
            {
                ans = max(ans,j-i);
                j++;
            }
            else i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends