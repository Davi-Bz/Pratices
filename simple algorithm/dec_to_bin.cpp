#include <iostream>
using namespace std;


/*
    - Receber um numero entre 0 e 255
    - Transformar e retornar esse número em Binário

*/

string conversion(int decimal){

int v = 128;
string octeto;

for(int i = 0; i < 8; i++){

    if(decimal < v) {
        octeto += "0";
    }
    else { 
        octeto += "1";
        decimal = decimal - v;
    }
    v = v / 2;
}
    return octeto;

}

int main(){

int dec { };
std::cout << "Insira um numero entre 0 e 255\n";
std::cin >> dec;

    std::cout << "Valor em decimal: " << dec << endl;
    std::cout << "Valor em binario: " << conversion(dec) << endl;

}