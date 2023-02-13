// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/trees/construct-bst-from-inorder-traversal/ojquestion

#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int val)
    {
        this->val = val;
    }
};
// logic code
TreeNode* helper(vector<int> in,int le,int ri)
{
    if(le>ri)
    return NULL;
    
    int mid=(le+ri)/2;
    TreeNode* node=new TreeNode(in[mid]);
    
    node->left=helper(in,le,mid-1);
    node->right=helper(in,mid+1,ri);
    return node;
    
}

TreeNode *constructFromInOrder(vector<int> &in)
{
    return helper(in,0,in.size()-1);
}

// input_Section_====================================================================

void display(TreeNode *node)
{
    if (node == nullptr)
        return;

    string str = "";
    str += ((node->left != nullptr ? to_string(node->left->val) : "."));
    str += (" -> " + to_string(node->val) + " <- ");
    str += ((node->right != nullptr ? to_string(node->right->val) : "."));

    cout << str << endl;

    display(node->left);
    display(node->right);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> in(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }

    TreeNode *root = constructFromInOrder(in);
    display(root);
}

int main()
{
    solve();
    return 0;
}