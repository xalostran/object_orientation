//
//  figure.hpp
//  figure
//
//  Created by Stran Rasoul on 2023-12-05.
//

#ifndef Figure_hpp
#define Figure_hpp

#include <stdio.h>
#include <iostream>
#include <exception>

using namespace std;

class Color{
    
};

class Figure{
protected:
    int x, y;
    Color c;
public:
    Figure(int nx, int ny, Color nc)
    : x(nx), y(ny), c(nc)
    {}
    
    virtual void move(int nx, int ny){
        x = nx; y = ny;
    }
    virtual void draw() = 0;
};

class Line : public Figure{
    int length;
    double angle;
    
public:
    Line(int x, int y, Color c, int length, double angle)
    : Figure(x, y, c), length(length), angle(angle)
    {}
    Line()
        : Figure(0, 0, Color()), length(1), angle(0.0)
    {}
    int getLenght() {return length;}
    
    void draw(){
        cout<< "Line drawn:"<< " pos = "<< Figure::x<< "/"<< y
        << " length = "<< length<< " angle = "<< angle<< endl;
    }
};

class Circle : public Figure{
    double radius;
    
public:
    Circle(int x, int y, Color c, int radius)
        : Figure(x, y, c), radius(radius)
    {}
    Circle()
        : Figure(0, 0, Color()), radius(10)
    {}
    void move(int nx, int ny) override{
        if (nx < 0 || ny < 0) {
            throw invalid_argument("Circle x or y < 0");
        }
        else
            Figure::move(nx, ny);
        
    }
    void draw() override{
        cout<< "Circle drawn:" << " pos = " << x << "/" << y <<" radius = "<< radius <<endl;
    }
};
#endif /* Figure_hpp */

