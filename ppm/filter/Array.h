//Karagiannis Stefanos 3150057
//Morfiadakis Emmanouil 3150112
#ifndef _Array_
#define _Array_
#include"Vec3.h"
#include <vector>
#include<cstddef>

namespace math{
	
	template<typename T>
	class Array{

		
		   protected:
		   std::vector<T> buffer;
		   unsigned int width,height;
		   
		   public:
		   
		   /*! Returns the width of the image
		 */
		   const unsigned int getWidth() const {return width;}      
		
		/*! Returns the height of the image
		 */
		const unsigned int getHeight() const {return height;} 
		
		std::vector<T> getVector()const {
			return buffer;
		}

		void setData(const T * & data_ptr) {
			if (buffer.size()>0)
				buffer.clear();
			for (int i = 0; i<width*height; i++)
				buffer.push_back(data_ptr[i]);
		}
		


		void setPixel(unsigned int x, unsigned int y, T c){
			buffer[x + width * y] = c;
		}
		
		Array() {
			width = 0;
			height = 0;
		}
		 
	
       
		Array(unsigned int width, unsigned int height) {
			this->height = height;
			this->width = width;
		}

		Array(const Array &right) {
			this->height = right.getHeight();
			this->width = right.getWidth();
			for (int j = 0; j<height; j++)
				for (int i = 0; i<width; i++)
					buffer.push_back(right(i, j));
		}

		Array& operator = (const Array & right) {
			this->height = right.getHeight();
			this->width = right.getWidth();
			if (buffer.size() > 0)
				this->buffer.clear();
			for (int j = 0; j<height; j++)
				for (int i = 0; i<width; i++)
					buffer.push_back(right(i, j));
			return *this;
		}
	
		
		T operator()(unsigned int x, unsigned int y)const {
			return buffer[x + width * y];
		}
	  	
		 
	};
	
	
	
	
	
	
}
#endif