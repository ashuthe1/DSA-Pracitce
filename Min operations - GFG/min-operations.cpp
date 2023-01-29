//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binary(int n)
    {
        string s;
        while(n){
          if(n & 1) 
            s += '1';
          else
            s += '0';
    
          n >>= 1; 
        }   
        reverse(s.begin(),s.end());
        return s;
    }
    int solve(int A, int B) {
        string a = binary(A), b = binary(B);
        while(a.size() < b.size()) a = '0' + a;
        
        while(b.size() < a.size()) b = '0' + b;
        
        int n = a.size(), ans = 0, op1 = 0, op2 = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(a[i] == '1' && b[i] == '0') op1++;
            if(b[i] == '1' && a[i] == '0') op2++;
            
            if(a[i] != b[i]) ans++;
        }
        if(ans >= 2)
        {
            if(op1 && op2) return 2;
            else return 1;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int a;
        scanf("%d",&a);
        
        
        int b;
        scanf("%d",&b);
        
        Solution obj;
        int res = obj.solve(a, b);
        
        printf("%d\n", res);
        
    }
}

// } Driver Code Ends