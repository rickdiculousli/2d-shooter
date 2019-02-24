#pragma once
//----------------------------------------------------------------------------------
//
// Basic Sprite Emitter Class
//
//
//  Kevin M. Smith - CS 134 SJSU

#include "Sprite.h"


//  General purpose Emitter class for emitting sprites
//  This works similar to a Particle emitter
//
class Emitter : public BaseObject {
public:
	Emitter(SpriteSystem *);
	void draw();
	void start();
	void stop();
	void setLifespan(float);
	void setVelocity(ofVec3f);
	void setChildVelocity(ofVec3f, float);
	void setChildImage(ofImage);
	void setChildSize(float w, float h) { childWidth = w; childHeight = h; }
	void setImage(ofImage);
	void setRate(float);
	float maxDistPerFrame();
	void update();
	void setChildWindowBound(bool);
	void setWindowBound(bool);
	SpriteSystem *sys;
	float rate;
	ofVec3f velocity;
	ofVec3f childDirection; // unit vector
	float childSpeed;
	float lifespan;
	bool started;
	float lastSpawned;
	ofImage childImage;
	ofImage image;
	bool drawable;
	bool haveChildImage;
	bool haveImage;
	bool isBoundByWindow;
	float width, height;
	float childWidth, childHeight;

private:
	void windowBounds();
	void spawnSprite(float);
};
