#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Fretboard.h"
#include "TabbedSong.h"

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif


using namespace std;


int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	cout << "Welcome to guitar tab creator" << endl;

	Fretboard* f = new Fretboard();
	TabbedSong* song = new TabbedSong();
	TabPiece* tmpPiece;

	fstream file;
	ofstream outfile;

	string inFilename = "input.txt";
	string outFilename = "output.txt";

	string noteLetter;
	string octave;
	string noteBeat;

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
		cout << "noteLetter: " << noteLetter << '\n';
		cout << "noteOctave: " << octave << '\n';
		cout << "noteBeat: " << noteBeat << '\n';
		int oct = stoi(octave);
		currNoteBeat = stoi(noteBeat);
		Note tmpNote(noteLetter, oct);
		
		upperLimit = prevFret;
		lowerLimit = prevFret;

		while (!f->getNotePositionInRange(stringNo, fretNo, &tmpNote, lowerLimit, upperLimit))
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
			for (int i = tmpBeat; i < beatTo; i+=4)
			{
				outfile << "-\t";
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

	_CrtDumpMemoryLeaks();

	return 0;
}