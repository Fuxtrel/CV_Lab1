#include "my_robot.h"


Robot::Robot(const Size2f &m_areaSize, const Size2f &m_robotBodySize, const Size2f &m_robotWheelSize, float motionSpeed)
        : m_robotMotionSpeed(motionSpeed), m_robotRotateAngle(30 * M_PI / 180), m_directionOfRotation(1),
          m_currentAngle(0), deltaY(1), deltaX(1)
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
    line(img, m_robotBody[0], m_robotBody[1], color, 3);
    line(img, m_robotBody[1], m_robotBody[2], color, 3);
    line(img, m_robotBody[2], m_robotBody[3], color, 3);
    line(img, m_robotBody[3], m_robotBody[0], color, 3);

    line(img, m_robotBody[2], m_robotBody[11], color, 3);
    line(img, m_robotBody[3], m_robotBody[14], color, 3);

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
                    borderCheck(point);
                    return;
                }
                drownRobot(robotColor);
                break;
            case 's':
                drownRobot(color);
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
                    borderCheck(point);
                    return;
                }
                drownRobot(robotColor);
                break;
            case 'd':
                drownRobot(color);
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
                drownRobot(robotColor);
                break;
            case 'a':
                drownRobot(color);
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
                drownRobot(robotColor);
                break;
            case 'e':
                m_directionOfRotation = 1;
                m_currentAngle -= 30;
                drownRobot(color);
                robotRotation();

                break;
            case 'q':
                m_directionOfRotation = -1;
                m_currentAngle += 30;
                drownRobot(color);
                robotRotation();

                break;
            case 27:
                exit(0);

        }

    }
}

void Robot::robotRotation()
{
    float tmp_x = 0, tmp_y = 0;
    for (int i = 0; i < 16; i++)
    {
        Point2f tmpPoint = m_robotBody[i];
        m_robotBody[i].x -= m_robotBody[16].x;
        m_robotBody[i].y -= m_robotBody[16].y;
        tmp_x = m_robotBody[i].x;
        tmp_y = m_robotBody[i].y;
        m_robotBody[i].x = (tmp_x * cos(m_robotRotateAngle) +
                            tmp_y * m_directionOfRotation * (-sin(m_robotRotateAngle)));
        m_robotBody[i].y = (tmp_x * m_directionOfRotation * sin(m_robotRotateAngle) +
                            tmp_y * (cos(m_robotRotateAngle)));
        m_robotBody[i].x += m_robotBody[16].x;
        m_robotBody[i].y += m_robotBody[16].y;
    }
    drownRobot(robotColor);
}


void Robot::borderCheck(Point2f &point)
{
    if ((point.x >= m_areaSize.width) || (point.x <= 0) || (point.y >= m_areaSize.height) || point.y <= 0)

        return;
}

void Robot::saveArray()
{
    for (int i = 0; i < 17; i++)
    {
        m_tmpRobotBody[i] = m_robotBody[i];
    }
    return;
}





