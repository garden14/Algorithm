#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> list;

int maxValue = -1e9;
int minValue = 1e9;
int N;

void calculate(int add, int sub, int mul, int div, int depth, int value)
{
	if (depth == N)
	{
		maxValue = max(maxValue, value);
		minValue = min(minValue, value);
		return;
	}

	if (add != 0)
		calculate(add - 1, sub, mul, div, depth + 1, value + list[depth]);
	if (sub != 0)
		calculate(add, sub - 1, mul, div, depth + 1, value - list[depth]);
	if (mul != 0)
		calculate(add, sub, mul - 1, div, depth + 1, value * list[depth]);
	if (div != 0)
		calculate(add, sub, mul, div - 1, depth + 1, value / list[depth]);
	
	return;
}

int main()
{
	int operators[4];

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int temp;
		cin >> temp;

		list.push_back(temp);
	}

	for (int i = 0; i < 4; ++i)
	{
		int temp;
		cin >> temp;

		operators[i] = temp;
	}

	calculate(operators[0], operators[1], operators[2], operators[3], 1, list[0]);

	cout << maxValue << "\n" << minValue << endl;
}