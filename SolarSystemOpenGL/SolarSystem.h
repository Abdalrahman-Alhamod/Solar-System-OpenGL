#pragma once
#include "Color.h"
#include "Point.h"
#include "Planet.h"
#include "SolarSystemConstants.h"



//  Control Constants
constexpr bool axisRX = 0, axisRY = 0, axisRZ = 1;
constexpr bool axisTX = 1, axisTY = 0, axisTZ = 0;
constexpr double TranslateZFromCenter = -100;
constexpr double slicesAndStacks = 0.5;	// Slices and Stacks values relative to quality value
constexpr bool enableMouseControls = false;
constexpr bool showControlPanel = false;
constexpr bool showPerformancePanel = false;
constexpr auto SimulationMode = Practical; // Real , Practical
constexpr double FPS = 60.0;



/**
 * @class SolarSystem
 * @brief Simulates and displays a solar system with planets and their orbits.
 */
class SolarSystem
{
public:
	/**
	 * @brief Draw a planet, including its orbit if enabled.
	 * @param planet The planet to be drawn.
	 */
	void drawPlanet(Planet& planet);

	/**
	 * @brief Decode keyboard input to control various aspects of the simulation.
	 * @param keys An array representing the state of keyboard keys.
	 */
	void decodeKeyboard(bool keys[256]);

	/**
	 * @brief Decode mouse input to control the camera or other features.
	 */
	void decodeMouse();

	/**
	 * @brief Control the camera based on keyboard input.
	 * @param keys An array representing the state of keyboard keys.
	 */
	void controlCamera(bool keys[256]);

	/**
	 * @brief Draw the entire solar system, including all planets and their orbits.
	 */
	void drawSolarSystem();

	/**
	 * @brief Load the projection matrix based on screen dimensions and simulation settings.
	 * @param width The width of the window or screen.
	 * @param height The height of the window or screen.
	 */
	void loadProjection(GLsizei width, GLsizei height);

	/**
	 * @brief Load initial values and configure the planets based on the selected simulation mode.
	 */
	void loadValues();
};