#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

string editText(string str)
{
	int x;
	string returnText;
	if ((str[2] == 'R' && str[3] == 'T') && str[5] == '@')
	{
	//Tweet is a retweet
		for (x = 0; x < str.length(); x++)
			if (str[x] == ':')
			{
				returnText = str.substr(x + 2);
				cout << returnText << endl;
				break;
			}
		returnText[returnText.length() - 3] = ' ';
	}
	else { returnText = str; }
	string space = " ";
	for (x = 0; x < returnText.length(); x += 1)
	{
		if (returnText[x] == '?' || returnText[x] == '(' || returnText[x] == ')' || returnText[x] == '!' || returnText[x] == '#' || returnText[x] == '%' || returnText[x] == '$')
		{
	
			returnText.insert(x + 1, space);
			if (!(x == 0))
			returnText.insert(x, space);

			x = x + 1;
		}
	//	if (returnText[x] == '?' || returnText[x] == '(' || returnText[x] == ')' || returnText[x] == '!' || returnText[x] == '#' || returnText[x] == '%')
	//		x -= 1;
	}
	returnText.pop_back();
	returnText.pop_back();

	return returnText;
}

bool checkText(string str, int x)
{
	string returnText = str.substr(1,7);
	if (x == 0)
	{
		cout << returnText << endl;
		if (returnText == "tweetId")
		{
			cout << "stopping\n";
			return true;
		}
	}
	else
	{
		returnText = str.substr(1, 9);
		cout << returnText << endl;
		if (returnText == "tweetText")
		{
			cout << "stopping\n";
			return true;
		}
	}
	return false;
}

int main()
{
	ifstream in("TwitterTrainingData.txt");

	ofstream out("log.txt");

	if (in.fail())
		cout << "Failed to open file\n";


	cout << "hi!!\n";
	string ID, walker, Text;
	string Delimit = "\"tweetId\"";
	while (!in.eof())
	{
		in >> ID;
		cout << ID << endl;
		//cout << ID << endl;
		if (ID == "\"tweetText\":")
		{		
			cout << "done\n";
		    //cout << "True\n";
			getline(in,Text);
		//	cout << "Got line\n";
			//cout << Text << endl;
			Text = editText(Text);
			cout << Text << endl;
			out << Text << " ";
			//Sleep(300);
		}
		if (in.eof())
			break;
	}

	cin >> ID;


	return 0;
}