#ifndef TEST_MY_ROBOT_H
#define TEST_MY_ROBOT_H

#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <cmath>

using namespace std;
using namespace cv;

class Robot
{

public:
    Robot() = default;

    Robot(const Size2f m_areaSize, const Size2f robotBodySize, const Size2f &m_robotWheelSize, float motionShift,
          float rotationShift, Point2f m_rectangleSize, Point2f m_rectangleCentre);

    void playRobot();

    void drownRobot(Scalar color);

private:
    const Size m_areaSize;
    const Size m_robotBodySize;
    float m_robotRotationShift;
    float m_robotMotionShift;
    float m_robotRotateAngle;
    float m_currentAngle;
    float m_currentTowerAngle;
    float m_rotationMatrix[6];
    int m_directionOfRotation;
    float m_tmpAngle;
    float m_tmpAngleTower;
    Point2f m_tmpRobotBody[28];
    Point2f m_robotBody[17];
    Point2f m_robotTower[11];
    Point2f m_shell[5];
    Point2f m_rectangleSize;
    Point2f m_rectangleCentre;
    Mat img;
    Scalar robotColor;
    Scalar color;
    Point2f rectangle[4];
//Функция обеспечивающая поворот робота относительно его центра
    void robotRotation(Point2f *array, int length);
//Функция, обеспечивающая считывание нажатий клавишь и запуска необходимых функций
    void robotMotion();
//Функция, проверяющая выход робота за пределы фона
    void borderCheck();
//Функция сохраняющая координаты робота до их изменения
    void saveArray();
//Функция, осуществляющая движение вперёд
    void forwardMove(Point2f *array, int length, float angle);
//Функция, осуществляющая движение назад
    void backMove(Point2f *array, int length);
//Функция, осуществляющая движение вправо
    void rightMove(Point2f *array, int length);
//Функция, осуществляющая движение влево
    void leftMove(Point2f *array, int length);

    bool checkRectangleBorder(Point2f p1, Point2f p2);
    bool isCrossRectangle();

};

#endif //TEST_MY_ROBOT_H
