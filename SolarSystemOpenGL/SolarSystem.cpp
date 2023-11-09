#include "SolarSystem.h"
#include "Constants.h";
#include "PrimitiveDrawer.h"
#include "Color.h"
#include "Point.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

// Planets Objects
Planet Sun, Mercury, Venus, Earth, Moon, Mars, Jupiter, Saturn, Uranus, Neptune;

// Scalars Variables
double EarthOrbitRadiusScalar, EarthSizeScalar;

// Control Changing Variables
double EarthPeriodScalar = YearPerSecond; // YearPerSecond , DayPerSecond , HourPerSecond , MinutePerSecond , SecondPerSecond 
double GraphicQuality = HightQuality; // HightQuality , MediumQuality , LowQuality
bool drawOrbit = true;
bool coloredOrbits = true;	// true => orbit color = planet color , false => orbit color = white
bool enableKeyboardControls = true;
auto ProjectionMode = Parallel; // Perspective , Parallel
auto SimulationMode = Practical; // Real , Practical

// Camera Veriables
bool enableCamera = true;
double movX, movY, movZ, lX, lY;
double increamentValue = 1.0;

// Window variables
double windowWidth, windowHeight;

void SolarSystem::loadValues() {
	if (SimulationMode == Real) {
		Sun = Planet(0, SunSize, 0, 0, SunColor, false, false);
		Mercury = Planet(MercuryOrbitRadius, MercurySize, MercuryRotationPeriod, MercuryRevolutionPeriod, MercuryColor, false, false);
		Venus = Planet(VenusOrbitRadius, VenusSize, VenusRotationPeriod, VenusRevolutionPeriod, VenusColor, false, false);
		Earth = Planet(EarthOrbitRadius, EarthSize, EarthRotationPeriod, EarthRevolutionPeriod, EarthColor, true, false);
		Moon = Planet(MoonOrbitRadius, MoonSize, 0, MoonRevolutionPeriod, MoonColor, false, false);
		Mars = Planet(MarsOrbitRadius, MarsSize, MarsRotationPeriod, MarsRevolutionPeriod, MarsColor, false, false);
		Jupiter = Planet(JupiterOrbitRadius, JupiterSize, JupiterRotationPeriod, JupiterRevolutionPeriod, JupiterColor, false, false);
		Saturn = Planet(SaturnOrbitRadius, SaturnSize, SaturnRotationPeriod, SaturnRevolutionPeriod, SaturnColor, false, true);
		Uranus = Planet(UranusOrbitRadius, UranusSize, UranusRotationPeriod, UranusRevolutionPeriod, UranusColor, false, false);
		Neptune = Planet(NeptuneOrbitRadius, NeptuneSize, NeptuneRotationPeriod, NeptuneRevolutionPeriod, NeptuneColor, false, false);
	}
	else if (SimulationMode == Practical) {
		Sun = Planet(0, SunSize / 30, 0, 0, SunColor, false, false);
		Mercury = Planet(MercuryOrbitRadius, MercurySize, MercuryRotationPeriod, MercuryRevolutionPeriod, MercuryColor, false, false);
		Venus = Planet(VenusOrbitRadius, VenusSize, VenusRotationPeriod, VenusRevolutionPeriod, VenusColor, false, false);
		Earth = Planet(EarthOrbitRadius, EarthSize, EarthRotationPeriod, EarthRevolutionPeriod, EarthColor, true, false);
		Moon = Planet(MoonOrbitRadius * 200, MoonSize, 0, MoonRevolutionPeriod, MoonColor, false, false);
		Mars = Planet(MarsOrbitRadius, MarsSize, MarsRotationPeriod, MarsRevolutionPeriod, MarsColor, false, false);
		Jupiter = Planet(JupiterOrbitRadius / 2.5, JupiterSize, JupiterRotationPeriod, JupiterRevolutionPeriod, JupiterColor, false, false);
		Saturn = Planet(SaturnOrbitRadius / 3, SaturnSize, SaturnRotationPeriod, SaturnRevolutionPeriod, SaturnColor, false, true);
		Uranus = Planet(UranusOrbitRadius / 4.5, UranusSize, UranusRotationPeriod, UranusRevolutionPeriod, UranusColor, false, false);
		Neptune = Planet(NeptuneOrbitRadius / 6, NeptuneSize, NeptuneRotationPeriod, NeptuneRevolutionPeriod, NeptuneColor, false, false);
	}
}

