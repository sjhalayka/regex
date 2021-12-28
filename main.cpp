#include <regex>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<string> std_strtok(const string& s, const string &regex_s)
{
	vector<string> tokens;

	regex r(regex_s);

	sregex_token_iterator iter(s.begin(), s.end(), r, -1);
	sregex_token_iterator end;

	while (iter != end) 
	{
		if(*iter != "")
			tokens.push_back(*iter);
		
		iter++;
	}

	return tokens;
}

int main(void)
{
	vector<string> vs = std_strtok(
		"bla1 bla1 bla1... bla2 bla22bla2?! bla3 bla3bla3!",
		"[.?!]\\s*");

	cout << vs.size() << endl;

	for (size_t i = 0; i < vs.size(); i++)
		cout << "\'" << vs[i] << "\'" << endl;

	return 0;
}
