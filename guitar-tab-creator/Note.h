#pragma once
#include <iostream>
using namespace std;
class Note
{
public:
	Note() = delete;
	Note operator=(const Note& other) = delete;
	~Note();
	Note(string letter, int octave);

private:
	string Letter;
	int Octave;

public:
	string GetLetter();
	int GetOctave();
	bool Equals(const Note* other);


};

