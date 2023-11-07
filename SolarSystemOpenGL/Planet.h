#pragma once
#include "Color.h"
#include "Point.h"

/**
 * @class Planet
 * @brief Represents a celestial body in a solar system with orbital and physical properties.
 */
class Planet
{
public:
    /**
     * @brief Constructor for the Planet class.
     * @param OrbitRadius The orbital radius of the planet.
     * @param Size The size or radius of the planet.
     * @param RotationPeriod The rotation period of the planet.
     * @param RevolutionPeriod The revolution period of the planet.
     * @param color The color of the planet.
     * @param drawMoon Whether to draw a moon around the planet.
     * @param drawRing Whether to draw planetary rings around the planet.
     */
    Planet(const double OrbitRadius, const double Size, const double RotationPeriod, const double RevolutionPeriod, const Color& color, const bool drawMoon, const bool drawRing);

    /**
     * @brief Default constructor for the Planet class.
     */
    Planet();

    double OrbitRadius; /**< The orbital radius of the planet. */
    double Size; /**< The size or radius of the planet. */
    double RotationPeriod; /**< The rotation period of the planet. */
    double RevolutionPeriod; /**< The revolution period of the planet. */
    double Angle; /**< The current angle of the planet's position in its orbit. */
    bool drawMoon; /**< Indicates whether a moon is drawn around the planet. */
    bool drawRing; /**< Indicates whether planetary rings are drawn around the planet. */
    Color color; /**< The color of the planet. */
private:
};
