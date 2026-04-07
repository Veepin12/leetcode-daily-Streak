#include <iostream>
#include <vector>
#include <tuple>
#include <string>
using namespace std;

class Robot {
    // 
    int w, h, perimeter, pos;
public:
    Robot(int width, int height) {
        w = width;
        h = height;
        perimeter = 2 * (w - 1) + 2 * (h - 1);
        pos = 0;
    }
    
    void step(int num) {
        pos += num;
        pos %= perimeter;
        if (pos == 0 && num > 0) {
            pos = perimeter;
        }
    }
    
    vector<int> getPos() {
        if (pos == 0 || pos == perimeter) return {0, 0};
        if (pos <= w - 1) return {pos, 0};
        if (pos <= w - 1 + h - 1) return {w - 1, pos - (w - 1)};
        if (pos <= 2 * w - 2 + h - 1) return {w - 1 - (pos - (w - 1 + h - 1)), h - 1};
        return {0, h - 1 - (pos - (2 * w - 2 + h - 1))};
    }
    
    string getDir() {
        if (pos == 0) return "East";
        if (pos == perimeter) return "South";
        if (pos <= w - 1) return "East";
        if (pos <= w - 1 + h - 1) return "North";
        if (pos <= 2 * w - 2 + h - 1) return "West";
        return "South";
    }
};

int main() {
    Robot robot(20, 13);

    robot.step(12);
    robot.step(21);
    auto p1 = robot.getPos();
    auto d1 = robot.getDir();
    cout << "getPos: [" << p1[0] << ", " << p1[1] << "]" << endl; // [17, 12]
    cout << "getDir: " << d1 << endl;                               // West

    robot.step(17);
    auto p2 = robot.getPos();
    auto d2 = robot.getDir();
    cout << "getPos: [" << p2[0] << ", " << p2[1] << "]" << endl; // [0, 12]
    cout << "getDir: " << d2 << endl;                               // West ✓

    auto p3 = robot.getPos();
    auto d3 = robot.getDir();
    cout << "getPos: [" << p3[0] << ", " << p3[1] << "]" << endl; // [0, 12]
    cout << "getDir: " << d3 << endl;                               // West ✓

    return 0;
}