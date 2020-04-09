#include <iostream>
#include "cube.h"

Block::Block() {
    id = -1;
    ori = -1;
}
Block::Block(int new_id, int new_ori) {
    id = new_id;
    ori = new_ori;
}
int Block::getID() {
    return id;
}
int Block::getORI() {
    return ori;
}

Cube::Cube() {
    dim = 0;
    corners = NULL;
    edges = NULL;
    centers = NULL;
}
Cube::Cube(int new_dim) {
    dim = new_dim;
    corners = new Block[4*sizeof(Block)];
    edges = new Block[12*(dim-2)*sizeof(Block)];
    centers = new Block[(dim-2)*(dim-2)*sizeof(Block)];
}
Cube::~Cube() {
    if (dim > 0) {
        delete[] corners;
        delete[] edges;
        delete[] centers;
    }
}

int Cube::getDim() {
    return dim;
}
