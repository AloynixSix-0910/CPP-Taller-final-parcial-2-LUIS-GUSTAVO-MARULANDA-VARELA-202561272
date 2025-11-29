#include <iostream>
#include <string>
using namespace std;

//EJERCICIO 2,2 EMPLEADOS BASE, FULLTIME Y POR HORAS

class Empleado{

private:
    string Fullname;
    string number;
    double salarioBase;

public:
    Empleado(string n, string nu, double sal)
    :Fullname(n), number(nu),salarioBase(sal){}

//getters

    string getName()const {
        return Fullname;}

    string getNumeroEmpleado()const {
        return number;}

    double getSalarioBase()const {
        return salarioBase;}

//Setters

void setNombre(string n){
Fullname= n;
}

void setNumber(string nu){
number=nu;
}

void setSalarioBase(double sal){
if(sal>=0){
    salarioBase=sal;}

else{
    cout<<"El salario base no puede ser negativo"<<endl;
}

}

virtual double calcularSalarioTotal() const{
        return salarioBase;
    }


    virtual void mostrarInfo() const{
        cout << "======INFORMACION EMPLEADO======"<<endl;
        cout << "Nombre: " << Fullname<< endl;
        cout << "Numero: " << number<< endl;
        cout << "Salario base: $" << salarioBase<< endl;
    }

};


//herencia de empleado, empleado fulltimme

class EmpleadoFullTime: public Empleado{

private:
    string beneficio;
    double bono;

public:
    EmpleadoFullTime(string n, string nu, double sal, string ben, double bo)
    :Empleado(n, nu, sal), beneficio(ben), bono(bo){}

string getBeneficio()const {
return beneficio;}

double getBono()const {
return bono;}

void setBeneficio(string ben){
beneficio= ben;}

void setBono(double bo){
bono=bo;}

double calcularSalarioTotal() const override{
return getSalarioBase()+bono;}


void mostrarInfo() const override{


cout << "===== INFORMACION DE EMPLEADO TIEMPO COMPLETO (FULL TIME) ====="<<endl;
        cout << "Nombre: "<<getName()<<endl;
        cout << "Numero: "<<getNumeroEmpleado()<<endl;
        cout << "Salario base: $"<<getSalarioBase()<<endl;
        cout << "Beneficios: " <<beneficio<<endl;
        cout << "Bono: $"<< bono<<endl;
        cout << "Salario total: $"<<calcularSalarioTotal()<<endl;
    }

};

//herencia de empleado, empleado x horas

class EmpleadoHoras: public Empleado{

private:
    int horas;
    double tarifa;

public:
    EmpleadoHoras(string n, string nu, double sal, int ho, double tar)
    :Empleado(n, nu, sal), horas(ho),tarifa(tar){}

int getHoras()const{
return horas;}

double getTarifa()const{
return tarifa;}

void setHora(int ho){
horas=ho;}

void setTarifa(double tar){
tarifa=tar;}


double calcularSalarioTotal()const override {
        return horas* tarifa;
    }

 void mostrarInfo()const override {
        cout << "===== EMPLEADO POR HORAS ====="<<endl;
        cout << "Nombre: "<<getName()<<endl;
        cout << "Numero: "<<getNumeroEmpleado()<<endl;
        cout << "Horas trabajadas: "<<horas<<endl;
        cout << "Tarifa por hora: $"<<tarifa<<endl;
        cout << "Salario total: $" <<calcularSalarioTotal()<<endl;
    }



};




int main(){

EmpleadoFullTime emp1("Luis Marulanda","001", 2000, "seguro medico",500);

EmpleadoHoras emp2("Natalia Pareja","002", 0, 40, 15);

emp1.mostrarInfo();
cout<<endl;

emp2.mostrarInfo();
cout<<endl;


return 0;

}

