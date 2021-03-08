#include "TabPiece.h"

TabPiece::TabPiece(int stringNo, int fret, int beat)
{
	StringNo = stringNo;
	Fret = fret;
	Beat = beat;
	next = nullptr;
}
