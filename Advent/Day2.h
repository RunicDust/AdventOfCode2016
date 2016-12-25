#pragma once
#include <string>
#include <map>

struct Point {
	int x_ = 0;
	int y_ = 0;

	Point(int x, int y) {
		x_ = x;
		y_ = y;
	}
};

struct cmpByCoordinates {
	bool operator()(const Point& a, const Point& b) const {
		return std::tie(a.x_, a.y_) < std::tie(b.x_, b.y_);
	}
};

class Board
{
public:

	Board();
	int getButton();
	void makeStep(char& s);
	void setCurrentPoint(int x, int y);
	bool isButton();
	
private:
	Point currentPoint_;
	std::map<Point, int, cmpByCoordinates> board_;
};


class Board2
{
public:

	Board2();
	int getButton();
	void makeStep(char& s);
	void setCurrentPoint(int x, int y);
	Point getCurrentPoint() const;
	bool isButton();

private:
	Point currentPoint_;
	std::map<Point, int, cmpByCoordinates> board_;
};
