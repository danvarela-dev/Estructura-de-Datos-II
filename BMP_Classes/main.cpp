#include "BMP.h"
int main() {
	MyBitmap A;
	A.openBMP("m.bmp");
	A.print_metaData();
}