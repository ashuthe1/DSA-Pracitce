//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


// } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

Node *reverse(Node *head, Node *last)
{
    if(head == NULL || head->next == NULL) return head;
    Node *p = NULL, *cur = head, *n = head->next;
        
    while(cur != last)
    {
        cur->next = p;
        p = cur;
        cur = n;
        if(n != last) n = n->next;
    }
    return p;
}
void dis(Node *h)
{
    Node *t = h;
    cout << "List is : ";
    while(t != NULL)
    {
        cout << t->data << " ";
    }
    cout << endl;
}
class Solution
{
    public:
    Node* reverseBetween(Node* head, int m, int n)
    {
        Node *f = head, *pf = head, *s = head, *ns = NULL,*t = head;
        int siz = 0;
        while(t != NULL) siz++, t = t->next;
        for(int i = 1; i < m; i++){
            pf = f;
            f = f->next;
        }
        
        for(int i = 1; i < n; i++){
            s = s->next;
        }
        ns = s->next;
        // cout << f->data << " " << ns->data <<endl;
        Node * rev = reverse(f,ns);
        if(m == 1) head = rev;
        else pf->next = rev;
        // Node *rev = reverse(f,ns);
        if(n == siz) f->next = NULL;
        else f->next = ns; 
        
        return head;
    }
};

//{ Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}

// } Driver Code Ends