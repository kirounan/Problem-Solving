#include <iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<string>


using namespace std;
string s;
map<char, int> RomanSigns;
vector<int> numbers;
int num = 0;
string previ = "0";
int main()
{
	RomanSigns['I'] = 1;
	RomanSigns['V'] = 5;
	RomanSigns['X'] = 10;
	RomanSigns['L'] = 50;
	RomanSigns['C'] = 100;
	RomanSigns['D'] = 500;
	RomanSigns['M'] = 1000;
	getline(cin, s);
	numbers.push_back(0);
	for (int i = 0; i < s.length(); i++)
	{
		if (RomanSigns[s[i]] > num)
		{
			num = RomanSigns[s[i]] - num;
		}
		else
		{
	
			 if (RomanSigns[s[i]] > RomanSigns[previ[0]])
			{
				 for (int i = numbers.size() - 1; i >= 0; i--)
				 {
					 if (RomanSigns[s[i]] > numbers[i])
					 {
						 num -= 2 * (numbers[i]);
					 }
					 else
						 break;
				}

			}

			num += RomanSigns[s[i]];
		}
		numbers.push_back(RomanSigns[s[i]]);
		previ[0] = s[i];
	}
	cout << num;
	cin.get();
}
//Solution on LeetCode
/*
#include <iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<string>

using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        vector<int> numbers;
     map<char, int> RomanSigns;
int num = 0, flag = false, diff = 1;
string previ = "0";
        RomanSigns['I'] = 1;
	RomanSigns['V'] = 5;
	RomanSigns['X'] = 10;
	RomanSigns['L'] = 50;
	RomanSigns['C'] = 100;
	RomanSigns['D'] = 500;
	RomanSigns['M'] = 1000;
	numbers.push_back(0);
	for (int i = 0; i < s.length(); i++)
	{
		if (RomanSigns[s[i]] > num)
		{
			num = RomanSigns[s[i]] - num;
		}
		else
		{
	
			 if (RomanSigns[s[i]] > RomanSigns[previ[0]])
			{
				 for (int i = numbers.size() - 1; i >= 0; i--)
				 {
					 if (RomanSigns[s[i]] > numbers[i])
					 {
						 num -= 2 * (numbers[i]);
					 }
					 else
						 break;
				}

			}

			num += RomanSigns[s[i]];
		}
		numbers.push_back(RomanSigns[s[i]]);
		previ[0] = s[i];
	}
	return num;
    }

};
*/