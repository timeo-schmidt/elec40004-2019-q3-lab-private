#include "rover_action_writer.hpp"

#include "rover_action.hpp"

#include <cassert>
#include <cmath>
#include <algorithm>

RoverActionWriter::RoverActionWriter()
{
    m_time=0;
    m_angle=0;
    m_position={0,0};
    m_speed=0;
    m_pen_down=false;
}

RoverActionWriter::~RoverActionWriter()
{
}

float RoverActionWriter::get_time() const
{
    return m_time;
}

vector2d RoverActionWriter::get_position()  const
{
    return m_position;
}

float RoverActionWriter::get_speed()  const
{
    return m_speed;
}

float RoverActionWriter::get_angle() const
{
    return m_angle;
}

bool RoverActionWriter::get_pen_down() const
{
    return m_pen_down;
}

void RoverActionWriter::set_speed(float speed)
{
    assert(speed >= 0);
    m_speed=speed;
}

void RoverActionWriter::set_angle(float angle)
{
    m_angle=angle;
}

void RoverActionWriter::set_pen_down(bool pen_down)
{
    m_pen_down=pen_down;
}

void RoverActionWriter::advance_time(float dt)
{
    vector2d p = m_position;
    vector2d direction = vector2d{ cos(m_angle) , sin(m_angle) } ;
    vector2d pn = m_position + direction * dt * m_speed;

    cout << RoverAction{dt, m_angle, m_speed, m_pen_down} << endl;

    m_time += dt;
    m_position=pn;

    // Diagnostic information being printed out. This goes to a
    // different place than cout, and is not part of the program output.
    cerr << "New position at " << m_time << " is " << m_position << endl;
}
