#include "vectorinador10000.hpp"
Vector::Vector(float X, float Y, float Z) : X(X), Y(Y), Z(Z) {}

Vector Vector::operator+(const Vector& v) const {
    return Vector(this->X + v.X, this->Y + v.Y, this->Z + v.Z);
}

Vector Vector::operator-(const Vector& v) const {
    return Vector(this->X - v.X, this->Y - v.Y, this->Z - v.Z);
}

Vector Vector::productocruz(const Vector& v) const{
    float cruzX = (this->Y * v.Z) - (this->Z * v.Y);
    float cruzY = (this->Z * v.X) - (this->X * v.Z);
    float cruzZ = (this->X * v.Y) - (this->Y * v.X);
    return Vector(cruzX, cruzY, cruzZ);
}

float Vector::productopunto(const Vector& v) const {
    return (this->X * v.X) + (this->Y * v.Y) + (this->Z * v.Z);
}

float Vector::modulo() const {
    return std::sqrt((X * X) + (Y * Y) + (Z * Z));
}

void Vector::imprimir_vector() const {
    std::cout << "Vector: (" << X << ", " << Y << ", " << Z << ")" << std::endl;
}

void Vector::modificar_vector(float nuevoX, float nuevoY, float nuevoZ) {
    X = nuevoX;
    Y = nuevoY;
    Z = nuevoZ;
}
