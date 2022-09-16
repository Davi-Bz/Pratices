#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
auto sf = std::fixed;
auto sp = std::setprecision(2);


struct Calc {
    int battery_max {0};
    int battery {0};
    float display {0};

    Calc(){

    }

    void calculator(int btm){        //inicia uma calculadora passando sua bateria máxima;
        battery_max = 0;
        battery = 0;
        battery_max = btm;
    }

    void charge(int qtd){           //Carrega a bateria da calculadora 
        battery += qtd;
        if(battery > battery_max)
        battery = battery_max % battery;
    }

    bool usebattery(){             //Se tiver bateria, realiza uma operação; Se não, avisa um erro 
        if(battery == 0)
            return true;
                return false;
    }

    void sum(int a, int b){         //soma 2 valores e atribui para o display
        if(usebattery() == true){
            cout<<"fail: bateria insuficiente\n";
        } else {
        int sum = a + b;
        battery--;
        display = sum;
        }
    }

      void sub (int a, int b){         //soma 2 valores e atribui para o display
        if(usebattery() == true){
            cout<<"fail: bateria insuficiente\n";
        } else {
        int sub = a - b;
        battery--;
        display = sub;
        }
    }

      void mult(int a, int b){         //soma 2 valores e atribui para o display
        if(usebattery() == true){
            cout<<"fail: bateria insuficiente\n";
        } else {
        int mult = a * b;
        battery--;
        display = mult;
        }
    }

    void division(int a, int b){            //divide 2 valores e atribui para o display
        if(battery == 0){
            cout <<"fail: bateria insuficiente\n";
        } else if(a == 0 || b == 0){
            cout << "fail: divisao por zero\n";
            battery--;
        } else {
            float div = (float)a / b;
            battery--;
            display = div;
        }
    }

    void show(){                    // mostra o display e a bateria da calculadora 

        cout<< "display = " << sf << sp << (float)display << ", battery = " << battery << endl;
    }
};

 void comand(Calc calc){
         while(true){
    string cmd;
    cin>> cmd;

    if(cmd == "end"){           //end
        cout<<"$end\n";
        break;

    } else if(cmd == "init"){       //init  v
        
        int bt;
        cin>> bt;
        cout<<"$init "<<bt<<endl;
        calc.calculator(bt);        

    } else if(cmd == "charge"){         //charge v
        int bt;
        cin>> bt;
        cout<<"$charge "<<bt<<endl;
        calc.charge(bt);

    } else if(cmd == "sum"){        //sum a b
        int a, b;
        cin>> a >> b;
        cout<<"$sum "<< a << " " << b << endl;
        calc.sum(a, b);

    } else if(cmd == "sub"){        //sub a b
        int a, b;
        cin>> a >> b;
        cout<<"$sub "<< a << " " << b << endl;
        calc.sub(a, b);

    } else if(cmd == "mult"){        //sum a b
        int a, b;
        cin>> a >> b;
        cout<<"$mult "<< a << " " << b << endl;
        calc.mult(a, b);

    } else if(cmd == "div"){        //sum a b
        int a, b;
        cin>> a >> b;
        cout<<"$div " << a << " " << b << endl;
        calc.division(a, b);

    } else if(cmd == "show"){
        cout<<"$show\n";
        calc.show();

    } else {
        cout<<"comando invalido\n";
    }
   }
  }

int main(){
    Calc calc;

    comand(calc);
  
}
