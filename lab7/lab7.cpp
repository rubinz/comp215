//zevi rubin
//Algorithms 
//lab 7

# include <iostream>
# include <string>
# include <string.h>
# include <fstream>
# include <time.h>
# include <math.h>
# include <stdio.h>
# include <queue>
# include <sstream>

using namespace std;



int* marker1;
int counter1;
int counter2;
int* marker2;

class myGraph
{
public:
	int nbVertices;
	int** adjMatrix;
	void DFS();
	void BFS();
	myGraph();
	myGraph(int value);
	~myGraph();
private:
	void dfs(int v);
	void bfs(int v);
};

// myGraph::myGraph();
// myGraph::myGraph(int value);
// myGraph::~myGraph();
// void myGraph::DFS();
// void myGraph::BFS();
// void myGraph::bfs(int v);
// int openFile();

myGraph::myGraph(){
	nbVertices = 0;
	adjMatrix = NULL;
}
myGraph::myGraph(int value){
	nbVertices = value;
	adjMatrix = new int*[nbVertices];
	for (int i=0; i<nbVertices; i++)
		adjMatrix[i] = new int[nbVertices];
}

myGraph::~myGraph(){
	for (int i=0; i<nbVertices; i++)
		delete [] adjMatrix[i];
	delete[] adjMatrix;
}


void myGraph::DFS(){
	marker1 = new int[nbVertices];
	marker2 = new int[nbVertices];
	counter1 = 0;
	counter2 = 0;
	for (int i = 0; i < nbVertices; i++)
	{
		marker1[i] = counter1;
		marker2[i] = counter2;
	}
	for (int h = 0; h < nbVertices; h++)
	{
		if (marker1 [h] == 0)
			dfs (h);
	}
	cout << "The original order was " << "\n" << endl;
	for (int i = 0; i < nbVertices; i++)
	{
		cout << marker1[i] << ' ';
	}
	cout << "the post DFS order is " << "\n" << endl;
	for (int i = 0; i < nbVertices; i++)
	{
		cout << marker2[i] << ' ';
	}
}


void myGraph::BFS(){
	marker1 = new int[nbVertices];
	counter1 = 0;
	for (int i = 0; i < nbVertices; i++)
	{
		marker1[i] = counter1;
	}
	for (int h = 0; h < nbVertices; h++)
	{
		if (marker1[h] == 0)
			bfs(h);
	}
	cout << "The BFS order is " << "\n" << endl;
	for (int i = 0; i < nbVertices; i++)
	{
		cout << marker1[i] << ' ';
	}
}


void myGraph::bfs(int v){
	counter1++;
	marker1[v] = counter1;
	queue <int> q = *new queue < int > ;
	while (!q.empty()){
		for (int i = 0; i < nbVertices; i++){
			if (adjMatrix[q.front()][i] == 1)
				if (marker1[i] == 0){
					counter1++;
					marker1[i] = counter1;
					q.push(i);
				}
		}
		q.pop();
	}
}


void myGraph::dfs(int v)
{
	counter1++;
	marker1[v] = counter1;
	for (int i = 0; i < nbVertices; i++)
	{
		if (adjMatrix[v][i] == 1)
		{
			if (marker1[i] == 0)
			{
				dfs(i);
			}
		}
	}
	counter2++;
	marker2[v] = counter2;
}


int openFile(){
	string response, line;
	int number1, number2, vertices, a, b;
	cout << "Please enter the name of the input file you want to use: " << endl;
	cin >> response;

	char *c_response = new char[response.length()+1];
	strcpy(c_response, response.c_str());

	stringstream stringNumber;
	ifstream myFile(c_response);
	ofstream myfile;
	//myfile.open(c_response);
	getline(myFile, line);
	istringstream iss(line);
	iss >> vertices;
	// NBLINES = number1;
	myGraph Graph = myGraph(vertices);
	int counter = 0;
	if (myFile.is_open()){
		getline(myFile, line);
		for (int i = 0; i < vertices; i++){
			line.erase(remove(line.begin(), line.end(), ' '), line.end());
			for (int j = 0; j < vertices; j++){
				if (line[j] == '1'){
					Graph.adjMatrix[i][j] = 1;
				}
				else if (line[j] == '0'){
					Graph.adjMatrix[i][j] = 0;
				}
			}
			getline(myFile, line);
		}	
	}
	Graph.DFS();
	Graph.BFS();

}

int main (){openFile(); return 0;}