#include "my_robot.h"


Robot::Robot(const Size2f m_areaSize, const Size2f robotBodySize, const Size2f &m_robotWheelSize, float motionSpeed, float rotationSpeed)
        : m_robotMotionSpeed(motionSpeed), m_robotRotateAngle(rotationSpeed * M_PI / 180), m_directionOfRotation(1),
          m_currentAngle(0), m_areaSize(m_areaSize), m_robotRotationSpeed(rotationSpeed), m_robotBodySize(robotBodySize)
{

    m_robotBody[0].x = (m_areaSize.width / 2) - (m_robotBodySize.width / 2);
    m_robotBody[3].x = (m_areaSize.width / 2) - (m_robotBodySize.width / 2);
    m_robotBody[1].x = (m_areaSize.width / 2) + (m_robotBodySize.width / 2);
    m_robotBody[2].x = (m_areaSize.width / 2) + (m_robotBodySize.width / 2);

    m_robotBody[0].y = (m_areaSize.height / 2) + (m_robotBodySize.height / 2);
    m_robotBody[1].y = (m_areaSize.height / 2) + (m_robotBodySize.height / 2);
    m_robotBody[2].y = (m_areaSize.height / 2) - (m_robotBodySize.height / 2);
    m_robotBody[3].y = (m_areaSize.height / 2) - (m_robotBodySize.height / 2);

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
    m_robotBody[16].x = m_robotBody[0].x + (m_robotBodySize.width / 2);
    m_robotBody[16].y = m_robotBody[0].y - (m_robotBodySize.height / 2);
    /*******************************************************************/
    m_robotTower[0].x = m_robotBody[16].x - (m_robotBodySize.width / 4);
    m_robotTower[1].x = m_robotBody[16].x + (m_robotBodySize.width / 4);
    m_robotTower[2].x = m_robotBody[16].x + (m_robotBodySize.width / 3);
    m_robotTower[3].x = m_robotBody[16].x + (m_robotBodySize.width / 4);
    m_robotTower[4].x = m_robotBody[16].x - (m_robotBodySize.width / 4);
    m_robotTower[5].x = m_robotBody[16].x - (m_robotBodySize.width / 3);

    m_robotTower[0].y = m_robotBody[16].y - (m_robotBodySize.height / 4);
    m_robotTower[1].y = m_robotBody[16].y - (m_robotBodySize.height / 4);
    m_robotTower[3].y = m_robotBody[16].y + (m_robotBodySize.height / 4);
    m_robotTower[4].y = m_robotBody[16].y + (m_robotBodySize.height / 4);
    m_robotTower[2].y = m_robotBody[16].y;
    m_robotTower[5].y = m_robotBody[16].y;

    m_robotTower[6].x = m_robotBody[16].x - (m_robotBodySize.width / 16);
    m_robotTower[7].x = m_robotBody[16].x - (m_robotBodySize.width / 16);
    m_robotTower[8].x = m_robotBody[16].x + (m_robotBodySize.width / 16);
    m_robotTower[9].x = m_robotBody[16].x + (m_robotBodySize.width / 16);
    m_robotTower[10].x = m_robotBody[16].x;

    m_robotTower[6].y = m_robotTower[0].y;
    m_robotTower[7].y = m_robotTower[0].y - (m_robotBodySize.width / 6);
    m_robotTower[8].y = m_robotTower[0].y - (m_robotBodySize.width / 6);
    m_robotTower[9].y = m_robotTower[0].y;
    m_robotTower[10].y = m_robotBody[16].y;


    robotColor = {0, 0, 0};
    color = {0, 100, 0};
    img = {m_areaSize, CV_8UC3, color};
    m_rotationMatrix[0] = cos(m_robotRotateAngle);
    m_rotationMatrix[1] = -sin(m_robotRotateAngle);
    m_rotationMatrix[2] =
            m_robotBody[16].x * (1 - cos(m_robotRotateAngle)) + m_robotBody[16].y * sin(m_robotRotateAngle);
    m_rotationMatrix[3] = sin(m_robotRotateAngle);
    m_rotationMatrix[4] = cos(m_robotRotateAngle);
    m_rotationMatrix[5] =
            m_robotBody[16].y * (1 - cos(m_robotRotateAngle) - m_robotBody[16].x * sin(m_robotRotateAngle));

};

