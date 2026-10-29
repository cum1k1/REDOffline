#ifndef PhysicalConstants_h
#define PhysicalConstants_h

#ifdef HAVE_CLHEP

// ok, we have system CLHEP, take it from there
#include <CLHEP/Units/PhysicalConstants.h>

#else

// well, let's substitute some old copy from CLHEP instead

#include "units/SystemOfUnits.h"
namespace CLHEP
{

  static const double Avogadro = 6.02214179e+23/mole;
  static const double c_light   = 2.99792458e+8 * m/s;
  static const double c_squared = c_light * c_light;
  static const double STP_Temperature = 273.15*kelvin;
  static const double STP_Pressure    = 1.*atmosphere;

}  // namespace CLHEP

#endif /* HAVE_CLHEP */

#endif /* PhysicalConstants_h */
