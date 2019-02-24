#include "ofApp.h"
#include "Emitter.h"


void ofApp::setup(){
	ofSetVerticalSync(true);  // working on 144hz monitor need to set Vsync true for consistent framerate. Default rate = 60fps
	ofBackground(30, 28, 45);

	// setting up the player emitter
	player = new Emitter(new SpriteSystem());
	player->setPosition(ofVec3f(ofGetWindowWidth() / 2, ofGetWindowHeight() * 2 / 3, 0));
	player->setImage(ofImage("images/ship.png"));
	player->setChildImage(ofImage("images/shot.png"));
	player->setSound("sounds/pew_sound.wav");
	player->setChildSize(10,10);
	player->stop();
	player->setWindowBound(true);
	player->setChildWindowBound(true);
	
	playerSpeed = 5;  // pixels per frame
	playerVelocity = ofVec3f(0, 0, 0);  // initially not moving
	principleDir = ofVec3f(0, -1, 0);  // the principle emitting direction (UP)
	

	gui.setup();
	gui.add(fireRate.setup("rate", 6, 1, 10));
	gui.add(life.setup("life", 2, .1, 10));
	gui.add(direction.setup("direction",0, -180, 180 )); // direction slider by angle in degrees
	gui.add(fireSpeed.setup("speed", 500, 1, 1000));
	bHide = false;
}

//--------------------------------------------------------------
void ofApp::update() {
	if (!gameStart) return;

	// take directional keypress and set player velocity.
	// Each press is stored as 0/1 in move array. Arithmetic allows
	// for registering simultaneous presses of L+R and UP+DOWN
	playerVelocity.x = (move[1] - move[0]) * playerSpeed;
	playerVelocity.y = (move[3] - move[2]) * playerSpeed;
	player->setVelocity(playerVelocity);

	//ofxGui changes
	player->setChildVelocity(principleDir.getRotated(direction, ofVec3f(0,0,1)), fireSpeed);  // shooting direction determied by rotating principle direction
	player->setRate(fireRate);
	player->setLifespan(life * 1000);

	player->update();
}


//--------------------------------------------------------------
void ofApp::draw(){
	if (!gameStart) return;

	player->draw();

	if (!bHide) {
		gui.draw();
	}
}

//--------------------------------------------------------------
void ofApp::checkCollisions() {


}

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
	// NOTE: Depending on keyboard hardware, pressing more than 2-3 buttons
	// may cause input to be dropped. This is not a software issue. Most 
	// laptops with low-end keyboards only have 3-key rollover. Search
	// "Key rollover/ N-KRO / 3-KRO" for more information.
	switch (key) {
	case 'H':
	case 'h':
		bHide = !bHide;
		break;
	case ' ':
		cout << "KEY: space" << endl;
		if (!gameStart) { gameStart = true; }	// start the game
		else if (!player->started) { player->start(); }	// begin shooting
		break;
	case OF_KEY_LEFT:
		cout << "KEY: left" << endl;
		move[0] = 1;
		break;
	case OF_KEY_RIGHT:
		cout << "KEY: right" << endl;
		move[1] = 1;
		break;
	case OF_KEY_UP:
		cout << "KEY: up" << endl;
		move[2] = 1;
		break;
	case OF_KEY_DOWN:
		cout << "KEY: down" << endl;
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

