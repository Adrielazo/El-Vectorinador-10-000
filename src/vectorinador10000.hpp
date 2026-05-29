#ifndef VECTORINADOR10000_HPP
#define VECTORINADOR10000_HPP
#include <iostream>
#include <cmath>
#include <vector>

class Vector{
    private:
        float X,Y,Z;
    public:
        Vector(float X = 0.0, float Y = 0.0, float Z = 0.0 );
        
        Vector operator+(const Vector& v) const;
        Vector operator-(const Vector& v) const;
        
        float productopunto(const Vector& v) const;
        float modulo() const;
        Vector productocruz(const Vector& v) const;
        void imprimir_vector() const;
        void modificar_vector(float nuevoX, float nuevoY, float nuevoZ);

};
#endif 
