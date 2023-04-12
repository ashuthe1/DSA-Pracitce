//{ Driver Code Starts
// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, i;
        cin >> n;
        int price[n];
        for (i = 0; i < n; i++) cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}

// } Driver Code Ends
void stockBuySell(int v[], int n) {
    int prev = v[0], mx = v[0], pInd = 0, mInd = 0;
    vector<pair<int,int>> ans;
    for(int i = 1; i < n; i++)
    {
        if(v[i] < mx)
        {
            if(pInd != mInd){
                ans.push_back({pInd, mInd});
                pInd = mInd = i;
                prev = mx = v[i];
            }
            if(v[i] < prev)
            {
                prev = mx = v[i];
                mInd = pInd = i;
            }
        }
        else{
            mx = v[i];
            mInd = i;
        }
    }
    if(pInd != mInd) ans.push_back({pInd, mInd});
    if(ans.size() == 0) {cout << "No Profit\n"; return;}
    for(auto &e : ans) cout << "(" << e.first << " " << e.second << ") ";
    cout << "\n";
}