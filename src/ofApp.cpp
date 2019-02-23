#include "ofApp.h"
#include "Emitter.h"
//----------------------------------------------------------------------------------
//
// This example code demonstrates the use of an "Emitter" class to emit Sprites
// and set them in motion. The concept of an "Emitter" is taken from particle
// systems (which we will cover next week).
//
//  1) Creates a simple Emitter  that you can drag around (without images)
//  2) Creates an Sprite to Collide with
//
//  requires ofxGUI add-in for sliders for changing parameters
// 
//
//
//  Kevin M. Smith - CS 134 SJSU

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);  // working on 144hz monitor need to set Vsync true for consistent framerate. Default rate = 60fps
	ofBackground(0, 0, 0);

	player = new Emitter(new SpriteSystem());
	player->setChildSize(10,10);
	player->setChildVelocity(ofVec3f(0, -500, 0));
	player->setRate(3);
	player->stop();
	player->isBoundByWindow = true;
	player->setChildWindowBound(true);
	player->setPosition(ofVec3f(ofGetWindowWidth() / 2, ofGetWindowHeight() * 2 / 3, 0));
	playerVelocity = ofVec3f(0, 0, 0);
	playerSpeed = 5;  // pixels per frame
}

//--------------------------------------------------------------
void ofApp::update() {
	playerVelocity.x = (move[1] - move[0]) * playerSpeed;
	playerVelocity.y = (move[3] - move[2]) * playerSpeed;
	player->setVelocity(playerVelocity);
	player->update();
}


//--------------------------------------------------------------
void ofApp::draw(){
	player->draw();
}

void ofApp::checkCollisions() {


}


//--------------------------------------------------------------

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
//	cout << "mouse( " << x << "," << y << ")" << endl;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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

void ofApp::keyPressed(int key) {
	switch (key) {
	case 'H':
	case 'h':
		bHide = !bHide;
		break;
	case ' ':
		if(!player->started) player->start();  // start() resets timer
		break;
	case OF_KEY_LEFT:
		move[0] = 1;
		break;
	case OF_KEY_RIGHT:
		move[1] = 1;
		break;
	case OF_KEY_UP:
		move[2] = 1;
		break;
	case OF_KEY_DOWN:
		move[3] = 1;
		break;
	}
}


//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	switch (key) {
	case ' ':
		player->stop();
		break;
	case OF_KEY_LEFT:
		move[0] = 0;
		break;
	case OF_KEY_RIGHT:
		move[1] = 0;
		break;
	case OF_KEY_UP:
		move[2] = 0;
		break;
	case OF_KEY_DOWN:
		move[3] = 0;
		break;
	}
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
