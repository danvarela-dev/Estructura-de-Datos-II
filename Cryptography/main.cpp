#include "program.h"



int main(int argc, char** argv)
{
	
	MyBitmap a;

	string option = argv[1];
	string filename = argv[2];
	string option2;
	string message;
	string fileSrc;
	string fileDest;


	if (option == "-o") {
		
		option2 = argv[3];
		message = argv[4];

		if (option2 == "-m") {
			a.msgEncryptor(filename, message);
		}
		else if (option2 == "-f") {
			fileSrc = argv[4];

			a.msgEncryptorFile(filename, fileSrc);
		}
	}
	else if (option == "-e") {

		if (argc > 3) {
			fileDest = argv[4];
			option2 = argv[3];
			if (option2 == "-f") {
				a.msgDecryptor2File(filename, fileDest);
			}
		}else{
			a.msgDecryptor(filename);
		}

		
		}
	else if(option == "-t"){
		filename = argv[2];
		cout << "Max Alloc is: " << a.getMaxSpace(filename) <<" char(s)" <<endl;
	}
	else if (option == "-v") {
		
		option2 = argv[1];
		filename = argv[2];
		a.validation(filename);

	}


}

