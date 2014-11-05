//project 1
//by Zevi Rubin


# include <iostream>
# include <string>
# include <string.h>
# include <fstream>
# include <time.h>
# include <math.h>
# include <stdio.h>
# include <queue>
# include <sstream>
# include <stdlib.h>
# include <cmath>
# include "dictEntry.h"

using namespace std;

int main()
{
	cout << "got here" << endl;

	return 0;
}

bool dictEntry::operator==(string s){
	if (this->word.compare(s) != 0){
		return false;
	else
		return true;
}
bool dictEntry::operator<(string s){
	if (this->word.compare(s) < 0){
		return true;
	else
		return false;
}
bool dictEntry::operator<=(string s){
	if ((this->word.compare(s) <= 0){
		return true;
	else
		return false;
}
bool dictEntry::operator>(string s){
	if (this->word.compare(s) > 0){
		return true;
	else
		return false;
}
bool dictEntry::operator>=(string s){
	if (this->word.compare(s) >= 0){
		return true;
	else
		return false;
}


dictEntry::dictEntry(string w, string d){


}


dictEntry::~dictEntry(){


}


string dictEntry::getDefinition(){


}


void dictEntry::updateDefinition(string def){


}

