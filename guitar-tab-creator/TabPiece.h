#pragma once
class TabPiece
{
public:
	TabPiece() = default;
	TabPiece(const TabPiece& other) = delete;
	~TabPiece() = default;

	TabPiece(int stringNo, int fret, int beat);
	
private:

public:
	TabPiece* next;
	int StringNo;
	int Fret;
	int Beat;
	
};

