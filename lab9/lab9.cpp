//zevi rubin
//Algorithms 
//lab 9

# include <iostream>
# include <string>
# include <string.h>
# include <fstream>
# include <time.h>
# include <math.h>
# include <stdio.h>
# include <queue>
# include <sstream>
#include <stdlib.h>
#include <cmath>

using namespace std;

class myItem
{
public:
	int serialNumber;
	string name;
	myItem(){};
	myItem(int sn, string s);
	~myItem(){};
	
	bool operator==(myItem serial);
	bool operator>(myItem serial);
	bool operator<(myItem serial);
	bool operator<=(myItem serial);
	bool operator>=(myItem serial);
	bool operator==(myItem serial[]);
	bool operator<(myItem serial[]);
	bool operator<=(myItem serial[]);
	bool operator>(myItem serial[]);
	bool operator>=(myItem serial[]);

};


//=====================================================================================
//=====================================================================================
void mergeSort(myItem intArray[], int size);
void merge(myItem b[], myItem c[], myItem intArray[], int numberFloor, int numberCeiling);
void lomutoSort(myItem intArrayl[], int l, int r);
int lomutoPartition(myItem A[], int l, int r);
void hoareSort(myItem intArrayh[], int l, int r);
int hoarePartition(myItem intArrayh[], int l, int r);

//=====================================================================================
//=====================================================================================
void cmergeSort(myItem intArray[], int size);
void cmerge(myItem b[], myItem c[], myItem intArray[], int numberFloor, int numberCeiling);
void clomutoSort(myItem intArrayl[], int l, int r);
int clomutoPartition(myItem A[], int l, int r);
void choareSort(myItem intArrayh[], int l, int r);
int choarePartition(myItem intArrayh[], int l, int r);

//=====================================================================================
//=====================================================================================
bool myItem::operator==(myItem serial[]){return (this->serialNumber == serial->serialNumber);}
bool myItem::operator>(myItem serial[]){return (this->serialNumber > serial->serialNumber);}
bool myItem::operator<(myItem serial[]){return (this->serialNumber < serial->serialNumber);}
bool myItem::operator<=(myItem serial[]){return (this->serialNumber <= serial->serialNumber);}
bool myItem::operator>=(myItem serial[]){return (this->serialNumber >= serial->serialNumber);}

bool myItem::operator==(myItem serial){return (this->serialNumber == serial.serialNumber);}
bool myItem::operator>(myItem serial){return (this->serialNumber > serial.serialNumber);}
bool myItem::operator<(myItem serial){return (this->serialNumber < serial.serialNumber);}
bool myItem::operator<=(myItem serial){return (this->serialNumber <= serial.serialNumber);}
bool myItem::operator>=(myItem serial){return (this->serialNumber >= serial.serialNumber);}

//=====================================================================================
//=====================================================================================


//GLOBAL VARIABLE:
int countNumber = 0;

myItem::myItem(int sn, string s){
	serialNumber = sn;
	name = s;
}

void lomutoSort(myItem intArrayl[], int l, int r)
{
	if (l < r)
	{
		int s = lomutoPartition(intArrayl, l, r);
		lomutoSort(intArrayl, l, s-1);
		lomutoSort(intArrayl, s+1, r);
	}
}

int lomutoPartition(myItem intArrayl[], int l, int r)
{
	int pivotPoint = intArrayl[l].serialNumber;
	int s = l;
	for (int i = l+1; i < r; i++)
	{
		if (intArrayl[i].serialNumber < pivotPoint)
		{
			s += 1;
			swap(intArrayl[s], intArrayl[i]);
		}
	}
	swap(intArrayl[l], intArrayl[s]);
	return s;
}

void mergeSort(myItem intArray[], int size){
	if (size > 1){
		int numFloor = floor((size/2));
		int numCeiling = size - numFloor;
		myItem Left[numFloor];
		myItem Right[numCeiling];
		for (int i = 0; i < numFloor; i++){
			Left[i] = intArray[i];}
		for (int j = numFloor, k = 0; j < size; j++, k++){
			Right[k] = intArray[j];}

		mergeSort(Left, numFloor);
		mergeSort(Right, numCeiling);
		merge(Left, Right, intArray, numFloor, numCeiling);
	}
}

