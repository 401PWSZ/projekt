#include <iostream>  //bridge
using namespace std;

class DP1 {
    public:
        void draw_a_line() {
            cout << "Linia V1" << endl;
        }
        void draw_a_circle() {
            cout << "Okrag V1" << endl;
        }
};

class DP2 {
    public:
        void drawline() {
            cout << "Linia V2" << endl;
        }
        void drawcircle() {
            cout << "Okrag V2" << endl;
        }
};

class Drawing {
    public:
        virtual void drawLine() = 0;
        virtual void drawCircle() = 0;
        virtual ~Drawing() { }
};

class Shape {
    public:
        Shape( Drawing *p ) : ptr{p} { }
        virtual ~Shape() { }
        virtual void draw() = 0;
        void setlib( Drawing* p) { ptr = p; }
    protected:
        void drawLine() { ptr->drawLine(); }
        void drawCircle() { ptr->drawCircle(); }
    private:
        Drawing* ptr { nullptr };
};

class Circle : public Shape {
    public:
        using Shape::Shape; //wygeneruj konstruktor Circle na wzor Shape
        void draw() {
            cout << "Circle ";
            drawCircle();
        }
};

class Rectangle : public Shape {
    public:
        using Shape::Shape; //wygeneruj konstruktor Rectangle na wzor Shape
        void draw() {
            cout << "Prostokat ";
            drawLine();
        }
};

class V1Drawing : public Drawing {
    public:
        V1Drawing( DP1& r ) : ref(r) { }
        void drawLine() {
            ref.draw_a_line();
        }
        void drawCircle() {
            ref.draw_a_circle();
        }
    private:
        DP1& ref;
};

class V2Drawing : public Drawing {
    public:
        V2Drawing( DP2& r ) : ref(r) { }
        void drawLine() {
            ref.drawline();
        }
        void drawCircle() {
            ref.drawcircle();
        }
    private:
        DP2& ref;
};
int main() {
    
    DP1 library1; // pierwsza biblioteka graficzna
    DP2 library2; // druga biblioteka graficzna

    Drawing *d1 = new V1Drawing( library1 );
    Drawing *d2 = new V2Drawing( library2 );

    Shape *p1 = new Rectangle( d1 );
    Shape *p2 = new Circle( d2 );

    p1->draw(); // rectangle line V1
    p2->draw(); // circle line V2
    p1->setlib( d2 );
    p2->setlib( d1 );
    p1->draw(); // rectangle line V2
    p2->draw(); // circle line V1

    delete p1;
    delete p2;
    delete d1;
    delete d2;
    
}
