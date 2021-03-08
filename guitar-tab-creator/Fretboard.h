#pragma once
#include "Note.h"

class Fretboard
{
public:
	// big 4
	Fretboard();
	Fretboard& operator=(const Fretboard& other);
	Fretboard(const Fretboard& other);
	~Fretboard();

public:
	Note* getNoteAt(int stringNo, int fretNo);
	void getNotePosition(int& stringNo, int& fretNo, Note* note);
	void getNotePositionInRange(int& stringNo, int& fretNo, Note* note, int lowerRange, int higherRange);

private:
	Note LowEString[22] = {
		Note("E", 0), Note("F", 0), Note("F#", 0), Note("G", 0), Note("G#", 0), Note("A", 0), Note("A#", 0), Note("B", 0), Note("C", 0), Note("C#", 0), Note("D", 0), Note("D#", 0),
		Note("E", 1), Note("F", 1), Note("F#", 1), Note("G", 1), Note("G#", 1), Note("A", 1), Note("A#", 1), Note("B", 1), Note("C", 1), Note("C#", 1)
	};
	Note AString[22] = {
		Note("A", 0), Note("A#", 0), Note("B", 0), Note("C", 0), Note("C#", 0), Note("D", 0), Note("D#", 0), Note("E", 1), Note("F", 1), Note("F#", 1), Note("G", 1), Note("G#", 1), 
		Note("A", 1), Note("A#", 1), Note("B", 1), Note("C", 1), Note("C#", 1), Note("D", 1), Note("D#", 1), Note("E", 2), Note("F", 2), Note("F#", 2)
	};
	Note DString[22] = {
		Note("D", 0), Note("D#", 0), Note("E", 1), Note("F", 1), Note("F#", 1), Note("G", 1), Note("G#", 1), Note("A", 1), Note("A#", 1), Note("B", 1), Note("C", 1), Note("C#", 1), 
		Note("D", 1), Note("D#", 1), Note("E", 2), Note("F", 2), Note("F#", 2), Note("G", 2), Note("G#", 2), Note("A", 2), Note("A#", 2), Note("B", 2)
	};
	Note GString[22] = {
		Note("G", 1), Note("G#", 1), Note("A", 1), Note("A#", 1), Note("B", 1), Note("C", 1), Note("C#", 1), Note("D", 1), Note("D#", 1), Note("E", 2), Note("F", 2), Note("F#", 2), 
		Note("G", 2), Note("G#", 2), Note("A", 2), Note("A#", 2), Note("B", 2), Note("C", 2), Note("C#", 2), Note("D", 2), Note("D#", 2), Note("E", 3)
	};
	Note BString[22] = {
		Note("B", 1), Note("C", 1), Note("C#", 1), Note("D", 1), Note("D#", 1), Note("E", 2), Note("F", 2), Note("F#", 2), Note("G", 2), Note("G#", 2), Note("A", 2), Note("A#", 2), 
		Note("B", 2), Note("C", 2), Note("C#", 2), Note("D", 2), Note("D#", 2), Note("E", 3), Note("F", 3), Note("F#", 3), Note("G", 3), Note("G#", 3)
	};
	Note HighEString[22] = {
		Note("E", 2), Note("F", 2), Note("F#", 2), Note("G", 2), Note("G#", 2), Note("A", 2), Note("A#", 2), Note("B", 2), Note("C", 2), Note("C#", 2), Note("D", 2), Note("D#", 2),
		Note("E", 3), Note("F", 3), Note("F#", 3), Note("G", 3), Note("G#", 3), Note("A", 3), Note("A#", 3), Note("B", 3), Note("C", 3), Note("C#", 3)
	};
	Note FretboardArray[6][22] = {
		{ Note("E", 0), Note("F", 0), Note("F#", 0), Note("G", 0), Note("G#", 0), Note("A", 0), Note("A#", 0), Note("B", 0), Note("C", 0), Note("C#", 0), Note("D", 0), Note("D#", 0),
		Note("E", 1), Note("F", 1), Note("F#", 1), Note("G", 1), Note("G#", 1), Note("A", 1), Note("A#", 1), Note("B", 1), Note("C", 1), Note("C#", 1) },
		{ Note("A", 0), Note("A#", 0), Note("B", 0), Note("C", 0), Note("C#", 0), Note("D", 0), Note("D#", 0), Note("E", 1), Note("F", 1), Note("F#", 1), Note("G", 1), Note("G#", 1),
		Note("A", 1), Note("A#", 1), Note("B", 1), Note("C", 1), Note("C#", 1), Note("D", 1), Note("D#", 1), Note("E", 2), Note("F", 2), Note("F#", 2) },
		{ Note("D", 0), Note("D#", 0), Note("E", 1), Note("F", 1), Note("F#", 1), Note("G", 1), Note("G#", 1), Note("A", 1), Note("A#", 1), Note("B", 1), Note("C", 1), Note("C#", 1),
		Note("D", 1), Note("D#", 1), Note("E", 2), Note("F", 2), Note("F#", 2), Note("G", 2), Note("G#", 2), Note("A", 2), Note("A#", 2), Note("B", 2) },
		{ Note("G", 1), Note("G#", 1), Note("A", 1), Note("A#", 1), Note("B", 1), Note("C", 1), Note("C#", 1), Note("D", 1), Note("D#", 1), Note("E", 2), Note("F", 2), Note("F#", 2),
		Note("G", 2), Note("G#", 2), Note("A", 2), Note("A#", 2), Note("B", 2), Note("C", 2), Note("C#", 2), Note("D", 2), Note("D#", 2), Note("E", 3) },
		{ Note("B", 1), Note("C", 1), Note("C#", 1), Note("D", 1), Note("D#", 1), Note("E", 2), Note("F", 2), Note("F#", 2), Note("G", 2), Note("G#", 2), Note("A", 2), Note("A#", 2),
		Note("B", 2), Note("C", 2), Note("C#", 2), Note("D", 2), Note("D#", 2), Note("E", 3), Note("F", 3), Note("F#", 3), Note("G", 3), Note("G#", 3) },
		{ Note("E", 2), Note("F", 2), Note("F#", 2), Note("G", 2), Note("G#", 2), Note("A", 2), Note("A#", 2), Note("B", 2), Note("C", 2), Note("C#", 2), Note("D", 2), Note("D#", 2),
		Note("E", 3), Note("F", 3), Note("F#", 3), Note("G", 3), Note("G#", 3), Note("A", 3), Note("A#", 3), Note("B", 3), Note("C", 3), Note("C#", 3) }
	};

	int NumStrings = 6;
	int NumFrets = 22;
};


