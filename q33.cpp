#include <simplecpp>
#include <stdlib.h> 
#include <time.h>   


void drawGrid() {
    int gridSize = 10, squareSize = 50;
    for (int i = 0; i <= gridSize; i++) {
        Line l1(i * squareSize, 0, i * squareSize, gridSize * squareSize);
        l1.imprint();
        Line l2(0, i * squareSize, gridSize * squareSize, i * squareSize);
        l2.imprint();
    }
}

int main() {
    initCanvas("Moving Across Grid", 500, 500);
    drawGrid();

    Circle c(25, 25, 20); // Starting position

    srand(time(0));

    int dx = 10, dy = 0; // Initial direction

    while (true) {
        c.move(dx, dy);
        wait(0.05);

        
        if (((int)c.getX() % 50 == 25) && ((int)c.getY() % 50 == 25)) {
            int direction = rand() % 4; 
            switch (direction) {
                case 0: dx = 0; dy = -10; break;
                case 1: dx = 10; dy = 0; break;
                case 2: dx = 0; dy = 10; break;
                case 3: dx = -10; dy = 0; break;
            }
        }


        if (c.getX() < 0 || c.getX() > 500 || c.getY() < 0 || c.getY() > 500) {
            dx = -dx;
            dy = -dy;
        }
    }
}