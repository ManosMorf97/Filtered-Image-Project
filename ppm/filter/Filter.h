//Karagiannis Stefanos 3150057
//Morfiadakis Emmanouil 3150112
#ifndef FILTER
#define FILTER
#include "Image.h"
using namespace math;
	class Filter {
	public:
		virtual Image operator <<(const Image &image) = 0;
	};
#endif