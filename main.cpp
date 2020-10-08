#include "my_robot/my_robot.h"

int main() {
    Size2f areaSize(1920, 1080);
    Size2f robotBodySize(80, 200);
    Size2f robotWheelSize(30, 30);
    Scalar robotColor = {0, 0, 0};
    Scalar color = {0, 200, 0};
    Point2f recSize(300, 300);
    Point2f recCentre(900, 850);
    Robot robot(areaSize, robotBodySize, robotWheelSize, 10, 3, recSize, recCentre);
    robot.playRobot();
    
}
