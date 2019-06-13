//Karagiannis Stefanos 3150057
//Morfiadakis Emmanouil 3150112
#include "stdafx.h"
#include"FilterLaplace.h"

	Image FilterLaplace::operator <<(const Image &image) {
		int f[3][3] = { {0,1,0},{1,-4,1},{0,1,0} };
		Image im(image);
		for (int j = 0; j < im.getHeight(); j++) {
			for (int i = 0; i < im.getWidth(); i++) {
				Vec3<float> v;
				for (int m = -1; m < 2; m++) {
					for (int n = -1; n < 2; n++) {
						if (m + i < im.getWidth() && n + j < im.getHeight() && m + i >= 0 && n + j >= 0) {
							v = v + image(m + i, n + j)*f[m + 1][n + 1];
						}
					}
				}
				v=v.clampToUpperBound(1);
				v=v.clampToLowerBound(0);
				im.setPixel(i, j, v);
			}
		}
		return im;
	}
	

