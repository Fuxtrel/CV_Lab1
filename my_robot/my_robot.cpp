#include "my_robot.h"


Robot::Robot(const Size2f m_areaSize, const Size2f robotBodySize, const Size2f &m_robotWheelSize, float motionShift,
             float rotationShift, Point2f rectangleSize, Point2f rectangleCentre) : m_robotMotionShift(motionShift),
                                                                                    m_robotRotateAngle(
                                                                                            rotationShift * M_PI / 180),
                                                                                    m_directionOfRotation(1),
                                                                                    m_currentAngle(0),
                                                                                    m_areaSize(m_areaSize),
                                                                                    m_robotRotationShift(rotationShift),
                                                                                    m_robotBodySize(robotBodySize),
                                                                                    m_currentTowerAngle(0),
                                                                                    m_rectangleSize(rectangleSize),
                                                                                    m_rectangleCentre(rectangleCentre)
{
    //Задаём координаты робота относитльно центра фона
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

    m_robotTower[0].y = m_robotBody[16].y - (m_robotBodySize.height / 6);
    m_robotTower[1].y = m_robotBody[16].y - (m_robotBodySize.height / 6);
    m_robotTower[3].y = m_robotBody[16].y + (m_robotBodySize.height / 6);
    m_robotTower[4].y = m_robotBody[16].y + (m_robotBodySize.height / 6);
    m_robotTower[2].y = m_robotBody[16].y;
    m_robotTower[5].y = m_robotBody[16].y;

    m_robotTower[6].x = m_robotBody[16].x - (m_robotBodySize.width / 16);
    m_robotTower[7].x = m_robotBody[16].x - (m_robotBodySize.width / 16);
    m_robotTower[8].x = m_robotBody[16].x + (m_robotBodySize.width / 16);
    m_robotTower[9].x = m_robotBody[16].x + (m_robotBodySize.width / 16);
    m_robotTower[10].x = m_robotBody[16].x;

    m_robotTower[6].y = m_robotTower[0].y;
    m_robotTower[7].y = m_robotTower[0].y - (m_robotBodySize.width / 3);
    m_robotTower[8].y = m_robotTower[0].y - (m_robotBodySize.width / 3);
    m_robotTower[9].y = m_robotTower[0].y;
    m_robotTower[10].y = m_robotBody[16].y;

    rectangle[0].x = rectangleCentre.x - (rectangleSize.x / 2);
    rectangle[1].x = rectangleCentre.x + (rectangleSize.x / 2);
    rectangle[2].x = rectangleCentre.x + (rectangleSize.x / 2);
    rectangle[3].x = rectangleCentre.x - (rectangleSize.x / 2);

    rectangle[0].y = rectangleCentre.y - (rectangleSize.y / 2);
    rectangle[1].y = rectangleCentre.y - (rectangleSize.y / 2);
    rectangle[2].y = rectangleCentre.y + (rectangleSize.y / 2);
    rectangle[3].y = rectangleCentre.y + (rectangleSize.y / 2);

    //Задаём цвета, матрицу поворота, а также настройки фона
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

    line(img, rectangle[0], rectangle[1], robotColor, 2);
    line(img, rectangle[1], rectangle[2], robotColor, 2);
    line(img, rectangle[2], rectangle[3], robotColor, 2);
    line(img, rectangle[3], rectangle[0], robotColor, 2);

    if (color == robotColor)
    {
        imshow("Empty window", img);
    }
}

