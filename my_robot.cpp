#include "my_robot/my_robot.h"


Robot::Robot(const Size m_areaSize, const Size m_robotBodySize, const Size m_robotWheelSize, int motionSpeed)
        : m_robotMotionSpeed(motionSpeed)
{
    //Задаются иксовые координаты тела робота
    m_robotBody[0].x = (m_areaSize.width / 2) - m_robotBodySize.width;
    m_robotBody[3].x = (m_areaSize.width / 2) - m_robotBodySize.width;
    m_robotBody[1].x = (m_areaSize.width / 2) + m_robotBodySize.width;
    m_robotBody[2].x = (m_areaSize.width / 2) + m_robotBodySize.width;
    //Задаются игриковые координаты тела робота
    m_robotBody[0].y = (m_areaSize.height / 2) + m_robotBodySize.height;
    m_robotBody[1].y = (m_areaSize.height / 2) + m_robotBodySize.height;
    m_robotBody[2].y = (m_areaSize.height / 2) - m_robotBodySize.height;
    m_robotBody[3].y = (m_areaSize.height / 2) - m_robotBodySize.height;
    //
    m_robotBody[4].x = m_robotBody[0].x - m_robotWheelSize.width;
    m_robotBody[5].x = m_robotBody[0].x - m_robotWheelSize.width;
    m_robotBody[6].x = m_robotBody[0].x;
    m_robotBody[13].x = m_robotBody[0].x - m_robotWheelSize.width;
    m_robotBody[14].x = m_robotBody[0].x - m_robotWheelSize.width;
    m_robotBody[15].x = m_robotBody[0].x;

    m_robotBody[7].x = m_robotBody[1].x + m_robotWheelSize.width;
    m_robotBody[8].x = m_robotBody[1].x + m_robotWheelSize.width;
    m_robotBody[9].x = m_robotBody[1].x;
    m_robotBody[10].x = m_robotBody[1].x + m_robotWheelSize.width;
    m_robotBody[11].x = m_robotBody[1].x + m_robotWheelSize.width;
    m_robotBody[12].x = m_robotBody[1].x;
//
    m_robotBody[4].y = m_robotBody[0].y;
    m_robotBody[5].y = m_robotBody[0].y - m_robotWheelSize.height;
    m_robotBody[6].y = m_robotBody[0].y - m_robotWheelSize.height;
    m_robotBody[7].y = m_robotBody[0].y;
    m_robotBody[8].y = m_robotBody[0].y - m_robotWheelSize.height;
    m_robotBody[9].y = m_robotBody[0].y - m_robotWheelSize.height;

    m_robotBody[10].y = m_robotBody[2].y;
    m_robotBody[11].y = m_robotBody[2].y + m_robotWheelSize.height;
    m_robotBody[12].y = m_robotBody[2].y + m_robotWheelSize.height;
    m_robotBody[13].y = m_robotBody[2].y;
    m_robotBody[14].y = m_robotBody[2].y + m_robotWheelSize.height;
    m_robotBody[15].y = m_robotBody[2].y + m_robotWheelSize.height;
    robotColor = {0, 0, 0};
    color = {0, 100, 0};
    img = {m_areaSize, CV_8UC3, color};


};

void Robot::drownRobot(Scalar color)
{
    line(img, m_robotBody[0], m_robotBody[1], color, 3);
    line(img, m_robotBody[1], m_robotBody[2], color, 3);
    line(img, m_robotBody[2], m_robotBody[3], color, 3);
    line(img, m_robotBody[3], m_robotBody[0], color, 3);

    line(img, m_robotBody[0], m_robotBody[4], color, 3);
    line(img, m_robotBody[4], m_robotBody[5], color, 3);
    line(img, m_robotBody[5], m_robotBody[6], color, 3);

    line(img, m_robotBody[1], m_robotBody[7], color, 3);
    line(img, m_robotBody[7], m_robotBody[8], color, 3);
    line(img, m_robotBody[8], m_robotBody[9], color, 3);

    line(img, m_robotBody[2], m_robotBody[10], color, 3);
    line(img, m_robotBody[10], m_robotBody[11], color, 3);
    line(img, m_robotBody[11], m_robotBody[12], color, 3);

    line(img, m_robotBody[3], m_robotBody[13], color, 3);
    line(img, m_robotBody[13], m_robotBody[14], color, 3);
    line(img, m_robotBody[14], m_robotBody[15], color, 3);
    if (color == robotColor)
    {
        imshow("Empty window", img);
        robotMotion();
    }
}

void Robot::robotMotion()
{
    while (true)
    {
        switch (waitKey(1))
        {
            case 'w':
                drownRobot(color);
                for (int i = 0; i < 16; i++)
                {
                    m_robotBody[i].y -= m_robotMotionSpeed;
                }
                drownRobot(robotColor);
                break;
            case 's':
                drownRobot(color);
                for (int i = 0; i < 16; i++)
                {
                    m_robotBody[i].y += m_robotMotionSpeed;
                }
                drownRobot(robotColor);

                break;
            case 'd':
                drownRobot(color);
                for (int i = 0; i < 16; i++)
                {
                    m_robotBody[i].x += m_robotMotionSpeed;
                }
                drownRobot(robotColor);
                break;
            case 'a':
                drownRobot(color);
                for (int i = 0; i < 16; i++)
                {
                    m_robotBody[i].x -= m_robotMotionSpeed;
                }
                drownRobot(robotColor);
                break;
            case 'e':
                robotRotation();
                break;
            case 27:
                return;

        }

    }
}

void Robot::robotRotation()
{

}




