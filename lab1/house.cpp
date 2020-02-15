#include "drawing.hpp"

int main()
{
    Drawing *d=new Drawing;

    d->add_square("green", 0.0,6.0, 10.0,10.0);
    d->add_square("blue", 0.0,0.0, 10.0,6.0);

    d->add_square("orange", 1.0,9.0, 9.0,4.0);
    d->add_triangle("darkred", 1.0,4.0, 5.0,1.0, 9.0,4.0);

    d->add_square("white", 2,5, 3.5,6.5);
    d->add_square("white", 8,5, 6.5,6.5);
    d->add_square("grey", 4,9, 6,5);
    d->add_square("darkred", 2,4, 3,2);

    d->write_svg();

    delete d;
}
