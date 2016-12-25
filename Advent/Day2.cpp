#include "stdafx.h"
#include <map>
#include "Day2.h"


Board::Board() : currentPoint_(Point(1, 1))
{
	board_[Point(0, 0)] = 7;
	board_[Point(0, 1)] = 4;
	board_[Point(0, 2)] = 1;
	board_[Point(1, 0)] = 8;
	board_[Point(1, 1)] = 5;
	board_[Point(1, 2)] = 2;
	board_[Point(2, 0)] = 9;
	board_[Point(2, 1)] = 6;
	board_[Point(2, 2)] = 3;
}

int Board::getButton()
{
	return board_.find(currentPoint_)->second;
}

void Board::makeStep(char& s)
{
	switch (s)
	{
	case ('U'):
		if (currentPoint_.y_<2)
			currentPoint_.y_ += 1;
		break;
	case ('D'):
		if (currentPoint_.y_>0)
			currentPoint_.y_ -= 1;
		break;
	case ('L'):
		if (currentPoint_.x_>0)
			currentPoint_.x_ -= 1;
		break;
	case ('R'):
		if (currentPoint_.x_<2)
			currentPoint_.x_ += 1;
		break;
	default: break;
	}

}

void Board::setCurrentPoint(int x, int y)
{
	currentPoint_.x_ = x;
	currentPoint_.y_ = y;
}

bool Board::isButton()
{
	return board_.find(currentPoint_) != board_.end();
}

Board2::Board2(): currentPoint_(Point(-1,1))
{
	board_[Point(0, 0)] = 10;
	board_[Point(0, 1)] = 6;
	board_[Point(0, 2)] = 2;
	board_[Point(1, 0)] = 11;
	board_[Point(1, 1)] = 7;
	board_[Point(1, 2)] = 3;
	board_[Point(2, 0)] = 12;
	board_[Point(2, 1)] = 8;
	board_[Point(2, 2)] = 4;

	board_[Point(-1, 1)] = 5;
	board_[Point(1, -1)] = 13;
	board_[Point(3, 1)] = 9;
	board_[Point(1, 3)] = 1;
}

int Board2::getButton()
{
	return board_.find(currentPoint_)->second;
}


void Board2::makeStep(char& s)
{	
	switch (s)
	{
	case ('U'):
		if (currentPoint_.y_<3)
			currentPoint_.y_ += 1;
		if (!isButton())
			currentPoint_.y_-= 1;
		break;

	case ('D'):
		if (currentPoint_.y_>-1)
			currentPoint_.y_ -= 1;
		if (!isButton())
			currentPoint_.y_ += 1;
		break;

	case ('L'):
		if (currentPoint_.x_>-1)
			currentPoint_.x_ -= 1;
		if (!isButton())
			currentPoint_.x_ += 1;
		break;

	case ('R'):
		if (currentPoint_.x_<3)
			currentPoint_.x_ += 1;
		if (!isButton())
			currentPoint_.x_ -= 1;
		break;
	default: break;
	}
}

void Board2::setCurrentPoint(int x, int y)
{
	currentPoint_.x_ = x;
	currentPoint_.y_ = y;
}

Point Board2::getCurrentPoint() const
{
	return currentPoint_;
}

bool Board2::isButton()
{
	return board_.find(currentPoint_) != board_.end();
}

