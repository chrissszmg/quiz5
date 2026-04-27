//BLOQUE 4 POLIMORFISMO -- vector<Personaje*>, motor arranca todos
//Paso 1. Convierte el destructor de Personaje en virtual. Localiza '~Personaje() {}' en la clase y agrega
//'virtual':
// En class Personaje, reemplaza el destructor por:
//virtual ~Personaje() {}
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
//Funcion virtual atacar() agregada dentro del public de Personaje (BLOQUE 3)
virtual void atacar() const {
cout << nombre_ << " ataca de forma basica." << endl;

//Convierte el destructor de Personaje en virtual.

}virtual ~Personaje() {}
protected: 
string nombre_;
int vida_;
int nivel_;
};



//Paso 2. Entiende por que NO puedes guardar objetos por valor en el vector. Lee este ejemplo y el problema
//que causa:
// MAL: object slicing -- al copiar Guerrero dentro de Personaje,
// C++ recorta los atributos propios (arma_, fuerza_) y el override.
//vector<Personaje> v;
//v.push_back(Guerrero("Thorin", 100, 5, "Hacha", 42));
//v[0].atacar(); // llama a Personaje::atacar() -- no al de Guerrero


// BIEN: puntero apunta al objeto completo en memoria -- sin recorte.
//vector<Personaje*> v;
//v.push_back(new Guerrero("Thorin", 100, 5, "Hacha", 42));
//v[0]->atacar(); // dispatch virtual correcto: llama a Guerrero::atacar()


//Paso 3. Agrega '#include <vector>' al inicio del archivo junto a los otros includes. Luego reemplaza el
//main() con el motor completo -- completa los ___ con los cuatro objetos de la partida:
//bloque 4
vector<Personaje*> partida;
partida.push_back(new Personaje("Aldeano", 30, 1)); // Personaje: "Aldeano", 30, 1
partida.push_back(new Guerrero("Thorin", 100, 5, "Hacha de Guerra", 42)); // Guerrero: "Thorin", 100, 5, "Hacha de Guerra", 42
partida.push_back(new Mago("Elara", 75, 7, "Fuego", 120)); // Mago: "Elara", 75, 7, "Fuego", 120
partida.push_back(new Guerrero("Ragnar", 120, 8, "Espada Runa", 58)); // Guerrero: "Ragnar", 120, 8, "Espada Runa", 58
cout << "=== RONDA DE COMBATE ===" << endl;
for (Personaje* p : partida) {
p->mostrar(); 
p->atacar(); 
cout << endl;
}

for (Personaje* p : partida) delete p;
