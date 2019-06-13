//Karagiannis Stefanos 3150057
//Morfiadakis Emmanouil 3150112
#include "stdafx.h"
#include"Image.h"
#include"ppm/ppm.h"
#include<string>
using namespace math;
	Image::Image(unsigned int w, unsigned int h) :Array<Vec3<float>>(w, h) {};
	Image::Image() :Array<Vec3<float>>() {};
	bool Image::load(const std::string & filename, const std::string & format) {
	if (strcmp(format.c_str(), "ppm")) {
		return false;
	}
	std::string last = filename + format;
	float *ar = ReadPPM(last.c_str(), (int*)&width, (int*)&height);//width height unsigned int
	if (ar == nullptr) return false;
	if(buffer.size()>0)
	buffer.clear();
	int q=0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			buffer.push_back(Vec3<float>(ar[q], ar[q + 1], ar[q + 2]));
			q+= 3;
		}
	}
	return true;

}
bool Image::save(const std::string & filename, const std::string & format) {
	if (strcmp(format.c_str(), "ppm")) {
		return false;
	}
	int a = 0;
	float *f = new float[3 * width*height];
	for (int j = 0; j <height; j++){
		for (int i = 0; i < width; i++) {
			for (int k = 0; k < 3; k++) {
				f[a] = (*this)(i, j)[k];
				a++;
			}
		}
		}
	std::string fi2 =filename+format;
	return WritePPM(f, width, height, fi2.c_str());
}


