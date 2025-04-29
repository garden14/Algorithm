#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int N;
	string command, c;
	int sec;
	cin >> N;
	vector<pair<int, string>> v;
	v.push_back(make_pair(0, ""));
	for (int i = 0; i < N; i++)
	{
		cin >> command >> c >> sec;
		if (command == "type")
		{
			string lastString = v.back().second;
			v.push_back(make_pair(sec, lastString + c));
		}
		else
		{	int index = v.size() - 1;
			for (int i = 0; i < v.size(); i++)
			{
				if (sec - stoi(c) <= v.at(i).first)
				{
					index = i - 1;
					break;
				}
			}
			if (index == -1)
			{
				v.push_back(make_pair(sec, ""));
			}
			else
			{
				v.push_back(make_pair(sec, v.at(index).second));
			}
		}
	}
	if (v.back().second != "")
	{
		cout << v.back().second << "\n";
	}
	return 0;
}