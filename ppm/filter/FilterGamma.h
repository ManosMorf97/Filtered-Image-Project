//Karagiannis Stefanos 3150057
//Morfiadakis Emmanouil 3150112
#ifndef FG
#define FG
#include"Filter.h"
class FilterGamma : virtual public Filter {
private:
	float y;
public:
	float getY();

	FilterGamma(float y);

	Image operator <<(const Image &image);

	FilterGamma();

	FilterGamma(FilterGamma& f);

	FilterGamma operator=(FilterGamma& f);

	Vec3<float> POW(Vec3<float>a, float y);
};
#endif