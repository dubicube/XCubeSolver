#ifndef CUBE_H
#define CUBE_H


class Block {
private:
    int id;
    int ori;
public:
    Block();
    Block(int new_id, int new_or);
    int getID();
    int getORI();
};

class Cube {
private:
    int dim;
    Block* corners;
    Block* edges;
    Block* centers;
public:
    Cube();
    Cube(int new_dim);
    ~Cube();
    int getDim();
};

#endif
