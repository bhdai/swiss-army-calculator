// randfuncs.cpp
#include "randfuncs.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

namespace {
    bool seeded = false;
    void ensure_seeded() {
        if (!seeded) {
            srand(time(0));
            seeded = true;
        }
    }
}

void flipCoin() {
    ensure_seeded();
    if (rand() % 2 == 0) {
        std::cout << "Result: Heads" << std::endl;
    } else {
        std::cout << "Result: Tails" << std::endl;
    }
}

int rollDice(int sides) {
    ensure_seeded();
    if (sides <= 0) {
        std::cerr << "Error: Number of sides must be positive." << std::endl;
        return -1;
    }
    return (rand() % sides) + 1;
}
