#include "mathfuncs.h"
#include <stdexcept>

// this comment's just for testing make

double add(double a, double b) {
  return a + b;
}

double subtract(double a, double b) {
  return a - b;
}

double multiply(double a, double b) {
  return a * b;
}

double divide(double a, double b) {
  if (b == 0) {
    throw std::runtime_error("Error: Division by zero!");
  }
  return a / b;
}
