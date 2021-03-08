#include "Note.h"

Note Note::operator=(const Note& other)
{
	Note* tmp = new Note(other.Letter, other.Octave);
	
	return *tmp;
}

Note::~Note()
{
}


Note::Note(const char* letter, int octave)
{
	this->Letter = letter;
	this->Octave = octave;
}

const char* Note::GetLetter()
{
	return Letter;
}

int Note::GetOctave()
{
	return Octave;
}

bool Note::Equals(const Note* other)
{
	return strcmp(Letter, other->Letter) == 0 && Octave == other->Octave;
}




