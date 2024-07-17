//
//  main.cpp
//  route planner pro
//
//  Created by Bhavya Mathala on 17/07/24.
//

#include <iostream>
#include <iomanip>
#include <limits>
#include "places.hpp"

using namespace std;

// Function prototypes
void displayCityMenu(const map<string, string>& cities);
void displaySingleTripDetails(const TravelDetails& details);
bool hasFlightRoute(const vector<TravelDetails>& allTravelDetails, const string& origin, const string& destination);
void displayHotelOptions(const vector<HotelDetails>& hotels);
double calculateHotelCost(double costPerDay, int numberOfDays);

int main() {
    // Display city menu
    displayCityMenu(cities);

    // Variables to accumulate total trip cost
    double totalFlightCost = 0.0;
    double totalHotelCost = 0.0;

    // Loop to handle multiple destinations
    string origin, destination;
    bool firstSelection = true; // Flag to check if it's the first destination selection

    while (true) {
        if (firstSelection) {
            // Get user's choice for origin city
            cout << "\nEnter origin city code: ";
            cin >> origin;

            // Validate user input for origin
            while (cities.find(origin) == cities.end()) {
                cout << "Invalid city code. Please enter a valid origin city code: ";
                cin >> origin;
            }
            firstSelection = false;
        }

        // Display available destinations from the selected origin
        cout << "Destinations from " << cities.at(origin) << ":\n";
        bool availableRoutes = false;
        for (const auto& details : allTravelDetails) {
            if (details.origin == origin) {
                cout << "- " << cities.at(details.destination) << endl;
                availableRoutes = true;
            }
        }

        // Check if there are available routes
        if (!availableRoutes) {
            cout << "There are no available flights from " << cities.at(origin) << ". Please choose another origin.\n";
            firstSelection = true; // Reset flag to ask for origin again
            continue;
        }

        // Get user's choice for destination city
        cout << "\nEnter destination city code: ";
        cin >> destination;

        // Validate user input for destination
        while (cities.find(destination) == cities.end() || origin == destination) {
            if (origin == destination) {
                cout << "Destination city must be different from origin city. Please enter again: ";
            } else {
                cout << "Invalid city code. Please enter a valid destination city code: ";
            }
            cin >> destination;
        }

        // Check if there is a flight route available
        if (!hasFlightRoute(allTravelDetails, origin, destination)) {
            cout << "There are no flights available from " << cities.at(origin) << " to " << cities.at(destination) << ". Please choose another route.\n";
            continue;
        }

        // Retrieve travel details based on user's selection
        TravelDetails singleTripDetails;
        for (const auto& details : allTravelDetails) {
            if (details.origin == origin && details.destination == destination) {
                singleTripDetails = details;
                break;
            }
        }

        // Output results for selected single trip
        displaySingleTripDetails(singleTripDetails);

        // Ask user how many days they want to stay
        int numberOfDays;
        cout << "\nHow many days do you want to stay in " << cities.at(destination) << "? ";
        cin >> numberOfDays;

        // Validate user input for number of days
        while (numberOfDays <= 0) {
            cout << "Invalid number of days. Please enter a positive integer: ";
            cin >> numberOfDays;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        // Display hotel options for the destination
        vector<HotelDetails> destinationHotels = hotels.at(cities.at(destination));
        displayHotelOptions(destinationHotels);

        // Ask user to select a hotel
        int hotelChoice;
        cout << "Select a hotel (1-" << destinationHotels.size() << "): ";
        cin >> hotelChoice;

        // Validate user input for hotel choice
        while (hotelChoice < 1 || hotelChoice > destinationHotels.size()) {
            cout << "Invalid choice. Please select a valid hotel: ";
            cin >> hotelChoice;
        }

        // Calculate total cost for the selected hotel and duration
        HotelDetails selectedHotel = destinationHotels[hotelChoice - 1];
        double totalHotelCostForTrip = calculateHotelCost(selectedHotel.costPerDay, numberOfDays);
        
        // Accumulate total costs for the trip
        totalFlightCost += singleTripDetails.price;
        totalHotelCost += totalHotelCostForTrip;

        // Display booking details
        cout << "\nHotel booking details:\n";
        cout << "Hotel Name: " << selectedHotel.name << endl;
        cout << "Cost per day: Rs. " << fixed << setprecision(2) << selectedHotel.costPerDay << endl;
        cout << "Number of days: " << numberOfDays << endl;
        cout << "Total Cost: Rs. " << fixed << setprecision(2) << totalHotelCostForTrip << endl;

        // Ask user if they want to visit another place from the current destination
        char choice;
        cout << "\nDo you want to visit another place from " << cities.at(destination) << "? (y/n): ";
        cin >> choice;

        // Convert input to lowercase for case-insensitive comparison
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        choice = tolower(choice);

        if (choice != 'y') {
            break; // Exit the loop if user does not want to visit another place
        }

        // Set new origin as the current destination
        origin = destination;
    }

    // Display total trip cost details
    cout << "\n\nTotal Trip Cost Summary:\n";
    cout << "--------------------------------\n";
    cout << "Total Flight Cost: Rs. " << fixed << setprecision(2) << totalFlightCost << endl;
    cout << "Total Hotel Cost: Rs. " << fixed << setprecision(2) << totalHotelCost << endl;
    cout << "--------------------------------\n";
    cout << "\nThank you for choosing our trip planner!\n";

    return 0;
}

// Function to display city menu
void displayCityMenu(const map<string, string>& cities) {
    cout << "Welcome to Travel Planner!\n";
    cout << "Available cities:\n";
    for (const auto& city : cities) {
        cout << city.first << ". " << city.second << endl;
    }
}

// Function to display details of a single trip
void displaySingleTripDetails(const TravelDetails& details) {
    cout << "\nTrip Details:\n";
    cout << "Origin: " << cities.at(details.origin) << " (" << details.origin << ")\n";
    cout << "Destination: " << cities.at(details.destination) << " (" << details.destination << ")\n";
    cout << "Distance: " << details.distance << " km\n";
    cout << "Flight Duration: " << details.flightDuration << " hours\n";
    cout << "Price: Rs. " << fixed << setprecision(2) << details.price << endl;
}

// Function to check if there is a flight route between two cities
bool hasFlightRoute(const vector<TravelDetails>& allTravelDetails, const string& origin, const string& destination) {
    for (const auto& details : allTravelDetails) {
        if (details.origin == origin && details.destination == destination) {
            return true;
        }
    }
    return false;
}

// Function to display hotel options for a destination
void displayHotelOptions(const vector<HotelDetails>& hotels) {
    cout << "\nHotel Options:\n";
    int index = 1;
    for (const auto& hotel : hotels) {
        cout << index << ". " << hotel.name << " (Cost per day: Rs. " << fixed << setprecision(2) << hotel.costPerDay << ")\n";
        index++;
    }
}

// Function to calculate total hotel cost for a given number of days
double calculateHotelCost(double costPerDay, int numberOfDays) {
    return costPerDay * numberOfDays;
}
