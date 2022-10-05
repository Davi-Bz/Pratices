
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <_aux.hpp>
using namespace std;


class Pet{
private:
    int energyMax {0}, hungryMax {0}, cleanMax {0};
    int energy {0}, hungry {0}, clean {0};
    int diamonds {0};
    int age {0};
    bool alive;

    bool testAlive() {
        if (alive){
            return true;
        }
        else {
        std::cout << "fail: pet esta morto" << '\n';
        
        }
    }

    void setHungry(int value) {
        if (value <= 0) {
            hungry = 0;
            std::cout << "fail: pet morreu de fome" << '\n';
            alive = false;
        } else if (value > hungryMax) {
            hungry = hungryMax;
        } else {
            hungry = value;
        }
    }
    void setEnergy(int value) { //todo
        if(value <= 0){
            energy = 0;
            cout << "fail: pet morreu de fraqueza\n";
            alive = false; 
        }   else if(value > energyMax){
            energy = energyMax; 
        } else {
            energy = value;
        }
    }

    void setClean(int value) { //todo
        if(value <= 0){
            clean = 0;
            cout<< "fail: pet morreu de sujeira\n";
            alive = false;
        } else if(value > cleanMax){
            clean = cleanMax;
        } else {
            clean = value;
        }
    }


public:
    Pet(int energy = 0, int hungry = 0, int clean = 0){
        this->energy = energy;
        this->hungry = hungry;
        this->clean = clean;
        energyMax = energy;
        hungryMax = hungry; 
        cleanMax = clean; 
        
    }

    void play() {
        if (!testAlive())
            return;
        setEnergy(getEnergy() - 2);
        setHungry(getHungry() - 1);
        setClean(getClean() - 3);
        diamonds += 1;
        age += 1;
    }

    void shower() { //todo
         if (!testAlive())
            return;
        setEnergy(getEnergy() - 3);
        setHungry(getHungry() - 1);
        setClean(cleanMax);
        diamonds += 0;
        age += 2;
    }

    void eat() { //todo
         if (!testAlive())
            return;
        setEnergy(getEnergy() - 1);
        setHungry(getHungry() + 4);
        setClean(getClean() - 2);
        diamonds += 0;
        age += 1;

    }

    void sleep() { //todo

        if(!testAlive()){
            return;
        }
        else if (testAlive() && (getEnergy() <= getEnergyMax() - 5)){
             age += (energyMax - getEnergy());
        setEnergy(getEnergyMax());
        setHungry(getHungry() - 1);
        }
        else {
            cout<< "fail: nao esta com sono\n";
        }
    }


    int getClean() {
        return clean;
    }
    int getHungry() {
        return hungry;
    }
    int getEnergy() {
        return energy;
    }
    int getEnergyMax() {
        return energyMax;
    }
    int getCleanMax() {
        return cleanMax;
    }
    int getHungryMax() {
        return hungryMax;
    }

    std::string toString() {
        std::stringstream ss;
        ss <<  "E:" << energy << "/" << energyMax << ", "
           <<  "S:" << hungry << "/" << hungryMax << ", "
           <<  "L:" << clean << "/" << cleanMax << ", "
           <<  "D:" << diamonds << ", " << "I:"  << age;
        return ss.str();
    }

};


int main() {
    aux::Chain chain;
    aux::Param ui;
    Pet pet;
    auto toint = aux::to<int>;
    chain["show"] = [&]() { std::cout << pet.toString() << '\n'; };
    chain["init"] = [&]() { pet = Pet(toint(ui[1]), toint(ui[2]), toint(ui[3])); };
    chain["play"] = [&]() { pet.play(); };
    chain["eat"]  = [&]() { pet.eat(); };
    chain["clean"] =[&]() { pet.shower(); };
    chain["sleep"] =[&]() { pet.sleep(); };
    
    aux::execute(chain, ui);
};