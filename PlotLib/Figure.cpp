#include "pch.h"
#include "Figure.h"

std::vector<std::pair<double, double>> Figure::pairXY(const std::vector<double>& x, const std::vector<double>& y)
	{
		std::vector<std::pair<double, double>> xyPlot;
		xyPlot.reserve(x.size());
		std::transform(x.begin(), x.end(), y.begin(), std::back_inserter(xyPlot),
			[](double a, double b) { return std::make_pair(a, b); });
		return xyPlot;
	}

void Figure::plotOneCurve(Gnuplot& gp, const std::string baseCommand)
{
	std::string command = baseCommand;
	gp << command << std::endl;
	gp.send1d(pairXY(curves[0]->x, curves[0]->y));
}

void Figure::plotMultipleCurvesHoldOn(Gnuplot& gp, const std::string baseCommand)
{
	std::string command = baseCommand;
	for (auto i = 1; i < curves.size(); ++i) {
		command += ", '-' with lines t'" + curves[i]->label + "'" + " lw " + std::to_string(curves[i]->lineWidth);
	}
	gp << command << std::endl;
	for (auto curve : curves) {
		gp.send1d(pairXY(curve->x, curve->y));
	}
}

void Figure::plotMultipleCurvesHoldOff(Gnuplot& gp, const std::string baseCommand)
{
	auto command = baseCommand;
	for (auto i = 0; i < curves.size(); ++i) {
		command = "set term wxt " + std::to_string(i) + "title '" + title + "' " + "persist" + "\n" + baseCommand;
		gp << command << std::endl;
		gp.send1d(pairXY(curves[i]->x, curves[i]->y));
	}
}

void Figure::plot(const Curve2D& curve)
{
	curves.emplace_back(&curve);
	labels.emplace_back(curve.label);

	std::string command = "set term wxt  title '" + title + "'\n" + "set key outside\n plot '-' with lines t '" + curves[0]->label + "'" + " lw " + std::to_string(curves[0]->lineWidth);
	if (curves.size() == 1) {
		plotOneCurve(gp, command);
		return;
	}
	else if (doHoldOn)
	{
		plotMultipleCurvesHoldOn(gp, command);
	}
	else
	{
		plotMultipleCurvesHoldOff(gp, command);

	}
}

void Figure::setXlabel(std::string label)
{
	label = '\"' + label + '\"';
	std::string command = "set xlabel " + label + "\n";
	gp << command << std::endl;
}

void Figure::setYlabel(std::string label)
{
	label = '\"' + label + '\"';
	std::string command = "set ylabel " + label + "\n";
	gp << command << std::endl;
}

void Figure::setTitle(std::string _title)
{
	title = _title;
}


