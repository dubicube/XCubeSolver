#include <iostream>
#include "cube.h"

Block::Block() {
    id = -1;
    orientation = -1;
}
Block::Block(int new_id, int new_orientation) {
    id = new_id;
    orientation = new_orientation;
}
int Block::getID() {
    return id;
}
int Block::getOrientation() {
    return orientation;
}

Cube::Cube() {
    dimension = 0;
    corners = NULL;
    edges = NULL;
    centers = NULL;
}
Cube::Cube(int new_dimension) {
    dimension = new_dimension;

    nbrCorner = 4;
    nbrEdge = 12*(dimension-2);
    nbrCenter = (dimension-2)*(dimension-2);

    corners = new Block[nbrCorner*sizeof(Block)];
    edges = new Block[nbrEdge*sizeof(Block)];
    centers = new Block[nbrCenter*sizeof(Block)];

    baseIDCorner = 0;
    baseIDEdge = 8;
    baseIDCenter = 12*(dimension-2);
}
Cube::~Cube() {
    if (dimension > 0) {
        delete[] corners;
        delete[] edges;
        delete[] centers;
    }
}

void Cube::init() {
    for (int i = 0; i < nbrCorner; i++) {
        corners[i] = Block(i+baseIDCorner, 0);
    }
    for (int i = 0; i < nbrEdge; i++) {
        corners[i] = Block(i+baseIDEdge, 0);
    }
    for (int i = 0; i < nbrCenter; i++) {
        corners[i] = Block(i+baseIDCenter, 0);
    }
}

int Cube::getDimension() {
    return dimension;
}

//0 UP
//1 DWON
//2 RIGHT
//3 LEFT
//4 FRONT
//5 BACK

void Cube::move(Cube c, int axe, int side, int layer, int direction) {
}
