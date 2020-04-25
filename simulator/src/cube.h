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

    // Rotate block, according to type and move
    void rotate(int type, int axe, int angle);
private:
};

class Cube {
private:
    int dimension;
    Block* blocks;
    int nbrBlock;
public:
    Cube();
    Cube(int new_dimension);
    ~Cube();
    int getDimension();
    void init();
    void move(Cube* c, int axe, int layer, int angle);
    void aff();
private:

    // Rotate in 2D a coord to a new coord
    // Angle is 0, 1, 2, or 3
    void rotate(int xs, int ys, int angle, int* xe, int* ye);

    // 0 -> in the cube
    // 1 -> face
    // 2 -> edge
    // 3 -> corner
    int getBlockType(int x, int y, int z);
};

#endif
