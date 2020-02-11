#include "BMP.h"
int main() {
	MyBitmap A;
	A.openBMP("BLU.BMP");
	A.print_metaData();

}
