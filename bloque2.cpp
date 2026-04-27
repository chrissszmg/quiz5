/*BLOQUE 2 HERENCIA -- Guerrero y Mago heredan de Personaje*/
//Clase Guerrero -- completa los huecos:

class Guerrero : public Personaje { // hereda de Personaje
public:
     

Guerrero(string nombre, int vida, int nivel,
string arma, int fuerza)
: Personaje(nombre, vida, nivel), // inicializa la parte Personaje primero
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
// Linea con ___ Que debes escribir ahi
 // Personaje(_,_,_) los tres argumentos del padre en orden: nombre, vida, nivel
 // arma_(___) el parametro 'arma' del constructor de Guerrero
 // fuerza_(___) el parametro 'fuerza'
// cout << ___ el atributo arma_ (es private de Guerrero, accesible aqui)
// cout << ___ el atributo fuerza_
// Clase Mago -- aplica el mismo patron:
class Mago : public Personaje {
public:
Mago(string nombre, int vida, int nivel,
string escuela, int mana)
: Personaje(nombre, vida, nivel), // inicializa la parte Personaje
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

int main() {
Guerrero g("Thorin", 100, 5, "Hacha de Guerra", 42);
g.mostrar(); // HEREDADO de Personaje -- no lo escribiste en Guerrero
g.info_guerrero(); // PROPIO de Guerrero
cout << endl;
Mago m("Elara", 75, 7, "Fuego", 120);
m.mostrar(); // HEREDADO de Personaje   
m.info_mago(); // PROPIO de Mago

Guerrero a("Ragnar", 120, 8, "Espada Runa", 58);
a.mostrar(); 
a.info_guerrero();

Mago n("Seraphina", 60, 9, "Hielo", 200);
n.mostrar();  
n.info_mago(); 
return 0;
}
