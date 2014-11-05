#include <iostream>
#include <string>

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
monkey::monkey(){ cout << "the ctor for monkey that takes nothing" << endl;}
monkey::monkey(bool x){ cout << "the ctor for class monkey that takes a bool" << endl;}
monkey::~monkey(){ cout << "the destructor for class monkey was called" << endl;}
void monkey::eatBanana(){ cout << "I am the eat banana virtual function from monkey" << endl;}
void monkey::scratchHead(){ cout << "I am the scratch head virtual function from monkey" << endl;}


class ape: public monkey {
public:
	ape();
	ape(bool);
	~ape();
	void eatBanana();
	void virtual scratchHead();
}; 
ape::ape(){ cout << "the ctor for ape that takes nothing" << endl;}
ape::ape(bool x): monkey(x){ cout << "im the ctor from ape that takes a bool" << endl;};
ape::~ape(){ cout << "the destructor for class ape was called" << endl;}
void ape::eatBanana(){ cout << "the function Eat Banana that is in class ape" << endl;}
void ape::scratchHead(){ cout << "the virtual function from class ape" << endl;}




class parrot
{
public:
	char *vocabulary;
	parrot();
	parrot(char*);
	~parrot();
	void talk();
};
parrot::parrot(){ cout << "the ctor for parrot that takes nothing" << endl;}
parrot::~parrot(){ cout << "the destructor for class parrot was called" << endl;}
parrot::parrot(char* x){ cout << "the ctor for class parrot that takes a charecter pointer" << endl;}
void parrot::talk(){ cout << "the talk function from parrot class" << endl;}




class human: public parrot, public ape{
public:
	human();
	human(bool);
	human(bool, char *);
	~human();
	void eatBanana();
	void scratchHead();
};
human::human(){ cout << "the ctor for human that takes nothing" << endl;}
human::~human(){ cout << "the destructor for class human was called" << endl;}
human::human(bool x): ape(x){ cout << "the human ctor that takes bool" << endl;} 
human::human(bool x, char* y): ape(x), parrot(y) { cout << "the human ctor that takes a bool and char" << endl;} 
void human::eatBanana(){ cout << "eatBanana in human class" << endl;}
void human::scratchHead(){ cout << "scratchHead in human class" << endl;}


int main(){
	bool x = true;
	char y = 'f';
	cout << "got to main: " << endl;
	

	return 0;
}





