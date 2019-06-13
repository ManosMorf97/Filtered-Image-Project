//Karagiannis Stefanos 3150057
//Morfiadakis Emmanouil 3150112
#include "stdafx.h"
#include"FilterLinear.h"

	Vec3<float> FilterLinear::getA() {
		return a;
	}

	Vec3<float> FilterLinear::getC() {
		return c;
	}
	FilterLinear::FilterLinear(Vec3<float>a, Vec3<float>c) {
		this->a = a;
		this->c = c;
	}
	 Image FilterLinear::operator <<(const Image &image) {
		unsigned int w = image.getWidth();
		unsigned int h = image.getHeight();
		Vec3<float> v3;
		Image im(image);
		for (int j = 0; j < h; j++) {
			for (int i = 0; i < w; i++) {
				v3 = a*image(i, j);
				v3 += c;
				v3=v3.clampToLowerBound(0);
				v3=v3.clampToUpperBound(1);
				im.setPixel(i, j, v3);
			}
		}
		return im;
		


	}
	FilterLinear::FilterLinear() {
	
	}
	FilterLinear::FilterLinear(FilterLinear& f) {
		a = f.getA();
		c = f.getC();
	}

	FilterLinear FilterLinear::operator=(FilterLinear& f) {
		a = f.getA();
		c = f.getC();
		return *this;
	}



