#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Tarea {
public:
    string titulo;
    string fechaLimite;
    Tarea(string t, string f) : titulo(t), fechaLimite(f) {}

    virtual void mostrarDetalles() {
        cout << "Tarea: " << titulo << " (Vence: " << fechaLimite << ")" << endl;
    }
    virtual ~Tarea() {}
};

class TareaUrgente : public Tarea {
public:
    TareaUrgente(string t, string f) : Tarea(t, f) {}
    void mostrarDetalles() override {
        cout << "!!! URGENTE !!! " << titulo << " - Prioridad Maxima." << endl;
    }
};

class IRepository {
public:
    virtual void guardar(const vector<Tarea*>& tareas) = 0;
    virtual ~IRepository() {}
};

class DatabaseRepository : public IRepository {
public:
    void guardar(const vector<Tarea*>& tareas) override {
        cout << "Accion: Guardando tareas en Base de Datos..." << endl;
        for (auto t : tareas) t->mostrarDetalles();
    }
};

class GestorTareas {
private:
    vector<Tarea*> lista; 
public:
    void agregarTarea(Tarea* t) {
        lista.push_back(t);
    }

    void procesarGuardado(IRepository* repo) {
        repo->guardar(lista);
    }
};

int main() {
    GestorTareas miGestor;
    Tarea* t1 = new Tarea("Hacer informe", "2026-03-28");
    Tarea* t2 = new TareaUrgente("Examen de Programacion", "2026-03-27");

    miGestor.agregarTarea(t1);
    miGestor.agregarTarea(t2);

    IRepository* miRepo = new DatabaseRepository();
    miGestor.procesarGuardado(miRepo);

    delete t1; delete t2; delete miRepo;
    return 0;
}