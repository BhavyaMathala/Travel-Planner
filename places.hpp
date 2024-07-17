//
//  places.hpp
//  route planner pro
//
//  Created by Bhavya Mathala on 17/07/24.
//

#ifndef PLACES_H
#define PLACES_H

#include <string>
#include <vector>
#include <map>

// Structure for travel details
struct TravelDetails {
    std::string origin;
    std::string destination;
    double distance; // in kilometers
    double flightDuration; // in hours (assumed)
    double price; // in INR
};

// Structure for hotel details
struct HotelDetails {
    std::string name;
    double costPerDay; // in INR per day
};

// Map to store cities and their names
extern std::map<std::string, std::string> cities;

// Vector to store travel details for all city combinations
extern std::vector<TravelDetails> allTravelDetails;

// Map to store hotels for each city
extern std::map<std::string, std::vector<HotelDetails>> hotels;

#endif // PLACES_H

