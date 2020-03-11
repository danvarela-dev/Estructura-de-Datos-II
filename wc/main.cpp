#include <iostream>
#include <string>
#include <vector>
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


	char* buffer = new char[fileSize];


	myfile.read(buffer, fileSize);
	buffer[fileSize] = 0;

	for (int i = 0; i < fileSize; i++)
	{
		if (buffer[i] == ' ' && buffer[i + 1] != ' ') {
			contWords++;
		}
		else if (buffer[i] == '\n') {
			contNewLines++;

			if (buffer[i + 1] != '\n') {

				contWords++;
			}

		}
		else if ((fileSize - 1) == i) {
			contWords++;
		}
	}

	contChars = fileSize;

	myfile.close();

	cout << contNewLines << "\t" << contWords << "\t" << contChars << "\t" << filename << endl;

}


void tail(int lines, string filename) {


	ifstream myfile;
	int contNewLines = 0;
	char c;
	string line;

	myfile.open(filename, ios::in);

	if (!myfile)
	{
		cerr << "Error reading file..." << endl;
		return;
	}
	myfile.seekg(0, ios::end);
	int size = myfile.tellg();

	int i = 0;
	while (size)
	{
		myfile.seekg(--size, ios::_Seekbeg);
		myfile.get(c);

		if (c == '\n')
		{

			if (contNewLines++ == (lines - 1)) break;
		}

		line = c + line;


		i++;

	}

	
	cout << line;


	myfile.close();

}


int main(int argc, char** argv) {

	//wc("test.txt");
	/*wc(argv[1]);*/

	tail(4, "test0.txt");
}
