//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string s, int n)
    {
        string upperCase = "", lowerCase = "", ans = "";
        for(char c : s)
        {
            if(c >= 'a' && c <= 'z') lowerCase += c;
            else upperCase += c;
        }
        sort(upperCase.begin(),upperCase.end());
        sort(lowerCase.begin(),lowerCase.end());
        
        int i = 0, j = 0;
        for(int k = 0; k < n; k++)
        {
            if(s[k] >= 'a' && s[k] <= 'z') ans += lowerCase[i], i++;
            else ans += upperCase[j], j++;
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
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends