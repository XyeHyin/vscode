#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string rgbToHex(int r, int g, int b) {
    stringstream ss;
    ss << hex << setw(2) << setfill('0') << r;
    ss << hex << setw(2) << setfill('0') << g;
    ss << hex << setw(2) << setfill('0') << b;
    return ss.str();
}

int solution(string rgb) {
    int r, g, b;
    sscanf(rgb.c_str(), "rgb(%d, %d, %d)", &r, &g, &b);
    string hexStr = rgbToHex(r, g, b);
    return stoi(hexStr, nullptr, 16);
}

int main() {
    cout << (solution("rgb(192, 192, 192)") == 12632256) << endl;
    cout << (solution("rgb(100, 0, 252)") == 6553852) << endl;
    cout << (solution("rgb(33, 44, 55)") == 2174007) << endl;
    cout << (solution("rgb(255, 255, 255)") == 16777215) << endl;
    cout << (solution("rgb(0, 0, 0)") == 0) << endl;
    return 0;
}