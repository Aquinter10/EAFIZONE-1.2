//Hola, esta es la clase inventario, inclui comentarios sobre los metodos.

#include <iostream>
#include <string>
#include "Articulo.cpp"
using namespace std;


class Node {
public:
    Articulo* data;
    Node* next;

    Node(Articulo* data) {
        this->data = data;
        this->next = nullptr;
    }
  Node(ArticuloDeportivo* data) {
        this->data = data;
        this->next = nullptr;
    }
  Node(ArticuloTecnologico* data) {
        this->data = data;
        this->next = nullptr;
    }

  Node(ArticuloExtranjero* data) {
        this->data = data;
        this->next = nullptr;
    }


  
};

class Inventario {
private:
    Node* head;
//Constructor de inventarios.
public:
    Inventario() {
        head = nullptr;
    }

    void add(Articulo* data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
//Metodo para remover objetos.
    void remove(string id) {
        if (head == nullptr) {
            return;
        }

        if (head->data->id == id) {
            Node* nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->data->id == id) {
                Node* nodeToDelete = current->next;
                current->next = current->next->next;
                delete nodeToDelete;
                return;
            }
            current = current->next;
        }
    }
// Metodo para encontrar un articulo, metodo muy necesario para verificaciones de articulos que ya existen.
    Articulo* find(string id) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data->id == id) {
               
                return current->data;
            }
            current = current->next;
        }
      
        return nullptr;
    }

// Metodo para modificar un articulo, creo que no modifica el tipo aun. 
 void modify(string id, string attribute, string new_value) {
        Articulo* articulo = find(id);
        if (articulo != nullptr) {
            if (attribute == "nombre") {
                articulo->nombre = new_value;
            } 
      
            else if (attribute == "precio") {
                articulo->precio = stod(new_value);
            } else {
                cout << "Atributo no valido" << endl;
            }
        } else {
            cout << "Articulo no encontrado" << endl;
        }
    }


// Metodo para imprimir los articulos del inventario.

    void print() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data->id << ", " << current->data->nombre << ", " << current->data->precio << endl;
            current = current->next;
        }

    
    }

// Metodo para vaciar el inventario.
    void vaciarInvent(){
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    
      
    }

// Imprimir Objetos deportivos.
// Dynamic cast para identificar la clase.
void printDeportivo() {
        Node* current = head;
        while (current != nullptr) {
        ArticuloDeportivo* deportivo = dynamic_cast<ArticuloDeportivo*>(current->data);
            if (deportivo != nullptr) {
                deportivo->imprimir();
            
            }
        
          current = current->next;
        }
    
    }

// Imprimir Objetos tecnologicos.
void printTecnologicos() {
        Node* current = head;
        while (current != nullptr) {
        ArticuloTecnologico* deportivo = dynamic_cast<ArticuloTecnologico*>(current->data);
            if (deportivo != nullptr) {
                deportivo->imprimir();
            
            }
        
          current = current->next;
        }
    
    }


//Imprimir articulo entranjero
// 
void printExtranjeros() {
        Node* current = head;
        while (current != nullptr) {
        ArticuloExtranjero* deportivo = dynamic_cast<ArticuloExtranjero*>(current->data);
            if (deportivo != nullptr) {
                deportivo->imprimir();
            
            }
        
          current = current->next;
        }
    
    }
//Ojala funcione
//Upadte: Si funciona!
void printPorTipo(){
  printDeportivo();
  printTecnologicos();
  printExtranjeros();  
}

// Castear Tecnologicos
  bool vefCastTecnologico(){
    int count=0;
    Node* current = head;
         int countipo=0;
        while (current != nullptr) {
          count=count+1;
          ArticuloTecnologico* deportivo = dynamic_cast<ArticuloTecnologico*>(current->data);
            if (deportivo != nullptr) {
                
                countipo=countipo+1;
                if (countipo==2){
                  return true;
                  break;
                }
                }
          else{countipo=0;}  
          current = current->next;    
        }
    return false;
    
  }
//Castear Extranjeros
bool vefCastExtranjero(){
    int count=0;
    Node* current = head;
         int countipo=0;
        while (current != nullptr) {
          count=count+1;
          ArticuloExtranjero* deportivo = dynamic_cast<ArticuloExtranjero*>(current->data);
            if (deportivo != nullptr) {
                
                countipo=countipo+1;
                if (countipo==2){
                  return true;
                  break;
                }
                }
          else{countipo=0;}  
          current = current->next;    
        }
    return false;
    
  }
//Castear Deportivos 
bool vefCastDeportes(){
    int count=0;
    Node* current = head;
         int countipo=0;
        while (current != nullptr) {
          count=count+1;
          ArticuloDeportivo* deportivo = dynamic_cast<ArticuloDeportivo*>(current->data);
            if (deportivo != nullptr) {
                
                countipo=countipo+1;
                if (countipo==2){
                  return true;
                  break;
                }
                }
          else{countipo=0;}  
          current = current->next;    
        }
    return false;
    
  }
//Castear todo

bool vefCast(){
  
  if (vefCastExtranjero()==true){
    return true;
  }
  else if (vefCastDeportes()==true){
    return true;
  
  }
  else if (vefCastTecnologico()==true){
    return true;
  
  }
  else{
    return false;
  }
    }
};

