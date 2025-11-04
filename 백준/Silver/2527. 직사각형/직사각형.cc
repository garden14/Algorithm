#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < 4; ++i) {
        int x1, y1, p1, q1;
        int x2, y2, p2, q2;

        cin >> x1 >> y1 >> x2 >> y2 >> p1 >> q1 >> p2 >> q2;

        char result;

        if(x2 < p1 || x1 > p2 || y2 < q1 || y1 > q2) {
            result = 'd';
        }

        else if ((x2 == p1 && y2 == q1) || 
                 (x1 == p2 && y2 == q1) || 
                 (x2 == p1 && y1 == q2) || 
                 (x1 == p2 && y1 == q2)) {
                    result = 'c';
        }

        else if (x2 == p1 || 
                 x1 == p2 || 
                 y2 == q1 || 
                 y1 == q2) {
            result = 'b';
        }

        else result = 'a';

        cout << result << "\n";
    }
    

    return 0;
}