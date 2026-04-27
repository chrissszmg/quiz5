/*BLOQUE 0 struct vs class -- Encapsulacion*/

#include <iostream>
#include <string>
// #include <vector> Bloque 4
#include <vector>
using namespace std;
struct Espada {
string nombre; // public por defecto
int dano;
}; // <-- quita este ';' y mira el error del compilador
 
/*
int main() {
Espada e;
e.nombre = "Hacha";
e.dano = 42;
cout << e.nombre << " -- dano: " << e.dano << endl;
return 0;
}
*/

/*Al momento de quitar el ; se produce error de compilacion 
/tmp/QIBL9aBVYP/main.cpp:7:2: error: expected ';' after struct definition*/

/*BLOQUE 1 CLASE BASE -- Personaje*/
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

virtual ~Personaje() {}

protected: 
string nombre_;
int vida_;
int nivel_;
};

/*BLOQUE 2 HERENCIA -- Guerrero y Mago heredan de Personaje*/
class Guerrero : public Personaje {
public:
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

class Mago : public Personaje {
public:
void atacar() const override {
    cout << nombre_ << " lanza un hechizo de " << escuela_ << endl;
    cout << " Dano magico: " << mana_ / 2 << endl;
}
Mago(string nombre, int vida, int nivel,
string escuela, int mana)
: Personaje(nombre, vida, nivel),
escuela_(escuela),
mana_(mana) {}
void info_mago() const {
cout << " Escuela: " << escuela_ << endl;
cout << " Mana : " << mana_ << endl;
}
private:
string escuela_;
int mana_;
};

/* ===== ARQUERO (AGREGADO DEL ENUNCIADO) ===== */
class Arquero : public Personaje {
public:
Arquero(string nombre, int vida, int nivel,
string arco, int precision)
: Personaje(nombre, vida, nivel),
arco_(arco),
precision_(precision) {}

void atacar() const override {
cout << nombre_ << " dispara con " << arco_ << endl;
cout << "Precision: " << precision_ << "% Dano: " << precision_ * 3 << endl;
}

private:
string arco_;
int precision_;
};

int main() {
    //bloque 1
Personaje p("Thorin", 100, 5);
p.mostrar();
Personaje a1("Elara", 85, 3);
a1.mostrar();
//bloque 2
Guerrero g("Thorin", 100, 5, "Hacha de Guerra", 42);
g.mostrar();
g.info_guerrero();
cout << endl;
Mago m("Elara", 75, 7, "Fuego", 120);
m.mostrar();   
m.info_mago();

Guerrero a2("Ragnar", 120, 8, "Espada Runa", 58);
a2.mostrar(); 
a2.info_guerrero();

Mago n("Seraphina", 60, 9, "Hielo", 200);
n.mostrar();  
n.info_mago();

// BLOQUE 3
Personaje p2("Aldeano", 30, 1);
Guerrero g2("Thorin", 100, 5, "Hacha de Guerra", 42);
p2.atacar(); 
g2.atacar();

Mago m2("Elara", 75, 7, "Fuego", 120);
m2.atacar();

//bloque 4
vector<Personaje*> partida;
partida.push_back(new Personaje("Aldeano", 30, 1));
partida.push_back(new Guerrero("Thorin", 100, 5, "Hacha de Guerra", 42));
partida.push_back(new Mago("Elara", 75, 7, "Fuego", 120));
partida.push_back(new Guerrero("Ragnar", 120, 8, "Espada Runa", 58));

//Bloque 5 parte del enunciado solicitado
partida.push_back(new Arquero("Legolas", 90, 6, "Arco Largo", 85));
partida.push_back(new Arquero("Sylvan", 80, 5, "Arco Corto", 70));

cout << "=== RONDA DE COMBATE ===" << endl;
for (Personaje* p : partida) {
p->mostrar();
p->atacar();
cout << endl;
}

for (Personaje* p : partida) delete p;

return 0;
}
