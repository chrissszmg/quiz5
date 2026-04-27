//Enunciado: Crea la clase Arquero : public Personaje. Atributos propios: arco (string) y precision (int,
//0-100). Override de atacar(): muestra '[nombre] dispara con [arco]' y 'Precision: [precision]% Dano:
//[precision * 3]'. Agrega dos Arqueros al vector partida del Bloque 4 y ejecuta la ronda de combate. Los
//Arqueros deben aparecer en el bucle for sin modificarlo. Recuerda agregar 'delete' para cada new
//Arquero.

//1. Clase Arquero
class Arquero : public Personaje {
public:
    Arquero(string nombre, int vida, int nivel,
            string arco, int precision)
        : Personaje(nombre, vida, nivel),
          arco_(arco), precision_(precision) {}

    void atacar() const override {
        cout << nombre_ << " dispara con " << arco_ << endl;
        cout << "Precision: " << precision_
             << "% Dano: " << precision_ * 3 << endl;
    }

private:
    string arco_;
    int precision_;
};

//2. Agregar Arqueros al vector partida
partida.push_back(new Arquero("Legolas", 90, 6, "Arco Largo", 85));
partida.push_back(new Arquero("Sylvan", 80, 5, "Arco Corto", 70));


//3. Liberar memoria
for (int i = 0; i < partida.size(); i++) {
    delete partida[i];
}