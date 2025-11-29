#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


// Ejercicio 3.2: Clase Base Cuenta
class Cuenta {
protected:
    string numeroCuenta, propietario;
    double saldo;

public:
    Cuenta(string num, string prop, double s) : numeroCuenta(num), propietario(prop), saldo(s >= 0 ? s : 0) {}
    virtual void depositar(double monto) { if (monto > 0) saldo += monto; }
    virtual void retirar(double monto) { if (monto > 0 && monto <= saldo) saldo -= monto; }
    virtual void mostrarInfo() const {
        cout << " Cuenta " << numeroCuenta << " | Propietario: " << propietario << " | Saldo: $" << fixed << setprecision(2) << saldo << "\n";
    }
    virtual ~Cuenta() = default;
};

// Ejercicio 3.2: Clase CuentaAhorro
class CuentaAhorro : public Cuenta {
private:
    double tasaInteres;
public:
    CuentaAhorro(string num, string prop, double s, double tasa)
        : Cuenta(num, prop, s), tasaInteres(tasa) {}

    double getTasaInteres() const { return tasaInteres; }

    void generarInteres() {
        double interes = saldo * tasaInteres;
        saldo += interes;
        cout << " Interes (" << tasaInteres * 100 << "%) generado: $" << fixed << setprecision(2) << interes
             << " | Nuevo Saldo: $" << fixed << setprecision(2) << saldo << "\n";
    }

    void mostrarInfo() const override {
        cout << " CTA AHORRO: " << numeroCuenta << " | Propietario: " << propietario << " | Saldo: $" << fixed << setprecision(2) << saldo
             << " | Tasa: " << tasaInteres * 100 << "%\n";
    }
};

// Ejercicio 3.2: Clase CuentaCorriente
class CuentaCorriente : public Cuenta {
private:
    double limiteDescubierto;
public:
    CuentaCorriente(string num, string prop, double s, double limite) : Cuenta(num, prop, s), limiteDescubierto(limite >= 0 ? limite : 0) {}

    void solicitarDescubierto(double monto) {
        if (monto > 0 && monto <= limiteDescubierto) cout << " Solicitud de descubierto de $" << monto << " aprobada.\n";
        else cout << "Solicitud rechazada\n";
    }

    void retirar(double monto) override {
        if (monto > 0 && monto <= (saldo + limiteDescubierto)) {
            saldo -= monto;
            cout << " Retiro de $" << monto << " realizado.\n";
        } else {
            cout << " Retiro rechazado: excede saldo +descubierto.\n";
        }
    }
};

int main() {


    cout << "\n[3.2] PRUEBA DE CUENTA BANCARIA\n";
    cout<<endl;

    CuentaAhorro ahorros("123456", "Carlos Ahorrador", 5000, 0.02);
    ahorros.mostrarInfo();
    ahorros.depositar(1000);
    ahorros.mostrarInfo();
    ahorros.generarInteres();
    ahorros.mostrarInfo();

    CuentaCorriente cta("CTA-99", "Juan Perez", 1000, 200);
    cta.mostrarInfo();
    cta.solicitarDescubierto(100);
    cta.retirar(1150);
    cta.mostrarInfo();

    return 0;
}
