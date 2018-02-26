#pragma once

class City {

	char name;
	int x_coordinate;
	int y_coordinate;
public:
	inline char getname() 
	{
		return name;
	}
	inline int getxCoord()
	{
		return x_coordinate;
	}
	inline int getyCoord()
	{
		return y_coordinate;
	}
};