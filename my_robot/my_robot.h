#ifndef TEST_MY_ROBOT_H
#define TEST_MY_ROBOT_H

#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <cmath>
#include <chrono>

using namespace std;
using namespace cv;

class Robot{

public:
    Robot() = default;
    Robot(const Size2f& m_areaSize, const Size2f& m_robotBodySize, const Size2f& m_robotWheelSize, float motionSpeed);

    void drownRobot(Scalar color);

private:
    const Size2f m_areaSize;
    const Size2f m_robotBodySize;
    const Size2f m_robotWheelSize;
    float m_robotMotionSpeed;
    float m_robotRotateAngle;
    //17я точка - это центр робота
    Point2f m_robotBody[17];
    Mat img;
    Scalar robotColor;
    Scalar color;
    float m_rotationMatrix[6];
    float m_currentAngular;
    float koefLeftRightRotate;

    void robotRotation();

    void robotMotion();



};

#endif //TEST_MY_ROBOT_H
