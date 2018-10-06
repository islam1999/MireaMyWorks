//
// Created by khitr on 24.02.2018.
//

#ifndef LAB3_TILES_H
#define LAB3_TILES_H

#pragma once
#include <iostream>
using namespace std;

class Tiles {
public:
    string brand;
    int size_h;
    int size_w;
    int price;

    Tiles(string brand, int size_h, int size_w, int price);

    Tiles();

    ~Tiles();

    void getData();
};


#endif //LAB3_TILES_H
