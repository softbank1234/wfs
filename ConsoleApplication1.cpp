// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <math.h>

#include <xuexi.h>

#define PI 3.1415926535  //圆周率
#define RADIAN_ANGLE_TRANSFORMATION_CONSTANT 0.0174532925  //角度弧度转换常数




Point::Point(double x[])//构造函数
{
    xofpoint_ = x[0];
    yofpoint_ = x[1];
    zofpoint_ = x[2];

}

double Point::ForDistance(Point x)//输入两点坐标，求距离
{
    double distance = sqrt((x.xofpoint_ - xofpoint_) * (x.xofpoint_ - xofpoint_) + (x.yofpoint_ - yofpoint_) * (x.yofpoint_ - yofpoint_) + (x.zofpoint_ - zofpoint_) * (x.zofpoint_ - zofpoint_));
    return distance;
}

double Vector::GetModuleLength()//计算模长
{
    double a = sqrt(coordinateofvector_[0] * coordinateofvector_[0] + coordinateofvector_[1] * coordinateofvector_[1] + coordinateofvector_[2] * coordinateofvector_[2]);
    return a;
}

Vector::Vector(double x[])//输入向量初值
{
    coordinateofvector_[0] = x[0];
    coordinateofvector_[1] = x[1];
    coordinateofvector_[2] = x[2];

}


void Vector::GetVector(Point x, Point y)//输入两点坐标，求其连线方向单位向量
{
    Vector a;
    a.coordinateofvector_[0] = y.xofpoint_ - x.xofpoint_;
    a.coordinateofvector_[1] = y.yofpoint_ - x.yofpoint_;
    a.coordinateofvector_[2] = y.zofpoint_ - x.zofpoint_;
    double b = a.GetModuleLength();
    coordinateofvector_[0] = a.coordinateofvector_[0] / b;
    coordinateofvector_[1] = a.coordinateofvector_[1] / b;
    coordinateofvector_[2] = a.coordinateofvector_[2] / b;
};

int Vector::GetElevationOfVector()//由方向向量求仰角
{
    double r1 = coordinateofvector_[2] / sqrt(coordinateofvector_[0] * coordinateofvector_[0] + coordinateofvector_[1] * coordinateofvector_[1] + coordinateofvector_[2] * coordinateofvector_[2]);
    double r2 = acos(r1) / RADIAN_ANGLE_TRANSFORMATION_CONSTANT;
    return (int)(r2 + 0.5);
}

int Vector::GetAzimuthOfVector()//由方向向量求方位角
{
    double r2 = atan2(coordinateofvector_[1], coordinateofvector_[0]) / RADIAN_ANGLE_TRANSFORMATION_CONSTANT;
    if (coordinateofvector_[1] < 0)
    {
        r2 = r2 + 360;
    }
    else {
        r2 = r2;
    }
    return  (int)(r2 + 0.5);
}

void Vector::GetNormalVector(Vector a, Vector b)//求法向向量
{
    Vector n;
    n.coordinateofvector_[0] = a.coordinateofvector_[1] * b.coordinateofvector_[2] - a.coordinateofvector_[2] * b.coordinateofvector_[1];
    n.coordinateofvector_[1] = a.coordinateofvector_[2] * b.coordinateofvector_[0] - a.coordinateofvector_[0] * b.coordinateofvector_[2];
    n.coordinateofvector_[2] = a.coordinateofvector_[0] * b.coordinateofvector_[1] - a.coordinateofvector_[1] * b.coordinateofvector_[0];
}


double Vector::GetVectorMultiplied(Vector a, Vector b)//求点乘
{
    double c = a.coordinateofvector_[0] * b.coordinateofvector_[0] + a.coordinateofvector_[1] * b.coordinateofvector_[1] + a.coordinateofvector_[2] * b.coordinateofvector_[2];
    return  c;
};


int main()
{
    double dot_1[3] = { 0,1,1 }; //发射点
    double dot_2[3] = { 0,0,0 }; //反射点
 //   double dot_3[3] = { 1,0,0 }; double dot_4[3] = { 0,1,0 }; double dot_5[3] = { 0,0,1 };  //三点共面
    Vector vector21, vector12, vector34, vector35, vectorN;
    vector21.GetVector(dot_2, dot_1);///求 反射到发射点的向量
    vector12.GetVector(dot_1, dot_2);
/*
    vector34.GetVector(dot_3, dot_4);
    vector35.GetVector(dot_3, dot_5);
    vectorN.GetNormalVector(vector34, vector35);
 */
    int yj = vector21.GetElevationOfVector();
    int fwj = vector12.GetAzimuthOfVector();
    printf("方位角是%d，仰角是%d\n", fwj, yj);
    

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
