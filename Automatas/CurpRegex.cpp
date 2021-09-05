#include <iostream>
#include <regex>
#include <string.h>
#include <cstring>

using namespace std;

int main()
{
   string regS = "";
   string curp = "";
   int dia, mes, anio;
   string nombre, apPat, apMat, entidad, sexo, var;
   
   cout << "Introduzca su primer nombre: " << endl;
   cin >> nombre;
   cout << "Introduzca su apellido Paterno: " << endl;
   cin >> apPat;
   cout << "Introduzca su apellido Materno: " << endl;
   cin >> apMat;
   cout << "Introduzca su dia de nacimiento: " << endl;
   cin >> dia;
   cout << "Introduzca su mes de nacimiento: " << endl;
   cin >> mes;
   cout << "Introduzca su anio de nacimiento: " << endl;
   cin >> anio;
   cout << "Introduzca su sexo: " << endl;
   cin >> sexo; 
   cin.ignore();
   cout << "Introduzca su entidad de nacimiento: " << endl;
   getline(cin, entidad); 
   string agr = "";
   
   agr += apPat[0];
   
   var = "";
   regex reg("[aeiou]");
   smatch m;
   while (regex_search (apPat,m,reg)) {
      for (auto x:m) { var = x;  }
      break; 
   }
   if (var == "") { var = "X"; }
   agr += var;
   agr += apMat[0];
   agr += nombre[0];
   
   var = to_string(anio);
   var.erase (var.begin(), var.end()-2);
   agr += var;
   
   var = "";
   if(mes < 9) var = "0";
   var += to_string(mes);
   agr += var;
   
   var = "";
   if(dia < 9) var = "0";
   var += to_string(dia);
   agr += var;
   
   agr += sexo[0];
   
   var = "";
   
   if(entidad == "AGUASCALIENTES") var = "AS"; 
   else if(entidad == "BAJA CALIFORNIA") var = "BC";
   else if(entidad == "BAJA CALIFORNIA SUR") var = "BS";
   else if(entidad == "CAMPECHE") var = "CC";
   else if(entidad == "COAHUILA") var = "CL";
   else if(entidad == "COLIMA") var = "CM";
   else if(entidad == "CHIAPAS") var = "CS";
   else if(entidad == "CHIHUAHUA") var = "CH";
   else if(entidad == "DISTRITO FEDERAL") var = "DF";
   else if(entidad == "DURANGO") var = "DG";
   else if(entidad == "GUANAJUATO") var = "GT";
   else if(entidad == "GUERRERO") var = "GR";
   else if(entidad == "HIDALGO") var = "HG";
   else if(entidad == "JALISCO") var = "JC";
   else if(entidad == "MEXICO") var = "MC";
   else if(entidad == "MICHOACAN") var = "MN";
   else if(entidad == "MORELOS") var = "MS";
   else if(entidad == "NAYARIT") var = "NT";
   else if(entidad == "NUEVO LEON") var = "NL";
   else if(entidad == "OAXACA") var = "OC";
   else if(entidad == "PUEBLA") var = "PL";
   else if(entidad == "QUERETARO") var = "QT";
   else if(entidad == "QUINTANA ROO") var = "QR";
   else if(entidad == "SAN LUIS POTOSI") var = "SP";
   else if(entidad == "SINALOA") var = "SL";
   else if(entidad == "SONORA") var = "SR";
   else if(entidad == "TABASCO") var = "TC";
   else if(entidad == "TAMAULIPAS") var = "TS";
   else if(entidad == "TLAXCALA") var = "TL";
   else if(entidad == "VERACRUZ") var = "VZ";
   else if(entidad == "YUCATAN") var = "YN";
   else if(entidad == "ZACATECAS") var = "ZS";
   else var = "NE";
   
   agr += var;
   
   var = "";
   reg = "[^aeiouA-Z ]";
   while (regex_search (apPat,m,reg)) {
      for (auto x:m) { var = x;  }
      break; 
   }
   if (var == "") { var = "X"; }
   
   var = "";
   while (regex_search (apMat,m,reg)) {
      for (auto x:m) { var = x;  }
      break; 
   }
   if (var == "") { var = "X"; }
   
   var = "";
   while (regex_search (nombre,m,reg)) {
      for (auto x:m) { var = x;  }
      break; 
   }
   if (var == "") { var = "X"; }
   
   agr += "[A-Z0-9][A-Z0-9]";
   
   
   string curpReal = "";
   for (int i = 0; i < agr.length(); i++) {
      curpReal += toupper(agr[i]);
   }
   
   reg = curpReal;
   
      
   var = "";
   var += "[A-Z]"; // Primera letra del apellido paterno
   var += "[AEIOUX]";  // Primera vocal del apellido paterno
   var += "[A-Z]";  // Primera letra del apellido materno
   var += "[A-Z]";  // Primera letra del primer nombre
   var += "[0-9]{2}"; // Ultimos dos digitos del anio de nacimiento
   var += "(0[1-9]|1[0-2])"; // Mes de nacimiento
   var += "(0[1-9]|1[0-9]|2[0-9]|3[0-1])"; // Dia de nacimiento
   var += "[HM]"; // Sexo
   var += "(AS|B[CS]|C[CLMSH]|D[FG]|G[TR]|HG|JC|M[CNS]|N[ETL]|OC|PL|Q[TR]|S[PLR]|T[CSL]|VZ|YN|ZS)"; // Estados
   var += "[^AEIOU]{3}"; // Consonantes de apellidos
   var += "[A-Z0-9][A-Z0-9]"; // 
   
   
   
   cout << "Validador de CURP general: " << var << endl;
   cout << "REGEX: "<< curpReal << endl;
   cout << "Introduzca su CURP: " << endl;
   cin >> curp;
   cout << "CURP: "<< curp << endl << endl;
   regex valid(var);
   
   bool estructuraCorrecta = false;
   while (regex_search (curp,m,valid)) {
      for (auto x:m) estructuraCorrecta = true;
      break; 
   }
   
   if(estructuraCorrecta == true) cout << "El curp introducido TIENE estructura valida.";
   else cout << "El curp introducido NO TIENE estructura valida.";
   
   
   bool esValido = false;
   while (regex_search (curp,m,reg)) {
      for (auto x:m) esValido = true;
      break; 
   }
   
   cout << endl;
   if(estructuraCorrecta == true) cout << "El curp introducido PERTENECE a usted.";
   else cout << "El curp introducido NO PERTENECE a usted.";
   
   return 0;
}
