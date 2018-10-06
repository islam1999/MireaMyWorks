//
// Created by khitr on 24.02.2018.
//

#include "Tiles.h"

Tiles::Tiles(string brand, int size_h, int size_w, int price) {
    this->brand = brand;
    this->size_h = size_h;
    this->size_w = size_w;
    this->price = price;
}
Tiles::Tiles(){
    this->brand = "";
    this->size_h = 0;
    this->size_w = 0;
    this->price = 0;
}
Tiles::~Tiles() = default;

void Tiles::getData() {
    cout <<
         "brand: " << brand << endl <<
         "size_h: " << size_h << endl <<
         "size_w: " << size_w << endl <<
         "price: " << price << endl;
}