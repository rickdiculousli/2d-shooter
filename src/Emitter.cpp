


#include "ofMain.h"
#include "Emitter.h"



//  Create a new Emitter - needs a SpriteSystem
//
Emitter::Emitter(SpriteSystem *spriteSys) {
	sys = spriteSys;
	lifespan = 3000;    // milliseconds
	started = false;
	isBoundByWindow = false;
	lastSpawned = 0;
	rate = 1;    // sprites/sec
	haveChildImage = false;
	haveImage = false;
	velocity = ofVec3f(0, 0, 0);
	childVelocity = ofVec3f(100, 100, 0);
	drawable = true;
	width = 50;
	height = 50;
	childWidth = 10;
	childHeight = 10;
}

//  Draw the Emitter if it is drawable. In many cases you would want a hidden emitter
//
//
void Emitter::draw() {
	if (drawable) {

		if (haveImage) {
			image.draw(-image.getWidth() / 2.0 + trans.x, -image.getHeight() / 2.0 + trans.y);
		}
		else {
			ofSetColor(0, 0, 255);
			ofDrawRectangle(-width / 2 + trans.x, -height / 2 + trans.y, width, height);
		}
	}

	// draw sprite system
	//
	sys->draw();
}

//  Update the Emitter. If it has been started, spawn new sprites with
//  initial velocity, lifespan, birthtime.
//
void Emitter::update() {
	if (started) {
		float time = ofGetElapsedTimeMillis();
		if ((time - lastSpawned) > (1000.0 / rate)) {
			// spawn a new sprite
			spawnSprite(time);
			lastSpawned = time;
		}
	}
	cout << "spritesys# (" << sys->sprites.size() <<")" << endl;
	trans += velocity;
	if (isBoundByWindow) windowBounds();
		
	sys->update();
}

// Start/Stop the emitter.
//
void Emitter::start() {
	started = true;
	float time = ofGetElapsedTimeMillis();
	if ((time - lastSpawned) > (1000.0 / rate))
	{
		spawnSprite(time);
		lastSpawned = time;
	}
	
	
}

void Emitter::stop() {
	started = false;
}


void Emitter::setLifespan(float life) {
	lifespan = life;
}

void Emitter::setVelocity(ofVec3f v) {
	velocity = v;
}

void Emitter::setChildVelocity(ofVec3f v) {
	childVelocity = v;
}

void Emitter::setChildImage(ofImage img) {
	childImage = img;
	haveChildImage = true;
	childWidth = img.getWidth();
	childHeight = img.getHeight();
}

void Emitter::setImage(ofImage img) {
	image = img;
}

void Emitter::setRate(float r) {
	rate = r;
}

//float Emitter::maxDistPerFrame() {
//	return  childVelocity.length() / ofGetFrameRate();
//}

void Emitter::setChildWindowBound(bool b) {
	sys->isBoundByWindow = b;
}

void Emitter::windowBounds() {
	float xOffset, yOffset;
	if (haveImage) {
		xOffset = image.getWidth() / 2.0;
		yOffset = image.getHeight() / 2.0;
	}
	else {
		xOffset = width / 2;
		yOffset = height / 2;
	}
	if ((trans.x - xOffset) < 0) trans.x = xOffset;
	if ((trans.x + xOffset) > ofGetWindowWidth()) trans.x = ofGetWindowWidth() - xOffset;
	if ((trans.y - yOffset) < 0) trans.y = yOffset;
	if ((trans.y + yOffset) > ofGetWindowHeight()) trans.y = ofGetWindowHeight() - yOffset;
}

void Emitter::spawnSprite(float time) {
	Sprite sprite;
	if (haveChildImage) sprite.setImage(childImage);
	sprite.velocity = childVelocity;
	sprite.lifespan = lifespan;
	sprite.setPosition(trans);
	sprite.birthtime = time;
	sprite.width = childWidth;
	sprite.height = childHeight;
	sys->add(sprite);
}

