#include "Airport.h"
#include <algorithm> // for std::find_if

// Constructor
Airport::Airport(const std::string& name, const std::string& city)
    : name_(name), city_(city) {}

// Accessor for airport name
std::string Airport::name() const {
    return name_;
}

// Accessor for airport city
std::string Airport::city() const {
    return city_;
}

// Handle landing of an airplane
void Airport::land(const airplane& ap) {
    airplanes_.push_back(ap);
}

// Handle takeoff of an airplane by ID
void Airport::takeoff(const std::string& id) {
    for (size_t i = 0; i < airplanes_.size(); ++i) {
        if (airplanes_[i].id == id) {
            airplanes_.erase(airplanes_.begin() + i);
            break;
        }
    }
}

// Count how many airplanes from a given airline are currently landed
int Airport::count_airplanes(const std::string& airline) const {
    int count = 0;
    for (const auto& ap : airplanes_) {
        if (ap.airline == airline) {
            ++count;
        }
    }
    return count;
}