void SolarSystem::loadProjection(GLsizei width, GLsizei height) {
	windowWidth = width;
	windowHeight = height;
	if (ProjectionMode == Perspective) {

		double scalar;
		if (SimulationMode == Real) {
			scalar = 0.01;  // Adjust this value based on your preference.
			EarthOrbitRadiusScalar = 120;
			EarthSizeScalar = 0.2;
		}
		else if (SimulationMode == Practical) {
			scalar = 1;
			EarthOrbitRadiusScalar = 60;
			EarthSizeScalar = 3;
		}

		double fov = 100.0f / scalar; // Calculate the modified field of view angle.

		gluPerspective(fov, (double)width / (double)height, 0.1f, 10000.0f);
	}
	else if (ProjectionMode == Parallel) {

		double scalar;
		if (SimulationMode == Real) {
			scalar = 1;
			EarthOrbitRadiusScalar = 800;
			EarthSizeScalar = 1;
		}
		else if (SimulationMode == Practical) {
			scalar = 5;
			EarthOrbitRadiusScalar = 60;
			EarthSizeScalar = 3;
		}
		glOrtho(-width / scalar, width / scalar, -height / scalar, height / scalar, -100000, 100000);
	}
}

void SolarSystem::drawPlanet(Planet& planet)
{
	// Choose correct color when drawing orbit
	Color orbitColor;
	if (coloredOrbits) {
		// orbit color should be like planet color
		orbitColor = planet.color;
	}
	else {
		// orbit color should be white
		orbitColor = whiteColor;
	}


	glPushMatrix();

	if (drawOrbit)
		PrimitiveDrawer().drawCircleLine(centerPoint, planet.OrbitRadius * EarthOrbitRadiusScalar, orbitColor);

	// rotate planet around the sun , with increasing angle every frame
	if (planet.RevolutionPeriod != 0) {
		double angleIncreament = EarthPeriodScalar * (360.0 / (planet.RevolutionPeriod * FPS));
		glRotated(planet.Angle += angleIncreament, axisRX, axisRY, axisRZ);
	}

	// calculate translation value
	double translateValue = planet.OrbitRadius * EarthOrbitRadiusScalar;

	// translate due to translate selected axis
	glTranslated(translateValue * axisTX, translateValue * axisTY, translateValue * axisTZ);

	// planet color
	glColor3ub(planet.color.red, planet.color.green, planet.color.blue);

	// draw planet
	glutSolidSphere(planet.Size * EarthSizeScalar, slicesAndStacks * GraphicQuality, slicesAndStacks * GraphicQuality);

	if (planet.drawRing) {
		PrimitiveDrawer().drawRing(centerPoint, Moon.OrbitRadius * EarthOrbitRadiusScalar * 1.8, Moon.OrbitRadius * EarthOrbitRadiusScalar * 2.3, planet.color);
	}

	if (planet.drawMoon)
	{
		// Choose correct color when drawing orbit
		Color MoonOrbitColor;
		if (coloredOrbits) {
			// orbit color should be like Moon color
			MoonOrbitColor = Moon.color;
		}
		else {
			// orbit color should be white
			MoonOrbitColor = whiteColor;
		}

		if (drawOrbit)
			PrimitiveDrawer().drawCircleLine(centerPoint, Moon.OrbitRadius * EarthOrbitRadiusScalar, MoonOrbitColor);

		// rotate moon around the planet , with increasing angle every frame
		glRotated(Moon.Angle += EarthPeriodScalar * (360 / (Moon.RevolutionPeriod * FPS)), axisRX, axisRY, axisRZ);

		// calculate translation value
		double translateValue = Moon.OrbitRadius * EarthOrbitRadiusScalar;

		// translate due to translate selected axis
		glTranslated(translateValue * axisTX, translateValue * axisTY, translateValue * axisTZ);

		// Moon color
		glColor3ub(Moon.color.red, Moon.color.green, Moon.color.blue);

		// draw Moon
		glutSolidSphere(Moon.Size * EarthSizeScalar, slicesAndStacks * GraphicQuality, slicesAndStacks * GraphicQuality);

	}

	glPopMatrix();


}

