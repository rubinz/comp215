//zevi rubin
//Algorithms 
//lab 6

# include <iostream>
# include <string>
# include <string.h>
# include <fstream>
# include <time.h>
# include <math.h>
# include <stdio.h>
# include <sstream>


using namespace std;

int NBLINES;

class pairsAgain
{
public:
	int val1;
	int val2;

	pairsAgain(){};
	pairsAgain(int x, int y);
	~pairsAgain(){};
	bool operator==(pairsAgain pair);
	bool operator>(pairsAgain pair);
	bool operator<(pairsAgain pair);
	bool operator<=(pairsAgain pair);
	bool operator>=(pairsAgain pair);
};
void whichsearchType(pairsAgain* intArray, int numberOfLines);
pairsAgain* selectionSort(pairsAgain* intArray, int numberOfLines);
pairsAgain* bubbleSort(pairsAgain* intArray, int numberOfLines);
int sequentialSearch(pairsAgain* intArray, int numberOfLines);
int bruteForceStringMatch(string text, string findText);

bool pairsAgain::operator==(pairsAgain pair){ return (this->val1 == pair.val1);}
bool pairsAgain::operator>(pairsAgain pair){ return (this->val1 < pair.val1);}
bool pairsAgain::operator<(pairsAgain pair){ return (this->val1 > pair.val1);}
bool pairsAgain::operator<=(pairsAgain pair){ return (this->val1 <= pair.val1);}
bool pairsAgain::operator>=(pairsAgain pair){ return (this->val1 >=pair.val1);}

pairsAgain::pairsAgain(int int1, int int2){
	val1 = int1;
	val2 = int2;

}



int openFile(){
	
	char fileType;
	string response, line;
	int number1, number2, NBLINES, a, b;
	cout << "Please specify if your file will use numbers or letters (N/L): " << endl;
	cin >> fileType;
	// cout << "Please enter the name of the input file you want to use: " << endl;
	// cin >> response;
	response = "Numbers1.txt";

	char *c_response = new char[response.length()+1];
	strcpy(c_response, response.c_str());

	stringstream stringNumber;
	ifstream myFile(c_response);
	ofstream myfile;
	//myfile.open(c_response);
	getline(myFile, line);
	istringstream iss(line);
	iss >> NBLINES;
	// NBLINES = number1;
	
	int counter = 0;
	
	if (fileType == 'N'){
 	
		pairsAgain *intArray = new pairsAgain[NBLINES]; 

		while (getline(myFile, line))
		{
		    istringstream iss(line);
 			
		    iss >> a >> b;

			intArray[counter].val1 = a;
			intArray[counter].val2 = b;
			counter++;
		}
 		
		int numberOfLines = NBLINES;
		whichsearchType(intArray, numberOfLines);
	}


	else if (fileType == 'L'){
		string fileName;
		string line1;
		
		cin.ignore();
		cout << "Please enter the name of the input file: " << endl;
		cin >> fileName;
		char *c_response = new char[fileName.length()+1];
		strcpy(c_response, fileName.c_str());

		ifstream fin;
		// ofstream myfile;
		fin.open(c_response);
		getline(fin, line1);
		int numberOfLines = atoi(line1.c_str());


		string text;
		if(fin.is_open()){
			getline(fin, line1);
			for (long i = 0; i<numberOfLines; i++){
				if (!line1.empty() && (line1[line1.length() - 1] == '\n')){
					line1.erase(line1.length()-1);

				}
				text = text + line1;
				getline(fin, line1);

			}

		}
		cout << "TEXT LENGTH" << text.length() << endl;
		string findText;
		int found = 69;
		
		while(found >= 0){
	
			cout << "Enter a patern that might be found in the text: " << endl;
			cin.ignore();
			cin >> findText;
			// getline(cin, line);
			found = (bruteForceStringMatch(text, findText));

			if (found >= 0){
				cout << "The patter you wanted has been found at: " << found <<endl;
			}
			else{
				cout << "the pattern you are looking for wasnt found" << endl;
			}
		} 
		
		

	}
	else 
		{cout << "You have entered an invalid option. " << endl;}

	return 0;
}

