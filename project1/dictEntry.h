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

using namespace std;


class dictEntry
{
public:
	dictEntry(string w, string d);
	~dictEntry();
	string getDefinition();
	void updateDefinition(string def);

	bool operator==(string s);
	bool operator<(string s);
	bool operator<=(string s);
	bool operator>(string s);
	bool operator>=(string s);
	
private:
	string word;
	string definition;
};
