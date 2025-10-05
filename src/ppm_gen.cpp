#include "vec3.h"
#include "color.h"

#include <iostream>

int main(){
	const float aspect_ratio = 16.0/9.0;
	const int image_width  = 700;
	const int image_height = int(image_width/aspect_ratio);

	const float viewport_height = 2.0;
	const float viewport_width  = viewport_height * (double(image_width)/image_height);

	std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

	for (int i = 0; i < image_height; i++){
		std::clog << "\rScanLines remaining: " << (image_height - i) << " " << std::flush; 
		for (int j = 0; j < image_width; j++){
			auto pixel_color = Color(double(j)/(image_width - 1), double(i)/(image_height - 1),0);
			write_color(std::cout, pixel_color);
		}
	}
	std::clog << "\rDone.                               \n";
}
