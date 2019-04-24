#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool isBalanced(string s)
{
	vector<char> parentheses;
	bool isValid = true;

	for (int i = 0; i < s.length() && isValid; i++)
	{
		if (s[i] == '(')
		{
			parentheses.push_back(s[i]);
		}
		else if (s[i] == ')' && !parentheses.empty())
		{
			if (!parentheses.empty())
			{
				parentheses.pop_back();
			}
			else
				isValid = false;
		}
	}

	if (!parentheses.empty())
		isValid = false;

	return isValid;
}

int main()
{
	ifstream file;
	file.open("balancedTestCases.txt");
	string s;
	while (getline(file, s))
	{
		if (isBalanced(s))
			cout << s << " is balanced." << endl;
		else
			cout << s << " is not balanced. " << endl;
	}

}