// 874
#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
struct POS {
    long x;
    long y;
    int angle;
};
int robotSim(vector<int>& commands, vector<vector<int>>& obstacles);
int main() {
    vector<int> commands = {4, -1, 4, -2, 4};
    vector<vector<int>> obstacles = {{2, 4}};
    cout << robotSim(commands, obstacles) << endl;
    return 0;
}
int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    POS robot{0, 0, 0};
    unordered_set<string> set;
    long maxDis = 0;
    for (auto obstacle : obstacles) {
        set.emplace(to_string(obstacle[0]) + "," + to_string(obstacle[1]));
    }
    for (auto command : commands) {
        if (command == -2) {
            robot.angle = (robot.angle + 90) % 360;
        } else if (command == -1) {
            robot.angle = (robot.angle - 90 + 360) % 360;
        } else if (command > 0) {
            switch (robot.angle) {
                case 0:
                    for (int y = 0; y < command; y++) {
                        auto key = to_string(robot.x) + "," + to_string(robot.y + 1);
                        if (set.count(key)) {
                            break;
                        }
                        robot.y += 1;
                    }
                    break;
                case 90:
                    for (int x = 0; x < command; x++) {
                        auto key = to_string(robot.x - 1) + "," + to_string(robot.y);
                        if (set.count(key)) {
                            break;
                        }
                        robot.x -= 1;
                    }
                    break;
                case 180:
                    for (int y = 0; y < command; y++) {
                        auto key = to_string(robot.x) + "," + to_string(robot.y - 1);
                        if (set.count(key)) {
                            break;
                        }
                        robot.y -= 1;
                    }
                    break;
                case 270:
                    for (int x = 0; x < command; x++) {
                        auto key = to_string(robot.x + 1) + "," + to_string(robot.y);
                        if (set.count(key)) {
                            break;
                        }
                        robot.x += 1;
                    }
                    break;
            }
            maxDis = max(maxDis, robot.x * robot.x + robot.y * robot.y);
        }
    }
    return maxDis;
}