void merge(myItem Left[], myItem Right[], myItem intArray[], int sizeL, int sizeR){
	int i = 0;	
	int j = 0;	
	int k = 0;	

	while ((i < sizeL) and (j < sizeR)){
		if (Left[i] <= Right[j]){
			intArray[k] = Left[i];
			i++;
		}
		else{
			intArray[k] = Right[j];
			j++;}
		k++;}
	if (i == sizeL){
		for (; j < sizeR; j++, k++){
			intArray[k] = Right[j];}
	}
	else{
		for (; i < sizeL; i++, k++){
			intArray[k] = Left[i];}
	}
}

void hoareSort(myItem intArrayh[], int l, int r){
	if (l < r){
		int s = hoarePartition(intArrayh, l, r);
		hoareSort(intArrayh, l, s-1);
		hoareSort(intArrayh, s+1, r);}
	
}

int hoarePartition(myItem intArrayh[], int l, int r){
	myItem pivotPoint;

	if (intArrayh[l] < intArrayh[r]) {
        pivotPoint = intArrayh[l] ;} 
    else{
        swap(intArrayh[l],  intArrayh[r]) ;
        pivotPoint = intArrayh[l] ;} 
	int i = l;
	int j = r+1;

	do {
		do {
			i += 1;
		} while (intArrayh[i] < pivotPoint);
		do {
			j -= 1;
		} while (intArrayh[j] > pivotPoint);
		swap(intArrayh[i], intArrayh[j]);
	} while (i < j);

	swap(intArrayh[i], intArrayh[j]);
	swap(intArrayh[l], intArrayh[j]);
	return j;
}

//===================================================================================
//=====================================================================================
//=====================================================================================
void clomutoSort(myItem intArrayl[], int l, int r){
	if (l < r){
		countNumber++;

		int s = clomutoPartition(intArrayl, l, r);
		clomutoSort(intArrayl, l, s-1);
		clomutoSort(intArrayl, s+1, r);
	}
	countNumber++;
}

int clomutoPartition(myItem intArrayl[], int l, int r)
{
	int pivotPoint = intArrayl[l].serialNumber;
	int s = l;
	for (int i = l+1; i < r; i++)
	{
		countNumber++;

		if (intArrayl[i].serialNumber < pivotPoint)
		{
			countNumber++;

			s = s + 1;
			swap(intArrayl[s], intArrayl[i]);
		}
		countNumber++;

	}
		countNumber++;

	swap(intArrayl[l], intArrayl[s]);
	return s;
}

void cmergeSort(myItem intArray[], int size){
if (size > 1){
		countNumber++;
		int numFloor = floor((size/2));
		int numCeiling = size - numFloor;
		myItem b[numFloor];
		myItem c[numCeiling];
		for (int i = 0; i < numFloor; i++){
			countNumber++;
			b[i] = intArray[i];}
		countNumber++;
		for (int j = numFloor, k = 0; j < size; j++, k++){
			countNumber++;
			c[k] = intArray[j];}
		countNumber++;

		cmergeSort(b, numFloor);
		cmergeSort(c, numCeiling);
		cmerge(b, c, intArray, numFloor, numCeiling);}
	countNumber++;
}

void cmerge(myItem b[], myItem c[], myItem intArray[], int sizeL, int sizeR){
	int i = 0;	
	int j = 0;	
	int k = 0;	

	while ((i < sizeL) and (j < sizeR)){
		countNumber++;
		if (b[i] <= c[j])
		{
			countNumber++;
			intArray[k] = b[i];
			i++;
		}
		else
		{
			countNumber++;
			intArray[k] = c[j];
			j++;
		}
		k++;
	}
	countNumber++;
	if (i == sizeL)
	{
		countNumber++;
		for (; j < sizeR; j++, k++)
		{
			countNumber++;
			intArray[k] = c[j];
		}
	}
	else
	{
		countNumber++;
		for (; i < sizeL; i++, k++)
		{
			countNumber++;
			intArray[k] = b[i];
		}
	}
}

void choareSort(myItem intArrayh[], int l,int r){
	if (l < r)
	{
		countNumber++;
		int s = choarePartition(intArrayh, l, r);
		choareSort(intArrayh, l, s-1);
		choareSort(intArrayh, s+1, r);
	}
	countNumber++;
}

