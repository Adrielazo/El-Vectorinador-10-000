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

Vector Vector::mult_escalar(float escalar) const {
    return Vector(this->X * escalar, this->Y *escalar, this->Z * escalar);
}

Vector Vector::unitario() const {
    float mod = this->modulo();
    if (mod == 0) {
        std::cerr << "Error: No se puede calcular el vector unitario de un vector nulo.\n";
        return Vector(0, 0, 0);
    }
    return Vector(this->X / mod, this->Y / mod, this->Z / mod);    
}

float Vector::angulo_entre(const Vector& v) const {
    float punto = this->productopunto(v);
    float mod1= this->modulo();
    float mod2 = v.modulo();
    if (mod1 == 0 || mod2 == 0) {
        std::cerr << "Error: No se puede calcular el ángulo entre un vector nulo.\n";
        return 0.0;
    }
    float cos_angulo = punto / (mod1 * mod2);
    return std::acos(cos_angulo)*(180.0/M_PI);
}
