/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

Node* right_rotate(Node* node)
{
    Node*a=node,*b=node->left;
    
    a->left=b->right;
    b->right=a;
    
    a->height=1+max(a->left?a->left->height:0,a->right?a->right->height:0);
    b->height=1+max(b->left?b->left->height:0,b->right?b->right->height:0);
    return b;
}

Node* left_rotate(Node* node){
    Node*a=node,*b=node->right;
    
    a->right=b->left;
    b->left=a;
    // as node a goes down and b node comes up
    // therefor update height of "a" first then update height of "b"
    a->height=1+max(a->left?a->left->height:0,a->right?a->right->height:0);
    b->height=1+max(b->left?b->left->height:0,b->right?b->right->height:0);
    return b;
}
class Solution{
  public:
    /*You are required to complete this method */
    Node* insertToAVL(Node* node, int data)
    {
        //Your code here
        if(node==NULL)
        return new Node(data);
        int x=node->data;
        
        if(data>x) 
        node->right=insertToAVL(node->right,data);
        else if(data<x) 
        node->left=insertToAVL(node->left,data);
        // else 
        // return node;
        
        int l=(node->left?node->left->height:0);
        int r=(node->right?node->right->height:0);
        
        node->height=1+max(l,r);
        
        int balance=l-r;
        
        if(balance>1 and data<(node->left->data)) // LL rotation
        {
            node = right_rotate(node);
        }
        else if(balance>1 and data>(node->left->data)) // LR rotation
        {
            node->left=left_rotate(node->left); // L rotation
            node = right_rotate(node);// R rotation
        }
        else if(balance<-1 and data>(node->right->data))// RR rotation
        {
            node = left_rotate(node);// L rotation
        }
        else if(balance<-1 and data<(node->right->data)) // RL rotation
        {
            node->right=right_rotate(node->right);// R rotation
            node = left_rotate(node); // L rotation
        }
        
        return node;
    }
};
