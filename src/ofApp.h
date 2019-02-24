#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Sprite.h"

class Emitter;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void checkCollisions();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		// ofxGui Stuff
		bool bHide;
		ofxFloatSlider fireRate;
		ofxFloatSlider life;
		ofxFloatSlider direction;
		ofxFloatSlider fireSpeed;
		ofxLabel screenSize;
		ofxPanel gui;

		// Player info
		Emitter *player;
		int move[4];	// directional key press array
		float playerSpeed;
		ofVec3f playerVelocity, principleDir;

		//Game state
		bool gameStart = false;

};
