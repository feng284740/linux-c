#include <stdio.h>
#include <math.h>

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt((x2-x1) * (x2-x1) + (y2-y1) * (y2-y1));
}

double area(double radius)
{
    return 3.1416 * radius * radius;
}
int main(void)
{
    double radius = distance(1.0, 2.0, 4.0, 6.0);
    double result = area(radius);
    printf("result is %f\n",radius);
    printf("result is %f\n",result);
    return 0;
}
