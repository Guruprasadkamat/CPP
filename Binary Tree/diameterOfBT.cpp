#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val)
    {
        data = val;
        left=NULL;
        right=NULL;
    }
};
int calcHeight(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int leftHeight = calcHeight(root->left);
    int rightHeight = calcHeight(root->right);
    return max(leftHeight,rightHeight) + 1;
}
///Diameter of Binary Tree
int calcDiameter(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);
    int currDiameter = lHeight + rHeight +1;
    int lDiameter = calcDiameter(root->left);
    int rDiameter = calcDiameter(root->right);

    return max(currDiameter,max(lDiameter,rDiameter));
}

int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right= new Node(5);
    root->right->left = new Node(4);
    root->right->right= new Node(5);
    cout<<calcDiameter(root)<<endl;

}

