﻿#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

/// <summary>
/// 物体の定義
/// </summary>
class Solid {
public:
    virtual double GetVolume() = 0;
    virtual double GetSurface() = 0;
};

/// <summary>
/// 箱型
/// </summary>
class Box :Solid {
private:
    double width;
    double height;
    double depth;

public:
    Box(
        double width,   //幅
        double height,  //高さ
        double depth) {//奥行
        this->width = width;
        this->height = height;
        this->depth = depth;
    }
    double GetVolume() {
        return width * height * depth;
    }
    double GetSurface() {
        return (width * height + height * depth + depth * width) * 2;
    }


};

class Cylinder :Solid {
private:
    double radius;
    double height;
    double busline;
 
public:
    Cylinder(double radius, double height,double busline) {
        this->radius = radius;//半径
        this->height = height;//高さ
        this->busline = busline;//母線
    }
    double GetVolume() {
        return radius*radius* M_PI*height*1/3;
    }
    double GetSurface() {
        return M_PI*radius*(busline+radius);
    }
};

int main()
{
    Box box{ 3,5,2.5 };
    cout << "boxの体積=" << box.GetVolume() << endl;
    cout << "boxの表面積=" << box.GetSurface() << endl;
    Cylinder  cylinder{ 3,2.5,5 };
    cout << "Cylinderの体積="<<cylinder.GetVolume() << endl;
    cout << "Cylinderの表面積=" << cylinder.GetSurface() << endl;
}