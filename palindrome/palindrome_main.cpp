#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

bool palindrome(string s)
{
	bool isValid = true;
	for (int i = 0; i < s.length() && isValid; i++)
	{
		if (s[0] == s[s.length() - 1])
		{
			return palindrome(s.substr(1, s.length() - 2));
		}
		else
		{
			if (s.length() == 1 || s.length() == 0)
			{
				isValid = true;
			}
			else
			{
				isValid = false;
			}
			return isValid;
		}
	}
}

string cleanedUp(string s)
{
	string result;
	for (int i = 0; i < s.length(); i++)
	{
		if (isalpha(s[i]))
		{
			result += tolower(s[i]);
		}
	}
	return result;
}


int main()
{
	ifstream file;
	file.open("testCases.txt");
	string s;


	while (getline(file, s))
	{
		//string s2 = cleanedUp(s);
		//cout << s2 << endl;

		if (palindrome(cleanedUp(s)))
		{
			cout << s << " is a palindrome. " << endl;
		}
		else
		{
			cout << s << " is NOT a palindrome. " << endl;
		} 
		cout << endl;
	}

	return 0;
}