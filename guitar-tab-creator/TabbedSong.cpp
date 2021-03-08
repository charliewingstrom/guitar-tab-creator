#include "TabbedSong.h"

TabbedSong::TabbedSong()
{
	LowEHead = nullptr;
	AHead = nullptr;
	DHead = nullptr;
	GHead = nullptr;
	BHead = nullptr;
	HighEHead = nullptr;

}

TabbedSong::~TabbedSong()
{
	TabPiece* tmpTab;
	while (LowEHead != nullptr)
	{
		tmpTab = LowEHead;
		LowEHead = LowEHead->next;
		delete tmpTab;
	}
	while (AHead != nullptr)
	{
		tmpTab = AHead;
		AHead = AHead->next;
		delete tmpTab;
	}
	while (DHead != nullptr)
	{
		tmpTab = DHead;
		DHead = DHead->next;
		delete tmpTab;
	}
	while (GHead != nullptr)
	{
		tmpTab = GHead;
		GHead = GHead->next;
		delete tmpTab;
	}
	while (BHead != nullptr)
	{
		tmpTab = BHead;
		BHead = BHead->next;
		delete tmpTab;
	}
	while (HighEHead != nullptr)
	{
		tmpTab = HighEHead;
		HighEHead = HighEHead->next;
		delete tmpTab;
	}

}

void TabbedSong::AddPieceToSong(TabPiece* piece)
{
	TabPiece* tmpTab;

	if (piece->StringNo == 0)
	{
		if (LowEHead == nullptr)
		{
			LowEHead = piece;
		}
		else
		{

			tmpTab = LowEHead;
			while (tmpTab->next != nullptr)
			{
				tmpTab = tmpTab->next;
			}
			tmpTab->next = piece;
		}
	}
	else if (piece->StringNo == 1)
	{
		if (AHead == nullptr)
		{
			AHead = piece;
		}
		else
		{

			tmpTab = AHead;
			while (tmpTab->next != nullptr)
			{
				tmpTab = tmpTab->next;
			}
			tmpTab->next = piece;
		}
	}
	else if (piece->StringNo == 2)
	{
		if (DHead == nullptr)
		{
			DHead = piece;
		}
		else
		{

			tmpTab = DHead;
			while (tmpTab->next != nullptr)
			{
				tmpTab = tmpTab->next;
			}
			tmpTab->next = piece;
		}
	}
	else if (piece->StringNo == 3)
	{
		if (GHead == nullptr)
		{
			GHead = piece;
		}
		else
		{

			tmpTab = GHead;
			while (tmpTab->next != nullptr)
			{
				tmpTab = tmpTab->next;
			}
			tmpTab->next = piece;
		}
	}
	else if (piece->StringNo == 4)
	{
		if (BHead == nullptr)
		{
			BHead = piece;
		}
		else
		{

			tmpTab = BHead;
			while (tmpTab->next != nullptr)
			{
				tmpTab = tmpTab->next;
			}
			tmpTab->next = piece;
		}
	}
	else if (piece->StringNo == 5)
	{
		if (HighEHead == nullptr)
		{
			HighEHead = piece;
		}
		else
		{

			tmpTab = HighEHead;
			while (tmpTab->next != nullptr)
			{
				tmpTab = tmpTab->next;
			}
			tmpTab->next = piece;
		}
	}
}
