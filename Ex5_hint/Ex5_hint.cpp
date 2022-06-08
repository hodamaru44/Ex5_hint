#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

/// <summary>
/// 物体の定義
/// </summary>
template<class T> class Solid {
public:
    virtual T  GetVolume() = 0;
    virtual T  GetSurface() = 0;
};

/// <summary>
/// 箱型
/// </summary>
template<class T> class Box :Solid<T> {
private:
    T width;
    T height;
    T depth;

public:
    Box(
        T width,   //幅
        T height,  //高さ
        T depth) {//奥行
        this->width = width;
        this->height = height;
        this->depth = depth;
    }
    T  GetVolume() {
        return width * height * depth;
    }
    T GetSurface() {
        return (width * height + height * depth + depth * width) * 2;
    }


};

template<class T> class Cone :Solid<T> {
private:
    T radius;
    T height;
    T busline;
 
public:
    Cone(double radius, double height,double busline) {
        this->radius = radius;//半径
        this->height = height;//高さ
        this->busline = busline;//母線
    }
    T GetVolume() {
        return radius*radius* M_PI*height*1/3;
    }
    T GetSurface() {
        return M_PI*radius*(busline+radius);
    }
};
template<class T> class  Cylinder :Solid<T> {
private:
    T rabius;//半径
    T heught;//高さ
public:
    Cylinder(double rabius,double heught) {
        this->rabius = rabius;
        this->heught = heught;
    }
    T GetVolume() {
        return rabius * rabius * M_PI * heught ;
    }
    T GetSurface() {
        return 2*M_PI*rabius*(heught+rabius);
    }
};

template<class T> class Sphere :Solid<T> {
private:
    T rabius;//半径
public:
    Sphere(double rabius) {
        this->rabius = rabius;
    }
    T GetVolume() {
        return 4/3*M_PI*rabius*rabius*rabius;
    }
    T GetSurface() {
        return 4*M_PI*rabius*rabius;
    }
};

int main()
{
    Box<double> box{ 3,5,2.5 };
    cout << "boxの体積=" << box.GetVolume() << endl;
    cout << "boxの表面積=" << box.GetSurface() << endl;
    Cone<double> cone{ 3,2.5,5 };
    cout << " Coneの体積="<< cone.GetVolume() << endl;
    cout << " Coneの表面積=" << cone.GetSurface() << endl;
    Cylinder<double> cylinder{ 3,2.5 };
    cout << "Cylinderの体積=" << cylinder.GetVolume() << endl;
    cout << "Cylinderの表面積=" << cylinder.GetSurface() << endl;
    Sphere<double> sphere{ 3 };
    cout << " Sphereの体積=" << sphere.GetVolume() << endl;
    cout << " Sphereの表面積=" << sphere.GetSurface() << endl;
}