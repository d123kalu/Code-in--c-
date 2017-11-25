#include <cmath>
#include <math.h>
#include "vec2.h"
#include <iostream>
#include <ostream>
using namespace std;

vec2::vec2()
{
   x = 0.0;
   y = 0.0;
}
vec2::vec2(float X , float Y )
{
  x=X;
  y=Y;
}

void vec2::operator*= ( const float s )
{
	x *= s;
	y *= s;
}

float vec2::operator* ( const vec2& v ) const
{
    return (x * v.x + y * v.y);
}

vec2 vec2::operator* ( const float s ) const
{
	return vec2( x * s, y * s );
}

ostream& operator<<(ostream &out,const vec2 &p)
{
  out << "(" << p.x << "," << p.y << ")\n" ;
  return out;
}
