#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//EJERCICIO 3,1 ANIMALES, CLASES Y SONIDOS

class Animal{

private:
    string name;
    int edad;
    double peso;

public:
    Animal(string n, int ed, double p):name(n), edad(ed), peso(p) {}

//getters
string getName()const {
return name;}

int getEdad()const {
return edad;}

double getPeso()const{
return peso;}

//setters

void setName(string n){
name=n;}

void setEdad(int ed){
if(ed>0){
  edad=ed;}
 else{
    cout<<"no sabes la edad??"<<endl;}

}

void setPeso(double p){
if(p>0){
   peso=p;}
 else{
    cout<<"pesa negativo?? ni existe ja"<<endl;}

}

virtual void hacerSonido(){
cout<<name<<"Hace un sonido desconocido"<<endl;
}

virtual void mostrarInfo(){
        cout << "Nombre: "<<name<<endl;
        cout << "Edad: "<< edad <<" anios"<<endl;
        cout << "Peso: "<<peso<<" kg"<<endl;
}

};

class Mamifero: public Animal{

private:
    bool cola;

public:
    Mamifero(string n, int ed, double p, bool c)
: Animal(n,ed,p), cola(c){}

bool getCola() const{
return cola;}

void setCola(bool c){
cola=c;}

void mostrarInfo() override{

cout<<"=====INFO DEL MAMIFERO"<<endl;
Animal::mostrarInfo();
cout<<"Tiene cola?: "<<(cola?"Si":"No")<<endl;

}


};


class Ave: public Animal{
private:
    double Alas;

public:
    Ave(string n, int ed, double p, double al)
    :Animal(n,ed,p), Alas(al){}


    double getAlas()const{
    return Alas;}

    void setAlas(double al){
    if(al>0){
        Alas=al;}

    }
  void mostrarInfo() override{
  cout<<"====INFO DEL AVE"<<endl;
  Animal::mostrarInfo();
  cout<<"Envergadura de alas: "<<Alas<<" metros"<<endl;
  }

};

class Perro: public Mamifero{

public:
    Perro(string n, int ed, double p, bool c)
    :Mamifero(n,ed,p,c){}

void hacerSonido()override{

cout<<getName()<<" Ladrido: GUAU, GUAU"<<endl;

}
void mostrarInfo() override{
cout<<"=========INFO DEL PERRO======="<<endl;
Mamifero::mostrarInfo();

}

};




class Gato: public Mamifero{

public:
    Gato(string n, int ed, double p, bool c)
    :Mamifero(n,ed,p,c){}

void hacerSonido()override{

cout<<getName()<<" Maullo: MIAU, MIAU"<<endl;

}
void mostrarInfo() override{
cout<<"=========INFO DEL GATO======="<<endl;
Mamifero::mostrarInfo();

}

};

class Loro: public Ave{

public:
    Loro(string n, int ed, double p, double al)
    :Ave(n,ed,p,al){}

    void hacerSonido()override{
    cout<<getName()<<" Dice: DAME GALLETA"<<endl;
    }

void mostrarInfo()override{
cout<<"==========INFO DEL LORO========"<<endl;
Ave::mostrarInfo();
}

};

class Aguila: public Ave{
public:
    Aguila(string n, int ed, double p, double al)
    :Ave(n,ed,p,al){}

    void hacerSonido() override{
    cout<<getName()<<" grita: SKREEEEEEEEEEKKKKKKLL"<<endl;
    }
void mostrarInfo() override{
cout<<"==========INFO DEL AGUILA=========="<<endl;
Ave::mostrarInfo();
}




};



int main(){

Perro per("Krohnos",5,25,true);
Gato cat("Canelo", 3, 5.5,true);
Loro lor("Mirringa", 2, 0.5, 0.3);
Aguila agui("Snake", 3, 1, 0.4);

per.mostrarInfo();
per.hacerSonido();
cout<<endl;

cat.mostrarInfo();
cat.hacerSonido();
cout<<endl;

lor.mostrarInfo();
lor.hacerSonido();
cout<<endl;

agui.mostrarInfo();
agui.hacerSonido();


}
