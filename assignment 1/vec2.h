#ifndef _vec2_
#define _vec2_
#include <cmath>
#include <fstream>
#include <ostream>

using namespace std;
class vec2
{
public:
 vec2();
 vec2(float X, float Y);

 friend ostream& operator<<(ostream &out,const vec2 &p);
 float operator* ( const vec2& v ) const;
 void operator*= ( const float s );
 vec2 operator* ( const float s ) const;
private:
 float x;
 float y;
};
#endif
