#pragma once
#include "TabPiece.h"
class TabbedSong
{
public:
	TabbedSong() = default;
	TabbedSong(const TabbedSong& other) = delete;
	~TabbedSong() = default;

public:
	TabPiece* LowEhead;
	TabPiece* AHead;
	TabPiece* DHead;
	TabPiece* GHead;
	TabPiece* BHead;
	TabPiece* HighEHead;

};

