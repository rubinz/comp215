//zevi rubin
//Algorithms 
//lab 8

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
int binarySearch(int* intArray, int nblines, int element);

void insertionSort(int intArray[], int nblines){
	int v, j;
	for (int i = 0; i<nblines; i++){
		v = intArray[i];
		j = (i-1);
		while ((j>=0) and (intArray[j]>v)){
			intArray[j+1] = intArray[j];
			j = (j-1);
		}  
		intArray[j+1] = v;
	}
	for (int z = 0; z < nblines; z++){
		cout << intArray[z] << ", " << endl;
	}

	int element = 0;
	cout << "enter the next element k you want to find in the array: " << endl;
	cin >> element;
	int foundIndex = binarySearch(intArray, nblines, element);


	while (foundIndex != -1){
		cout << "found the element at: " << foundIndex << endl;
		cout << "enter the next element k you want to find in the array: " << endl;
		cin >> element;
		foundIndex = binarySearch(intArray, nblines, element);

	}
}

int binarySearch(int* intArray, int nblines, int element){
	bool inArray = true;
	bool found = false;
	int l, m, r;
	l = 0;
	r = nblines - 1;
	

	while ((l<=r)){
		m = floor((l+r)/2);
		
		if (element == intArray[m]){
			//cout << "found the element at: " << m << " index" << endl;
	
			return m;
			}
		else if (element < intArray[m]){
		
			r = m-1;}
		else if (element > intArray[m]){	
		
				l = m+1;}	
	}
	return -1;
}

int main(){
	string response, line;
	int nblines, a;
	cout << "Please enter the name of the input file you want to use: " << endl;
	cin >> response;

	char *c_response = new char[response.length()+1];
	strcpy(c_response, response.c_str());

	stringstream stringNumber;
	ifstream myFile(c_response);
	ofstream myfile;
	getline(myFile, line);
	istringstream iss(line);
	iss >> nblines;
	//cout << "got here" << nblines << endl;
	int *intArray = new int[nblines]; 
	int counter = 0;

	while (getline(myFile, line))
		{
		    istringstream iss(line);
 			
		    iss >> a;
		   	//cout << "int is: " << a << endl;

			intArray[counter] = a;
			
			counter++;
		}	
	//cout << intArray[4818] << endl;

	insertionSort(intArray, nblines);
	

	return 0;
}