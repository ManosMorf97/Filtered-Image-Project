//Karagiannis Stefanos 3150057
//Morfiadakis Emmanouil 3150112
#ifndef FB
#define FB
#include"Filter.h"
using namespace math;
class FilterBlur :virtual public Filter, virtual public Array<float> {
private:
	int N;
public:
	FilterBlur(int N);

	FilterBlur();

	int getN();

	virtual Image operator <<(const Image &image);
};
#endif