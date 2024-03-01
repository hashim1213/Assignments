#include <simplecpp>
main_program {
    initCanvas("Square Spiral", 800, 600);
    Turtle t;
    t.penUp();
    t.moveTo(400, 300); // Start at center
    t.penDown();
    double side = 10; // Initial side length

    for (int i = 0; i < 50; ++i) { // Adjust iterations for spiral size
        t.forward(side);
        t.right(90);
        if (i % 4 == 3) side += 10; // Increase side length after completing a square
    }
    getClick();
    closeCanvas();
    return 0;
}
