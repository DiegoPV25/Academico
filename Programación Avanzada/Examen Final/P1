#include <iostream>
#include <string>
#include <map>

using namespace std;
int p = 1; int l = 1;

int main () {
   while(true) {
   int cont = 0; int juego;
   cin >> p;
   cin >> l;
   if(p == 0 and l == 0) return 0;
   map<int,bool> juegosP;
   map<int,bool> juegosL;
   while(p > 0) {
      cin >> juego;
      juegosP[juego] = true;
      juegosL[juego] = false;
      p--;
   }
   while(l > 0) {
      cin >> juego;
      juegosL[juego] = true;
      if(!juegosP[juego])
         juegosP[juego] = false;
      l--;
   }
   cont = 0;
   for (map<int,bool>::iterator it = juegosP.begin(); it != juegosP.end(); it++) { 
      if(juegosP[it->first] == juegosL[it->first]) { cont++; } 
      }
      cout << cont << endl;
   }
}
