#include <cmath> // Include the cmath library for access to the sqrt function
#include <iostream> // Include the iostream library for input and output operations
#include "calculate.h" // Include the custom header file for function declarations

// Function to calculate the total weight of the aircraft by summing up the base weight and the weights of fuel, passengers, and cargo.
double getTotalWeight(double fuel, double paxWeight, double cargo) {
    double baseWeight = 282500; // Aircraft base weight in pounds
    double totalWeight = baseWeight + fuel + paxWeight + cargo; // Sum the base weight with fuel, passengers, and cargo weights
    double maxTakeoffWeight = 585000; // Define the maximum allowable takeoff weight in pounds

    // Check if the calculated total weight exceeds the maximum allowable takeoff weight
    if (totalWeight > maxTakeoffWeight) {
        std::cerr << "Error: Total weight exceeds maximum takeoff weight!\n"; // Print an error message to the standard error stream
        return 0; // Return 0 to indicate an error or invalid state
    }
    std::cout << "Total Takeoff Weight: " << totalWeight << " lbs\n";
    return totalWeight; // Return the calculated total weight if within the allowable limit
}

// Function to calculate the stall speed (V_S) of the aircraft using the total weight and air density.
double getStallSpeed(double totalWeight, double density) {
    const double wingArea = 3800 * 0.092903; // Convert wing area from square feet to square meters (3800 square feet)
    const double liftCoefficient = 3.156; // Assume a fixed lift coefficient for the calculation
    double stallSpeed = std::sqrt((2 * (totalWeight * 4.44822)) / (density * wingArea * liftCoefficient)); // Calculate stall speed using the lift equation, converting weight from pounds to Newtons
    return stallSpeed * 1.94384; // Convert the stall speed from meters per second to knots and return it
}

// Function to calculate the rotation speed factor which adjusts the base takeoff speed based on safety margins for aircraft weight and altitude conditions.
double rotationSpeedFactor(double totalWeight, double elevationFeet) {
    double factor = 1.15; // Start with a base factor for rotation speed
    if (totalWeight > 500000) { // Check if the weight is over 500,000 pounds
        factor += 0.05; // Increase the factor by 0.05 for heavy aircraft
    }
    if (elevationFeet > 5000) { // Check if the elevation is over 5,000 feet
        factor += 0.05; // Increase the factor by 0.05 for high-altitude airfields
    }
    return factor; // Return the calculated factor
}

// Function to calculate the takeoff speed (V_R), which is the speed at which the aircraft should start to rotate for takeoff.
double takeoffSpeed(double stallSpeed, double rotationFactor) {
    return stallSpeed * rotationFactor; // Multiply the stall speed by the rotation speed factor to get the takeoff speed and return it
}

