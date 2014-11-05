#include <iostream>
#include <String>

using namespace std;


class cell {
	
	public:

		int value;
		cell* next;
		cell (int x);
		//cell (int x, cell *Ncell);
		

};


int main(){
	cout << "in main" << endl;
	cell firstcell(5);
	cell *Ncell;
	cout << firstcell.value << endl;
	//cell cell(4, *Ncell);


	return 0;
}

cell::cell(int input){
	value = input;

}



cell::cell(int input,cell Ncell){
	value = input;
	this->next = &cell;

}



