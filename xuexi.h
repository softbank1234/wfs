#pragma once

class Point
{
public:
    double xofpoint_;
    double yofpoint_;
    double zofpoint_;//�������

    Point() {};
    Point(double x[]);//���캯��

    double ForDistance(Point x);//����һ��͸õ�֮��ľ���
}; 

class Vector
{
public:
    double coordinateofvector_[3];//����������

    Vector() {};
    Vector(double x[]);//���캯��

    double operator*(const Vector& v1)
    {
        double a;
        a = coordinateofvector_[0] * v1.coordinateofvector_[0] + v1.coordinateofvector_[1] * coordinateofvector_[1] + v1.coordinateofvector_[2] * coordinateofvector_[2];
    };
    double GetModuleLength();//����ģ��
    double GetIncludedAngle(Vector x);//����һ�����������֪һ�������ļнǣ�����0-PI����ֵ
    void GetVector(Point x, Point y); //�����������꣬�������߷���λ����
    int GetAzimuthOfVector();//��������ķ�λ��
    int GetElevationOfVector();//��ķ�λ��
    double GetVectorMultiplied(Vector a, Vector b);////����
    void GetNormalVector(Vector a, Vector b);//��������
};
