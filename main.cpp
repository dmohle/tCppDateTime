#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

int main() {
    // Create a time_point for "2019-03-21" 00:00:00
    tm dateInfo = {};
    dateInfo.tm_year = 2019 - 1900; // Years since 1900
    dateInfo.tm_mon = 3 - 1;        // Months are zero-based
    dateInfo.tm_mday = 21;
    time_t time = mktime(&dateInfo);
    chrono::system_clock::time_point timePoint2019 = chrono::system_clock::from_time_t(time);

    // Get the current time
    chrono::system_clock::time_point now = chrono::system_clock::now();

    // Calculate the time difference
    chrono::duration<double> timeDifference = now - timePoint2019;

    // Calculate age in decimal years
    double hoursOld = timeDifference.count() / 3600; // Convert timeDifference to hours
    double exactAge = hoursOld / 24 / 365; // Convert hours to years

    // Output the exact age
    cout << "Exact age in years: " << exactAge << endl;

    return 0;
}
