//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int a, int b, int c, int d){
        int mi1 = min(a,b), mi2 = min(c,d),mx1 = max(a,b), mx2 = max(c,d), op = 0;
        while(mi1 > mi2 || mx1 > mx2)
        {
            if(mx1 > mx2)
            {
                if(a == mx1) a /= 2;
                else b /= 2;
                
                op++;
            }
            else if(mi1 > mi2)
            {
                if(a == mi1) a /= 2;
                else b /= 2;
                
                op++;
            }
            
            mi1 = min(a,b);
            mx1 = max(a,b);
        }
        return op;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends