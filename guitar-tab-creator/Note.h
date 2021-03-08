#pragma once
#include <iostream>
using namespace std;
class Note
{
public:
	Note() = delete;
	Note operator=(const Note& other);
	~Note();
	Note(const char* letter, int octave);

private:
	const char* Letter;
	int Octave;

public:
	const char* GetLetter();
	int GetOctave();
	bool Equals(const Note* other);


};

