//Karagiannis Stefanos 3150057
//Morfiadakis Emmanouil 3150112
#ifndef FLA
#define FLA
#include"FilterBlur.h"
class FilterLaplace :public FilterBlur {
public:
	Image operator <<(const Image &image);
	
};
#endif