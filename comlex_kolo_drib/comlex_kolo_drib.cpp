#include <iostream>
using namespace std;

class Drib {
private:
    int s1;
    int s2;

    void q() {
        int d = gcd(abs(s1), abs(s2));
        s1 /= d;
        s2 /= d;
        if (s2 < 0) {
            s1 = -s1;
            s2 = -s2;
        }
    }

    int gcd(int a, int b) const {
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

public:
    Drib(int num = 0, int den = 1) {
        s1 = num;
        s2 = (den == 0) ? 1 : den;
        q();
    }

    void input() {
        cout << "Enter numerator: ";
        cin >> s1;
        cout << "Enter denominator: ";
        cin >> s2;
        if (s2 == 0) {
            cout << "Denominator cannot be 0! Setting to 1.\n";
            s2 = 1;
        }
        q();
    }

    void dis() const {
        cout << s1 << "/" << s2;
    }

    Drib operator+(const Drib& other) const {
        return Drib(s1 * other.s2 + other.s1 * s2, s2 * other.s2);
    }

    Drib operator-(const Drib& other) const {
        return Drib(s1 * other.s2 - other.s1 * s2, s2 * other.s2);
    }

    Drib operator*(const Drib& other) const {
        return Drib(s1 * other.s1, s2 * other.s2);
    }

    Drib operator/(const Drib& other) const {
        return Drib(s1 * other.s2, s2 * other.s1);
    }
};

int main() {
    Drib f1, f2;
    cout << "Enter first fraction:\n";
    f1.input();
    cout << "Enter second fraction:\n";
    f2.input();

    cout << "\nSum: ";
    (f1 + f2).dis();

    cout << "\nDifference: ";
    (f1 - f2).dis();

    cout << "\nProduct: ";
    (f1 * f2).dis();

    cout << "\nDivision: ";
    (f1 / f2).dis();

    cout << endl;
}
