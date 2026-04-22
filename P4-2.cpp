#include <iostream>
#include <cmath>
using namespace std;

class Point {
    int x, y;

public:
    Point(int a = 0, int b = 0) {
        x = a;
        y = b;
    }

    Point& move(int dx, int dy) {
        x += dx;
        y += dy;
        return *this;
    }

    void display() {
        cout << "(" << x << "," << y << ")" << endl;
    }

    double distance() {
        return sqrt(x * x + y * y);
    }

    void set(int a, int b) {
        x = a;
        y = b;
    }

    friend void reset(Point* p);
};

void reset(Point* p) {
    p->set(0, 0);
}

int main() {
    Point p(1, 2);

    p.move(2, 3).move(-1, 4).move(5, -2);
    p.display();

    reset(&p);
    p.display();

    cout << p.distance() << endl;

    return 0;
}