#include <iostream>
#include <chrono>
#include <sstream>
#include <string>

using namespace std;

// Function to calculate the birthdate for a 4-year-old hyena born in the spring
string calculateHyenaBirthdate(string description, string birthSeason) {

    // Parse the birth season and create a date for March 21 of the current year
    chrono::system_clock::time_point today = chrono::system_clock::now();
    time_t now_c = chrono::system_clock::to_time_t(today);
    tm now_tm = *localtime(&now_c);

    int birthMonth = 3;  // March
    int birthDay = 21;

    // Check if the description contains the word "female" to determine the gender
    bool isFemale = (description.find("female") != string::npos);

    // Calculate the birth year based on the age (4 years old)
    int birthYear = now_tm.tm_year + 1900 - 4;

    // Create a string to represent the birthdate
    ostringstream oss;
    oss << "The " << (isFemale ? "female " : "") << "hyena born in " << birthSeason << " has a birthdate of "
        << birthMonth << "/" << birthDay << "/" << birthYear;

    return oss.str();
}

int main() {
    string description = "4 year old female hyena";
    string birthSeason = "born in spring";

    string birthdate = calculateHyenaBirthdate(description, birthSeason);
    cout << "4 year old hyena's birthdate is: " << birthdate << endl;


    return 0;
}
