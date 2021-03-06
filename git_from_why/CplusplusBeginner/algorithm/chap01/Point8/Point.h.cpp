/**
 * @file   Point.h
 * @author Wang Heyu <wang@wukong>
 * @date   Sat Aug 10 09:23:08 2019
 * 
 * @brief  A class design for points.
 * 
 * 
 */

#ifndef __CRAZYFISH__Point__
#define __CRAZYFISH__Point__

#include <iostream>
#include <vector>

template <int DIM>
class Point
{
private:
    double coordinate[DIM];
public:    
    Point(double x, double y);
    Point(double x, double y, double z);
    double *read();
};

template <int DIM>
Point<DIM>::Point(double x, double y) 
{
    if (DIM != 2)
    {
	std::cerr << "Dimension error!" << std::endl;
	std::exit(-1);
    }
    coordinate[0] = x;
    coordinate[1] = y;
};

template <int DIM>
Point<DIM>::Point(double x, double y, double z) 
{
    if (DIM != 3)
    {
	std::cerr << "Dimension error!" << std::endl;
	std::exit(-1);
    }
    coordinate[0] = x;
    coordinate[1] = y;
    coordinate[2] = z;
};

template <int DIM>
double *Point<DIM>::read()
{
    return (coordinate); 
};
#else

//Do nothing.

#endif

int main(int argc, char *argv[])
{
    Point<2> a(1, 2);
    double *A = a.read();
    A[0] = 3;   // Dangous! Unexpected chances to change the private values!
    std::cout << A[0] << ", " << A[1] << std::endl;
    Point<3> b(1, 2, 3);
    A = b.read();
    std::cout << A[0] << ", " << A[1] << ", " << A[2] << std::endl;
    return 0;
};


