#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    cin.ignore();

    while(T--) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string sound;
        vector<string> recorded_sounds;
        while(ss >> sound) {
            recorded_sounds.push_back(sound);
        }

        unordered_set<string> other_sounds;

        while(getline(cin, line) && line != "what does the fox say?") {
            stringstream ss_animal(line);
            string animal, goes, animal_sound;

            ss_animal >> animal >> goes >> animal_sound;

            other_sounds.insert(animal_sound);
        }

        bool is_first = true;

        for(const auto s : recorded_sounds) {
            if(other_sounds.find(s) == other_sounds.end()) { // 여우소리
                if(!is_first) {
                    cout << " ";
                }
                cout << s;
                is_first = false;
            }
        }
        cout << "\n";
    }

    return 0;
}