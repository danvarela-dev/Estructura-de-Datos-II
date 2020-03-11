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
			if (buffer[i] == ' ') {
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

	
		/*if (argv[2] == "-c")
			wc((char)argv[3], argv[4]);
		if (argv[2] == "-w")
			wc2(argv[3], argv[4]);*/
	//wc('m', "file.txt");
	wc2("mundo", "file.txt"); 

	
	/*	grep(argv[2], argv[3]);
	*/
	
	


}