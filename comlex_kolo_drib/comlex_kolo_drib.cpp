#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    double dijsna;
    double ujava;

public:
    Complex() : dijsna(0), ujava(0) {}
    Complex(double r) : dijsna(r), ujava(0) {}
    Complex(double r, double i) : dijsna(r), ujava(i) {}

    Complex operator+(const Complex& b) const {
        return Complex(dijsna + b.dijsna, ujava + b.ujava);
    }

    Complex operator-(const Complex& b) const {
        return Complex(dijsna - b.dijsna, ujava - b.ujava);
    }

    friend Complex operator*(const Complex& a, const Complex& b) {
        return Complex(a.dijsna * b.dijsna - a.ujava * b.ujava,
            a.dijsna * b.ujava + a.ujava * b.dijsna);
    }

    bool operator==(const Complex& b) const {
        return (dijsna == b.dijsna) && (ujava == b.ujava);
    }

    bool operator!=(const Complex& b) const {
        return !(*this == b);
    }

    bool operator!() const {
        return (dijsna == 0) && (ujava == 0);
    }

    double operator()() const {
        return sqrt(dijsna * dijsna + ujava * ujava);
    }

    friend ostream& operator<<(ostream& os, const Complex& c) {
        if (c.ujava >= 0)
            os << c.dijsna << " + " << c.ujava << "i";
        else
            os << c.dijsna << " - " << -c.ujava << "i";
        return os;
    }

    friend istream& operator>>(istream& is, Complex& c) {
        is >> c.dijsna >> c.ujava;
        return is;
    }
};
int main() {
    Complex a, b;

    cout << "Enter the first complex number (real imaginary): ";
    cin >> a;

    cout << "Enter the second complex number (real imaginary): ";
    cin >> b;

    cout << "\nFirst complex number: " << a;
    cout << "\nSecond complex number: " << b;

    cout << "\n\nSum: " << a + b;
    cout << "\nDifference: " << a - b;

    cout << "\n\nChecking for equality: ";
    if (a == b) cout << "a == b";
    else cout << "a != b";

    cout << "\n\nModule of the first: " << a();
    cout << "\nModule of the second: " << b();

    cout << endl;
}
