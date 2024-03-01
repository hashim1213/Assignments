#include <simplecpp>

main_program {
    initCanvas("question4", 800, 600);

    int radius;
    cout << "Enter radius for circle: ";
    cin >> radius;

    Circle circle(400, 300, radius);

    double side = 50; 
    Rectangle square(400, 300, side, side);

    while (true) {
        int clickPos = getClick();
        int x = clickPos / 65536; 
        int y = clickPos % 65536; 
        square.moveTo(x, y);
    }
    closeCanvas();
    return 0;
}
