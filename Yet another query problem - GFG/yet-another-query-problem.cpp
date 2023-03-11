//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int N, int num, vector<int> &A, vector<vector<int>> &Q) {
        vector<int>freq(N+1,1), temp(1e5+2, 0);
        for(int i = N-1; i >= 0; i--)
        {
            temp[A[i]]++;
            freq[i] = temp[A[i]];
        }
        
        vector<int>output;
        for(auto q : Q)
        {
            int l = q[0], r = q[1], k = q[2], ans = 0;
            for(int i = l; i <= r; i++)
            {
                if(freq[i] == k) ans++;
            }
            output.push_back(ans);
        }
        return output;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends