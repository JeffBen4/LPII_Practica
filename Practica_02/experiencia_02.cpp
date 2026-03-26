#include <iostream>
#include <string>
#include <vector>

using namespace std;
//no cambio
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
// aplicamos open/closed principle
class IRepository {
public:
    virtual void guardar(const vector<Tarea>& tareas) = 0;
    virtual ~IRepository() {}
};

class DatabaseRepository : public IRepository {
public:
    void guardar(const vector<Tarea>& tareas) override {
        cout << "Accion: Guardando en Base de Datos." << endl;
    }
};

class CloudRepository : public IRepository { // Nueva extensión
public:
    void guardar(const vector<Tarea>& tareas) override {
        cout << "Accion: Subiendo tareas a la NUBE (AWS/Google)." << endl;
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

    void procesarGuardado(IRepository* repo) {
        repo->guardar(lista);
    }
};

int main() {
    Tarea nuevaTarea("Aprender OCP", "2026-03-30");
    GestorTareas miGestor;
    miGestor.agregarTarea(nuevaTarea);

    // podemos usar el repositorio que queramos
    IRepository* miRepo = new DatabaseRepository();
    miGestor.procesarGuardado(miRepo);

    // Si yo quisiera guardar en la nube, bastaria con crear una nueva clase que implemente IRepository, sin modificar el código del GestorTareas
    IRepository* repoNube = new CloudRepository();
    miGestor.procesarGuardado(repoNube);

    delete miRepo;
    delete repoNube;
    return 0;
}