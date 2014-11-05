#include <iostream>
#include <string>
#include <cmath>



using namespace std;
class monkey
{
public:
	monkey();
	monkey(bool);
	~monkey();
	bool hungry;
	void virtual eatBanana();
	void virtual scratchHead();
}; 
monkey::monkey(){ cout << "the ctor for monkey that takes nothing\n" << endl;}
monkey::monkey(bool t){ cout << "the ctor for class monkey that takes a bool\n" << endl;}
monkey::~monkey(){ cout << "the destructor for class monkey was called\n" << endl;}
void monkey::eatBanana(){ cout << "I am the eat banana virtual function from monkey\n" << endl;}
void monkey::scratchHead(){ cout << "I am the scratch head virtual function from monkey\n" << endl;}


class ape: public monkey {
public:
	ape();
	ape(bool);
	~ape();
	void eatBanana();
	void virtual scratchHead();
}; 
ape::ape(){ cout << "the ctor for ape that takes nothing\n" << endl;}
ape::ape(bool t): monkey(t){ cout << "im the ctor from ape that takes a bool\n" << endl;};
ape::~ape(){ cout << "the destructor for class ape was called\n" << endl;}
void ape::eatBanana(){ cout << "the function Eat Banana that is in class ape\n" << endl;}
void ape::scratchHead(){ cout << "the virtual function from class ape\n" << endl;}




class parrot
{
public:
	char *vocabulary;
	parrot();
	parrot(char*);
	~parrot();
	void talk();
};
parrot::parrot(){ cout << "the ctor for parrot that takes nothing\n" << endl;}
parrot::~parrot(){ cout << "the destructor for class parrot was called\n" << endl;}
parrot::parrot(char* t){ cout << "the ctor for class parrot that takes a charecter pointer\n" << endl;}
void parrot::talk(){ cout << "the talk function from parrot class\n" << endl;}




class human: public parrot, public ape{
public:
	human();
	human(bool);
	human(bool, char *);
	~human();
	void eatBanana();
	void scratchHead();
};
human::human(){ cout << "the ctor for human that takes nothing\n" << endl;}
human::~human(){ cout << "the destructor for class human was called\n" << endl;}
human::human(bool t): ape(t){ cout << "the human ctor that takes bool\n" << endl;} 
human::human(bool t, char* f): ape(t), parrot(f) { cout << "the human ctor that takes a bool and char\n" << endl;} 
void human::eatBanana(){ cout << "eatBanana in human class\n" << endl;}
void human::scratchHead(){ cout << "scratchHead in human class\n" << endl;}

template <class myType> 
	myType GetMax (myType x, myType y, myType z) {
	int v; 
	v = (x + .5); //using ceil() didnt work for some reason, was only rounding down
	cout << v << endl;
	if (v%2==0){
		return y;
	} 
	else if (v%2==1){
		return z;
	}}


template <class cellType> 
	cellType GetMax (cellType value) {

	cellType::cellType();
	cellType::cellType(int value); //says it expects primary expression before value... tried everything I know and asked a few people. I must sleep now. good night

	};


int main(){
	int value;
	bool t = true;
	char f = 'f';
	cout << "got to main: \n" << endl;
	//--- question 5
	monkey* m;
	ape *a;
	human *h;
	parrot *p;
	//--- question 6
	m = new ape(true);
	//--- question 7
	m->eatBanana();
	//--- question 8	
	a = new human;
	//--- question 9
	delete m;
	m = a;
	//--- question 10
	m->scratchHead();
	//--- question 11
	a->scratchHead();
	//--- question 12
	m->eatBanana();
	//--- question 13
	a->eatBanana();
	//--- question 14
	h = dynamic_cast<human *> (a);
	//--- question 15
	delete h;
	h = new human(true, NULL);
	//--- question 16	
	h->talk();
	//--- question 17
	delete h;
	h = new human(true);
	//--- question 18
	h = dynamic_cast<human *> (m);
	delete h;

	a = new human(false, NULL);

	h->eatBanana();
	h->scratchHead();	
	//--- question 20 (where did 19 go?)
	cout << "================================" << endl;

	int x = 2 , y = 2, z = 7;

	int d = GetMax<int> (x, y, z);



	
	



	return 0;
}





