#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <sstream> // for parsing input
#include "mathfuncs.h"


void printHelp() {
  std::cout << "Swiss Army Calculator Help:" << std::endl;
  std::cout << "  help                 - Shows this help message." << std::endl;
  std::cout << "  add <num1> <num2>    - Adds two numbers." << std::endl;
  std::cout << "  sub <num1> <num2>    - Subtracts second number from first." << std::endl;
  std::cout << "  mul <num1> <num2>    - Multiplies two numbers." << std::endl;
  std::cout << "  div <num1> <num2>    - Divides first number by second." << std::endl;
  std::cout << "  exit                 - Exits the calculator." << std::endl;
  // Add help for random functions later when rand_feat is merged
}

int main() {
  std::string line;
  std::cout << "Welcom to Swiss Army Calculator!" << std::endl;
  printHelp();

  while (true) {
    std::cout << "> ";
    if (!std::getline(std::cin, line)) {
      break;
    }

    std::stringstream ss(line);
    std::string command;
    ss >> command;

    if (command == "exit") {
      break;
    } else if (command == "help") {
      printHelp();
    } else if (command == "add" || command == "sub" || command == "mul" || command == "div") {
      double num1, num2;
      if (!(ss >> num1 && ss >> num2)) {
        std::cerr << "Error: Please provide two number for math operations" << std::endl;
        continue;
      }
      try {
        if (command == "add") {
          std::cout << "Result: " << add(num1, num2) << std::endl;
        } else if (command == "sub") {
          std::cout << "Result: " << subtract(num1, num2) << std::endl;
        } else if (command == "mul") {
          std::cout << "Result: " << multiply(num1, num2) << std::endl;
        } else if (command == "div") {
          std::cout << "Result: " << divide(num1, num2) << std::endl;
        }
      } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
      }
    } else {
      std::cerr << "Unkown command. Type 'help' for available command." << std::endl;
    }
  }
  std::cout << "Exiting calculator" << std::endl;
  return 0;
}
