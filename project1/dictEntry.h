//project 1
//by Zevi Rubin


class dictEntry
{
public:
	dictEntry(string w, string d);
	~dictEntry();
	string getDefinition();
	void updateDefinition(string def);

private:
	string word;
	string definition;
};
