#pragma once

#include "pch.h"
#include "gnuplot-iostream.h"
#include "Curve2D.h"
#include <vector>
#include <string>

class Figure {

	Gnuplot gp;
	std::vector<const Curve2D*> curves;
	std::vector<std::string> labels;
	bool doHoldOn = true;
	std::string title = "fig"; 

	std::vector<std::pair<double, double>> pairXY(const std::vector<double>& x, const std::vector<double>& y);

	void plotOneCurve(Gnuplot& gp, const std::string baseCommand);

	void plotMultipleCurvesHoldOn(Gnuplot& gp, const std::string baseCommand);

	void plotMultipleCurvesHoldOff(Gnuplot& gp, const std::string baseCommand);
public:

	void plot(const Curve2D& curve);


	void setXlabel(std::string label);

	void setYlabel(std::string label);

	void setTitle(std::string _title);
};


