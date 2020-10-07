#include "my_robot/my_robot.h"

int main() {
    Size2f areaSize(1920, 1080);
    Size2f robotBodySize(80, 200);
    Size2f robotWheelSize(30, 30);
    Scalar robotColor = {0, 0, 0};
    Scalar color = {0, 200, 0};
    Robot robot(areaSize, robotBodySize, robotWheelSize, 10, 3, 1, 0);
    robot.playRobot();
    
}
