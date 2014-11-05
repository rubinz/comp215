// Comp_215_Lab_7.cpp : Defines the entry point for the console application.
//

//Programmer: Kamran Noorian

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <fstream>
#include <string>

using namespace std;

int* mark;
int* markPrime;
int counter;
int counterPrime;

class myGraph
{
public:
	myGraph();
	~myGraph();
	myGraph(int number);
	void DFS();
	void BFS();

	int nbVertices;
	int** adjMatrix;

private:
	void dfs(int v);
	void bfs(int v);
};

myGraph::myGraph()
{
	nbVertices = 0;
	adjMatrix = NULL;
}

myGraph::~myGraph()
{
	for (int i = 0; i < nbVertices; i++)
		delete[] adjMatrix[i];
	delete[] adjMatrix;
}

myGraph::myGraph(int number)
{
	nbVertices = number;
	adjMatrix = new int*[nbVertices];
	for (int i = 0; i < nbVertices; i++)
		adjMatrix[i] = new int[nbVertices];
}

void myGraph::DFS()
{
	mark = new int[nbVertices];
	markPrime = new int[nbVertices];
	counter = 0;
	counterPrime = 0;
	for (int i = 0; i < nbVertices; i++)
	{
		mark[i] = counter;
		markPrime[i] = counterPrime;
	}
	for (int v = 0; v < nbVertices; v++)
	{
		if (mark[v] == 0)
			dfs(v);
	}
	cout << "The order in which the vertices were added to the DFS Graph is: ";
	for (int i = 0; i < nbVertices; i++)
	{
		cout << mark[i] << ' ';
	}
	cout << endl;
	cout << endl;
	cout << "The order in which the vertices were popped is: ";
	for (int i = 0; i < nbVertices; i++)
	{
		cout << markPrime[i] << ' ';
	}
	cout << endl;
}

void myGraph::dfs(int v)
{
	counter++;
	mark[v] = counter;
	for (int w = 0; w < nbVertices; w++)
	{
		if (adjMatrix[v][w] == 1)
		{
			if (mark[w] == 0)
			{
				dfs(w);
			}
		}
	}
	counterPrime++;
	markPrime[v] = counterPrime;
}

void myGraph::BFS()
{
	mark = new int[nbVertices];
	counter = 0;
	for (int i = 0; i < nbVertices; i++)
	{
		mark[i] = counter;
	}
	for (int v = 0; v < nbVertices; v++)
	{
		if (mark[v] == 0)
			bfs(v);
	}
	cout << "The order in which the vertices were added to the BFS queue is: ";
	for (int i = 0; i < nbVertices; i++)
	{
		cout << mark[i] << ' ';
	}
}

void myGraph::bfs(int v)
{
	counter++;
	mark[v] = counter;
	queue <int> q = *new queue < int > ;
	while (!q.empty())
	{
		for (int w = 0; w < nbVertices; w++)
		{
			if (adjMatrix[q.front()][w] == 1)
			{
				if (mark[w] == 0)
				{
					counter++;
					mark[w] = counter;
					q.push(w);
				}
			}
		}
		q.pop();
	}
}

int main()
{
	ifstream myFile;
	string fileName;
	cout << "Please enter a file name for the input: ";
	getline(cin, fileName);
	myFile.open(fileName);
	string line;
	getline(myFile, line); //grab first line
	int vertices = atoi(line.c_str()); //set string line to an int
	myGraph g = myGraph(vertices);
	if (myFile.is_open())
	{
		getline(myFile, line);
		for (long i = 0; i < vertices; i++)
		{
			line.erase(remove(line.begin(), line.end(), ' '), line.end());
			for (int j = 0; j < vertices; j++)
			{
				if (line[j] == '1')
				{
					g.adjMatrix[i][j] = 1;
				}
				else if (line[j] == '0')
				{
					g.adjMatrix[i][j] = 0;
				}
			}
			getline(myFile, line);
		}
	}
	g.DFS();
	g.BFS();
	
	return 0;
}