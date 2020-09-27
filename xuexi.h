#pragma once

class Point
{
public:
    double xofpoint_;
    double yofpoint_;
    double zofpoint_;//点的坐标

    Point() {};
    Point(double x[]);//构造函数

    double ForDistance(Point x);//求另一点和该点之间的距离
}; 

class Vector
{
public:
    double coordinateofvector_[3];//向量的坐标

    Vector() {};
    Vector(double x[]);//构造函数

    double operator*(const Vector& v1)
    {
        double a;
        a = coordinateofvector_[0] * v1.coordinateofvector_[0] + v1.coordinateofvector_[1] * coordinateofvector_[1] + v1.coordinateofvector_[2] * coordinateofvector_[2];
    };
    double GetModuleLength();//计算模长
    double GetIncludedAngle(Vector x);//输入一向量，求和已知一个向量的夹角，返回0-PI弧度值
    void GetVector(Point x, Point y); //输入两点坐标，求其连线方向单位向量
    int GetAzimuthOfVector();//求三角面的方位角
    int GetElevationOfVector();//求的方位角
    double GetVectorMultiplied(Vector a, Vector b);////求点乘
    void GetNormalVector(Vector a, Vector b);//求法向向量
};
