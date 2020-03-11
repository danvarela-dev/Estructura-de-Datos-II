#include <iostream>
#include <string>
#include <fstream>

using namespace std;
#pragma warning(disable : 4996)

void wc(char c, string filename) {

	ifstream myfile;
	int contWords = 0, contChars = 0;

	myfile.open(filename, ios::in);

	if (!myfile)
	{
		cerr << "Error reading file..." << endl;
		return;
	}



	myfile.seekg(0, ios::end);
	const int fileSize = myfile.tellg();
	myfile.seekg(0, ios::beg);


	char* buffer = new char[fileSize];


	myfile.read(buffer, fileSize);
	buffer[fileSize] = 0;

	for (int i = 0; i < fileSize; i++)
	{
		if (buffer[i] == c) {
			contChars++;
		}
	}


	myfile.close();

	cout << contChars;
}

void wc2(string w, string filename) {

	ifstream myfile;
	string str;
	int contWords = 0;
	
	myfile.open(filename, ios::in);

	if (!myfile)
	{
		cerr << "Error reading file..." << endl;
		return;
	}



	myfile.seekg(0, ios::end);
	const int fileSize = myfile.tellg();
	myfile.seekg(0, ios::beg);


	char* buffer = new char[fileSize];


	myfile.read(buffer, fileSize);
	buffer[fileSize] = 0;

	int x = 0;
	for (int i = 0; i < fileSize; i++) {	
			str += buffer[i];
			if (buffer[i] == ' ' || buffer[i] == '\n') {
				if (str == w) contWords++;
				str = "";
			}
	}


	

	myfile.close();
	cout << contWords;
}

void grep(string str, string filename) {
	ifstream file;
	file.open(filename, ios::in);

	string line;
	string whole;

	
	while (getline(file, line))
	{

		if (line.find(str) != string::npos) whole += line += '\n';
	}
	
	cout << whole;


	file.close();


}


int main(int argc, char** argv) {

	//string option = argv[1];

	if (argc > 2) {
		string a = argv[2];

		if (a == "-c")
			wc('a', "file.txt");





		/*grep(argv[1], argv[2]);*/



	}
}