void SolarSystem::decodeKeyboard(bool keys[256]) {
	if (keys['E']) {
		enableKeyboardControls = !enableKeyboardControls;
		enableCamera = !enableCamera;
	}
	if (enableKeyboardControls) {
		// Control Quality
		if (keys['Q']) {
			if (GraphicQuality == HightQuality)
				GraphicQuality = LowQuality;
			else if (GraphicQuality == LowQuality)
				GraphicQuality = MediumQuality;
			else if (GraphicQuality == MediumQuality)
				GraphicQuality = HightQuality;
		}
		// Control Drawing Orbit
		if (keys['O']) {
			drawOrbit = !drawOrbit;
		}
		// Control Coloring Orbit
		if (keys['C']) {
			coloredOrbits = !coloredOrbits;

		}
		if (keys['P']) {
			if (ProjectionMode == Perspective)
				ProjectionMode = Parallel;
			else if (ProjectionMode == Parallel)
				ProjectionMode = Perspective;

			double width = windowWidth, height = windowHeight;
			glViewport(0, 0, width, height);						// Reset The Current Viewport
			glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
			glLoadIdentity();									// Reset The Projection Matrix
			// Calculate The Aspect Ratio Of The Window
			SolarSystem().loadProjection(width, height);
			glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
			glLoadIdentity();
			glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
			glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
			glClearDepth(1.0f);									// Depth Buffer Setup
			glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
			glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
			glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
			SolarSystem().loadValues();
		}
		if (keys['T']) {
			if (EarthPeriodScalar == DayPerSecond)
				EarthPeriodScalar = 10 * DayPerSecond;
			else if (EarthPeriodScalar == 10 * DayPerSecond)
				EarthPeriodScalar = 100 * DayPerSecond;
			else if (EarthPeriodScalar == 100 * DayPerSecond)
				EarthPeriodScalar = YearPerSecond;
			else if (EarthPeriodScalar == YearPerSecond)
				EarthPeriodScalar = 3 * YearPerSecond;
			else if (EarthPeriodScalar == 3 * YearPerSecond)
				EarthPeriodScalar = 6 * YearPerSecond;
			else if (EarthPeriodScalar == 6 * YearPerSecond)
				EarthPeriodScalar = 10 * YearPerSecond;
			else if (EarthPeriodScalar == 10 * YearPerSecond)
				EarthPeriodScalar = 30 * YearPerSecond;
			else if (EarthPeriodScalar == 30 * YearPerSecond)
				EarthPeriodScalar = 60 * YearPerSecond;
			else if (EarthPeriodScalar == 60 * YearPerSecond)
				EarthPeriodScalar = 100 * YearPerSecond;
			else if (EarthPeriodScalar == 100 * YearPerSecond)
				EarthPeriodScalar = DayPerSecond;
		}
		if (keys['G'] || keys['g']) {
			if (increamentValue == 1.0)
				increamentValue = 0.6;
			else if (increamentValue == 0.6)
				increamentValue = 0.3;
			else if (increamentValue == 0.3)
				increamentValue = 0.1;
			else if (increamentValue == 0.1)
				increamentValue = 0.06;
			else if (increamentValue == 0.06)
				increamentValue = 1;
		}
		if (keys['M']) {
			if (SimulationMode == Practical)
				SimulationMode = Real;
			else if (SimulationMode == Real)
				SimulationMode = Practical;
			SolarSystem().loadProjection(windowWidth, windowHeight);
			loadValues();
		}

	}
};

void SolarSystem::decodeMouse() {}

void SolarSystem::controlCamera(bool keys[256]) {
	// Control Camera
	gluLookAt(movX, movY, movZ, lX, lY, -5, 0, 1, 0);
	if (enableCamera) {
		if (keys['D'] || keys['d'])
			movX += increamentValue;
		if (keys['A'])
			movX -= increamentValue;
		if (keys['W'])
			movY += increamentValue;
		if (keys['S'])
			movY -= increamentValue;
		if (keys['Z'])
			movZ += increamentValue;
		if (keys['X'])
			movZ -= increamentValue;
		if (keys[VK_LEFT])
			lX += increamentValue;
		if (keys[VK_RIGHT])
			lX -= increamentValue;
		if (keys[VK_UP])
			lY += increamentValue;
		if (keys[VK_DOWN])
			lY -= increamentValue;
	}
}

void SolarSystem::drawSolarSystem() {

	drawPlanet(Sun);

	drawPlanet(Mercury);

	drawPlanet(Venus);

	drawPlanet(Earth);

	drawPlanet(Mars);

	drawPlanet(Jupiter);

	drawPlanet(Saturn);

	drawPlanet(Uranus);

	drawPlanet(Neptune);

}