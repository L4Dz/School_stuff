#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "Floatable.h"
#include <string>

class Submarine : public Floatable {
public:
    // Constructor
    Submarine(int id, double mass, const std::string& captain)
      : Floatable(id, mass), captain_(captain) {}

    // Destructor
    ~Submarine() {}

    // Accessor for captain
    std::string captain() const {
        return captain_;
    }

    // Implementation of buoyancy()
    double buoyancy() const override {
        const double g = 9.81;
        const double rho = 1025.0;
        return mass() * g * rho;
    }

private:
    std::string captain_;
};

#endif // SUBMARINE_H
