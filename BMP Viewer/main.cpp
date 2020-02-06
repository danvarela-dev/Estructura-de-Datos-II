#include "bmp.h"

int main() {

	Mybitmap bmp;
	bmp.openBMP("m.bmp");
	bmp.printHeader();

}