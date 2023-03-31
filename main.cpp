
#include <iostream>

#include "Sistema.cpp"

int main() {
  std::cout << "Hello World!\n";
  ArticuloDeportivo* tenis =new ArticuloDeportivo("#232","Tenis",324242);
ArticuloTecnologico* camara =new ArticuloTecnologico("4343","Camara",324242);
  ArticuloTecnologico* epson =new ArticuloTecnologico("3232","Epson",22222);
  ArticuloExtranjero* wisky=new ArticuloExtranjero("111111","Whisky",4600);
  Inventario tienda = Inventario();
  Inventario carrito= Inventario();
  tienda.add(tenis);
  tienda.add(camara);
  tienda.add(epson);
  tienda.add(wisky);
  
  
  tienda.printPorTipo();
  Cliente pedro=Cliente("Pedro",carrito,tienda);
  Coordinador alan=Coordinador("Alan",tienda);
  Interfaz tiendareal= Interfaz(tienda,alan,pedro);
  tiendareal.arrancar();
}