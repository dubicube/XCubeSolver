using namespace std;
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "cube.h"

int main(int argc, char* argv[]) {
    Cube c = Cube(3);
    cout << "Cube created with dim = " << c.getDim() << endl;
}
