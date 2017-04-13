#pragma once

#include "ofMain.h"

class ColorLine
{
public:
	ColorLine(ofColor body_color);
	~ColorLine();

	ofColor body_color;
	vector<ofVec3f> points;
	int move_value;

	int x_value;
	int y_value;
	int z_value;

	void update();
	void draw();
};