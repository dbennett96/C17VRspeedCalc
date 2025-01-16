#pragma once

// Function declarations for calculations
double getTotalWeight(double fuel, double paxWeight, double cargo);
double getStallSpeed(double totalWeight, double density);
double rotationSpeedFactor(double totalWeight, double elevationFeet);
double takeoffSpeed(double stallSpeed, double rotationFactor);
