# include <iostream>
# include <string>
# include <fstream>
# include <time.h>
# include <math.h>
# include <stdio.h>
# include <sstream>

using namespace std;

void reverse(){
	int counter=0;
	string line;
	string word1, word2, word3, word4, word5, word6, word7;
	int number1, number2, number3;
	stringstream stringNumber;
	
	ifstream myFile("barn.moo");
	ofstream myfile;

	//initiate the first number
	getline(myFile, line);
	istringstream iss(line);
	iss >> number1;
	cout << number1 << endl;
	int nbLines = number1;
	//open output file
	myfile.open ("reverse.dat");
	myfile << "this file has: " << number1 << " lines." << endl;

	//initiate array to reverse numbers
	int *reverseArray = new int[3*nbLines];
	//while to read in numbers to array
	while (getline(myFile, line))
	{
	    istringstream iss(line);
	    int currentNUmb;
	    iss >> word1 >> number1 >> word2 >> word3 >> number2 >> word4 >> word5 >> word6 >> number3 >> word7;
		
		reverseArray[counter] = number1;
		counter++;
		reverseArray[counter] = number2;
		counter++;
		reverseArray[counter] = number3;
		counter++;
	}
	//while to read numbers out of array backwards three at a time
	int j=counter-1;
	while (j > 0){
		number3 = reverseArray[j];
		number2 = reverseArray[j-1];
		number1 = reverseArray[j-2];
		myfile << number1 << "," << number2 << "," << number3 << "\n";
		j=j-3;
	}
	myfile.close();
}

void swapLines(){
	int counter = 0;
	bool evenOrOdd;
	int evenIntegers = 0;
	int divisibleByThree = 0;
	int divisibleByFive = 0;
	string line, word1, word2, word3, word4, word5, word6, word7, numberOne, numberTwo, numberThree, numberFour;
	int number1, number2, number3, number4, number5, number6, nbLines;

	stringstream stringNumber;
	ifstream myFile("reverse.dat");
	ofstream myfile;
	myfile.open("swap.dat");
	
	getline(myFile, line);
	istringstream iss(line);
	iss >> word1 >> word2 >> word3 >> number1 >> word4 ;
	nbLines = number1;
 	//nblines = atoi(line.substr(9).c_str());
 	cout << nbLines << "number of lines" << endl;
	getline(myFile, line);

	int *intSecondArray = new int[3*nbLines]; //size of array is showing as 8 lines? 

	cout << "GOT TO LOOP" << endl;
 	for (int i=0; i < nbLines; i++){
		//myfile << "There are: " << number1 << " lines in this file." << endl;

	 	numberOne = line.substr(0, line.find(","));
	 	numberTwo = line.substr(line.find(",")+1);

	 	numberThree = numberTwo.substr(numberTwo.find(",")+1);

	 	numberTwo = numberTwo.substr(0, numberTwo.find(","));

	 	number1 = atoi(numberOne.c_str());
	 	number2 = atoi(numberTwo.c_str());
	 	number3 = atoi(numberThree.c_str());

	 	if (number1%2==0){evenIntegers = evenIntegers++;}
	 	if (number1%3==0){divisibleByThree = divisibleByThree++;}
	 	if (number1%5==0){divisibleByFive = divisibleByFive++;}
	 	if (number2%2==0){evenIntegers = evenIntegers++;}
	 	if (number2%3==0){divisibleByThree = divisibleByThree++;}
	 	if (number2%5==0){divisibleByFive = divisibleByFive++;}
	 	if (number3%2==0){evenIntegers = evenIntegers++;}
	 	if (number3%3==0){divisibleByThree = divisibleByThree++;}
	 	if (number3%5==0){divisibleByFive = divisibleByFive++;}

		
		intSecondArray[counter] = number1;
		counter++;
		intSecondArray[counter] = number2;
		counter++;
		intSecondArray[counter] = number3;
		counter++;

		getline(myFile, line);

	}

	int j=0;
	while (j < nbLines){

		//cout << "length is: " << sizeof(intSecondArray) << endl;    THIS IS WHERE THE PROBLEM IS!

		number1 = intSecondArray[j];
		number2 = intSecondArray[j+1];
		number3 = intSecondArray[j+2];

		number4 = intSecondArray[j+3];
		number5 = intSecondArray[j+4];
		number6 = intSecondArray[j+5];
		myfile << "First integer: " << number4 << " Second Integer: " << number5 << " Third Integer: " << number6 << "\n";
		myfile << "First integer: " << number1 << " Second Integer: " << number2 << " Third Integer: " << number3 << "\n";
		
		j = j+6;
		}


	if (nbLines%2==0){
		cout << "There are an even number of lines in this code." << endl;}
		else{
			myfile << "First integer: " << evenIntegers << " Second Integer: " << divisibleByThree << " Third Integer: " << divisibleByFive << "\n";

		}

}	


int main ()
{

	int nblines;
	//cout << "got to main" << endl;
	reverse();
	swapLines();


	
	return 0;
}