#include <iostream>
#include "Coordinador.cpp"

class Interfaz {
public:
    Inventario inventario;
    Inventario carrito;
    Coordinador coordinador = Coordinador("Juan",inventario);
    Cliente cliente= Cliente("Pedro",carrito,inventario);
    
   
  //Constructor de Interfaz, pensemos en Interfaz como en un constructor de toda la tienda y sus participantes.

    Interfaz(Inventario inventario,Coordinador coordinador,Cliente cliente) {
        this->inventario = inventario;
        this->coordinador=coordinador;
        this->cliente=cliente;


    }
    void iniciarMenu(){
      string opcion;
  cout << "\n____________________________________________________" <<endl;
  cout << "\n▯        Bienvenido a EafiZone!                    ▯" <<endl;
  cout << "\n▯  Somos la tienda con los mejores articulos.      ▯" <<endl;
  cout << "\n▯        Es usted Cliente o Coordinador?           ▯" <<endl;
  cout << "\n▯        Escriba 1 para Cliente.                   ▯" <<endl;
  cout << "\n▯        Escriba 2 para coordinador.               ▯" <<endl;
  cout << "\n▯        Escriba 3 para finalizar  .               ▯" <<endl;
  cout << "\n____________________________________________________" <<endl;

 cin >> opcion;
  
  if (opcion=="1"){

  cliente.opclient();
  iniciarMenu();
  
  }
  
  else if (opcion=="2"){
   coordinador.menuCoordinador();
  iniciarMenu();
  }

  else if (opcion=="3"){

    cout<< "____________________________________________________"<<endl;
    cout<< "____________________________________________________"<<endl;
    cout<< "______________________Cerrando______________________"<<endl;
    cout<< "____________________________________________________"<<endl;
    cout<< "____________________________________________________"<<endl;
  }
    
  else{

  cout << "Ingresa una opcion valida!"<<endl;
    iniciarMenu();
  }
    }

void logo(){
cout<<"__________________________________________________________________________"<<endl;
cout<<"__________________________________________________________________________"<<endl;
cout<<"d88888b  .d8b.  d88888b d888888b        d88888D  .d88b.  d8b   db d88888b "<<endl;
cout<<"88'     d8' `8b 88'       `88'          YP  d8' .8P  Y8. 888o  88 88'     "<<endl;
cout<<"88ooooo 88ooo88 88ooo      88              d8'  88    88 88V8o 88 88ooooo "<<endl;
cout<<"88~~~~~ 88~~~88 88~~~      88    C8888D   d8'   88    88 88 V8o88 88~~~~~ "<<endl;
cout<<"88.     88   88 88        .88.           d8' db `8b  d8' 88  V888 88.     "<<endl;
cout<<"Y88888P YP   YP YP      Y888888P        d88888P  `Y88P'  VP   V8P Y88888P "<<endl;
cout<<"__________________________________________________________________________"<<endl;
cout<<"__________________________________________________________________________"<<endl;
}

void arrancar(){
  logo();
  iniciarMenu();
}

};