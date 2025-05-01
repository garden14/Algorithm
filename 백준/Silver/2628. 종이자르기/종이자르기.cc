#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int	main(void){
	int	y, x, n, dir, num, rowMax = -1, columnMax = -1;
	vector <int> row, column;

	cin >> x >> y;
	cin >> n;
    
	row.push_back(0);
	row.push_back(x);
    
	column.push_back(0);
	column.push_back(y);
    
	for(int i = 0; i < n; i++) {
		cin >> dir >> num;
		if (dir == 1) row.push_back(num);
		else column.push_back(num);
	}
    
	sort(row.begin(), row.end());
	sort(column.begin(), column.end());
	
	for (int i = 0; i < row.size(); i++)
		if (row.size() > i + 1 && row[i + 1] - row[i] > rowMax)
			rowMax = row[i + 1] - row[i];
	for (int i = 0; i < column.size(); i++)
		if (column.size() > i + 1 && column[i + 1] - column[i] > columnMax)
			columnMax = column[i + 1] - column[i];
	cout << rowMax * columnMax;
	
	return (0);
}