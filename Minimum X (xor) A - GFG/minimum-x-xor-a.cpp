//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#define deb(x) cout << #x << "=" << x << "\n";
#define deb2(x,y) cout << #x << "=" << x << "," << #y << "=" << y << "\n";
class Solution {
  public:
    string dtoB(int num)
    {
        string str = "";
          while(num){
          if(num & 1) // 1
            str+='1';
          else // 0
            str+='0';
          num>>=1; // Right Shift by 1 
        }   
        reverse(str.begin(),str.end());
        return str;
    }
    int minVal(int a, int b) {
        int bits = __builtin_popcount(b),n;
        string s = dtoB(a);
        n = s.size();
        string ans(n,'0');
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1' && bits > 0)
            {
                ans[i] = '1';
                bits--;
            }
        }
        // deb2(s,bits)
        int sz = ans.size();
        int i = sz-1;
        while(bits > 0 && i >= 0)
        {
            if(ans[i] == '0'){
                ans[i] = '1';
                bits--;
                // i--;
            }
            i--;
        }
        // deb2(ans,bits)
        // while(bits > 0)
        // {
        //     ans = '1' + ans;
        //     bits--;
        // }
        int x = 0;
        sz = ans.size();
        for(i = sz-1; i >= 0; i--)
        {
            if(ans[i] == '1')
            {
                x += (1 << sz-i-1);
            }
        }
        return x;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends