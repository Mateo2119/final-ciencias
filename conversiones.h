#ifndef CONVERSIONES_H
#define CONVERSIONES_H

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>


class conversiones{	  
      public: conversiones(){}	  
	  		string toString(auto &i);
	  		int toInt(string i);
	  		float toFloat(string i);
			vector<string> obtenerVector(string cadena);	  
};

string conversiones::toString(auto &i){
   std::stringstream ss;
   ss << i;
   return ss.str();
}

int conversiones::toInt(string i){
   stringstream ss(i);
   int x = 0;
   ss << x;
   return x;
}

float conversiones::toFloat(string i){
   stringstream ss(i);
   float x = 0;
   ss << x; 
   return x;
}

vector<string> conversiones::obtenerVector(string cadena){
	vector<string> result;
	string textoLinea;
	std::stringstream ss(cadena);
	while(getline(ss,textoLinea,' ')){
			result.push_back(textoLinea);		
	}
	return result;
}

#endif
