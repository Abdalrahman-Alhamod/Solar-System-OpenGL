#pragma once
#include "Color.h"
#include "Point.h"

// Graphics Quality Contants
constexpr double HightQuality = 100; // Hight Graphic Quality Vlaues
constexpr double MediumQuality = 50;	// Medium Graphic Quality Vlaues
constexpr double LowQuality = 25;	// Low Graphic Quality Vlaues

// projection Mode
constexpr auto Perspective = "Perspective";	// Far obkects looks small, close object looks big, simulate human eye
constexpr auto Parallel = "Parallel";	// far and close objects look the same, preserve shapes

// Planets Orbit Radius Constants
constexpr double MercuryOrbitRadius = 0.39;		// Mercury Orbit Radius relative to Earth Orbit Radius
constexpr double VenusOrbitRadius = 0.72;			// Venus Orbit Radius relative to Earth Orbit Radius
constexpr double EarthOrbitRadius = 1.0;			// Earth Orbit Radius
constexpr double MoonOrbitRadius = 0.5 * 0.001;			// Moon Orbit Radius relative to Earth Orbit Radius
constexpr double MarsOrbitRadius = 1.52;			// Mars Orbit Radius relative to Earth Orbit Radius
constexpr double JupiterOrbitRadius = 5.2;			// Jupiter Orbit Radius relative to Earth Orbit Radius
constexpr double SaturnOrbitRadius = 9.58;			// Saturn Orbit Radius relative to Earth Orbit Radius
constexpr double UranusOrbitRadius = 19.22;		// Uranus Orbit Radius relative to Earth Orbit Radius
constexpr double NeptuneOrbitRadius = 30.05;		// Neptune Orbit Radius relative to Earth Orbit Radius

// Planets Size Constants
constexpr double SunSize = 109.0;			// Sun Size relative to Earth Size
constexpr double MercurySize = 0.4;			// Mercury Size relative to Earth Size
constexpr double VenusSize = 0.95;			// Venus Size relative to Earth Size
constexpr double EarthSize = 1.0;			// Earth Size
constexpr double MoonSize = 0.25;			// Moon Size relative to Earth Size
constexpr double MarsSize = 0.8;			// Mars Size relative to Earth Size
constexpr double JupiterSize = 4.0;			// Jupiter Size relative to Earth Size
constexpr double SaturnSize = 1.6;			// Saturn Size relative to Earth Size
constexpr double UranusSize = 2.0;			// Uranus Size relative to Earth Size
constexpr double NeptuneSize = 2.1;			// Neptune Size relative to Earth Size

// Panets Color Constants
const Color SunColor = Color(255, 255, 0);				// Sun Color
const Color MercuryColor = Color(110, 110, 110);		// Mercury Color
const Color VenusColor = Color(255, 120, 0);			// Venus Color
const Color EarthColor = Color(0, 0, 255);				// Earth Color
const Color MoonColor = Color(200, 200, 200);			// Moon Color
const Color MarsColor = Color(255, 0, 0);				// Mars Color
const Color JupiterColor = Color(255, 165, 0);			// Jupiter Color
const Color SaturnColor = Color(101, 95, 69);			// Saturn Color 
const Color UranusColor = Color(173, 216, 230);		// Uranus Color
const Color NeptuneColor = Color(0, 0, 128);			// Neptune Color 

// Planets Rotation Period Constants ( Around it self )
constexpr double MercuryRotationPeriod = 58.6;			// Mercury Rotation Period relative to Earth Day
constexpr double VenusRotationPeriod = 243.0;			// Venus Rotation Period relative to Earth Day
constexpr double EarthRotationPeriod = 1.0;			// Earth Rotation Period
constexpr double MarsRotationPeriod = 1.03;			// Mars Rotation Period relative to Earth Day
constexpr double JupiterRotationPeriod = 0.41;			// Jupiter Rotation Period relative to Earth Day
constexpr double SaturnRotationPeriod = 0.45;			// Saturn Rotation Period relative to Earth Day
constexpr double UranusRotationPeriod = 0.72;			// Uranus Rotation Period relative to Earth Day
constexpr double NeptuneRotationPeriod = 0.67;			// Neptune Rotation Period relative to Earth Day

// Planets Revolution Period Constants ( Around the Sun )
constexpr double MercuryRevolutionPeriod = 87.97;			// Mercury Revolution Period relative to Earth Day
constexpr double VenusRevolutionPeriod = 224.7;			// Venus Revolution Period relative to Earth Day
constexpr double EarthRevolutionPeriod = 365.26;			// Earth Revolution Period
constexpr double MoonRevolutionPeriod = 27.3;			// Moon Revolution Period relative to Earth Day
constexpr double MarsRevolutionPeriod = 1.88 * 365.26;			// Mars Revolution Period relative to Earth Day
constexpr double JupiterRevolutionPeriod = 11.86 * 365.26;			// Jupiter Revolution Period relative to Earth Day
constexpr double SaturnRevolutionPeriod = 29.46 * 365.26;			// Saturn Revolution Period relative to Earth Day
constexpr double UranusRevolutionPeriod = 84.01 * 365.26;			// Uranus Revolution Period relative to Earth Day
constexpr double NeptuneRevolutionPeriod = 164.79 * 365.26;			// Neptune Revolution Period relative to Earth Day

// Simulation Modes
constexpr auto Real = "Real"; // Real 100% Accurate simulation
constexpr auto Practical = "Practical"; // Pratical 80% Accurate simulation

// Period Constants
constexpr double YearPerSecond = 365.25;  // Every year takes a second
constexpr double DayPerSecond = 1.0;	 // Every day takes a second
constexpr double HourPerSecond = DayPerSecond / 24.0; // Every houd takes a second
constexpr double MinutePerSecond = HourPerSecond / 60.0; // Every minute takes a second
constexpr double SecondPerSecond = MinutePerSecond / 60.0; // Every second takes a second

// Other Constants
const Point centerPoint = Point(0, 0, 0); // Center Point for drawing shapes
const Color whiteColor = Color(255, 255, 255);  // Predefined White color for Moons and non-colored orbits

class SolarSystemConstants
{
};

