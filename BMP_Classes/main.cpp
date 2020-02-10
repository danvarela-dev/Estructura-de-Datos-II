#include "BMP.h"
int main() {
	MyBitmap A;
	A.openBMP("m.BMP");
	A.print_metaData();
}
