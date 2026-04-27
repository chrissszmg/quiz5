
 //BLOQUE 3 FUNCIONES VIRTUALES -- virtual y override

#include <iostream> 
using namespace std;
// Paso 1. Localiza class Personaje en rpg.cpp. Agrega la funcion virtual atacar() dentro de public:, justo antes
// del destructor ~Personaje():
// Agrega en class Personaje, seccion public:, antes de ~Personaje()
//virtual void atacar() const {
//cout << nombre_ << " ataca de forma basica." << endl;
//}

class Personaje {
public:
Personaje(string nombre, int vida, int nivel)
: nombre_(nombre), 
vida_(vida),
nivel_(nivel) {}
void mostrar() const { 
cout << "[" << nivel_ << "] " << nombre_
<< " HP: " << vida_ << endl;
}

string getNombre() const { return nombre_; }
int getVida() const { return vida_; }
int getNivel() const { return nivel_; }
virtual void atacar() const {
cout << nombre_ << " ataca de forma basica." << endl;
}
//Funcion virtual atacar() agregada dentro del public de Personaje
virtual void atacar() const {
cout << nombre_ << " ataca de forma basica." << endl;
}virtual ~Personaje() {}
protected:
string nombre_;
int vida_;
int nivel_;
};

//Paso 2. Localiza class Guerrero. Agrega el override de atacar() dentro de public:, despues del constructor:
// Agrega en class Guerrero, seccion public:
//void atacar() const override {
//cout << nombre_ << " golpea con " << ___ << endl;
//cout << " Dano fisico: " << ___ * 2 << endl;
//}

class Guerrero : public Personaje { // hereda de Personaje
public:
//Override de atacar() agregado dentro del public de Guerrero
    void atacar() const override {
cout << nombre_ << " golpea con " << arma_ << endl;
cout << " Dano fisico: " << fuerza_ * 2 << endl;
}


Guerrero(string nombre, int vida, int nivel,
string arma, int fuerza)
: Personaje(nombre, vida, nivel), 
arma_(arma),
fuerza_(fuerza) {}

void info_guerrero() const {
cout << " Arma : " << arma_ << endl;
cout << " Fuerza: " << fuerza_ << endl;
}
private:
string arma_;
int fuerza_;
};

//paso 3 compilacion 
int main() {
Personaje p("Aldeano", 30, 1);
Guerrero g("Thorin", 100, 5, "Hacha de Guerra", 42);
p.atacar(); // version base del padre
g.atacar(); // override de Guerrero
return 0;

//Paso 3b
class Mago : public Personaje {
public:
    Mago(string nombre, int vida, int nivel,
         string escuela, int mana)
        : Personaje(nombre, vida, nivel),
          escuela_(escuela), mana_(mana) {}

    //  Método atacar separado correctamente
    void atacar() const override {
        cout << nombre_ << " lanza un hechizo de " << escuela_ << endl;
        cout << "Dano magico: " << mana_ / 2 << endl;
    }
};

//Paso 4 (Compilacion final correcta)
