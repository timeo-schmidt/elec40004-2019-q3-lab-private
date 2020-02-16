#include "rover_svg_writer.hpp"

#include <cassert>
#include <cmath>
#include <algorithm>

RoverSVGWriter::RoverSVGWriter()
{
    cout<<"<?xml version='1.0' encoding='UTF-8'?>"<<endl;
    cout<<"<svg xmlns='http://www.w3.org/2000/svg' "; // height='256' width='256'"<<endl;
    cout<<"  viewBox='-1.1 -1.1 2.2 2.2' >" << endl;

    m_time=0;
    m_angle=0;
    m_position={0,0};
    m_speed=0;
    m_pen_down=false;
}

RoverSVGWriter::~RoverSVGWriter()
{
    cout<<"</svg>"<<endl;
}

void RoverSVGWriter::advance_time(float dt)
{
    vector2d p = m_position;
    vector2d direction = vector2d{ cos(m_angle) , sin(m_angle) } ;
    vector2d pn = m_position + direction * dt * m_speed;

    if(m_pen_down){
        float width = max(0.001, min(0.01, 1.0/m_speed));

        cout << "  <line x1 = '"<<p.x<<"' y1 = '"<<p.y<<"' x2 = '"<<pn.x<<"' y2 = '"<<pn.y<<"' stroke = 'black' stroke-width = '"<<width<<"'/>" << endl;
    }

    m_time += dt;
    m_position=pn;
}
