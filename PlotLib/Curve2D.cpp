#include "pch.h"
#include "Curve2D.h"

Curve2DBuilder& Curve2DBuilder::setX(const std::vector<double>& _x)
{
	x = &_x;
	return *this;
}

Curve2DBuilder& Curve2DBuilder::setY(const std::vector<double>& _y)
{
	y = &_y;
	return *this;
}

Curve2DBuilder& Curve2DBuilder::setLabel(const std::string _label)
{
	label = _label;
	return *this;
}

Curve2DBuilder& Curve2DBuilder::setWidth(const double lw)
{
	lineWidth = lw;
	return *this;
}

Curve2D Curve2DBuilder::build() const
{
	return Curve2D::Curve2D(x, y, label, lineWidth);
}
