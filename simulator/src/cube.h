#ifndef CUBE_H
#define CUBE_H


class Block {
private:
    int id;
    int orientation;
public:
    Block();
    Block(int new_id, int new_orientation);
    int getID();
    int getOrientation();
};

class Cube {
private:
    int dimension;
    Block* corners;
    Block* edges;
    Block* centers;
    int baseIDCorner, baseIDEdge, baseIDCenter;
    int nbrCorner, nbrEdge, nbrCenter;
public:
    Cube();
    Cube(int new_dimension);
    ~Cube();
    int getDimension();
    void init();
    void move(Cube c, int axe, int side, int layer, int direction);
private:
};

#endif
