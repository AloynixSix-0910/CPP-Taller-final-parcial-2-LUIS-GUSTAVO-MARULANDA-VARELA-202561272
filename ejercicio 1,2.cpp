#include <iostream>
#include <string>
using namespace std;

//EJERCICIO 1,2

class Producto{

private:
    string codigo;
    string nombre;
    double precio;
    int cantidad;
public:
    Producto(string cod, string n, double p, int ca){
    codigo= cod;
    nombre= n;
    precio=p;
    cantidad= ca;

    }
//getters
    string getCodigo(){
    return codigo;
    }

    string getNombre(){
    return nombre;
    }

    double getPrecio(){
    return precio;
    }

    int getCantidad(){
    return cantidad;
    }
    double calcularVlrTotal(){
    return precio*cantidad;
   }



   //setters
   void setCodigo(string cod){
   codigo=cod;
   }
   void setNombre(string n){
    nombre=n;
   }
   void setPrecio(double p){
   if(p<0){
    cout<<"El precio no puede ser negativo"<<endl;}
   else{
    precio=p;}
   }
   void setCantidad(int ca){
   if(ca<0){
    cout<<"La cantidad no puede ser negativa"<<endl;}
    else{
        cantidad=ca;}
   }
   void aplicarDescuento(double porcentaje){
   if(porcentaje <0 || porcentaje> 100){
    cout<<"El porcentaje no es valido escoja (0-100)";
   }
   else{
    precio -= precio*(porcentaje/100.0);}

   }

   void mostrarInfo() {
       cout<<endl;
        cout<<"==========FACTURA========="<<endl;
        cout << "Código: "   << codigo  << endl;
        cout << "Nombre: "   << nombre  << endl;
        cout << "Precio: "   << precio  << endl;
        cout << "Cantidad: " << cantidad << endl;
        cout << "Valor total: $" << calcularVlrTotal() << endl;

    }



};






int main(){

 string codigo, nombre;
    double precio;
    int cantidad;

    cout << "=== INGRESO DE UN PRODUCTO ===\n";

    cout << "Codigo: ";
    cin >> codigo;

    cout << "Nombre: ";
    cin >>ws;
    getline(cin,nombre);

    cout << "Precio: ";
    cin >> precio;

    cout << "Cantidad: ";
    cin >> cantidad;

    // Crear producto
    Producto p(codigo, nombre, precio, cantidad);

    cout << "=== PRODUCTO INGRESADO ==="<<endl;
    p.mostrarInfo();


    // Aplicar descuento fijo del 10%
    cout << "Descuento del 10%"<<endl;
    p.aplicarDescuento(10);

    // Mostrar producto después del descuento
    cout << "Nuevo precio despues del descuento"<<endl;
    p.mostrarInfo();




}
