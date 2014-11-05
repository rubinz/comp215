#include <iostream>
#include <string>

//Zevi Rubin, Assignment 1

// as asked in the HW, what makes a binary search tree unique is that an
// in order traversal of the tree will yield a sorted list of numbers, 
// regardless of the order they are inserted in. 

using namespace std;

//tree node class
class treeNode{
public:
	treeNode(int number);
	int key;
	int value;
	treeNode* left;
	treeNode* right;
private:
};

//binary search tree class
class binarySearchTree{

private:
	void destroy_tree(treeNode* leaf);
	void insert_help(int key, treeNode* leaf);
	bool search_help(int key, treeNode* leaf);
	void inOrder_help(treeNode* leaf);
	treeNode* root;

public:
	void inOrderTraversal();
	bool search(int key); //returns bool
	void insert(int key);
	binarySearchTree();
	~binarySearchTree();
};


//Constructor for binarySearchTree
binarySearchTree::binarySearchTree(){
	root = NULL;

}
//Destructor for binarySearchTree
binarySearchTree::~binarySearchTree(){
	destroy_tree(root);

}
//constructor for destroy tree
void binarySearchTree::destroy_tree(treeNode* leaf){
	if (leaf != NULL){
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf; 
	}
}

//Constructor for treeNode
treeNode::treeNode(int number){
	this->value = number;
	this->left = NULL;
	this->right = NULL;
}

//insert function
void binarySearchTree::insert(int key){
	if (root == NULL)
	{
		root = new treeNode(key);
	}
	else{
		insert_help(key, root);
	}
}
//search function
bool binarySearchTree::search(int key){
	return search_help(key, root);
}
//actual search function
bool binarySearchTree::search_help(int key, treeNode* leaf){
	if (leaf == NULL)
	{
		return false;
	}
	else if (leaf->value == key)
	{
		return true;
	}
	else if (key < leaf->value)
	{
		//cout << "too small" << endl;
		return search_help(key, leaf->left);
	}
	else
	{
		//cout << "too big" << endl;
		return search_help(key, leaf->right);
	}
}
//actual insert function
void binarySearchTree::insert_help(int key, treeNode* leaf){
	if ((key < leaf->value) and (leaf->left != NULL))
	{
		insert_help(key, leaf->left);
	}
	else if ((key < leaf->value) and (leaf->left == NULL))
	{
		leaf->left = new treeNode(key);
	}
	else if ((key > leaf->value) and (leaf->right != NULL))
	{
		insert_help(key, leaf->right);
	}
	else if ((key > leaf->value) and (leaf->right == NULL))
	{
		leaf->right = new treeNode(key);
	}
	else if (key == leaf->value)
	{
		cout << "value already exists in tree" << endl;
	}
}
//inOrderTraversal function
void binarySearchTree::inOrderTraversal()
{
	inOrder_help(root);
}
//inOrder_help function
void binarySearchTree::inOrder_help(treeNode* leaf)
{
	if (leaf == NULL)
	{
		return;
	}
	else if (leaf != NULL)
	{
		inOrder_help(leaf->left);
		cout << leaf->value << endl;
		inOrder_help(leaf->right);
	}

}

//driver main function
int main(){
	binarySearchTree myTree; //create test tree
	int temp;
	int findNode = 1;

	do
	{
		cout << "please enter a number in the tree? enter something 0 to continue to the next step" << endl;
		cin >> temp;
		if (temp>0)
		{
			myTree.insert(temp);
		}
	} while (temp > 0);

	while (findNode > 0)
	{
		cout <<  "would you like to find an integer? \n if so, please enter a integer. enter 0 to stop" << endl;
		cin >> findNode;
		if (findNode > 0)
		{
			if ((myTree.search(findNode)) == true)
			{
				cout << "we found the number: " << findNode << endl;
			}
			else if ((myTree.search(findNode)) == false)
			{
				cout << "could not find this value\n" << endl;
			}
		}
	}

	cout << "the in order traversal of this tree is: \n" << endl;
	myTree.inOrderTraversal();
	
	return 0;
}


