//Karagiannis Stefanos 3150057
//Morfiadakis Emmanouil 3150112
#include "stdafx.h"
#include"FilterBlur.h"
	FilterBlur::FilterBlur(int N) {
		this-> N = N;
	}
	FilterBlur::FilterBlur() {

	}
	int FilterBlur::getN() {
		return N;
	}
	  Image FilterBlur::operator <<(const Image &image) {
		Image im(image);
		for (int j = 0; j < im.getHeight(); j++) {
			for (int i = 0; i < im.getWidth(); i++) {
				Vec3<float> v;
				for (int m =-N/2; m<N/2+1; m++){
					for (int n = -N/2; n<N/2+1; n++) {
						if (n + j < im.getHeight() && m + i < im.getWidth() && n + j >= 0 && m + i >= 0) {
							v = v + image(m+i,n+j)*1/(N*N);
						}
					
					}
				}
				v=v.clampToLowerBound(0);
				v=v.clampToUpperBound(1);
				im.setPixel(i, j, v);
			}	
		}
		return im;
	}
