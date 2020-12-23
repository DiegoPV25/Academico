#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

int main () {
   string cad = "";
   getline(cin, cad);
   while(cad != "*") {
      bool tautograma = true;
      vector<string> vectorPalabras;
      stringstream separador(cad);
      string palabra;
      
      while(getline(separador, palabra, ' ')) {
         vectorPalabras.push_back(palabra);
      }
      
      palabra = vectorPalabras.back();
      char letra = palabra[0];
      vectorPalabras.pop_back();
      
      while(vectorPalabras.size() > 0 and tautograma == true ) {
         palabra = vectorPalabras.back();
         vectorPalabras.pop_back();
         if (toupper(letra) != toupper(palabra[0])) tautograma = false;
      }
      
      if(tautograma == true) cout << "SI" << endl;
      else cout << "NO" << endl;
      
      getline(cin, cad); 
   }
   
   
   }
