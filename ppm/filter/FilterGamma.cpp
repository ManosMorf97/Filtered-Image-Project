//Karagiannis Stefanos 3150057
//Morfiadakis Emmanouil 3150112
#include "stdafx.h"
#include"FilterGamma.h"
float FilterGamma::getY() {
		return y;
	}

	FilterGamma::FilterGamma(float y) {
		this->y = y;
	}
	 Image FilterGamma::operator <<(const Image &image) {
		unsigned int w = image.getWidth();
		unsigned int h = image.getHeight();
		Image im(image);
		for (int j = 0; j < h; j++)
			for (int i = 0; i < w; i++)
				im.setPixel(i,j,(POW(image(i, j), y)));
		return im;



	}
	FilterGamma::FilterGamma() {

	}
	FilterGamma::FilterGamma(FilterGamma& f) {
		y = f.getY();
	}

	FilterGamma FilterGamma::operator =(FilterGamma& f) {
		y = f.getY();
		return *this;
	}

	Vec3<float> FilterGamma::POW(Vec3<float>a, float y) {
		float f[3];
		for (int i = 0; i < 3; i++)
			f[i] = pow(a[i], y);
		Vec3<float>v(f[0], f[1], f[2]);
		v=v.clampToLowerBound(0);
		v=v.clampToUpperBound(1);
		return v;
	}

