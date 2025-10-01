#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;    

class Circle {
private:
    double radius;

public:
    Circle() : radius(0) {}
    Circle(double r) : radius(r) {}

    double getRadius() const { 
        return radius; }

    double length() const { 
        return 2 * M_PI * radius; }

    bool operator==(const Circle& other) const {
        return radius == other.radius;
    }

    bool operator>(const Circle& other) const {
        return this->length() > other.length();
    }

    Circle& operator+=(double value) {
        radius += value;
        if (radius < 0) radius = 0;
        return *this;
    }

    Circle& operator-=(double value) {
        radius -= value;
        if (radius < 0) radius = 0;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Circle& c) {
        os << "Radius = " << c.radius << ", Length = " << c.length();
        return os;
    }
};

int main() {
	
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    
    Circle c1(10), c2(5);

    cout << "Circle 1: " << c1 << endl;
    cout << "Circle 2: " << c2 << endl;

    if (c1 == c2) cout << "Радіуси рівні\n";
    else cout << "Радіуси різні\n";

    if (c1 > c2) cout << "Довжина першого кола більша\n";
    else cout << "Довжина першого кола не більша\n";

    c1 += 3;
    cout << "\nПісля c1 += 3: " << c1 << endl;

    c2 -= 4;
    cout << "Після c2 -= 4: " << c2 << endl;

}
