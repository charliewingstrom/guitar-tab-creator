#include "Note.h"



Note::~Note()
{
}

Note::Note(string letter, int octave)
{
	this->Letter = letter;
	this->Octave = octave;
}

string Note::GetLetter()
{
	return Letter;
}

int Note::GetOctave()
{
	return Octave;
}

bool Note::Equals(const Note* other)
{
	return Letter == other->Letter && Octave == other->Octave;
}




