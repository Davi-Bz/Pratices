#include <iostream>
#include <vector>
using namespace std;


/*
    - Receber um octeto de zeros e uns;
    - Transformar esse octeto binário para um número decimal;
*/

int conversion (string octeto) {
    vector<int> vet {128, 64, 32, 16, 8, 4, 2, 1};
    int dec { };

    for(int i = 0; i < 8; i++){
        if(octeto[i] == '1')
        dec += vet[i];
    }

    return dec;
}

int main() {

    string octeto;
    cout << "insira um octeto: \n"; 
    cin >> octeto;

    cout << "Numero em binario: " << octeto              << endl;
    cout << "Numero em decimal: " << conversion (octeto) << endl;

}