void Robot::robotMotion()
{
    while (true)
    {
        //ожидаем нажатия
        switch (waitKey(1))
        {
            case 'w':
                //закрашиваем робота цветом фона
                drownRobot(color);
                //сохраняем текущие кординаты точек робота
                saveArray();
                //вызываем функции движения в нужную сторону
                //тела робота
                forwardMove(m_robotBody, 17);
                //башни робота
                forwardMove(m_robotTower, 11);
                //проверяем пересечение границ крайними угловыми точками робота
                borderCheck();
                //отрисовываем робота на фоне
                drownRobot(robotColor);
                break;
            case 's':
                drownRobot(color);
                saveArray();
                backMove(m_robotBody, 17);
                backMove(m_robotTower, 11);
                borderCheck();
                drownRobot(robotColor);
                break;
            case 'd':
                drownRobot(color);
                saveArray();
                rightMove(m_robotBody, 17);
                rightMove(m_robotTower, 11);
                borderCheck();
                drownRobot(robotColor);
                break;
            case 'a':
                drownRobot(color);
                saveArray();
                leftMove(m_robotBody, 17);
                leftMove(m_robotTower, 11);
                borderCheck();
                drownRobot(robotColor);
                break;
            case 'e':
                //выбор коэфффициента поворота по часосвой или против часовой стрелки
                m_directionOfRotation = 1;
                //сохраняем координаты робота
                saveArray();
                //отслеживание текущего угла поворота
                m_currentAngle -= m_robotRotationShift;
                //закраска робота на фоне
                drownRobot(color);
                //пересчёт координат при путём умножения на матрицу поворота
                robotRotation(m_robotBody, 17);
                robotRotation(m_robotTower, 11);
                borderCheck();
                drownRobot(robotColor);
                break;
            case 'q':
                m_directionOfRotation = -1;
                saveArray();
                m_currentAngle += m_robotRotationShift;
                drownRobot(color);
                robotRotation(m_robotBody, 17);
                robotRotation(m_robotTower, 11);
                borderCheck();
                drownRobot(robotColor);
                break;
            case 'j':
                m_directionOfRotation = -1;
                m_currentTowerAngle += m_robotRotationShift;
                drownRobot(color);
                saveArray();
                robotRotation(m_robotTower, 11);
                drownRobot(robotColor);
                break;
            case 'l':
                m_directionOfRotation = 1;
                m_currentTowerAngle += m_robotRotationShift;
                drownRobot(color);
                saveArray();
                robotRotation(m_robotTower, 11);
                drownRobot(robotColor);
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
        array[i].x = (tmp_x * cos(m_robotRotateAngle) + tmp_y * m_directionOfRotation * (-sin(m_robotRotateAngle)));
        array[i].y = (tmp_x * m_directionOfRotation * sin(m_robotRotateAngle) + tmp_y * (cos(m_robotRotateAngle)));
        array[i].x += array[length - 1].x;
        array[i].y += array[length - 1].y;
    }

}


void Robot::borderCheck()
{
    for (int i = 4; i < 14; i += 3)
    {
        if ((m_robotBody[i].x >= m_areaSize.width) || (m_robotBody[i].x <= 0) ||
            (m_robotBody[i].y >= m_areaSize.height) || m_robotBody[i].y <= 0 || isCrossRectangle())
        {
            for (int j = 0; j < 17; j++)
            {
                m_robotBody[j] = m_tmpRobotBody[j];
            }
            for (int j = 17, g = 0; j < 28; j++, g++)
            {
                m_robotTower[g] = m_tmpRobotBody[j];
            }
            m_currentAngle = m_tmpAngle;
            m_currentTowerAngle = m_tmpAngleTower;
            return;
        }
    }


}

void Robot::saveArray()
{
    for (int i = 0; i < 17; i++)
    {
        m_tmpRobotBody[i] = m_robotBody[i];
    }
    for (int i = 17, j = 0; i < 28; i++, j++)
    {
        m_tmpRobotBody[i] = m_robotTower[j];
    }
    m_tmpAngle = m_currentAngle;
    m_tmpAngleTower = m_currentTowerAngle;
}

void Robot::playRobot()
{
    drownRobot(robotColor);
    robotMotion();
}

void Robot::forwardMove(Point2f *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (sin((m_currentAngle) * M_PI / 180) == 0)
        {
            array[i].y -= m_robotMotionShift;
        } else if (sin((m_currentAngle) * M_PI / 180) == 1)
        {
            array[i].x -= m_robotMotionShift;
        } else if (sin((m_currentAngle) * M_PI / 180) == (-1))
        {
            array[i].x += m_robotMotionShift;
        } else
        {
            array[i].y -= m_robotMotionShift * cos((m_currentAngle) * M_PI / 180);
            array[i].x -= m_robotMotionShift * sin((m_currentAngle) * M_PI / 180);
        }
    }
}

