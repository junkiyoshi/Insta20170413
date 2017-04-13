#include "ColorLine.h"

ColorLine::ColorLine(ofColor body_color)
{
	this->body_color = body_color;
	this->move_value = 15;

	this->x_value = ofRandom(0.5, 10.0);
	this->y_value = ofRandom(0.5, 10.0);
	this->z_value = ofRandom(0.5, 10.0);

	this->points.push_back(ofVec3f(0, 0, 0));
}

ColorLine::~ColorLine()
{

}

void ColorLine::update()
{
	ofVec3f next;
	next.set(this->points[this->points.size() - 1]);
	next += ofVec3f(ofRandom(-this->x_value, this->x_value), ofRandom(-this->y_value, this->y_value), ofRandom(-this->z_value, this->z_value));

	this->points.push_back(next);

	if (this->points.size() > 128) {
		this->points.erase(this->points.begin());
	}
}

void ColorLine::draw()
{
	ofPath line_path = ofPath();
	line_path.setFilled(false);
	line_path.setStrokeColor(this->body_color);
	line_path.setStrokeWidth(2);
	line_path.moveTo(this->points[0]);
	for (int i = 1; i < this->points.size(); i++) {
		line_path.lineTo(this->points[i]);
	}

	line_path.draw();
	line_path.close();

	ofSetColor(this->body_color);
	ofNoFill();

	ofPushMatrix();
	ofTranslate(this->points[this->points.size() - 1]);
	ofSphere(2);
	ofPopMatrix();
}