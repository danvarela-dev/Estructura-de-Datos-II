#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void wc(string filename) {

	ifstream myfile;
	int contWords = 0, contNewLines = 0, contChars = 0;

	myfile.open(filename, ios::in);

	if (!myfile)
	{
		cerr << "Error reading file..." << endl;
		return;
	}

	bool FOUND = 0;

	myfile.seekg(0, ios::end);
	const int fileSize = myfile.tellg();
	myfile.seekg(0, ios::beg);


	char * buffer = new char[fileSize];


	myfile.read(buffer, fileSize);
	buffer[fileSize] = 0;

	for (int i = 0; i < fileSize; i++)
	{
		if (buffer[i] == ' ' && buffer[ i+ 1] != ' ') {
			contWords++;
		}
		else if (buffer[i] == '\n') {
			contNewLines++;

				if (buffer[i + 1] != '\n') {
				
					contWords++;
				}
			
		}
		else if((fileSize - 1) == i){
			contWords++;
		}
	}

	contChars = fileSize;

	myfile.close();

	cout  << contNewLines  << "\t" << contWords  << "\t" << contChars << "\t" << filename << endl;

}


void tail(string lines, string filename) {
}


int main(int argc, char** argv) {

	//wc("test.txt");
	wc(argv[1]);
}
