#include "Point.hpp"

/* A utility function to calculate area of triangle formed by (x1, y1),
   (x2, y2) and (x3, y3) */
float area(Point a, Point b, Point c)
{
   return std::abs((a.getXv()*(b.getYv()-c.getYv()) + 
                b.getXv()*(c.getYv()-a.getYv())+ 
                c.getXv()*(a.getYv()-b.getYv()))/2.0);
}
  
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    /* Calculate area of triangle ABC */
   float ABC = area (a,b,c);
  
   /* Calculate area of triangle PBC */ 
   float PBC = area (point, b, c);
 
   /* Calculate area of triangle PAC */ 
   float PAC = area (point, a, c);

   /* Calculate area of triangle PAB */  
   float PAB = area (point, a, b);

   return (ABC == PBC + PAC + PAB);
}