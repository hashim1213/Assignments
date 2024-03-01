#include <simplecpp>

main_program {
    initCanvas("Interactive Rectangle Resizing", 800, 600);
    double x = 400, y = 300, width = 100, height = 50;
    Rectangle r(x, y, width, height);


    while (true) {
        XEvent event;
        nextEvent(event); 
        if (checkEvent(event) && keyPressEvent(event)) { 
            char key = charFromEvent(event); 
            if (key == 'w' || key == 'W') {
                width += 10; 
                r.reset(x, y, width, height); 
            } else if (key == 'n' || key == 'N') {
                if (width > 10) { 
                    width -= 10; 
                    r.reset(x, y, width, height); 
                }
            }
        }
    }

   
}
