#include <simplecpp>

main_program {
    initCanvas("question3", 800, 600);  
    double x = 100, y= 100, width = 50, height = 50, dx = 5, dy = 5;

    Rectangle box(x, y, width, height);
    box.setColor(COLOR("red"));
    box.setFill(true);

    repeat(1000) {
        box.move(dx, dy);
        x = box.getX();
        y = box.getY();
        if (x + width/2 >= 800 || x - width/2 <= 0) {
            dx = -dx; 
            box.setColor(COLOR(rand()%256, rand()%256, rand()%256)); 
        }
        if (y + height/2 >= 600 || y - height/2 <= 0) {
            dy = -dy; 
            box.setColor(COLOR(rand()%256, rand()%256, rand()%256)); 
        }
 
        wait(0.05);
    }

    return 0;
}
