#include <iostream>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;
unsigned short int t, n;
unsigned int s, sa;
int main()
{

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> s;
		vector<int> arr2;
		set<int> arr;

		for (unsigned int j = 0; j < s; j++)
		{
			int g;
			cin >> g;
			arr.insert(g);
			arr2.push_back(g);
		}

		sa = arr.size();

		sort(arr2.begin(), arr2.end());
		for (int j = 0; j < s; j++)
		{
			int h = j + 1, l = j + 2;
			if (h > (s - 1))
				h -= s;
			if (l > (s - 1))
				l -= s;

			arr.insert(arr2[j] + arr2[h] + arr2[l]);

		}
		if (arr.size() == sa)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}

}
// main idea to compare set size before and after adding  (3 adjacent items) from sorted vector
// if the length increased that mean that array doesnt follow the problem rule 
// remember set order the array and remove dublications
//problem link : https://codeforces.com/problemset/problem/1698/C
//difficulty level : 1300