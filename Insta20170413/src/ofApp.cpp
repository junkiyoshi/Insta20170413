#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("openFrameworks");
	ofBackground(0);
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	ofSetDepthTest(true);
	ofSetFrameRate(0);

	int line_count = 256;
	int span = 256 / line_count;
	for (int i = 0; i < line_count; i++) {
		ofColor body_color;
		body_color.setHsb(i * span, 255, 255);
		lines.push_back(ColorLine(body_color));
	}

	this->loop_flg = true;
}

//--------------------------------------------------------------
void ofApp::update(){
	if (this->loop_flg) {
		for (ColorLine& line : lines) {
			line.update();
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	if (this->loop_flg) {
		cam.begin();

		for (ColorLine& line : lines) {
			line.draw();
		}

		cam.end();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	this->loop_flg = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
