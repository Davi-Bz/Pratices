

#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct Carro{
    int pass {0};
    int pass_max {5};
    int gas {0};
    int gas_max {100};
    int km {0};

    int car;

    Carro(){          //constructor 
        
    }


    void enter(){                   //entry of passengers in the car
        if(pass == pass_max)
            cout<<"fail: people limit reached\n";
        else
            pass += 1;
    }

    void leave(){                   //output of passengers of the car
        if(pass == 0)
            cout<<"fail: there's no one in the car\n";
        else
            pass -= 1;
    }

    void fuel(int comb){            //fill the car with fuel (max = 100)
        gas += comb;
        if(gas > gas_max){
            gas = gas_max % gas;
        }
    }

    void drive(int dtc){             //drives equal to value in parameter
        if(pass == 0)
            cout<<"fail: there's no one in the car\n";
        else if(dtc > gas){
            cout<<"fail: empty tank after driving " << gas << " km\n";
            km += gas;
            gas = 0;
            
        } else {
            km += dtc;
            gas -= dtc;
        }
    }

    void show(){
        cout<<"pass: " << pass << ", gas: " << gas << ", km: " << km << "\n";
    }

};

/*
    $end
    $enter
    $leave
    $fuel
    $drive
    $show
    */

int main(){
    Carro car;
   

    while(true){
        string cmd { };
        cin>> cmd;

        if(cmd == "end"){           //end the program
            cout<<"$$end\n";
            break;

        } else if(cmd == "enter"){      // insert a passenger in the car (max = 2)
            car.enter();
            car.show();

        } else if(cmd == "leave"){      // take off a passenger of the car 
            car.leave();
            car.show();

        } else if(cmd == "fuel"){       // insert fuel on the tank of the car (max = 100)
            int gs {0}; 
            cout<<"How much liters of gasoline? \n";
            cin>> gs;
            car.fuel(gs);
            car.show();

        } else if(cmd == "drive"){      // drive the car (loses fuel equal the km )
            int dr { };
            cout<<"drive how many kilometers?\n";
            cin>>dr;
            car.drive(dr);
            car.show();
        } else {
            cout<<"fail: invalid comand\n";
        }
    }
}
