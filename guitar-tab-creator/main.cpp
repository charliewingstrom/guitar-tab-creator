#include <iostream>
#include <fstream>
#include "Fretboard.h"
#include <string>
using namespace std;


int main() {
	cout << "Welcome to guitar tab creator" << endl;

	Fretboard* f = new Fretboard();

	
	fstream file;
	ofstream outfile;

	string inFilename = "input.txt";
	string outFilename = "output.txt";

	char* noteLetter = new char[2];
	char* octave = new char;

	int stringNo;
	int fretNo;

	file.open(inFilename.c_str());
	outfile.open(outFilename.c_str());
	
	Note* tmpNote;
	while (file >> noteLetter)
	{
		printf("------------------- NOTE -----------------------\n");
		file >> octave;
		printf("noteLetter: %s\n", noteLetter);
		printf("noteOctave: %s\n", octave);

		int oct = stoi(octave);
		tmpNote = new Note(noteLetter, oct);
		f->getNotePositionInRange(stringNo, fretNo, tmpNote, 0, 5);

		printf("string number: %d\n", stringNo);
		printf("fret number: %d\n", fretNo);
		delete tmpNote;

	}
	outfile << "Heres some output";
	file.close();
	outfile.close();
	delete f;
}