#include "bits/stdc++.h"
using namespace std;
/*
-properties-
1. max nodes at level L = 2^L
2. max nodes in a tree of height H = 2^H - 1
3. for N nodes, min possible height = log2(N+1)
4. a binary tree with L leaves has at least log2(N+1) + 1 number of levels
*/
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
    
};

int maxPathSumUtil(node* root, int &ans){
    if(root==NULL){
        return 0;
    }
    int left = maxPathSumUtil(root->left, ans);
    int right = maxPathSumUtil(root->right, ans);

    int nodeMax = max(max(root->data, root->data+left+right), max(root->data+left, root->data+right));
    ans = max(ans, nodeMax);
    return max(root->data, max(root->data + left, root->data + right));
}

int maxPathSum(node* root){
    int ans=INT32_MIN;
    maxPathSumUtil(root, ans);
    return ans;
}

/*
            10
          /    \
        5       15
       / \     
      3   9
*/

int main()
{
    node * root = new node(10);
    node * l = new node(5);
    node * ll = new node(3);
    node * lr = new node(9);
    node * r = new node(15);

    root->left = l;
    root->right = r;
    l->left = ll;
    l->right = lr;
    
    cout<<maxPathSum(root)<<endl;

    return 0;
}