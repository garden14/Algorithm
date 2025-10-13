#include <iostream>
#include <vector>

using namespace std;

int sudoku[9][9];
vector<pair<int, int>> blank;

void printSudoku() {
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            cout << sudoku[i][j] << " ";
        }
        cout << "\n";
    } 
}

bool isPossible(int row, int col, int n) {
    for(int i = 0; i < 9; ++i) {
        if(sudoku[row][i] == n) 
            return false;
    } 

    for(int i = 0; i < 9; ++i) {
        if(sudoku[i][col] == n) 
            return false;
    } 

    int start_r = (row / 3) * 3;
    int start_c = (col / 3) * 3;

    for(int i = start_r; i < start_r + 3; ++i) {
        for(int j = start_c; j < start_c + 3; ++j) {
            if(sudoku[i][j] == n)
                return false;
        }
    }

    return true;
}

void solve(int index) {
    if(index == blank.size()){
        printSudoku();
        exit(0);
    }

    int row = blank[index].first;
    int col = blank[index].second;

    for(int n = 1; n <= 9; ++n) {
        if(isPossible(row, col, n)) {
            sudoku[row][col] = n;
            solve(index + 1);
            sudoku[row][col] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            cin >> sudoku[i][j];
            if(sudoku[i][j] == 0) {
                blank.push_back({i, j});
            }
        }
    } 

    solve(0);


    return 0;
}