int choarePartition(myItem intArrayh[], int l, int r){
	myItem pivotPoint;

	if (intArrayh[l] < intArrayh[r]) {
		countNumber++;
        pivotPoint = intArrayh[l] ;} 
    else{
		countNumber++;

        swap(intArrayh[l],  intArrayh[r]) ;
        pivotPoint = intArrayh[l] ;} 
	int i = l;
	int j = r+1;

	do {
		countNumber++;

		do {
		countNumber++;

			i += 1;
		} while (intArrayh[i] < pivotPoint);
		do {
		countNumber++;

			j -= 1;
		} while (intArrayh[j] > pivotPoint);
		countNumber++;

		swap(intArrayh[i], intArrayh[j]);
	} while (i < j);
		countNumber++;

	swap(intArrayh[i], intArrayh[j]);
	swap(intArrayh[l], intArrayh[j]);
	return j;
}

//=================================================================================
//==================================================================================
//====================================================================================

int main(){
	string response, line, b;
	int nblines, a, inputSize;
	int l = 0;
	clock_t start, end;

	cout << "Please enter the name of the input file you want to use for merge sort: " << endl;
	cin >> response;
	cout << "Please enter the size of array needed for your input: " << endl;
	cin >> inputSize;
	//response = "test4.txt";


	char *c_response = new char[response.length()+1];
	strcpy(c_response, response.c_str());

	//stringstream stringNumber;
	ifstream myFile(c_response);
	ofstream myfile;
	//cout << "got here" << endl;
	int sizeOfArray = inputSize;
	myItem *intArray = new myItem[sizeOfArray]; 
	int counterer = 0;

	while (getline(myFile, line))
		{
		    istringstream iss(line);
 			
		    iss >> a >> b;
		   	
			intArray[counterer].serialNumber = a;
			intArray[counterer].name = b;
			counterer++;
		}	
	//cout << intArray[1].serialNumber << intArray[1].name << endl;
	cout << "\n original order: " << endl;
	for (int dlerp = 0; dlerp < sizeOfArray; dlerp++){
			cout << intArray[dlerp].serialNumber << " " << intArray[dlerp].name << endl;
		}

	start = clock();
	mergeSort(intArray, sizeOfArray);
	end = clock();
	cout << "\n mergeSort took " << (end - start) << " clock ticks.\n";
	
	cout << "\nmergeSort order: " << endl;
	for (int derpina = 0; derpina < sizeOfArray; derpina++){
			cout << intArray[derpina].serialNumber << " " << intArray[derpina].name << endl;
		}

//=====================================================================================
	
	myItem *intArrayl = new myItem[sizeOfArray];  
	int countererl = 0;

	while (getline(myFile, line))
		{
		    istringstream iss(line);
 			
		    iss >> a >> b;
		   	
			intArrayl[counterer].serialNumber = a;
			intArrayl[counterer].name = b;
			countererl++;
		}	
	cout << intArrayl[1].serialNumber << intArray[1].name << endl;
	cout << "\n original order: " << endl;
	for (int dlerp = 0; dlerp < sizeOfArray; dlerp++){
			cout << intArrayl[dlerp].serialNumber << " " << intArrayl[dlerp].name << endl;
		}
	start = clock();
	lomutoSort(intArrayl, l, sizeOfArray);
	end = clock();
	cout << "\n lomutoSort took " << (end - start) << " clock ticks.\n";

	cout << "\nlomuto order: " << endl;
	for (int dlerp = 0; dlerp < sizeOfArray; dlerp++){
			cout << intArrayl[dlerp].serialNumber << " " << intArrayl[dlerp].name << endl;
		}
//=====================================================================================


	myItem *intArrayh = new myItem[sizeOfArray]; 
	int countererh = 0;
	while (getline(myFile, line))
		{
		    istringstream iss(line);
 			
		    iss >> a >> b;
		   	
			intArrayh[counterer].serialNumber = a;
			intArrayh[counterer].name = b;
			countererh++;
		}	
	cout << intArrayh[1].serialNumber << intArray[1].name << endl;
	cout << "\n original order: " << endl;
	for (int dlerp = 0; dlerp < sizeOfArray; dlerp++){
			cout << intArrayh[dlerp].serialNumber << " " << intArrayh[dlerp].name << endl;
		}
	start = clock();
	hoareSort(intArrayh, l, sizeOfArray);
	end = clock();
	cout << "\n hoareSort took " << (end - start) << " clock ticks.\n";

	cout << "\nhoare sort order: " << endl;
	for (int dlerp = 0; dlerp < sizeOfArray; dlerp++){
			cout << intArrayh[dlerp].serialNumber << " " << intArrayh[dlerp].name << endl;
		}

//=====================================================================================

	return 0;
}