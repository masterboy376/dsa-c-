#include "bits/stdc++.h"
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int height(node* root){
    if(root == NULL){
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
}

int calcDiameter(node* root){ //O(n^2)
    if(root == NULL){
        return 0;
    }
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    int currDiameter = lHeight + rHeight + 1;

    int lDiameter = calcDiameter(root->left);
    int rDiameter = calcDiameter(root->right);
    
    return max( currDiameter, max(lDiameter, rDiameter));
}

int calcDiameter(node* root, int* height){ //O(n)
    if(root == NULL){
        *height =0;
        return 0;
    }
    int lHeight = 0;
    int rHeight = 0;
    int lDiameter = calcDiameter(root->left);
    int rDiameter = calcDiameter(root->right);
    int currDiameter = lHeight + rHeight + 1;

    *height =max(lHeight,rHeight) +1;


    return max( currDiameter, max(lDiameter, rDiameter));
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

    int height = 0;
    cout<<calcDiameter(root , &height)<<endl;

    return 0;
}