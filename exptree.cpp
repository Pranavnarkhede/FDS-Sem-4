#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    char data;
    Node *left, *right;
    
    Node(char data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void recursiveInorder(Node *root) 
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        if (root != NULL)
	    {
            recursiveInorder (root->left);
            cout << root->data;
            recursiveInorder (root->right);
        }
    }
}
void recursivePreorder(Node *root) 
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        if (root != NULL)
	    {
            cout << root->data;
            recursivePreorder (root->left);
            recursivePreorder (root->right);
        }
    }
}
void recursivePostorder(Node *root) 
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        if (root != NULL)
	    {
            recursivePostorder (root->left);
            recursivePostorder (root->right);
            cout << root->data;
        }
    }
}
void iterativeInorder(Node *root)
{
    stack<Node*> s;
    Node *curr = root;
    bool done = false;
    while(!done)
    {
        if(curr != NULL)        //if the node is intermediate or root
        {
            s.push(curr);
            curr = curr->left;
        }
        else                    //if the node is leaf node
        {
            if(!s.empty())
            {
                curr = s.top();
                s.pop();
                cout << curr->data;
                curr = curr->right;
            }
            else
            {
                done = true;
            }
        }
    }
}
void iterativePreorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    stack<Node*> s;
    s.push(root);
    while(!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        cout << temp->data;
        if(temp->right)
        {
            s.push(temp->right);
        }
        if(temp->left)
        {
            s.push(temp->left);
        }
    }
}
void iterativePostorder(Node *root)
{
    stack<Node*> s;
    Node* lastVisited = NULL;
    while (root or !s.empty()) 
    {
        if (root) 
        {
            s.push(root);
            root = root->left;
        } 
        else 
        {
            Node* peekNode = s.top();
            if (peekNode->right && peekNode->right != lastVisited) 
            {
                root = peekNode->right;
            } 
            else 
            {
                cout << peekNode->data ;
                lastVisited = peekNode;
                s.pop();
            }
        }
    }
}
void operand (char b , stack<Node*> &st) 
{
    Node *root = new Node(b);
    st.push(root);
} 
void operators (char a , stack<Node*> &st)
{
    Node *root = new Node(a);
    root->right = st.top ();   
    st.pop();
    root->left = st.top ();
    st.pop();
    st.push(root);
} 
int main() 
{
    int i = 0;
    char *postfix = new char[20];
    cout << "enter postfix expression : ";
    cin >> postfix;
    stack<Node*> st;
    while (postfix[i] != '\0')
    {
        if(isalnum(postfix[i]))
    	{
            operand (postfix[i] , st);
        }
        else
	    {
            operators (postfix[i] , st);
        }
        i++;
    }

    cout << "recursive inorder : " << endl ;
    recursiveInorder (st.top());
    cout << endl;

    cout << "iterative inorder " << endl;
    iterativeInorder (st.top());
    cout << endl;

    cout << "recursive preorder " << endl;
    recursivePreorder (st.top());
    cout << endl;

    cout << "iterative preorder " << endl;
    iterativePreorder (st.top());
    cout << endl;

    cout << "recursive postorder " << endl;
    recursivePostorder (st.top());
    cout << endl;

    cout << "iterative postorder " << endl;
    iterativePostorder (st.top());
    cout << endl;
    return 0;
}
