#include <simplecpp>
main_program{
    initCanvas("question 2", 500, 500);
    //circle 
    int x = 400, y = 400, radius = 50, dy = 5;
    
    Circle circle (x,y, radius);
    for (int i = 0; i < 100; i++){
        circle.move(0, dy);
        wait(0.1);
         if (y + dy > 600 - radius || y + dy < radius) {
            dy = -dy;
        }
        y+= dy;

    }
    
    return 0;
}