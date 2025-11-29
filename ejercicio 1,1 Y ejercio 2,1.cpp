#include <iostream>
#include <string>
using namespace std;

//EJERCICIO 1,1 VEHICULO y EJERCICIO 2,1

class Vehiculo{
private:
    string marca;
    string modelo;
    int year;
    double velocidadMaxima;
    string damage;

public:

    Vehiculo(string mar, string mod, int a, double v, string d){

    setMarca(mar);
    setModelo(mod);
    setYear(a);
    setVelocidad(v);
    setDamage(d);

}
    //aqui hacemos uso de los getters
    string getMarca(){
        return marca;
    }
    string getModelo(){
    return modelo;
    }

    int getYear(){
    return year;
    }
    double getVelocidad(){
    return velocidadMaxima;
    }
    string getDamage(){
    return damage;
    }

        //setter (modificadores)
    void setMarca(string mar){
    marca= mar;
    }
    void setModelo(string mod){
    modelo= mod;
    }
    void setYear(int a){
    if(a>=1886){
            year= a;}
   else{
    cout<<"El anio no puede ser menor a 1886"<<endl;
    year=1886;
   }
    }
    void setVelocidad(double v){
        if(v>=0){
          velocidadMaxima= v;
        }
    else{
        cout<<"La velocidad del vehiculo no puede ser negativa"<<endl;
        velocidadMaxima=0;
    }
}
    void setDamage(string d){
    damage= d;
    }
// aqui usamos el acelerar (duplicamos el valor de la velocidad maxima)
    void acelerar(){
        velocidadMaxima *= 2;
        cout << "La velocidad ha sido duplicada. Nueva velocidad: "
             << velocidadMaxima << " km/h" << endl;
    }

    //Metodo para mostrar la informacion
    virtual void mostrarInfo()const{
    cout<<"===========CONTROL DE VEHICULOS======="<<endl;
    cout<<endl;
    cout<<"Marca: "<<marca<<endl;
    cout<<"Modelo: "<<modelo<<endl;
    cout<<"Anio: "<<year<<endl;
    cout<<"Velocidad maxima del vehiculo: "<<velocidadMaxima<<endl;
    cout<<"Danio del vehiculo: "<<damage<<endl;
    }
};

//vamos a poner el ejercicio 2,1 en este mismo archivo, por ende aqui voy agregar las nuevas clases
//y abajo pondre en que parte esta el nuevo main (es decir, mi main original con el agregado de las nuevas clases y los datos)


class Auto: public Vehiculo{
private:
    int numeroPuertas;
    string tipoCombustible;

public:

    Auto(string mar, string mod, int a, double v, string d, int pu, string com)
:Vehiculo(mar, mod, a, v, d), numeroPuertas(pu), tipoCombustible(com){}

void mostrarInfo() const override {
        cout << "======= AUTO =======" << endl;
        Vehiculo::mostrarInfo();
        cout << "Puertas: " << numeroPuertas << endl;
        cout << "Combustible: " << tipoCombustible << endl;
    }


};


class Motocicleta : public Vehiculo {
private:
    bool tieneAleron;
    int cilindrada;

public:

    Motocicleta(string mar, string mod, int a, double v, string d,
                bool aleron, int cil)
        : Vehiculo(mar, mod, a, v, d)
    {
        tieneAleron = aleron;
        cilindrada = cil;
    }

    void mostrarInfo() const override {
        cout << "======= MOTOCICLETA =======" << endl;
        Vehiculo::mostrarInfo();
        cout << "Cilindrada: " << cilindrada << " cc" << endl;
        cout << "Aleron: " << (tieneAleron ? "Si" : "No") << endl;
    }
};






int main(){

string marca1,marca2, modelo1, modelo2, damage1, damage2;
int year1, year2;
double velocidadMaxima1, velocidadMaxima2;

//Agrega los datos del vehiculo 1
cout<<"==========INGRESE DATOS DEl VEHICULO 1=========="<<endl;
cout<<endl;
cout<<"Marca: ";
getline(cin,marca1);
cout<<"modelo: ";
getline (cin,modelo1);

cout<<"Anio del vehiculo: ";
cin>>year1;
cout<<"Velocidad Maxima en km/h (no es necesario agregar el km): ";
cin>>velocidadMaxima1;
cout<<"Danio para reparar: ";
cin>>ws;
getline(cin,damage1);

//se crea aqui para evitar problemas de que los mensajes de error se pasen al segundo bloque de info
Vehiculo v1(marca1, modelo1, year1, velocidadMaxima1, damage1);

cout<<endl;

cout<<"==========INGRESE DATOS DEl VEHICULO 2=========="<<endl;
cout<<endl;
cout<<"Marca: ";
getline(cin,marca2);
cout<<"modelo: ";
getline(cin,modelo2);

cout<<"Anio del vehiculo: ";
cin>>year2;
cout<<"Velocidad Maxima en km/h (no es necesario agregar el km): ";
cin>>velocidadMaxima2;
cout<<"Danio para reparar: ";
cin>>ws;
getline(cin,damage2);


//Crea los objetos de los vehiculos, osea lo que ingrese el usuario, lo asigna aqui

Vehiculo v2(marca2, modelo2, year2, velocidadMaxima2, damage2);

//mostrar la informacion
cout<<endl;
v1.mostrarInfo();
cout<<endl;
v2.mostrarInfo();

cout << "\nAcelerando vehiculo 1..." << endl;
    v1.acelerar();

    cout << "\nAcelerando vehiculo 2..." << endl;
    v2.acelerar();

//parte del main del ejercicio 2,1

 cout << "\n\n===== PRUEBA DE UN AUTO =====" << endl;
    Auto miAuto("Toyota", "Hilux", 2020, 180, "Golpe frontal", 4, "Gasolina");
    miAuto.mostrarInfo();

    cout << "\n===== PRUEBA DE UNA MOTOCICLETA =====" << endl;
    Motocicleta miMoto("Yamaha", "XTZ", 2025, 600, "Rayón lateral", true, 600);
    miMoto.mostrarInfo();



return 0;
}
