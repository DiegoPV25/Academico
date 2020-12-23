#include<iostream>
#include<map>
using namespace std;
int casos, longitud;
string palabra;
int main() {
   cin >> casos;
   while(casos > 0) {
      map<string, int> listaPal;
      cin >> longitud;
      cin >> palabra;
      string palabraOrig = palabra;
      listaPal[palabra] = 0;
      char letraMax = 'z';
      for(int i = 0; i < longitud; i++) {
         while(palabra[1] > letraMax) {
            palabra+=palabra[0];
            palabra.erase(palabra.begin());
            i++;
         }
         palabra+=palabra[0];
         palabra.erase(palabra.begin());
         if(!listaPal[palabra] && palabra != palabraOrig)  
            listaPal[palabra] = i+1;
         letraMax = palabra[0];
         }
         
      map<string,int>::iterator it = listaPal.begin();
      cout << it->second << endl;
      casos--;
   }
}