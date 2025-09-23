#include <iostream>

using namespace std;

int col, row, x, y, command, direction;

int map[20][20];
int dice[6]; // 밑 0 위 1 왼 2 오 3 앞 4 뒤 5

bool moveAvailable(int dir) {
    if(dir == 1 && y + 1 < row) {
        ++y;
        return 1;
    }
    else if(dir == 2 && y - 1 >= 0) {
        --y;
        return 1;
    }
    else if(dir == 3 && x - 1 >= 0) {
        --x;
        return 1;
    }
    else if(dir == 4 && x + 1 < col) {
        ++x;
        return 1;
    }
    return 0;
}
void rotate(int dir) {
    int temp = dice[0];

    if(dir == 1){
        // 동쪽으로 굴릴 때
        dice[0] = dice[3];
        dice[3] = dice[1];
        dice[1] = dice[2];
        dice[2] = temp;
    }
    else if(dir == 2) {
        // 서쪽으로 굴릴 때
        dice[0] = dice[2];
        dice[2] = dice[1];
        dice[1] = dice[3];
        dice[3] = temp;
    }
    else if (dir == 3) {
        // 북
		dice[0] = dice[5];
		dice[5] = dice[1];
		dice[1] = dice[4];
		dice[4] = temp;
	}
	else if (dir == 4) {
        // 남
		dice[0] = dice[4];
		dice[4] = dice[1];
		dice[1] = dice[5];
		dice[5] = temp;
	}

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 세로, 가로, 세로 좌표, 가로 좌표, 명령 개수
    cin >> col >> row >> x >> y >> command;

    for(int i = 0; i < col; ++i) {
        for(int j = 0; j < row; ++j) {
            cin >> map[i][j];
        }
    }

    // 동 1 서 2 북 3 남 4
    for(int i = 0; i < command; ++i) {
        cin >> direction;
        if(moveAvailable(direction)) {
            rotate(direction);
            if(map[x][y]) {
                dice[0] = map[x][y];
                map[x][y] = 0;
            } else {
                map[x][y] = dice[0];
            }
            cout << dice[1] << '\n';
        }
    }

    return 0;
}