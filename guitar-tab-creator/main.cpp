#include <iostream>
#include <fstream>
#include <string>

#include "Fretboard.h"
#include "TabbedSong.h"

using namespace std;


int main() {
	cout << "Welcome to guitar tab creator" << endl;

	Fretboard* f = new Fretboard();
	TabbedSong* song = new TabbedSong();
	TabPiece* tmpPiece;

	fstream file;
	ofstream outfile;

	string inFilename = "input.txt";
	string outFilename = "output.txt";

	char* noteLetter = new char[2];
	char* octave = new char;
	char* noteBeat = new char[2];

	int stringNo;
	int fretNo;

	int upperLimit;
	int lowerLimit;
	int prevFret = 9;
	int beat = 0;
	int currNoteBeat;
	file.open(inFilename.c_str());
	outfile.open(outFilename.c_str());
	
	Note* tmpNote;

	// read in each note from the file, add each note to the TabbedSong
	while (file >> noteLetter)
	{
		printf("------------------- NOTE -----------------------\n");
		file >> octave;
		file >> noteBeat;
		printf("noteLetter: %s\n", noteLetter);
		printf("noteOctave: %s\n", octave);
		printf("noteBeat: %s\n", noteBeat);
		int oct = stoi(octave);
		currNoteBeat = stoi(noteBeat);
		tmpNote = new Note(noteLetter, oct);
		
		upperLimit = prevFret;
		lowerLimit = prevFret;

		while (!f->getNotePositionInRange(stringNo, fretNo, tmpNote, lowerLimit, upperLimit))
		{
			if (upperLimit < 22)
				upperLimit++;
			if (lowerLimit > 0)
				lowerLimit--;
		}

		printf("string number: %d\n", stringNo);
		printf("fret number: %d\n", fretNo);

		tmpPiece = new TabPiece(stringNo, fretNo, beat);

		song->AddPieceToSong(tmpPiece);

		delete tmpNote;
		beat += currNoteBeat*2;
		prevFret = fretNo;
	}
	

	// get each note read into the song, then write it out into outfile
	TabPiece* tmp;

	int tmpBeat;
	int beatTo;
	int maxBeat = 512;


	TabPiece* heads[6] = { song->HighEHead, song->BHead, song->GHead, song->DHead, song->AHead, song->LowEHead };
	for (int i = 0; i < 6; i++)
	{
		tmp = heads[i];
		tmpBeat = 0;
		outfile << "|----";
		while (tmp != nullptr)
		{
			if (tmp->Fret > 9)
				beatTo = tmp->Beat - 1;
			else
				beatTo = tmp->Beat - 2;
			for (int i = tmpBeat; i < beatTo; i++)
			{
				outfile << "-";
			}
			outfile << to_string(tmp->Fret);
			tmpBeat = tmp->Beat;
			tmp = tmp->next;
		}
		// making tab look clean at the end
		for (int i = tmpBeat; i < maxBeat; i++)
			outfile << "-";
		outfile << "\n";
	}
	
	printf("Guitar tab creator finished. Check output.txt\n");

	// cleanup 
	
	file.close();
	outfile.close();

	delete f;
	delete song;
}