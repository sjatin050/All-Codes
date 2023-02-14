/* Node is as follows:

struct Node
{
	int data, height;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		height = 1;
		left = right = NULL;
	}
};

*/

Node* right_rotate(Node* node)
{
    if(node==NULL)
    return NULL;
    Node*a=node,*b=node->left;
    
    a->left=b->right;
    b->right=a;
    
    a->height=1+max(a->left?a->left->height:0,a->right?a->right->height:0);
    b->height=1+max(b->left?b->left->height:0,b->right?b->right->height:0);
    return b;
}

Node* left_rotate(Node* node)
{
    if(node==NULL)return NULL;
    Node*a=node,*b=node->right;
    
    a->right=b->left;
    b->left=a;
    // as node a goes down and b node comes up
    // therefor update height of "a" first then update height of "b"
    a->height=1+max(a->left?a->left->height:0,a->right?a->right->height:0);
    b->height=1+max(b->left?b->left->height:0,b->right?b->right->height:0);
    return b;
}

Node* min_element(Node* root)
{
    while(root->left)
    root=root->left;
    return root;
}

int getBalance(Node* root)
{
    int l=(root->left?root->left->height:0);
    int r=(root->right?root->right->height:0);
    
    return l-r;
}

Node* deleteNode(Node* root, int data)
{
    //add code here,
    if(root==NULL)
    return NULL;
     
    if(data>(root->data))
    root->right=deleteNode(root->right,data);
    else if(data<(root->data))
    root->left=deleteNode(root->left,data);
    else
    {
        // if node is leaf
        if(root->left==NULL and root->right==NULL)
        {
            root=NULL;
        }// if node has only one child
        else if(root->left==NULL or root->right==NULL)
        {
            if(root->left)
            {
                // it copies full node directly 
                *root=*(root->left);
            }
            else 
            {
                // it copies full node directly 
                *root=*(root->right);
            }
        }
        else // if node has both child then copy inorder successor
        {
            Node* temp=min_element(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
        }
    }
    // if while deleting node becomes NULL then return it
    if(root==NULL)
    return NULL;
    
    // correcting the height
    int l=(root->left?root->left->height:0);
    int r=(root->right?root->right->height:0);
    
    root->height=1+max(l,r);
    
    int balance=l-r;
    // getimbalence is used to know in which direction to rotate
    // balance will tell whether left subtree height is more or right subtree height is more
    // and imbalance tells in left or right subtree ..next which direction to take i.e. left or right
    if(balance>1 and getBalance(root->left)>=0) //LL --> L is get from imbalance and L is get from getimbalence
    {
        root = right_rotate(root);
    }
    else if(balance>1 and getBalance(root->left)<0)//LR --> L is get from imbalance and R is get from getimbalence
    {
        root->left=left_rotate(root->left);
        root = right_rotate(root);
    }
    else if(balance<-1 and getBalance(root->right)<=0)//RR --> R is get from imbalance and R is get from getimbalence
    {
        root = left_rotate(root);
    }
    else if(balance<-1 and getBalance(root->right)>0)//RL --> R is get from imbalance and L is get from getimbalence
    {
        root->right=right_rotate(root->right);
        root = left_rotate(root);
    }
    
    return root;
}