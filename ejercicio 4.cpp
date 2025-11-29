#include <iostream>
#include <string>
#include <vector> // Para vector<Curso>
#include <iomanip> // Para setprecision y fixed

using namespace std;

// Ejercicio 4.1: CLASE CURSO
class Curso {
private:
    string codigo, nombre, profesor;
    int creditos;
public:
    Curso(string cod, string n, int cred, string prof)
        : codigo(cod), nombre(n), creditos(cred), profesor(prof) {}

    string getNombre() const { return nombre; }
    void mostrarInfo() const { cout << " |_| - " << nombre << " (" << codigo << ")\n"; }
};

// Ejercicio 4.1: Clase Base Persona
class Persona {
protected:
    string nombre, cedula;
    int edad;
public:
    Persona(string n, int e, string c) : nombre(n), edad(e), cedula(c) {}
    virtual ~Persona() = default;
    virtual void mostrarInfo() const {
        cout << "  Nombre: " << nombre << ", Edad: " << edad << ", Cedula: " << cedula << "\n";
    }
};

// Ejercicio 4.1: Clase Estudiante
class Estudiante : public Persona {
private:
    string carrera;
    double promedio;
    int semestre;
    vector<Curso> cursos;
public:
    Estudiante(string n, int e, string c, string car, double prom, int sem) : Persona(n, e, c), carrera(car), promedio(prom), semestre(sem) {}

    void matricularCurso(const Curso& c) { cursos.push_back(c); }

    double calcularPromedioActual() const { return promedio; }

    void mostrarInfo() const override {
        cout << "\n ESTUDIANTE:\n";
        Persona::mostrarInfo();
        cout << " Carrera: " << carrera << ", Promedio: " << promedio << ", Semestre: " << semestre << "\n";
        cout << "  Cursos matriculados: " << cursos.size() << "\n";
    }
};

// Ejercicio 4.1: Clase Profesor
class Profesor : public Persona {
private:
    string especialidad;
    int aniosExperiencia;
    int numeroEstudiantes;
public:
    Profesor(string n, int e, string c, string esp, int anios, int num)  : Persona(n, e, c), especialidad(esp), aniosExperiencia(anios), numeroEstudiantes(num) {}

    // Método especial
    bool estaDisponible(int horaDelDia) const { return (horaDelDia >= 8 && horaDelDia <= 18); }

    void mostrarInfo() const override {
        cout << "\n PROFESOR:\n";
        Persona::mostrarInfo();
        cout << " Especialidad: " << especialidad << ", Experiencia: " << aniosExperiencia << " anios\n";
    }
};

// Ejercicio 4.1: Clase Personal
class Personal : public Persona {
private:
    string puesto, departamento;
    double salario;
public:
    Personal(string n, int e, string c, string p, string d, double s)
        : Persona(n, e, c), puesto(p), departamento(d), salario(s >= 0 ? s : 0) {}

    // Método especial
    double calcularSalarioMensual() const { return salario; }

    void mostrarInfo() const override {
        cout << "\nPERSONAL ADMINISTRATIVO:\n";
        Persona::mostrarInfo();
        cout << "  Puesto: " << puesto << ", Departa: " << departamento << ", Salario: $" << fixed << setprecision(2) << salario << "\n";
    }
};

int main() {
    cout << "=== NIVEL 4: SISTEMA UNIVERSITARIO COMPLETO ===\n";

    Estudiante est("Maria", 20, "1234", "Sistemas", 4.5, 3);
    Curso poo("POO101", "POO Avanzada", 4, "Dr. Strange");
    est.matricularCurso(poo);
    est.mostrarInfo();
    poo.mostrarInfo();

    Profesor prof("Dr. Strange", 45, "DOC-1", "Magia", 15, 50);
    prof.mostrarInfo();
    cout << " ¿Disponible a las 10:00? " << (prof.estaDisponible(10) ? "Si" : "No") << "\n";

    Personal admin("Luis Jefe", 30, "ADM-001", "Secretario", "Finanzas", 1500.00);
    admin.mostrarInfo();
    cout << " Salario Mensual: $" << admin.calcularSalarioMensual() << "\n";

    return 0;
}