void Robot::drownRobot(Scalar color)
{
    line(img, m_robotBody[0], m_robotBody[1], color, 2);
    line(img, m_robotBody[1], m_robotBody[2], color, 2);
    line(img, m_robotBody[2], m_robotBody[3], color, 2);
    line(img, m_robotBody[3], m_robotBody[0], color, 2);

    line(img, m_robotBody[2], m_robotBody[11], color, 2);
    line(img, m_robotBody[3], m_robotBody[14], color, 2);

    line(img, m_robotBody[0], m_robotBody[4], color, 2);
    line(img, m_robotBody[4], m_robotBody[5], color, 2);
    line(img, m_robotBody[5], m_robotBody[6], color, 2);

    line(img, m_robotBody[1], m_robotBody[7], color, 2);
    line(img, m_robotBody[7], m_robotBody[8], color, 2);
    line(img, m_robotBody[8], m_robotBody[9], color, 2);

    line(img, m_robotBody[2], m_robotBody[10], color, 2);
    line(img, m_robotBody[10], m_robotBody[11], color, 2);
    line(img, m_robotBody[11], m_robotBody[12], color, 2);

    line(img, m_robotBody[3], m_robotBody[13], color, 2);
    line(img, m_robotBody[13], m_robotBody[14], color, 2);
    line(img, m_robotBody[14], m_robotBody[15], color, 2);

    line(img, m_robotTower[0], m_robotTower[1], color, 2);
    line(img, m_robotTower[1], m_robotTower[2], color, 2);
    line(img, m_robotTower[2], m_robotTower[3], color, 2);
    line(img, m_robotTower[3], m_robotTower[4], color, 2);
    line(img, m_robotTower[4], m_robotTower[5], color, 2);
    line(img, m_robotTower[5], m_robotTower[0], color, 2);
    line(img, m_robotTower[6], m_robotTower[7], color, 2);
    line(img, m_robotTower[7], m_robotTower[8], color, 2);
    line(img, m_robotTower[8], m_robotTower[9], color, 2);
    line(img, m_robotTower[9], m_robotTower[6], color, 2);

    if (color == robotColor)
    {
        imshow("Empty window", img);
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
                saveArray();
                for (Point2f &point : m_robotBody)
                {
                    if (sin((m_currentAngle) * M_PI / 180) == 0)
                    {
                        point.y -= m_robotMotionSpeed;
                    } else if (sin((m_currentAngle) * M_PI / 180) == 1)
                    {
                        point.x -= m_robotMotionSpeed;
                    } else if (sin((m_currentAngle) * M_PI / 180) == (-1))
                    {
                        point.x += m_robotMotionSpeed;
                    } else
                    {
                        point.y -= m_robotMotionSpeed * cos((m_currentAngle) * M_PI / 180);
                        point.x -= m_robotMotionSpeed * sin((m_currentAngle) * M_PI / 180);
                    }
                }
                borderCheck();
                drownRobot(robotColor);
                break;
            case 's':
                drownRobot(color);
                saveArray();
                for (Point2f &point : m_robotBody)
                {
                    if (sin((m_currentAngle) * M_PI / 180) == 0)
                    {
                        point.y += m_robotMotionSpeed;
                    } else if (sin((m_currentAngle) * M_PI / 180) == 1)
                    {
                        point.x += m_robotMotionSpeed;
                    } else if (sin((m_currentAngle) * M_PI / 180) == (-1))
                    {
                        point.x -= m_robotMotionSpeed;
                    } else
                    {
                        point.y += m_robotMotionSpeed * cos((m_currentAngle) * M_PI / 180);
                        point.x += m_robotMotionSpeed * sin((m_currentAngle) * M_PI / 180);
                    }
                }
                borderCheck();
                drownRobot(robotColor);
                break;
            case 'd':
                drownRobot(color);
                saveArray();
                for (Point2f &point : m_robotBody)
                {
                    if (sin((m_currentAngle) * M_PI / 180) == 0)
                    {
                        point.x += m_robotMotionSpeed;
                    } else if (sin((m_currentAngle) * M_PI / 180) == 1)
                    {
                        point.y -= m_robotMotionSpeed;
                    } else if (sin((m_currentAngle) * M_PI / 180) == (-1))
                    {
                        point.y += m_robotMotionSpeed;
                    } else
                    {
                        point.y -= m_robotMotionSpeed * sin((m_currentAngle) * M_PI / 180);
                        point.x += m_robotMotionSpeed * cos((m_currentAngle) * M_PI / 180);
                    }
                }
                borderCheck();
                drownRobot(robotColor);
                break;
            case 'a':
                drownRobot(color);
                saveArray();
                for (Point2f &point : m_robotBody)
                {
                    if (sin((m_currentAngle) * M_PI / 180) == 0)
                    {
                        point.x -= m_robotMotionSpeed;
                    } else if (sin((m_currentAngle) * M_PI / 180) == 1)
                    {
                        point.y += m_robotMotionSpeed;
                    } else if (sin((m_currentAngle) * M_PI / 180) == (-1))
                    {
                        point.y -= m_robotMotionSpeed;
                    } else
                    {
                        point.y += m_robotMotionSpeed * sin((m_currentAngle) * M_PI / 180);
                        point.x -= m_robotMotionSpeed * cos((m_currentAngle) * M_PI / 180);
                    }
                }
                borderCheck();
                drownRobot(robotColor);
                break;
            case 'e':
                m_directionOfRotation = 1;
                m_currentAngle -= m_robotRotationSpeed;
                drownRobot(color);
                saveArray();
                robotRotation(m_robotBody, 17);
                break;
            case 'q':
                m_directionOfRotation = -1;
                m_currentAngle += m_robotRotationSpeed;
                drownRobot(color);
                saveArray();
                robotRotation(m_robotBody, 17);
                break;
            case 'j':
                m_directionOfRotation = -1;
                m_currentAngle += m_robotRotationSpeed;
                drownRobot(color);
                saveArray();
                robotRotation(m_robotTower, 11);
                break;
            case 'l':
                m_directionOfRotation = 1;
                m_currentAngle += m_robotRotationSpeed;
                drownRobot(color);
                saveArray();
                robotRotation(m_robotTower, 11);
                break;
            case 27:
                exit(0);

        }

    }
}

