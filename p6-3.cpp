#include<iostream>
using namespace std;
class Fuel{
    protected:
    string fuelType;
public:
    Fuel() {
        fuelType = "Unknown";
    }

    Fuel(string f) {
        if (f == "petrol" || f == "diesel" || f == "electric")
            fuelType = f;
        else {
            cout << "Invalid fuel type\n";
        }
    }
};
class Brand {
protected:
    string brandName;

public:
    Brand() {
        brandName = "Unknown";
    }

    Brand(string b) {
        brandName = b;
    } 