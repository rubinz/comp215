//
// Zevi Rubin, Lab 04
// This is lab 04. I still have a lot of work to do on it and should deffinitely have asked for an extension wednesday after lab.
// I know I wont be able to finish all the functions tonight, so I prototyped them and wrote the ones I could in the time I had. 
// I will see about finishing this up over the weekend and hope you can give some credit for the work I have done and will do over the weekend.
// Thanks! -Zevi

# include <iostream>
# include <string>
# include <fstream>
# include <time.h>
# include <math.h>

using namespace std;

void generateFile(){
	//srand(time(NULL));
	int value1=0;
	int value2=0;
	ofstream myfile;
	myfile.open ("InputNumbers.dat");
	if (myfile.is_open())
	{

		for (int i = 0; i < 1000; ++i) {
			value1 = rand(); 
			value2 = rand(); 
			myfile <<  value1 << " " << value2 << "\n"; }
	myfile.close();		}
	else {cout << "unable to open file" << endl;}
}

class integerPairs
{
public:
	int value1;
	int value2;
	integerPairs(){};
	integerPairs(int a, int b);
	~integerPairs();
	bool operator==(integerPairs p);
	bool operator>(integerPairs p);
	bool operator<(integerPairs p);
	bool operator<=(integerPairs p);
	bool operator>=(integerPairs p);
};
bool integerPairs::operator==(integerPairs p){ return (value1==p.value1) && (value2==p.value2);}
bool integerPairs::operator>(integerPairs p){ return (value1<p.value1) && (value2<p.value2);}
bool integerPairs::operator<(integerPairs p){ return (value1>p.value1) && (value2>p.value2);}
bool integerPairs::operator<=(integerPairs p){ return (value1<=p.value1) && (value2<=p.value2);}
bool integerPairs::operator>=(integerPairs p){ return (value1>=p.value1) && (value2>=p.value2);}

integerPairs::integerPairs(int a, int b){
	value1 = a;
	value2 = b;
}



integerPairs* readFile(int nbLines){

	integerPairs *a = new integerPairs[nbLines];
	string line;
	int counter = 0;

	ifstream myfile("InputNumbers.dat");
	myfile.open("InputNumbers");

	if(myfile.is_open()){
		getline(myfile, line);

		for(int i=0; i<nbLines; i++){
			int counter = line.find(" ");
			int num1=stoi(line.substr(0, counter));
			int num2=stoi(line.substr(counter+1));
			integerPairs p=integerPairs(num1, num2);
			a[i]=p;
			getline(myfile, line);
			cout << "getting number" << endl;
		}
	}
	else{
		cout << "couldnt find file" << endl;	}
	return a;
}

// int ourSort(integerPairs *a){
// 	//sorts integers in order increasing.
// }


// int findMax(integerPairs *a, int n){

//return 0;
// }

// int outSort(integerPairs *a, int n){

//return 0;
// }


int ourTreeTiming(int nbLines){
	int* size = readFile(nbLines);

	clock_t start,end;
	start = clock();
	binarySearchTree myTree; //create test tree
	int temp;
	int findNode = 1;

	//insert all size elements into array

	end = clock();
	cout << "The computation took " << (end - start) << " clock ticks to run." << endl;}
	//cout depth of the tree

	delete a;
	myTree.destroy_tree(treeNode* leaf);
	return 0;
}


int outSortTiming(int size){
	int pointerSize = readFile(size)

	clock_t start,end;
	start = clock();
	ourSort(integerPairs *a);
	end = clock();
	cout << "The computation took " << (end - start) << " clock ticks to run." << endl;}
	delete a;

return 0;
}

int main()
{
	


	cout << "in main" << endl;
	//generateFile();
	int nbLines = 1000;
	readFile(nbLines);
	int integers[10000];

	
	return 0;
}
//==============================================================
//BINARY SEARCH TREE STUFF BELOW HERE!!!!=======================
//==============================================================

class treeNode{
public:
	treeNode(int integerPairs);
	int key;
	int value;
	treeNode* left;
	treeNode* right;
private:
};

//binary search tree class
class binarySearchTree{

private:
	int depth() {//return depth of tree
	};
	void destroy_tree(treeNode* leaf);
	void insert_help(int key, treeNode* leaf);
	bool search_help(int key, treeNode* leaf);
	void inOrder_help(treeNode* leaf);
	treeNode* root;

public:
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
treeNode::treeNode(int value1, int value2){
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



