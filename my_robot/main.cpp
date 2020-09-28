#include "my_robot.h"

int main() {
    cv::Size areaSize(1920, 1080);
    Size robotBodySize(40, 100);
    Size robotWheelSize(30, 30);
    Scalar robotColor = {0, 0, 0};
    Scalar color = {0, 200, 0};


    Robot robot(areaSize, robotBodySize, robotWheelSize, 40);
    robot.drownRobot(robotColor);

}
