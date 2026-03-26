#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Tarea {
public:
    string titulo;
    string fechaLimite;
    bool estaCompletada;
    Tarea(string t, string f) {
        titulo = t;
        fechaLimite = f;
        estaCompletada = false;
    }
};

class GestorTareas {
private:
    vector<Tarea> lista;
public:
    void agregarTarea(Tarea t) {
        lista.push_back(t);
        cout << "Tarea '" << t.titulo << "' agregada." << endl;
    }
};

class TareaRepository {
public:
    void guardarEnArchivo(const vector<Tarea>& tareas) {
        cout << "Guardando tareas en la base de datos..." << endl;
    }
};

int main() {
    Tarea nuevaTarea("Terminar Practica 03", "2026-03-30");
    GestorTareas miGestor;
    
    miGestor.agregarTarea(nuevaTarea);
    
    return 0;
}