using namespace std;
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "cube.h"

int main(int argc, char* argv[]) {
    Cube c0 = Cube(3);
    Cube c1 = Cube(3);
    c0.init();
    c1.init();
    cout << "Cube created with dim = " << c0.getDimension() << endl;
    //c0.aff();
    //c1.aff();
    c0.move(&c1, 2, 0, 3);
    c1.aff();
    //c0.aff();
}
