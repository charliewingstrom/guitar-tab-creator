#include "Fretboard.h"

Fretboard::Fretboard()
{
}



Fretboard::Fretboard(const Fretboard& other)
{
	
}

Fretboard::~Fretboard()
{
}

Note* Fretboard::getNoteAt(int stringNo, int fretNo)
{
	return &this->FretboardArray[stringNo][fretNo];
}

void Fretboard::getNotePosition(int& stringNo, int& fretNo, Note* note)
{
	for (int i = 0; i < NumStrings; i++)
	{
		for (int j = 0; j < NumFrets; j++)
		{
			if (FretboardArray[i][j].Equals(note))
			{
				//printf("Note found in get note position\n");
				stringNo = i;
				fretNo = j;
				return;
			}
		}
	}
}

bool Fretboard::getNotePositionInRange(int& stringNo, int& fretNo, Note* note, int lowerRange, int higherRange)
{
	if (lowerRange >= 0 && higherRange <= NumFrets)
	{
		for (int i = 0; i < NumStrings; i++)
		{
			for (int j = lowerRange; j < higherRange; j++)
			{
				if (FretboardArray[i][j].Equals(note))
				{
					//printf("Note found in get note position\n");
					stringNo = i;
					fretNo = j;
					return true;
				}
			}
		}
	}
	return false;
}
