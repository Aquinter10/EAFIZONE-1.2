//La clase mas corta, es un simple objeto con ciertos atributos. Se incluye herencia porque estamos viendo programacion orientada a objetos...


#define ARTICULO_H
#include <iostream>
using namespace std;

class Articulo {
public:
    string id;
    string nombre;
    float precio;
Articulo(string id, string nombre, float precio) {
        this->id = id;
        this->nombre = nombre;
        this->precio = precio;
}

  string getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
virtual void imprimir() {
      cout << id << " - " << nombre << " - " << precio << endl;
    }


};

//Clases Heredadas
//Articulo Deportivo
class ArticuloDeportivo:public Articulo {
  public:
  ArticuloDeportivo(string id, string nombre, float precio) : Articulo(id, nombre, precio){
    
  }


};
//Articulo Tecnologico
class ArticuloTecnologico:public Articulo {

public:
  ArticuloTecnologico(string id, string nombre, float precio) : Articulo(id, nombre, precio){
    
  }

};

class ArticuloExtranjero:public Articulo {
public:
  ArticuloExtranjero(string id, string nombre, float precio) : Articulo(id, nombre, precio){

  }

};
