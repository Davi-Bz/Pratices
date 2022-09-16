
#include <iostream> 
#include <iomanip>
#include <string>
using namespace std;


class Time{ 
    private:
int hor {0};
int min {0};
int seg {0};

public: 
    Time(int h, int m, int s){

    }

    void setHour(int h){
         if(h >= 0 && h <= 23)
            hor = h;
    } 

    void setMin(int m){
         if(m >= 0 && m <= 59)
            min = m;
    }

    void setSec(int s){
        if(s >= 0 && s <= 59)
            seg = s;
    }

    int getHour(){
        return hor;
    }

    int getMin(){
        return min;
    }

    int getSeg(){
        return seg;
    }

    void set(){
        int h, m, s;
        cin>> h >> m >> s;

        // setHour(h);
        // setMin (m);
        // setSec (s);
        if(h < 0 || h > 23){
            cout<< "hora invalida\n";
            setSec(s);
            setMin (m);
        }
         if(m < 0 || m > 59){
            cout<< "minuto invalido\n";
            setHour(h);
            setSec (s);
        }
         if(s < 0 || s > 59){
            cout<< "segundo invalido\n";
            setHour(h);
            setMin (m);
        } 
        else{
           setHour(h);
           setMin (m);
           setSec (s); 
        }

    }

    void next(){
         seg += 1;
        if(seg > 59){
            min += 1;
            seg = 0;
        } if(min > 59){
            hor += 1;
            min = 0;
        } if(hor > 23){
            hor = 0;
        }
    }

      void show(){
        cout<<std::setfill('0');

        cout<< setw(2) << hor << ":" << setw(2) << min << ":" << setw(2) << seg << endl;

    }

};

    void comand(Time tempo){

    while(true){
    string cmd;
    cin>> cmd;

    if(cmd == "end"){
        cout<<"$end\n";
        break;
    } else if(cmd == "set"){
        cout<<"$set\n";
        tempo.set();
    } else if(cmd == "show"){
        cout<<"$show\n";
        tempo.show();
    }  else if(cmd == "next"){
        cout<<"$next\n";
        tempo.next();
   } else {
    cout<<"fail\n";
   }
 }
}
/*
    set h m s;
    show;
    next;
    end;
*/


int main(){
    Time tempo(0,0,0);

    comand(tempo);
}