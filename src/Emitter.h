#pragma once
//----------------------------------------------------------------------------------
//
// Basic Sprite Emitter Class
//
//
//  Kevin M. Smith - CS 134 SJSU

// With modifications by Rick Li

#include "Sprite.h"


//  General purpose Emitter class for emitting sprites
//  This works similar to a Particle emitter
//
class Emitter : public BaseObject {
public:
	Emitter(SpriteSystem *);
	// general methods
	void draw();
	void start();
	void stop();
	void update();

	// methods for SpriteSystem
	void setLifespan(float);
	void setChildVelocity(ofVec3f, float); // params: direction, speed
	void setChildImage(ofImage);
	void setChildSize(float w, float h) { childWidth = w; childHeight = h; }
	void setRate(float);
	float maxDistPerFrame();
	void setChildWindowBound(bool);
	void setSound(string);

	// methods for emitter itself
	void setVelocity(ofVec3f);
	void setImage(ofImage);
	void setWindowBound(bool);
	
	SpriteSystem *sys;
	ofImage childImage;
	ofImage image;
	ofVec3f velocity;
	ofVec3f childDirection; // unit vector
	ofSoundPlayer bulletSound;
	float rate;
	float childSpeed;
	float lifespan;
	float lastSpawned;
	float width, height;
	float childWidth, childHeight;
	bool started;
	bool drawable;
	bool haveChildImage;
	bool haveImage;
	bool isBoundByWindow;
	bool haveSound;

private:
	void windowBounds();
	void spawnSprite(float);
};
