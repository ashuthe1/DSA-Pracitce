//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++
#define deb(x) cout << #x << "=" << x << "\n";
#define deb2(x,y) cout << #x << "=" << x << "," << #y << "=" << y << "\n";
const int N = 1e4+10;
class Solution{
public:
    vector<bool>is_prime;
    vector<int>prime;
    void sieve()
    {
        is_prime.clear();
        is_prime.resize(N,true);
        is_prime[0] = is_prime[1] = false;
        for(int i = 2; i <= N; i++)
        {
            if(is_prime[i])
            {
                for(int j = 2*i; j <= N; j += i)
                    is_prime[j] = false;
            }
        }
    }
    void f()
    {
        for(int i = 2; i < N; i++)
        {
            if(is_prime[i])prime.push_back(i);
        }
    }
    Node *primeList(Node *head){
        sieve();
        f();
        Node *temp = head;
        while(temp != NULL)
        {
            if(is_prime[temp->val]){
                // Do nothing :))
            }
            else{
                auto it = upper_bound(prime.begin(),prime.end(),temp->val)-prime.begin();
                if(it == 0)
                {
                    temp->val = prime[it];
                }
                else{
                    int c1 = prime[it], c2 = prime[it-1];
                    if(abs(c1-temp->val) < abs(c2-temp->val)) temp->val = c1;
                    else temp->val = c2;
                }
            }
            temp = temp->next;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends