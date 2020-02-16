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
