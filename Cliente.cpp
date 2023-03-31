// Para reciclar la clase inventario, (Viendo el carrito de un cliente como un "inventario") he incluido los metodos de coordinador, de tal forma que se interactua con el inventario de la tienda (Pero sin los metodos de un coordinador XD) De tal modo que un cliente maneja dos inventarios, su carrito y la tienda como tal.

#include <iostream>

#include "Inventario.cpp"
using namespace std;

class Cliente {
public:
    string nombre;
    Inventario carrito;
    Inventario tienda;
    int valortotal=0;
    unsigned char counter=3;
    bool discount=false;
    

    Cliente(string nombre, Inventario carrito,Inventario tienda) {
        this->nombre =nombre;
      this->carrito =carrito;
        this->tienda=tienda;
    }
    
//Se pueden agregar mas categorias para visualizarlas.
    void verPorTipo(){ 
    
    tienda.printPorTipo();
    }

  
  void agregarAlCarrito(){

//IMPUESTOOOOOOOOO
  float tax;
  tax=10;
  
  string id;
  cout << "\nEscribe la ID del Articulo que quieres comprar"<<endl;
  cin >> id;
    Articulo* temporal =tienda.find(id);
    if (tienda.find(id)==nullptr){
      cout << "\nParece que ese articulo no existe" <<endl;
      agregarAlCarrito();

      
    }
  else

      
  {
    string ctrl2;
    
    ArticuloExtranjero* deportivo = dynamic_cast<ArticuloExtranjero*>(temporal);
            if (deportivo != nullptr) {

              valortotal=valortotal+(temporal->precio+((temporal->precio/100))*tax);
            carrito.add(temporal);
            }
            else{
     carrito.add(temporal);
    valortotal=valortotal+temporal->precio;

            }
    cout<< "--------Tu carrito--------"<<endl;
    carrito.print();
    cout<< "--------Tu carrito--------\n"<<endl;
  cout << "Deseas agregar otro producto?"<<endl;
  cout << "Escriba 1 para agregar otro producto."<<endl;
  cout << "Escriba cualquier otra tecla para terminar."<<endl;
    cin >> ctrl2;
    if (ctrl2=="1"){
    agregarAlCarrito();
      
    }
  }


    }

    int valorpago(){

      return valortotal;
    }

    void verCarrito(){

    carrito.print();
      
    }

    void vaciarCarrito(){

      carrito.vaciarInvent();
      valortotal=0;
    }



  


void opclient(){
  string ctrl1;
  cout << "\n____________________________________________________" <<endl;
  cout << "\n▯        Bienvenido cliente.                        ▯" <<endl;
  cout << "Usted tiene tres opciones."<<endl;
  cout << "\n1. Comprar Articulo"<<endl;
  cout << "\n2. Pagar Carrito"<<endl;
  cout << "\n3. Volver al menu"<<endl;

  cin >> ctrl1;

  if (ctrl1=="1"){
    cout << "\n____________________Lista de prodcutos ____________" <<endl;
    verPorTipo();
    agregarAlCarrito();
    opclient();
  }

  else if (ctrl1=="2"){

   cout<< "\n____________Esta es tu lista de Articulos ____________"<<endl;
    verCarrito();
  
  cout<< "\n____________Este es tu pago total. ____________"<<endl;
    cout <<"valor: "<<valorpago()<<endl;

    if (carrito.vefCast()==true){
      valortotal=valortotal-(valortotal*0.1);
      cout<<"Este es tu valor con descuento: "<< valorpago();
    }

  cout<< "\n____________Tienes dos opciones. ____________"<<endl;
  cout<< "\n____________1. Pagar el carrito."<<endl;
  cout<< "\n____________2. Cancelar la compra."<<endl;
  string ctrl2;
  cin >> ctrl2;
  if (ctrl2=="1"){
    cout<< "\nPago exitoso!"<<endl;
    vaciarCarrito();
    verCarrito();
    opclient();
  }  

  else if (ctrl2=="2"){

    cout << "\nCompra cancelada." <<endl;
    vaciarCarrito();
    opclient();
  }

  

  else{

    cout << "\nIngresa una opcion valida." <<endl;
    opclient();
  }
  
  
  
  }

  else if(ctrl1=="3"){
      cout << "================================"<<endl;
    }
}

};