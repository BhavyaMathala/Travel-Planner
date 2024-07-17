//
//  places.cpp
//  route planner pro
//
//  Created by Bhavya Mathala on 17/07/24.
//

#include "places.hpp"

// Define cities and their names
std::map<std::string, std::string> cities = {
    {"Delhi", "New Delhi"},
    {"Mumbai", "Mumbai"},
    {"Chennai", "Chennai"},
    {"Kolkata", "Kolkata"},
    {"Bengaluru", "Bengaluru"},
    {"Hyderabad", "Hyderabad"},
    {"Jaipur", "Jaipur"},
    {"Lucknow", "Lucknow"},
    {"Ahmedabad", "Ahmedabad"},
    {"Pune", "Pune"}
};

// Define travel details for all city combinations
std::vector<TravelDetails> allTravelDetails = {
    {"Delhi", "Mumbai", 1148.0, 2.0, 9000.0},
    {"Mumbai", "Delhi", 1148.0, 2.0, 9000.0},
    {"Delhi", "Chennai", 1760.0, 2.5, 14000.0},
    {"Chennai", "Delhi", 1760.0, 2.5, 14000.0},
    {"Delhi", "Kolkata", 1300.0, 2.0, 10000.0},
    {"Kolkata", "Delhi", 1300.0, 2.0, 10000.0},
    {"Delhi", "Bengaluru", 1740.0, 2.5, 14000.0},
    {"Bengaluru", "Delhi", 1740.0, 2.5, 14000.0},
    {"Delhi", "Hyderabad", 1250.0, 2.0, 10000.0},
    {"Hyderabad", "Delhi", 1250.0, 2.0, 10000.0},
    {"Mumbai", "Chennai", 1028.0, 1.5, 8000.0},
    {"Chennai", "Mumbai", 1028.0, 1.5, 8000.0},
    {"Mumbai", "Kolkata", 1650.0, 2.0, 13000.0},
    {"Kolkata", "Mumbai", 1650.0, 2.0, 13000.0},
    {"Mumbai", "Bengaluru", 840.0, 1.5, 7000.0},
    {"Bengaluru", "Mumbai", 840.0, 1.5, 7000.0},
    {"Mumbai", "Hyderabad", 710.0, 1.5, 6000.0},
    {"Hyderabad", "Mumbai", 710.0, 1.5, 6000.0},
    {"Chennai", "Kolkata", 1350.0, 2.0, 11000.0},
    {"Kolkata", "Chennai", 1350.0, 2.0, 11000.0},
    {"Chennai", "Bengaluru", 350.0, 1.0, 3000.0},
    {"Bengaluru", "Chennai", 350.0, 1.0, 3000.0},
    {"Chennai", "Hyderabad", 620.0, 1.5, 5000.0},
    {"Hyderabad", "Chennai", 620.0, 1.5, 5000.0},
    {"Kolkata", "Bengaluru", 1550.0, 2.0, 12500.0},
    {"Bengaluru", "Kolkata", 1550.0, 2.0, 12500.0},
    {"Kolkata", "Hyderabad", 1130.0, 1.5, 9000.0},
    {"Hyderabad", "Kolkata", 1130.0, 1.5, 9000.0},
    {"Bengaluru", "Hyderabad", 570.0, 1.0, 4500.0},
    {"Hyderabad", "Bengaluru", 570.0, 1.0, 4500.0}
};

// Define hotel details for each city
std::map<std::string, std::vector<HotelDetails>> hotels = {
    {"Delhi", {{"Taj Hotel", 4000.0}, {"Hyatt Regency", 3500.0}}},
    {"Mumbai", {{"Oberoi Hotel", 3800.0}, {"ITC Grand Central", 3200.0}}},
    {"Chennai", {{"Leela Palace", 3200.0}, {"Taj Coromandel", 2800.0}}},
    {"Kolkata", {{"The Lalit Great Eastern", 3000.0}, {"ITC Sonar Bangla", 2600.0}}},
    {"Bengaluru", {{"The Oberoi", 3500.0}, {"ITC Windsor", 3000.0}}},
    {"Hyderabad", {{"Park Hyatt", 3200.0}, {"Taj Falaknuma Palace", 2800.0}}},
    {"Jaipur", {{"Rambagh Palace", 3000.0}, {"ITC Rajputana", 2600.0}}},
    {"Lucknow", {{"Taj Mahal Lucknow", 2800.0}, {"Hyatt Regency Lucknow", 2400.0}}},
    {"Ahmedabad", {{"The Fern", 2600.0}, {"Crowne Plaza Ahmedabad", 2200.0}}},
    {"Pune", {{"The Westin", 3000.0}, {"JW Marriott", 2600.0}}}
};

