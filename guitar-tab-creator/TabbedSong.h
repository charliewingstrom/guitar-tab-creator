#pragma once
#include "TabPiece.h"
class TabbedSong
{
public:
	TabbedSong();
	TabbedSong(const TabbedSong& other) = delete;
	~TabbedSong();

	void AddPieceToSong(TabPiece* piece);
public:
	TabPiece* LowEHead;
	TabPiece* AHead;
	TabPiece* DHead;
	TabPiece* GHead;
	TabPiece* BHead;
	TabPiece* HighEHead;

};

