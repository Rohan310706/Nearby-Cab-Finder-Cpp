#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "json.hpp" 

using namespace std;
using json = nlohmann::json;

#define EARTH_RADIUS 6371.0

class Location {
public:
    double latitude;
    double longitude;

    Location(double lat, double lon) : latitude(lat), longitude(lon) {}
};

class Cab {
public:
    Location location;
    double distanceFromUser;

    Cab(double lat, double lon) : location(lat, lon), distanceFromUser(0.0) {}

    void calculateDistance(const Location& userLocation) {
        double lat1 = userLocation.latitude * M_PI / 180.0;
        double lon1 = userLocation.longitude * M_PI / 180.0;
        double lat2 = location.latitude * M_PI / 180.0;
        double lon2 = location.longitude * M_PI / 180.0;

        double dlat = lat2 - lat1;
        double dlon = lon2 - lon1;

        double a = pow(sin(dlat / 2), 2) +
                   cos(lat1) * cos(lat2) * pow(sin(dlon / 2), 2);
        double c = 2 * atan2(sqrt(a), sqrt(1 - a));

        distanceFromUser = EARTH_RADIUS * c;
    }
};

int main() {
    double userLat, userLon;
    cout << "Enter your location (latitude and longitude): ";
    cin >> userLat >> userLon;
    Location userLocation(userLat, userLon);

    // Load JSON file
    ifstream inputFile("cab_data.json");
    json cabJson;
    inputFile >> cabJson;

    vector<Cab> cabs;
    for (const auto& cab : cabJson) {
        double lat = cab["latitude"];
        double lon = cab["longitude"];
        cabs.emplace_back(lat, lon);
    }

    for (auto& cab : cabs) {
        cab.calculateDistance(userLocation);
    }

    sort(cabs.begin(), cabs.end(), [](const Cab& a, const Cab& b) {
        return a.distanceFromUser < b.distanceFromUser;
    });

    cout << "\nNearby Cabs (sorted by distance):\n";
    for (const auto& cab : cabs) {
        cout << "Cab at (" << cab.location.latitude << ", " << cab.location.longitude
             << ") - Distance: " << cab.distanceFromUser << " km" << endl;
    }

    return 0;
}
