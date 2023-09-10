#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Parse input
    string line;

    string str;
    int row;

    cin >> line;

    auto index = line.find(',', 0);
    str = line.substr(0, index);
    row = stoi(line.substr(index+1));
    // Parse end

    // Logic
    vector<vector<char> > vv(row, vector<char>());
    int curr_row = 0;
    bool flag = true;
    for (char c: str) {
        vv[curr_row].push_back(c);

        if (flag) {
            curr_row += 1;
            if (curr_row >= row) {
                flag = false;
                curr_row = row - 2;
            }
        } else {
            curr_row -= 1;
            if (curr_row < 0) {
                flag = true;
                curr_row = 1;
            }
        }
    }

    string result = "";
    for (auto& item: vv) {
        for (auto& c: item) {
            result += c;
        }
    }

    cout << result << endl;
}
// 64 位输出请用 printf("%lld")