//Karagiannis Stefanos 3150057
//Morfiadakis Emmanouil 3150112
#ifndef FL
#define LF
#include"Filter.h"
class FilterLinear: virtual public Filter{
private:
	Vec3<float>a;
	Vec3<float>c;
public:
	Vec3<float> getA();

	Vec3<float> getC();

	FilterLinear(Vec3<float>a, Vec3<float>c);

	Image operator <<(const Image &image);

	FilterLinear();

	FilterLinear(FilterLinear& f);

	FilterLinear operator=(FilterLinear& f);


};
#endif