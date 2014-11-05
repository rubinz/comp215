// Lab 2
//Zevi Rubin
//WRITTEN WORK:
//5: tested all these and they worked as expected. If you want to see the exact results kindly contact me with that reques. 
//6: time1 took: 24245101 clicks, time2 took 17941127 clicks, time3 took 17100 clicks, and tim4 took 11772 clicks.
//7: I reduced this number from 10m to 1m because I have soccer practice in the morning and didnt want to wait all night to finish the hw. 
//   bigtime5 took 345646 clicks, and bigtime6 took 227826 clicks.

#include <iostream>
#include <string>

using namespace std;

//declaring functions that the time functions will call. bla bla bla scope. this is how a coder do.
unsigned long expmod1 (unsigned long int b, unsigned long int n, unsigned long int m);
unsigned long expmod2 (unsigned long int b, unsigned long int n, unsigned long int m);
unsigned long expmod3 (unsigned long int b, unsigned long int n, unsigned long int m);
unsigned long expmod4 (unsigned long int b, unsigned long int n, unsigned long int m);
int bigtime5 (unsigned long int b, unsigned long int n, unsigned long int m);
int bigtime6 (unsigned long int b, unsigned long int n, unsigned long int m);

//time functions that will call the expmod functions while timing them
int time1 (unsigned long int b, unsigned long int n, unsigned long int m){
	clock_t start,end;
	start = clock();
	for (int i=0; i<50000; i++){
		expmod1(b, n, m);}
	end = clock();
	cout << "The computation took " << (end - start) << " clock ticks." << endl;}
int time2 (unsigned long int b, unsigned long int n, unsigned long int m){
	clock_t start,end;
	start = clock();
	for (int i=0; i<50000; i++){
		expmod2(b, n, m);}
	end = clock();
	cout << "The computation took " << (end - start) << " clock ticks." << endl;}
int time3 (unsigned long int b, unsigned long int n, unsigned long int m){
	clock_t start,end;
	start = clock();
	for (int i=0; i<50000; i++){
		expmod3(b, n, m);}
	end = clock();
	cout << "The computation took " << (end - start) << " clock ticks." << endl;}
int time4 (unsigned long int b, unsigned long int n, unsigned long int m){
	clock_t start,end;
	start = clock();
	for (int i=0; i<50000; i++){
		expmod4(b, n, m);}
	end = clock();
	cout << "The computation took " << (end - start) << " clock ticks." << endl;}
int bigtime5 (unsigned long int b, unsigned long int n, unsigned long int m){
	clock_t start,end;
	start = clock();
	for (int i=0; i<1000000; i++){
		expmod3(b, n, m);}
	end = clock();
	cout << "The computation took " << (end - start) << " clock ticks." << endl;}
int bigtime6 (unsigned long int b, unsigned long int n, unsigned long int m){
	clock_t start,end;
	start = clock();
	for (int i=0; i<1000000; i++){
		expmod4(b, n, m);}
	end = clock();
	cout << "The computation took " << (end - start) << " clock ticks." << endl;}




//MOD FUNCTIONS 1, 2, 3, and 4.
unsigned long expmod1 (unsigned long int b, unsigned long int n, unsigned long int m)
{
	if (n<=0){
		return 1;
	}
	else{
		return (b*(expmod1(b, n-1, m))%m);
	}
}
unsigned long expmod2 (unsigned long int b, unsigned long int n, unsigned long int m)
{
	unsigned long int result;
	result = 1;
	unsigned long int i = n;

	for (i; i>=1; i--){
   	//cout << "testing n:" << i << "Testing result:" << result<< endl;
   	result = ((result*b)%m);
	}
 	return result;
}
unsigned long expmod3 (unsigned long int b, unsigned long int n, unsigned long int m)
{
	if (n<=0){
		return 1;
	}
	else if(n%2==1){
		return (b*expmod3(b, n-1, m)%m);
	}
	else{return (expmod3(((b*b)%m),(n/2),m));
	}
}
unsigned long expmod4 (unsigned long int b, unsigned long int n, unsigned long int m)
{
	unsigned long int result;
	unsigned long int base=b;
	unsigned long int exp=n;
	unsigned long int i = n;
	result = 1;
	while (exp !=0){
		if(exp%2==1){
   			result = ((result*base)%m);
   			exp=exp--;
   		}
   		else{
   			base=(base*base)%m;
   			exp=exp/2;
   		}
	}
 	return result;
}


//MAIN DRIVER FUNCTION:
int main ()
{
	unsigned long int b, m, n;
	//where b=base, n=exponent, m=modulus.
	b=21415; n=25000; m=31457;
	//b=21415; n=1000000; m=31457;
	//b=21415; n=1000000000; m=31457;

	if (b>1 and m<65536){
		if (b>m){
			b=b%m;
			//function call
			cout << "expmod1: " << expmod1(b, n, m) << endl;
			cout << "expmod2:" << expmod2(b, n, m) << endl;
			cout << "expmod3: " << expmod3(b, n, m) << endl;
			cout << "expmod4: " << expmod4(b, n, m) << endl;
			// time1(b, n, m);
			// time2(b, n, m);
			// time3(b, n, m);
			// time4(b, n, m);
			// bigtime5(b, n, m);
			// bigtime6(b, n, m);
		}
		else{
			//function call
			cout << "expmod1: " << expmod1(b, n, m) << endl;
			cout << "expmod2:" << expmod2(b, n, m) << endl;
			cout << "expmod3: " << expmod3(b, n, m) << endl;
			cout << "expmod4: " << expmod4(b, n, m) << endl;
			// time1(b, n, m);
			// time2(b, n, m);
			// time3(b, n, m);
			// time4(b, n, m);
			// bigtime5(b, n, m);
			// bigtime6(b, n, m);

		}
	}
	else{
		cout << "the problem was: " << b << " (b) is less than 1,\n or that " << m << " (m) is greater than 65536" << endl;
	}
}//end main