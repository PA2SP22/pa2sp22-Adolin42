#include "temperature.h"

// CLASS FUNCTION DEFINITIONS GO HERE
Temperature::Temperature() {
  kelvin_ = 0;
}

Temperature::Temperature(double kelvin) {
  kelvin_ = kelvin;
}

Temperature::Temperature(double temp, char unit) {
  if (unit == 'F' || unit == 'f') {
    SetTempFromFahrenheit(temp);
  } else if (unit == 'C' || unit == 'c') {
    SetTempFromCelsius(temp);
  } else {
    SetTempFromKelvin(temp);
  }
}

void Temperature::SetTempFromKelvin(double kelvin) {
  kelvin_ = kelvin;
}

void Temperature::SetTempFromCelsius(double celsius) {
  kelvin_ = celsius + 273.15;
}

void Temperature::SetTempFromFahrenheit(double fahrenheit) {
  kelvin_ = (5.0 * (fahrenheit - 32) / 9) + 273.15;
}

double Temperature::GetTempAsKelvin() const {
  return kelvin_;
}

double Temperature::GetTempAsCelsius() const {
  return kelvin_ - 273.15;
}

double Temperature::GetTempAsFahrenheit() const {
  // K − 273.15) × 9/5 + 32
  return GetTempAsCelsius() * 9/5 + 32;
}

string Temperature::ToString(char unit) const {
  stringstream sout;
  sout.setf(std::ios::showpoint | std::ios::fixed);
  sout.precision(2);
  string unit_name;

  if (unit == 'C' || unit == 'c') {
    unit_name = "Celsius";
    sout << GetTempAsCelsius() << " " << unit_name;
    return sout.str();

  } else if (unit == 'F' || unit == 'f') {
    unit_name = "Fahrenheit";
    sout << GetTempAsFahrenheit() << " " << unit_name;
    return sout.str();

  } else if (unit == 'K' || unit == 'k') {
    unit_name = "Kelvin";
    sout << GetTempAsKelvin() << " " << unit_name;
    return sout.str();

  } else {
    return "Invalid Unit";
  }
}
