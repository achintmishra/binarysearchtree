#include <iostream>
using namespace std;
template <typename T>
class BinaryTreeNode{
public:
T data;
BinaryTreeNode *left;
BinaryTreeNode *right;
BinaryTreeNode(T data)
{
this->data=data;
left=NULL;
right=NULL;
}
~BinaryTreeNode()
{
delete left;
delete right;
}
};
class BST{
BinaryTreeNode <int> *root;
public:
BST()
{
root=NULL;
}
~BST()
{
delete root;
}
private:
bool hasData(int data,BinaryTreeNode <int> *node)
{
if(node==NULL)
return false;
if(node->data==data)
return true;
else if(data<node->data)
{
return hasData(data,node->left);
}
else{
return hasData(data,node->right);
}
}
public:
bool hasData(int data)
{
return hasData(data,root);
}
private:
BinaryTreeNode <int> *deleteData(int data,BinaryTreeNode <int> *node)
{
if(node==NULL)
{
return NULL;
}
if(data > node->data)
{
node->right=deleteData(data,node->right);
}
else if(data < node->data)
{
node->left=deleteData(data,node->left);
}
else
{
if(node->left==NULL && node->right==NULL)
{
delete node;
return NULL;
}
else if(node->left==NULL)
{
BinaryTreeNode <int> *temp=node->right;
node->right=NULL;
delete node;
return temp;
}
else if(node->right==NULL)
{
BinaryTreeNode <int> *temp=node->left;
node->left=NULL;
delete node;
return temp;
}
else
{
BinaryTreeNode <int> *minNode=node->right;
while(minNode->left!=NULL)
{
minNode=minNode->left;
}
int rightMin=minNode->data;
node->data=rightMin;
node->right=deleteData(rightMin,node->right);
return node;
}
}
return node;
}
void printTree(BinaryTreeNode <int> *root)
{
if(root==NULL)
{
return;
}
cout<<root->data<<" : ";
if(root->left!=NULL)
{
cout<<" L "<<root->left->data;
}
if(root->right!=NULL)
{
cout<<" R "<<root->right->data;
}
cout<<endl;
printTree(root->left);
printTree(root->right);
}
public:
void deleteData(int data)
{
root=deleteData(data,root);
}
void printTree()
{
printTree(root);
}
private:
BinaryTreeNode <int> *insert(int data,BinaryTreeNode <int> *node)
{
if(node==NULL)
{
BinaryTreeNode <int> *newNode=new BinaryTreeNode <int> (data);
return newNode;
}
if(data < node->data)
{
node->left=insert(data,node->left);
}
else
{
node->right=insert(data,node->right);
}
return node;
}
public:
void insert(int data)
{
this->root=insert(data,this->root);
}
};
int main()
{
BST *tree = new BST();
int choice, input;
cout<<"Enter 1 for insert"<<endl;
cout<<"Enter 2 for delete"<<endl;
cout<<"Enter 3 for search"<<endl;
while(true){
cin>>choice;
switch(choice){
case 1:
cin >> input;
tree->insert(input);
break;
case 2:
cin >> input;
tree->deleteData(input);
break;
case 3:
cin >> input;
if(tree->hasData(input)) {
cout << "true" << endl;
}
else {
cout << "false" << endl;
}
break;
default:
tree->printTree();
return 0;
break;
}
}
return 0;
}