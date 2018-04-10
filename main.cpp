#include "tgaimage.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);

// Lecture 1: draw a line between two points
void line(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor color);

int main(int argc, char** argv) {
	TGAImage image(100, 100, TGAImage::RGB);
	
    /* "Rendering" commands */
    line(5, 90, 90, 70, image, white);

	image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
	image.write_tga_file("output.tga");
	return 0;
}

void line(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor color) {
    for (float t = 0; t < 1; t += 0.01) {
        int x = x0 * (1 - t) + x1 * t;
        int y = y0 * (1 - t) + y1 * t;
        image.set(x, y, color);
    }
}

