#include <iostream>  // Include the standard I/O stream library for input and output operations
#include "calculate.h"  // Include the custom header file that declares functions related to aircraft performance calculations
#include "userinput.h"  // Include the custom header file that declares functions for getting user inputs

int main() {
    // Display the title and a brief description of the program to the user
    std::cout << "C-17 Globemaster III Takeoff Speed Calculator\n\n";
    std::cout << "Aircraft assumed to be in takeoff configuration (flaps 1/2, slats extended).\n\n";

    // Gather inputs for fuel, passengers, and cargo weights from the user
    double fuel = getFuel();  // Call the getFuel function to ask the user to enter the fuel load in pounds
    double paxWeight = getPax();  // Call the getPax function to ask the user to enter the number of passengers and calculate their total weight
    double cargo = getCargo();  // Call the getCargo function to ask the user to enter the cargo weight in pounds

    // Request the user to enter the field elevation in feet and store it
    std::cout << "Enter Field Elevation (ft): ";
    double elevationFeet;
    std::cin >> elevationFeet;

    // Calculate the air density based on the provided field elevation
    double density = getDensity(elevationFeet);  // Call the getDensity function, which calculates air density based on the elevation and other environmental factors

    // Perform calculations to determine the aircraft's takeoff performance
    double totalWeight = getTotalWeight(fuel, paxWeight, cargo);  // Calculate the total weight of the aircraft by summing the base weight, fuel, passengers, and cargo
    double stallSpeed = getStallSpeed(totalWeight, density);  // Calculate the stall speed based on the total weight and air density
    double factor = rotationSpeedFactor(totalWeight, elevationFeet);  // Calculate the rotation speed factor, which adjusts the stall speed based on aircraft weight and altitude
    double V_R = takeoffSpeed(stallSpeed, factor);  // Calculate the takeoff speed by applying the rotation speed factor to the stall speed

    // Output the results to the user
    std::cout << "Rotation Speed (V_R): " << V_R << " kts\n\n";  // Display the calculated rotation speed in knots
    std::cout << "Note: For educational and simulation purposes only!\n";  

    return 0;  // End of the program
}
