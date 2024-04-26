#pragma once
#include <string>
#include <iostream>

using namespace std;

struct Flight {
        string departureAirport;
        string arrivalAirport;
        int departureHour;
        int departureMinute;
        Flight* left;
        Flight* right;

        Flight(string departureAirport, string arrivalAirport, int departureHour, int departureMinute) {
            this->departureAirport = departureAirport;
            this->arrivalAirport = arrivalAirport;
            this->departureHour = departureHour;
            this->departureMinute = departureMinute;
            this->left = nullptr;
            this->right = nullptr;
            cout << departureAirport << " " << arrivalAirport << endl;
        }
    };