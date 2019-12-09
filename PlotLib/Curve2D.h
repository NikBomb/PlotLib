#pragma once


#include "pch.h"
#include <vector>
#include <string>

class Curve2DBuilder;

class Curve2D {

public:
	const std::string label;
	const std::vector<double>& x;
	const std::vector<double>& y;
	const double lineWidth;

private:
	friend Curve2DBuilder;
	Curve2D(const std::vector<double>* _x, const std::vector<double>* _y, const std::string _label, double lw) : x{ *_x }, y{ *_y }, label{ _label }, lineWidth{lw}  {

	};

};

class Curve2DBuilder {
private:
	std::string label = "curve";
	const std::vector<double>* x;
	const std::vector<double>* y;
	double lineWidth = 1.1;
public:

	Curve2DBuilder& setX(const std::vector<double>& _x);

	Curve2DBuilder& setY(const std::vector<double>& _y);

	Curve2DBuilder& setLabel(const std::string _label);

	Curve2DBuilder& setWidth(const double lw);


	Curve2D build() const;
	
};