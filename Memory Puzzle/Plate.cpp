#include "Plate.h"

Plate::Plate()
{
    shape = Shape::nullshp;
    color = Color::nullclr;
}

void Plate::SetAttributes(Color clr, Shape shp)
{
    shape = shp;
    color = clr;
}

bool Plate::is_open()
{
    return state;
}

void Plate::FlipOver()
{
    state = !state;
}

Shape Plate::GetShape()
{
    return shape;
}

Color Plate::GetColor()
{
    return color;
}
