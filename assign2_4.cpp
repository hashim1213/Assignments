#include <iostream>
#include <simplecpp>

using namespace std; 

class rectangle {
    public:
        int length;
        int width;

        int area() {
            return length * width;
        }

        int perimeter() {
            return 2 * (length + width);
        }
};
int main (){
    rectangle r1;
cout << "Enter the length of the rectangle: ";
cin >> r1.length;
cout << "Enter the width of the rectangle: ";
cin >> r1.width;

    cout << "Area: " << r1.area() << endl;
    cout << "Perimeter: " << r1.perimeter() << endl;

    return 0;
}