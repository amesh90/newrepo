
#include <bits/stdc++.h>

using namespace std;
 

void printVector(const vector<int>& v, int i)
{
    for (int j=i; j<v.size(); j++)
        cout << v[j] << " ";
    cout << endl;
}
 
// binary tree node
struct Node
{
    int data;
    Node *left,*right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};


void printallPaths_rec(Node *root, vector<int>& paths, int Goal)
{
    // cout <<"STEP 1\n";
    if(root == NULL) return;
    paths.push_back(root->data);

    // cout <<"STEP 2\n";
    printallPaths_rec(root->left, paths, Goal);

    // cout <<"STEP 3\n";
    printallPaths_rec(root->right, paths, Goal);

    int sum = 0;
    for (int i=paths.size()-1; i>= 0; i--)
    {
        // cout <<"STEP 4\n";
        sum += paths[i];
        if(sum == Goal)
            printVector(paths, i);
    }
    // cout <<"STEP 5\n";
    paths.pop_back();

} 

 
void printallPaths(Node *root, int Goal)
{
    vector<int> path;
    printallPaths_rec(root,path, Goal);
}
 
int main()
{
    int k;
    cin >> k;

    Node *root = new Node(5);
    root->left = new Node(-10);
    root->left->left = new Node(9);
    root->left->right = new Node(8);
    // root->left->right->left = new Node(1);
    root->right = new Node(3);
    root->right->left = new Node(-4);
    // root->right->left->left = new Node(1);
    // root->right->left->right = new Node(2);
    root->right->right = new Node(7);
    // root->right->right->right = new Node(2);
    

    printallPaths(root, k);
 
    return 0;
}
