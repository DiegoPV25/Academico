#include <iostream>
#include <algorithm> 
#include <array>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int main() { 
   string accion;
   vector<string> a1, aResultante;
   cout << "Introduce la accion"; cin >> accion;
   int elementos, pot; string pal;
   
   cout << "Introduce las cantidad de palabras en el Alfabeto 1";
   cin >> elementos;
   cout << "Introduce las palabras del Alfabeto 1";
   for (int i = 0; i < elementos; i++) { cin >> pal; a1.push_back(pal); }
   // REFLEXION
   if(accion == "reflexion") { 
      for(int i = 0; i < a1.size(); i++) { 
         string pal = a1.at(i);
         reverse(pal.begin(), pal.end());
         aResultante.push_back(pal);
      }
      cout << "Reflexion: ";
      for (int i = 0; i < aResultante.size() - 1; i++) cout << aResultante.at(i) << ", "; cout << aResultante.back() << endl;
      return 0;
   }
   
   // POTENCIA I-ESIMA o CLAUSURA DE KLEEN
   if(accion == "potencia" or accion == "clausuraKleen" or accion == "clausuraPos") {
      int potAct = 0, agregado = 0;
      cin >> pot;
      if(accion == "potencia") potAct = pot;
      while(potAct <= pot) {
         if(potAct == 0 and accion == "clausuraKleen") { aResultante.push_back("Lambda"); agregado++; }
         else {
            int longitud = pow(a1.size(),potAct-1);
            for(int i = 0; i < a1.size(); i++) { 
               for(int j = 0; j < longitud; j++) aResultante.push_back(a1.at(i));
            }
            
            for(int pos = 2; pos <= potAct; pos++) {
               int step1 = pow(a1.size(),potAct), step2 = pow(a1.size(),pos);
               int step = step1/step2;
               int j = -1;
               for(int i = 0 + agregado; i < aResultante.size(); i++) {
                  if((i-agregado) % step == 0) j++; if (j >= a1.size()) j=0;
                  aResultante.at(i).append(a1.at(j));
               }
            }
            
            agregado += longitud * a1.size();
         }
         potAct++;
      }
      cout << "Potencia: " << endl;
      for (int i = 0; i < aResultante.size() - 1; i++) cout << "-" << aResultante.at(i) << endl; cout << "-" << aResultante.back() << endl;
      return 0;
   } 
    
   vector<string> a2; 
   cout << "Introduce las cantidad de palabras en el Alfabeto 2";
   cin >> elementos;
   cout << "Introduce las palabras del Alfabeto 2";
   for (int i = 0; i < elementos; i++) { cin >> pal; a2.push_back(pal); }
   
   // CONCATENACION
   if(accion == "concat") {
      for(int i = 0; i < a1.size(); i++) { 
         for(int j = 0; j < a2.size(); j++) { 
            pal = a1.at(i); pal.append(a2.at(j));
            aResultante.push_back(pal);
         }
      }
      cout << "Concatenacion: ";
      for (int i = 0; i < aResultante.size() - 1; i++) cout << aResultante.at(i) << ", "; cout << aResultante.back() << endl;
      return 0;
   }
   
   vector<string> aResultanteA;
   // UNION o INTERSECCION
   if(accion == "union" or accion == "inter") {
      
   
      for (int i = 0; i < a1.size(); i++) { 
         vector<string>::iterator pos = find(a2.begin(), a2.end(), a1.at(i));
         if (pos != a2.end()) { // INTERSECCION
            aResultanteA.push_back(a1.at(i));
            a2.erase(pos); 
            } 
         aResultante.push_back(a1.at(i)); }
      for (int i = 0; i < a2.size(); i++) aResultante.push_back(a2.at(i));   
      if(accion == "union") { 
         cout << "Union: ";
         for (int i = 0; i < aResultante.size() - 1; i++) cout << aResultante.at(i) << ", "; cout << aResultante.back() << endl; }
      else {
         cout << "Interseccion: ";
         for (int i = 0; i < aResultanteA.size() - 1; i++) cout << aResultanteA.at(i) << ", "; cout << aResultanteA.back() << endl; 
      }   
   }
   
   if(accion == "complemento") { // COMPLEMENTO
   vector<string> conj;
   cout << "Introduce las cantidad de palabras en el conjunto";
   cin >> elementos;
   cout << "Introduce las palabras del conjunto";
   for (int i = 0; i < elementos; i++) { cin >> pal; conj.push_back(pal); }
   
   vector<string> au;
      for (int i = 0; i < a1.size(); i++) { au.push_back(a1.at(i)); }
      for (int i = 0; i < a2.size(); i++) { au.push_back(a2.at(i)); }
      
      for (int i = 0; i < conj.size(); i++) { 
         vector<string>::iterator pos = find(au.begin(), au.end(), conj.at(i));
         if (pos != au.end()) {
            aResultanteA.push_back(conj.at(i));
            au.erase(pos); 
            } 
      }
         
      for (int i = 0; i < au.size(); i++) aResultante.push_back(au.at(i));
      
      cout << "Complemento: ";
      for (int i = 0; i < aResultante.size() - 1; i++) cout << aResultante.at(i) << ", "; cout << aResultante.back() << endl;
      
   }
      return 0;
}
   
