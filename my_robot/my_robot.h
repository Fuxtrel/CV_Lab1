#ifndef TEST_MY_ROBOT_H
#define TEST_MY_ROBOT_H

#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <cmath>

using namespace std;
using namespace cv;

class Robot{

public:
    Robot() = default;
    Robot(const Size m_areaSize, const Size m_robotBodySize, const Size m_robotWheelSize, int motionSpeed);

    void drownRobot(Scalar color);

private:
    const Size m_areaSize;
    const Size m_robotBodySize;
    const Size m_robotWheelSize;
    int m_robotMotionSpeed;
    int m_robotRotateAngle;
    //17я точка - это центр робота
    Point2f m_robotBody[17];
    Mat img;
    Scalar robotColor;
    Scalar color;

    void robotRotation();

    void robotMotion();




};

#endif //TEST_MY_ROBOT_H
