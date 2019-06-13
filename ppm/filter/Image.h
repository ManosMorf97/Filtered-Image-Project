//Karagiannis Stefanos 3150057
//Morfiadakis Emmanouil 3150112
#ifndef IMAGE
#define IMAGE
#include"Array.h"
#include"ppm/ppm.h"
#include<string>
namespace math{
class Image:virtual public  Array<Vec3<float>>{
public:
	Image(unsigned int w, unsigned int h);
	Image();
	bool load(const std::string & filename, const std::string & format);
	bool save(const std::string & filename, const std::string & format);
};
}
#endif