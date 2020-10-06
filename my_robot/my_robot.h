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
    Robot(const Size2f m_areaSize, const Size2f robotBodySize, const Size2f &m_robotWheelSize, float motionSpeed, float m_robotRotationSpeed);
    void playRobot();
    void drownRobot(Scalar color);

private:
    const Size m_areaSize;
    const Size m_robotBodySize;
    float m_robotRotationSpeed;
    float m_robotMotionSpeed;
    float m_robotRotateAngle;
    float m_currentAngle;
    float m_rotationMatrix[6];
    int m_directionOfRotation;
    float tmp_angle;
    Point2f m_tmpRobotBody[17];
    Point2f m_robotBody[17];
    Point2f m_robotTower[11];
    Mat img;
    Scalar robotColor;
    Scalar color;


    void robotRotation(Point2f *array, int length);

    void robotMotion();

    void borderCheck();

    void saveArray();


};

#endif //TEST_MY_ROBOT_H
