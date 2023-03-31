
#include "Cliente.cpp"
#include <iostream>

class Coordinador {
public:
    string nombre;
    Inventario invent;
    Coordinador( string nombre,Inventario invent) {  
    this->nombre = nombre;
    this->invent = invent;

    }

    void verInventario(){

    this->invent.print();
      
    }
     
    
  void agregarArticulo(){
    string id;
    string namearticulo;
    float precioarticulo;
    string tipoarticulo;
    cout << "Agregando el articulo: Ingrese los datos del articulo: " <<endl;
    
    cout<< "\nIngrese la Id del articulo:"<<endl;
    cin>> id;

    if (invent.find(id)!=nullptr){

      cout<<"ESTE ARTICULO YA EXISTE"<<endl;
      cout<<"----------------------------------------"<<endl;
      agregarArticulo();
    }
  else{
    cout<< "\nIngrese el nombre del articulo:"<<endl;
    cin >> namearticulo;
    cout<< "\nIngrese el precio del articulo:"<<endl;
    cin >>precioarticulo;
    cout<< "\nTipo de articulo:\n1. Tecnologia\n2. Deportes\n3. Extranjero"<<endl;
    cin >>tipoarticulo;
    
    if (tipoarticulo=="1"){
    
        invent.add(new ArticuloTecnologico(id,namearticulo,precioarticulo));
        cout << "Articulo agregado"<<endl;
                  }
    else if (tipoarticulo=="2"){
    
        invent.add(new ArticuloDeportivo(id,namearticulo,precioarticulo));
        cout << "Articulo agregado"<<endl;
                  }
    else if (tipoarticulo=="3"){
    
        invent.add(new ArticuloExtranjero(id,namearticulo,precioarticulo));
        cout << "Articulo agregado"<<endl;
                  }
    else{
cout<<"INGRESA UN TIPO CORRECTO"<<endl;
      cout<<"----------------------------------------"<<endl;
      agregarArticulo();
      
    }
    
    verInventario();
  }

    
    };

//-------------------------------------------------------------------//
void modificarArticulo(){
  cout << "Modificando articulo, ingresa la ID, el atributo que quieres cambiar y el nuevo valor." <<endl;
  string id;
  string atributo;
  string valor_nuevo;
  cin >>id;
   cin >>atributo;
   cin >>valor_nuevo;
  if (invent.find(id)==nullptr){
    cout << "Este articulo no existe, intenta de nuevo."<<endl;
    modificarArticulo();
  }
  if (atributo=="nombre"){
    
  invent.modify(id, atributo,valor_nuevo);
  invent.print();
  }
  else if(atributo=="precio"){
    invent.modify(id, atributo,valor_nuevo);
    invent.print();
  }
else{
  cout << "Ingresa un atributo valido" <<endl;
  modificarArticulo();
}
  
}
//-------------------------------------------------------------------
    
void eliminarArticulo(){
string id;
cout << "Ingresa la ID del articulo" << endl;
cin >>id;
if (invent.find(id)==nullptr){
    cout << "Este articulo no existe, intenta de nuevo."<<endl;
    eliminarArticulo();}
else{
invent.remove(id);
invent.print();
}
  
}
//--------------------------------------------------------------------//

void menuCoordinador(){

string opcood;
  
  cout << "Bienvenido Coordinador!"<<endl;
  cout << "Usted tiene tres opciones."<<endl;
  cout << "\n1. Agregar Articulo"<<endl;
  cout << "\n2. Modificar Articulo"<<endl;
  cout << "\n3. Eliminar Articulo"<<endl;

  cin >>opcood;
    if (opcood=="1"){
  int ctrl;
  agregarArticulo();

  cout << "\nDesea volver al menu de coordinador? Marcar 1 "<<endl;
  cout << "\nDesea salir al menu principal? Marcar  otra tecla"<<endl;
  cin>> ctrl;  
  if (ctrl==1){
      menuCoordinador();
  }
    
    }

  else if (opcood=="2"){
  cout << "Modificando el articulo";
  modificarArticulo();
  int ctrl;
  cout << "\nDesea volver al menu de coordinador? Marcar 1 "<<endl;
  cout << "\nDesea salir al menu principal? Marcar  otra tecla"<<endl;
  cin >> ctrl;
    
  cin>> ctrl;  
  if (ctrl==1){
      menuCoordinador();
  }
    
    }
  

  else if (opcood=="3"){
  cout << "Eliminando el articulo"<<endl;
    eliminarArticulo();
  int ctrl;
  cout << "\nDesea volver al menu de coordinador? Marcar 1 "<<endl;
  cout << "\nDesea salir al menu principal? Marcar  otra tecla"<<endl;
  cin >> ctrl;
  if (ctrl==1){
      menuCoordinador();
  }
    
  }
}
};