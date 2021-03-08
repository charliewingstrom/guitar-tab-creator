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

	int stringNo;
	int fretNo;

	int beat = 0;

	file.open(inFilename.c_str());
	outfile.open(outFilename.c_str());
	
	Note* tmpNote;

	// read in each note from the file, add each note to the TabbedSong
	while (file >> noteLetter)
	{
		printf("------------------- NOTE -----------------------\n");
		file >> octave;
		printf("noteLetter: %s\n", noteLetter);
		printf("noteOctave: %s\n", octave);

		int oct = stoi(octave);
		tmpNote = new Note(noteLetter, oct);
		f->getNotePositionInRange(stringNo, fretNo, tmpNote, 5, 13);

		printf("string number: %d\n", stringNo);
		printf("fret number: %d\n", fretNo);

		tmpPiece = new TabPiece(stringNo, fretNo, beat);

		song->AddPieceToSong(tmpPiece);

		delete tmpNote;
		beat += 8;
	}
	

	// get each note read into the song, then write it out into outfile
	TabPiece* tmp;

	int tmpBeat;
	int maxBeat = 256;
	TabPiece* heads[6] = { song->HighEHead, song->BHead, song->GHead, song->DHead, song->AHead, song->LowEHead };
	for (int i = 0; i < 6; i++)
	{
		tmp = heads[i];

		tmpBeat = 0;
		while (tmp != nullptr)
		{
			for (int i = tmpBeat; i < tmp->Beat-2; i++)
			{
				outfile << "-";
			}
			outfile << to_string(tmp->Fret);
			tmpBeat = tmp->Beat;
			tmp = tmp->next;
		}
		// making tab look clean at the end
		for (int i = tmpBeat; i < maxBeat; i++)
		{
			outfile << "-";
		}
		outfile << "\n";
	}
	
	printf("Guitar tab creator finished. Check output.txt\n");

	// cleanup 
	
	file.close();
	outfile.close();

	delete f;
	delete song;
}