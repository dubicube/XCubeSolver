#include <iostream>
#include "cube.h"

using namespace std;

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
    //blocks = NULL;
}
Cube::Cube(int new_dimension) {
    dimension = new_dimension;

    nbrBlock = dimension*dimension*dimension;
    blocks = new Block[nbrBlock];
}
Cube::~Cube() {
    if (dimension > 0) {
        delete[] blocks;
    }
}

void Cube::init() {
    for (int i = 0; i < nbrBlock; i++) {
        blocks[i] = Block(i, 0);
    }
}

int Cube::getDimension() {
    return dimension;
}


void Block::rotate(int type, int axe, int angle) {
    // Rotate only if angle is odd
    if (angle&1) {
        if (type == 2) { // Edge
            // Always invert between 0 and 1
            orientation = 1-orientation;
        } else if (type == 3) { // Corner
            // This is magic
            if (orientation != axe)
                orientation = 3-axe-orientation;
        }
    }
}

void Cube::rotate(int xs, int ys, int angle, int* xe, int* ye) {
    if (angle == 1) {
        *xe = dimension-1-ys;
        *ye = xs;
    } else if (angle == 2) {
        *xe = dimension-1-xs;
        *ye = dimension-1-ys;
    } else if (angle == 3) {
        *xe = ys;
        *ye = dimension-1-xs;
    } else {
        *xe = xs;
        *ye = ys;
    }
}

int Cube::getBlockType(int x, int y, int z) {
    return (x==0||x==dimension-1)+(y==0||y==dimension-1)+(z==0||z==dimension-1);
}

void Cube::move(Cube* c, int axe, int layer, int angle) {
    int xe, ye;
    for(int xs = 0; xs < dimension; xs++) {
        for(int ys = 0; ys < dimension; ys+=((layer==0||layer==dimension-1||xs==0||xs==dimension-1)?1:dimension-1)) {
            rotate(xs, ys, angle, &xe, &ye);

            int btype = getBlockType(xe, ye, layer); // Independent of axe
            int ptrs, ptre;
            if (axe == 0) {
                ptrs = xs+ys*dimension+layer*dimension*dimension;
                ptre = xe+ye*dimension+layer*dimension*dimension;
            } else if(axe == 1) {
                ptrs = layer+xs*dimension+ys*dimension*dimension;
                ptre = layer+xe*dimension+ye*dimension*dimension;
            } else if (axe == 2) {
                ptrs = ys+layer*dimension+xs*dimension*dimension;
                ptre = ye+layer*dimension+xe*dimension*dimension;
            }
            c->blocks[ptre] = blocks[ptrs];
            c->blocks[ptre].rotate(btype, axe, angle);
        }
    }
}

void Cube::aff() {
    for(int z = 0; z < dimension; z++) {
        for(int y = 0; y < dimension; y++) {
            for(int x = 0; x < dimension; x++) {
                cout << blocks[x+y*dimension+z*dimension*dimension].getID() << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    //*
    for(int z = 0; z < dimension; z++) {
        for(int y = 0; y < dimension; y++) {
            for(int x = 0; x < dimension; x++) {
                cout << blocks[x+y*dimension+z*dimension*dimension].getOrientation() << " ";
            }
            cout << endl;
        }
        cout << endl;
    }//*/
}
