#include <iostream>
#include <vector>
using namespace std;

void fill (vector<int>& oct) {

    for(int i = 0; i < oct.size(); i++){
        std::cin >> oct[i];
    }
}

string show (vector<int> oct) {
    string bin;

    for(int i = 0; i < oct.size(); i++){
        bin += to_string(oct[i]);
    }
    return bin;

}

/*
    - Receber um octeto de zeros e uns;
    - Transformar esse octeto binário para um número decimal;
*/

int conversion (vector<int> oct) {

vector<int> vet {128, 64, 32, 16, 8, 4, 2, 1};

int dec { };

for(int i = 0; i < 8; i++) {

    if(oct[i] == 1)
    dec += vet[i];

}
    return dec;
}

void all(vector<int> oct) {

std::cout << "Insira um octeto(8 bits): \n";
fill(oct);

std::cout << "Valor em binario: " << show(oct)       << endl;
std::cout << "Valor em decimal: " << conversion(oct) << endl;
}

int main() {

vector<int> oct (8);
all(oct);

}
