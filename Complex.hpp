// Email - michibinyamin@gmail.com
// Id - 208768978

#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <cmath>

class Complex {
private:
    double realPart;
    double imagPart;

public:
    Complex(double real = 0.0, double imag = 0.0) : realPart(real), imagPart(imag) {}

    double getReal() const { // Retrieve the real component
        return realPart;
    }

    double getImag() const { // Retrieve the imaginary component
        return imagPart;
    }

    void setReal(double real) { // Assign a value to the real component
        realPart = real;
    }

    void setImag(double imag) { // Assign a value to the imaginary component
        imagPart = imag;
    }

    double magnitude() const { // Calculate the magnitude of the complex number
        return std::sqrt(realPart * realPart + imagPart * imagPart);
    }

    bool operator<(const Complex& other) const { // Compare magnitudes of two complex numbers
        return magnitude() < other.magnitude();
    }

    bool operator==(const Complex& other) const { // Check equality of two complex numbers
        return realPart == other.realPart && imagPart == other.imagPart;
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& c) { // Stream insertion for complex number
        os << c.realPart << " + " << c.imagPart << "i";
        return os;
    }
};

#endif // COMPLEX_HPP
