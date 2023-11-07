#include "Planet.h"
#include "Color.h"
#include "Point.h"
Planet::Planet(const double OrbitRadius,
	const double Size,
	const double RotationPeriod,
	const double RevolutionPeriod,
	const Color& color,
	const bool drawMoon,
	const bool drawRing)
{

	this->OrbitRadius = OrbitRadius;
	this->Size = Size;
	this->RotationPeriod = RotationPeriod;
	this->RevolutionPeriod = RevolutionPeriod;
	this->color = color;
	this->drawMoon = drawMoon;
	this->drawRing = drawRing;
	Angle = 0.0;
}
Planet::Planet() {
	this->OrbitRadius = 0.0;
	this->Size = 0.0;
	this->RotationPeriod = 0.0;
	this->RevolutionPeriod = 00.;
	this->color = Color();
	this->drawMoon = false;
	this->drawRing = false;
	Angle = 0.0;
}
