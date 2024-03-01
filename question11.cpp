#include <simplecpp>

void drawBoxWithDashes(int n) {
    for (int i = 0; i < n; i++) {
        cout << "-";
    }
    cout << endl;
    
    for (int i = 0; i < n - 2; i++) {
        cout << "-";
        for (int j = 0; j < n - 2; j++) {
            cout << " ";
        }
        cout << "-" << endl;
    }
    
    for (int i = 0; i < n; i++) {
        cout << "-";
    }
    cout << endl;
}

main_program {
    int size = 5;
    drawBoxWithDashes(size);
}
