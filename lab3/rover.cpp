#include "rover.hpp"

float Rover::get_time() const
{
    return m_time;
}

vector2d Rover::get_position() const
{
    return m_position;
}

float Rover::get_speed() const
{
    return m_speed;
}

float Rover::get_angle() const
{
    return m_angle;
}

bool Rover::get_pen_down() const
{
    return m_pen_down;
}

void Rover::set_speed(float speed)
{
    assert(speed >= 0);
    m_speed=speed;
}

void Rover::set_angle(float angle)
{
    m_angle=angle;
}

void Rover::set_pen_down(bool pen_down)
{
    m_pen_down=pen_down;
}
