#include "userinput.h"
#include <iostream>
#include <cmath>

// Function to get the total fuel load in pounds from the user.
// It checks if the entered value exceeds the maximum allowable fuel load and warns the user if so.
double getFuel() {
    std::cout << "Enter Fuel Load (lbs): ";
    double fuel{};
    std::cin >> fuel;
    const double maxFuel = 244000;  // Define maximum fuel load in pounds.
    if (fuel > maxFuel) {
        std::cerr << "Warning: Maximum fuel load (244,000 lbs) exceeded!\n";
        return 0;  // Return 0 to indicate an error state.
    }
    return fuel;  // Return the entered fuel load.
}

// Function to get the number of passengers including the flight crew.
// Ensures that the number does not exceed the maximum capacity.
double getPax() {
    std::cout << "Enter # of Pax, including flight crew: ";
    double pax{};
    std::cin >> pax;
    const double maxPax = 134;  // Maximum number of passengers allowed.
    if (pax > maxPax) {
        std::cerr << "Warning: Maximum passenger count exceeded!\n";
        return 0;  // Return 0 to indicate an error state.
    }
    return pax * 185;  // Return the total weight of passengers by assuming average weight.
}

// Function to get the cargo weight in pounds.
// It validates that the cargo weight does not exceed the aircraft's cargo capacity.
double getCargo() {
    std::cout << "Enter Total Cargo Weight (lbs): ";
    double cargo{};
    std::cin >> cargo;
    const double maxCargo = 170900;  // Maximum cargo weight in pounds.
    if (cargo > maxCargo) {
        std::cerr << "Warning: Maximum cargo payload (170,900 lbs) exceeded!\n";
        return 0;  // Return 0 to indicate an error state.
    }
    return cargo;  // Return the entered cargo weight.
}

// Function to retrieve the field elevation in feet from the user.
double getElevation() {
    std::cout << "Enter Field Elevation (ft): ";
    double elevationFeet{};
    std::cin >> elevationFeet;
    return elevationFeet;  // Return the entered elevation.
}

// Function to calculate and return air density based on various environmental parameters.
double getDensity(double elevationFeet) {
    std::cout << "Enter Local Temperature (F): ";
    double tempF{};
    std::cin >> tempF;

    std::cout << "Enter Barometric Setting (inHg): ";
    double baroInHg{};
    std::cin >> baroInHg;

    std::cout << "Enter Relative Humidity (%): ";
    double humidityPercent{};
    std::cin >> humidityPercent;

    // Convert elevation from feet to meters for the formula calculation.
    double elevationMeters = elevationFeet * 0.3048;
    // Convert temperature from Fahrenheit to Kelvin.
    double tempK = (tempF - 32) * 5.0 / 9.0 + 273.15;
    // Convert barometric pressure from inHg to Pascals.
    double P = baroInHg * 3386.39;
    // Calculate saturation vapor pressure using the Magnus-Tetens approximation (simplified).
    double P_sat = 6.1078 * std::exp((17.62 * (tempF - 32) / 1.8) / ((tempF - 32) / 1.8 + 243.12)) * 100;
    // Calculate the actual vapor pressure.
    double P_v = (humidityPercent / 100.0) * P_sat;
    // Calculate the dry air pressure.
    double P_d = P - P_v;
    // The ideal gas constant for dry air in J/(kg·K).
    const double R = 287.05;
    // Calculate air density using the ideal gas law.
    double density = P_d / (R * tempK);
    return density;  // Return the calculated air density in kg/m³.
}