void whichsearchType(pairsAgain* intArray, int numberOfLines){
	string response1, response2, response3;
	int a, b, counter;
	cout << "choose which type of search you want to do (selection/bubble/sequential): " << endl;
	cin >> response1;
 	cout << numberOfLines << " lines test" << endl;

	if (response1 == "selection"){
 	
		selectionSort(intArray, numberOfLines);

	}
	else if (response1 == "bubble"){
		bubbleSort(intArray, numberOfLines);

	}
	else if (response1 == "sequential"){
		sequentialSearch(intArray, numberOfLines);

	}

}

pairsAgain* selectionSort(pairsAgain* intArray, int numberOfLines){
	int min, j, swap, temp, temp1, temp2;
	int i = 0;
	string response;
	
	for (i; i<numberOfLines-1; i++){
		min = i;
	
			for (j = i+1; j<numberOfLines; j++){

				if (intArray[j]<intArray[min]){
					min = j;
					
				}

			}
 	
			pairsAgain swap = intArray[i];
			intArray[i] = intArray[min];
			intArray[min] = swap;
		
	}
	
	cout << "Enter the output file name: " << endl;
	cin >> response;
	char *c_response = new char[response.length()+1];
	strcpy(c_response, response.c_str());

	ofstream myfile;
	myfile.open(c_response);
	myfile << numberOfLines << "\n" << endl;
	for (i=numberOfLines-1; i>0; i--){
		myfile << intArray[i].val1 << " " << intArray[i].val2 << "\n" << endl;
	}


}

pairsAgain* bubbleSort(pairsAgain* intArray, int numberOfLines){
	int n = numberOfLines;
	string response;
	cout << n << endl;
	for (int i = 0; i <= n-2; i++){
		int nbswap;
	

		for (int j=0; j<=(n-2-i); j++){
	

			if (intArray[j+1] < intArray[j]){
	

				pairsAgain d = intArray[j+1];
				intArray[j+1] = intArray[j];
				intArray[j] = d;
			}
		}
	if (nbswap == 0){
		return intArray;
		}
	}

	cout << "Enter the output file name: " << endl;
	cin >> response;
	char *c_response = new char[response.length()+1];
	strcpy(c_response, response.c_str());

	ofstream myfile;
	myfile.open(c_response);
	myfile << numberOfLines << "\n" << endl;
	for (int z=numberOfLines-1; z>0; z--){
		myfile << intArray[z].val1 << " " << intArray[z].val2 << "\n" << endl;
	}

}
int sequentialSearch(pairsAgain* intArray, int numberOfLines){
int i = 0;
bool notfound = true;
pairsAgain element;
	cout << "Want to find a number pair? enter the first half: " << endl;
	cin >> element.val1;
	cout << "Enter the second half of the pair: " << endl;
	cin >> element.val2;
	while (notfound == true){
		notfound = false;
		for (int derp = 0; derp <= numberOfLines-1; derp++){
		
			if(intArray[derp].val1 == element.val1)
			
				cout << "\nFound the value " << intArray[i].val1 << " in the document" << endl;
				bool notfound = true;
				//return i;

		}
		
		cout << "\nWant to find a number pair? enter the first half: " << endl;
		cin >> element.val1;
		cout << "Enter the second half of the pair: " << endl;
		cin >> element.val2;
	}
}

int bruteForceStringMatch(string text, string findText){
	for(int i = 0; i < (text.length()-findText.length()); i++){
		int j = 0;
		int m = findText.length();
		int n = text.length();


		while (j < m && (findText[j] == text[i+j])){
			j++;
			cout << i << endl;
			cout << "test2" << endl;
		}
		if (j == (findText.length())){
			cout << i << endl;
		cout << "test3" << endl;


			return i;
		}
	}
	return -1;
}


int main (){openFile(); return 0;}