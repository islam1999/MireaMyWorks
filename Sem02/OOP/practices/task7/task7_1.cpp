//
//  main.cpp
//  practiceOOP
//
//  Created by MacBook Air on 31.03.2018.
//  Copyright © 2018 MacBook Air. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

class Animal {
protected:
    string name;
    string owner;
public:
    Animal(string name, string owner) {
        this->name = name;
        this->owner = owner;
    }
    ~ Animal() {}
    
    void changeOwner(string newOwnerName) {
        owner = newOwnerName;
    }
    void displayAnimalOwner() {
        cout << name << "'s owner is " << owner << "." << endl;
    }
    virtual void animalSound() {
        cout << "Animals sounds different" << endl;
    }
};

class Cat : public Animal {
private:
    string favoriteToy;
public:
    Cat(string name, string owner): Animal(name,owner) {}
    ~ Cat() {}
    
    void setFavoriteToy(string toy) {
        favoriteToy = toy;
        displayFavoriteToy();
    }
    void displayFavoriteToy() {
        cout << name << "'s favorite toy is " << favoriteToy << "." << endl;
    }
    void animalSound() override {
        cout << "meow-meow" << endl;
    }
};

class Dog : public Animal {
private:
    string favoritePlace;
public:
    Dog(string name, string owner): Animal(name,owner) {}
    ~ Dog() {}
    
    void setFavoritePlace(string place) {
        favoritePlace = place;
        displayFavoritePlace();
    }
    void displayFavoritePlace() {
        cout << name << "'s favorite place to walk is " << favoritePlace << "." << endl;
    }
    void animalSound() override {
        cout << "woof-woof" << endl;
    }
};

class Parrot : public Animal {
private:
    double flyingHeight;
public:
    Parrot(string name, string owner): Animal(name,owner) {}
    ~ Parrot() {}
    
    void setFlyingHeight(double height) {
        flyingHeight = height;
        displayFlyingHeight();
    }
    void displayFlyingHeight() {
        cout << name << "'s max fly hight is " << flyingHeight << "." << endl;
    }
    
    void animalSound() override {
        cout << "Prrrrivettt!" << endl;
    }
};

class Human {
public:
    void beckonAnimal(Animal *sound) {
        cout << "Human beckon an animal: ";
        sound->animalSound();
    }
};

int main() {
    //create a cat
    Cat cat("Murka","Boris");
    cat.changeOwner("Volodya");
    cat.displayAnimalOwner();
    cat.setFavoriteToy("mouse");
    
    Human owner;
    owner.beckonAnimal(&cat);
    
    return 0;
}











