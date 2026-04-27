//Completa los huecos ___ (en morado) -- luego ejecuta: 
#include <iostream>
#include <string>
using namespace std;
class Personaje {
public:
// Constructor con lista de inicializacion
Personaje(string nombre, int vida, int nivel)
: nombre_(nombre), // asigna el parametro 'nombre' al atributo nombre_
vida_(vida),
nivel_(nivel) {}
void mostrar() const { // const: este metodo no modifica el objeto
cout << "[" << nivel_ << "] " << nombre_
<< " HP: " << vida_ << endl;
}
// Getters: acceso de lectura a atributos protegidos
string getNombre() const { return nombre_; }
int getVida() const { return vida_; }
int getNivel() const { return nivel_; }
virtual void atacar() const {
cout << nombre_ << " ataca de forma basica." << endl;
}

~Personaje() {}
protected: // accesible desde esta clase Y desde sus clases hijas (Bloque 2)
string nombre_;
int vida_;
int nivel_;
}; // <-- punto y coma obligatorio
//Linea con ___ Que debes escribir ahi
//nombre_(___) el parametro 'nombre' que llega al constructor
//vida_(___) el parametro 'vida'
//nivel_(___) el parametro 'nivel'
//[i] Por que protected: y no private:
//Si los atributos estuvieran en private:, las clases hijas (Guerrero, Mago)
//no podrian leer nombre_, vida_ ni nivel_ directamente.
//Con protected: son privados para el exterior pero accesibles para las subclases.
//Veras esto en el Bloque 3 cuando Guerrero use nombre_ dentro de atacar().
int main() {
Personaje p("Thorin", 100, 5);
p.mostrar();
Personaje a("Elara", 85, 3);
a.mostrar();
return 0;
}
