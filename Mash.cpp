#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n,k,t;
string str;
char s;
vector<char> ch;
vector <int> instruct;
vector <int> cpnum;
queue<int> instructionq;
void excute(int n)
{
	for (int i = 0; i < n; i++)
	{
		
		if (instruct[i]) {
			instructionq.push(cpnum[i]);

		}
		else {
			cout << ch[i];
		}
		k--;
		if (!k)
		{
			break;
		}
	}

}
int main()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		if (str == "echo")
		{
			cin >> s;
			instruct.push_back(0);
			ch.push_back(s);
			cpnum.push_back(NULL);
		}
		else
		{
			cin >> t;
			instruct.push_back(1);
			cpnum.push_back(t);
			ch.push_back(NULL);
		}
	}
	excute(n);

	while (k>0)
	{
		for (int i = 0; i < instructionq.size(); i++)
		{
			int l = instructionq.front();
			if (k <= 0)
			{
				break;
			}
			excute(l);
			
			instructionq.pop();
	
		}
	}
	cout << endl;
	cin.get();
	system("pause");
	return 0;
}
// simple programming language with 2 instruction when instruction is cp we push the first m instruction
// in the instruction queue then excute k lines
//problem link : https://codeforces.com/gym/103860/problem/A
//difficulty level : 1200