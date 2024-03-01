#include <simplecpp>

main_program {
    initCanvas("Pattern of Circles", 800, 600);
    const int radius = 20;
    const int spacing = 45;
    int startX = 400, startY = 100; // Initial position for the first circle

    for (int row = 0; row < 5; ++row) {
        for (int col = 0; col <= row; ++col) {
            Circle c(startX + col * spacing - row * spacing / 2, startY + row * spacing, radius);
            c.imprint();
        }
    }
    getClick();
    closeCanvas();
    return 0;
}
