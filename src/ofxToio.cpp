//
//  ofxToio.cpp
// 
//
//  Created by @_xhi, @kentoids, @kkshmz on 2017/09/03.
//
//

#include "ofxToio.hpp"

ofxToio::ofxToio(void) {
    
}

ofxToio::~ofxToio(void) {
    
}


void ofxToio::setId(int i){
    id = i;
}

int ofxToio::getId(void){
    return id;
}

bool ofxToio::isAlive(long now) {
    return(now < lastUpdate+200);
}

ofVec3f ofxToio::getPos(void){
    return ofVec3f(x,y,deg);
}

int ofxToio::getUpdateTime(void){
    return lastUpdate;
}

void ofxToio::setPos(int sx, int sy, int sdeg, float stime){
    x = sx;
    y = sy;
    deg = sdeg;
    lastUpdate = stime;
}



ofVec2f ofxToio::aim(float tx, float ty) {
    int left = 0;
    int right = 0;
    float angleToTarget = atan2(ty-y, tx-x);
    float thisAngle = deg*PI/180;
    float diffAngle = thisAngle-angleToTarget;
    if (diffAngle > PI) diffAngle -= TWO_PI;
    if (diffAngle < -PI) diffAngle += TWO_PI;
    //if in front, go forward and
    //cout << diffAngle << endl;
    
    if (abs(diffAngle) < HALF_PI) {
        //in front
        float frac = cos(diffAngle);
        //cout << frac << endl;
        if (diffAngle > 0) {
            //up-left
            left = floor(100*frac);
            right = 100;
        } else {
            left = 100;
            right = floor(100*frac);
        }
    } else {
        //face back
        if (diffAngle > 0) {
            left  = -30;
            right = 30;
        } else {
            left  =  30;
            right = -30;
        }
    }
    
    //cout << ofToString(left) + " " + ofToString(right) << endl;
    
    ofVec2f res;
    res.set(left, right);
    
    return res;
}

ofVec2f ofxToio::aim2(float tx, float ty) {
    int left = 0;
    int right = 0;
    float angleToTarget = atan2(ty-y, tx-x);
    float thisAngle = deg*PI/180;
    float diffAngle = thisAngle-angleToTarget;
    if (diffAngle > PI) diffAngle -= TWO_PI;
    if (diffAngle < -PI) diffAngle += TWO_PI;
    //if in front, go forward and
    //cout << diffAngle << endl;
    
    if (abs(diffAngle) < HALF_PI) {
        //in front
        float frac = cos(diffAngle);
        //cout << frac << endl;
        if (diffAngle > 0) {
            //up-left
            left = floor(100*frac);
            right = 100;
        } else {
            left = 100;
            right = floor(100*frac);
        }
    } else {
        //face back
        float frac = cos(diffAngle + PI);
        //cout << frac << endl;
        if (diffAngle > 0) {
            //up-left
            left = -floor(100*frac);
            right = -100;
        } else {
            left = -100;
            right = -floor(100*frac);
        }
    }
    
    //cout << ofToString(left) + " " + ofToString(right) << endl;
    
    ofVec2f res;
    res.set(left, right);
    
    return res;
}

float ofxToio::distance(float ox, float oy) {
    return sqrt ( (x-ox)*(x-ox) + (y-oy)*(y-oy));
}