void Robot::backMove(Point2f *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (sin((m_currentAngle) * M_PI / 180) == 0)
        {
            array[i].y += m_robotMotionShift;
        } else if (sin((m_currentAngle) * M_PI / 180) == 1)
        {
            array[i].x += m_robotMotionShift;
        } else if (sin((m_currentAngle) * M_PI / 180) == (-1))
        {
            array[i].x -= m_robotMotionShift;
        } else
        {
            array[i].y += m_robotMotionShift * cos((m_currentAngle) * M_PI / 180);
            array[i].x += m_robotMotionShift * sin((m_currentAngle) * M_PI / 180);
        }
    }
}

void Robot::rightMove(Point2f *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (sin((m_currentAngle) * M_PI / 180) == 0)
        {
            array[i].x += m_robotMotionShift;
        } else if (sin((m_currentAngle) * M_PI / 180) == 1)
        {
            array[i].y -= m_robotMotionShift;
        } else if (sin((m_currentAngle) * M_PI / 180) == (-1))
        {
            array[i].y += m_robotMotionShift;
        } else
        {
            array[i].y -= m_robotMotionShift * sin((m_currentAngle) * M_PI / 180);
            array[i].x += m_robotMotionShift * cos((m_currentAngle) * M_PI / 180);
        }
    }
}

void Robot::leftMove(Point2f *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (sin((m_currentAngle) * M_PI / 180) == 0)
        {
            array[i].x -= m_robotMotionShift;
        } else if (sin((m_currentAngle) * M_PI / 180) == 1)
        {
            array[i].y += m_robotMotionShift;
        } else if (sin((m_currentAngle) * M_PI / 180) == (-1))
        {
            array[i].y -= m_robotMotionShift;
        } else
        {
            array[i].y += m_robotMotionShift * sin((m_currentAngle) * M_PI / 180);
            array[i].x -= m_robotMotionShift * cos((m_currentAngle) * M_PI / 180);
        }
    }
}

bool Robot::checkRectangleBorder(Point2f p1, Point2f p2)
{
    if
    (
        ((p1.x <= rectangle[0].x) && (p2.x >= rectangle[0].x)) ||
        ((p1.x <= rectangle[0].x) && (p2.x >= rectangle[0].x)) ||
        ((p2.x <= rectangle[0].x) && (p1.x >= rectangle[0].x)) ||
        ((p2.x <= rectangle[0].x) && (p1.x >= rectangle[0].x)) ||
        ((p2.x >= rectangle[0].x) && (p1.x <= rectangle[1].x)) ||
        ((p1.x >= rectangle[0].x) && (p2.x <= rectangle[1].x))
    )
    {
        for (int i = rectangle[0].x; i < rectangle[1].x; i++)
        {
            float tmp = ((((i - p2.x) * (p2.y - p1.y)) / (p2.x - p1.x)) + p2.y);
            if (tmp <= rectangle[2].y && tmp >= rectangle[0].y)
            {
                return true;
            }
        }
    }
    return false;
}

bool Robot::isCrossRectangle()
{
    if (checkRectangleBorder(m_robotBody[4], m_robotBody[7]) ||
        checkRectangleBorder(m_robotBody[13], m_robotBody[10]) ||
        checkRectangleBorder(m_robotBody[4], m_robotBody[5]) ||
        checkRectangleBorder(m_robotBody[7], m_robotBody[8]) ||
        checkRectangleBorder(m_robotBody[14], m_robotBody[13]) ||
        checkRectangleBorder(m_robotBody[11], m_robotBody[10]) ||
        checkRectangleBorder(m_robotBody[5], m_robotBody[6]) ||
        checkRectangleBorder(m_robotBody[6], m_robotBody[15]) ||
        checkRectangleBorder(m_robotBody[15], m_robotBody[14]) ||
        checkRectangleBorder(m_robotBody[8], m_robotBody[9]) ||
        checkRectangleBorder(m_robotBody[9], m_robotBody[12]) ||
        checkRectangleBorder(m_robotBody[12], m_robotBody[11]))
    {
        return true;
    }
    return false;
}