void Robot::robotRotation(Point2f *array, int length)
{
    float tmp_x = 0, tmp_y = 0;
    for (int i = 0; i < length - 1; i++)
    {
        array[i].x -= array[length - 1].x;
        array[i].y -= array[length - 1].y;
        tmp_x = array[i].x;
        tmp_y = array[i].y;
        array[i].x = (tmp_x * cos(m_robotRotateAngle) +
                            tmp_y * m_directionOfRotation * (-sin(m_robotRotateAngle)));
        array[i].y = (tmp_x * m_directionOfRotation * sin(m_robotRotateAngle) +
                            tmp_y * (cos(m_robotRotateAngle)));
        array[i].x += array[length - 1].x;
        array[i].y += array[length - 1].y;
    }
    borderCheck();
    drownRobot(robotColor);
}


void Robot::borderCheck()
{
    for (int i = 4; i < 14; i += 3)
    {
        if ((m_robotBody[i].x >= m_areaSize.width) || (m_robotBody[i].x <= 0) ||
            (m_robotBody[i].y >= m_areaSize.height) || m_robotBody[i].y <= 0)
        {
            for (int j = 0; j < 17; j++)
            {
                m_robotBody[j] = m_tmpRobotBody[j];
            }
        }
    }
}

void Robot::saveArray()
{
    for (int i = 0; i < 17; i++)
    {
        m_tmpRobotBody[i] = m_robotBody[i];
    }
}

void Robot::playRobot()
{
    drownRobot(robotColor);
    robotMotion();
}





