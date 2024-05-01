/* Programmer:Muhammad Abser Mansoor
 * Date: 28/03/2024
 * Descrption: Security System
 */

#include <iostream>
#include <string>
#include <cmath>

class Drone {

    public:

    float latitude,longitude,altitude,speed;

    Drone(float lat, float lon, float alt, float speed) : latitude(lat) , longitude(lon) , altitude(alt) , speed(speed) {}

    virtual void adjustAltitude(float meters) { altitude = meters; }
    virtual void setSpeed(float speed) { this->speed = speed; }

};

class Flyable {

    public:

    virtual void takeoff() = 0;
    virtual void land() = 0;
    virtual void navigateTo(float lat, float lon, float alt) = 0;
};

class Scannable {

    public:

    virtual void scanArea(float radius) = 0;
};

class ReconDrone : public Drone, public Flyable, public Scannable {

    float cameraResolution;
    float maxFlightTime;

    public:

    ReconDrone(float lat, float lon, float alt, float speed, float res, float max) : Drone(lat,lon,alt,speed) , cameraResolution(res) , maxFlightTime(max) {}

    void takeoff() override {

        if (altitude = 0) {
            altitude += 10;
        }
    }

    void land() override {
        altitude = 0;
    }

    void navigateTo(float lat, float lon, float alt) override {

        std::cout << "Time Taken = " << calculateDistance(lat,lon,alt,latitude,longitude,altitude)/speed << "s" << std::endl;
    }

    // Helper function for calculating distance using haversine formula
    float calculateDistance(float lat1, float lon1, float alt1, float lat2, float lon2, float alt2) {

        float earthRadius = 6371000.0; // Radius of Earth in meters
        float dLat = (lat2 - lat1) * 3.142 / 180.0;
        float dLon = (lon2 - lon1) * 3.142 / 180.0;
        float a = sin(dLat / 2) * sin(dLat / 2) +
                  cos(lat1 * 3.142 / 180.0) * cos(lat2 * 3.142 / 180.0) *
                  sin(dLon / 2) * sin(dLon / 2);
        float c = 2 * atan2(sqrt(a), sqrt(1 - a));
        float distance = earthRadius * c;

        // Calculate 3D distance considering altitude
        float altitudeDiff = fabs(alt2 - alt1);
        distance = sqrt(distance * distance + altitudeDiff * altitudeDiff);

        return distance;
    }

    void scanArea(float radius) override {

        // There are no specific objects to find in the question therefore the objects and their locations are randomised for the sake of simulation
        int numObjectsDetected = rand() % 10;
        std::cout << "Number of objects detected: " << numObjectsDetected << std::endl;
        std::cout << "Coordinates of detected objects:" << std::endl;

        for (int i = 0; i < numObjectsDetected; ++i) {

            float objLatitude = latitude + (rand() % (int)radius) - (radius / 2.0f);
            float objLongitude = longitude + (rand() % (int)radius) - (radius / 2.0f);
            std::cout << "Object " << i + 1 << ": Latitude=" << objLatitude << ", Longitude=" << objLongitude << std::endl;
        }
    }
};

int main() {
    srand(time(NULL));
    try {

        ReconDrone drone(40.7128, -74.0060, 100, 30, 12, 8);
        drone.navigateTo(40.730610, -73.935242, 150);
        drone.scanArea(500);

    } catch (const std::exception& e) {
        std::cerr << "Exception occurred: " << e.what() << std::endl;
    }

    return 0;
}
