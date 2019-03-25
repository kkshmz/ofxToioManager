//
//  ofxToioManager.hpp
//  colorTracker
//
//  Created by @kentoids and @kkshmz on 2017/12/12.
//

#pragma once

#include "ofxToio.hpp"
#include "ofxOSC.h"
#include "ofxPubSubOsc.h"

struct toioData {
    int _id;
    int _matId;
    int _posx;
    int _posy;
    int _degrees;
}

constexpr auto HOST = "127.0.0.1";
constexpr int PORT = 9624;

class ofxToioManager {
public:
    ofxToioManager();
    void initToio(const int num);
    void setup(const string SND_HOST, const int SND_PORT, int RCV_PORT);
    void update();
    void drawPositions(float x_offset, float y_offset);
    void sendMotorControl(int id, int left, int right, int duration);
    /*
     1: go to pos without back
     2: go to pos with back
     3: go to pos (turn when it's there)
    */
    void goTo(int id, float xpos, float ypos, float normalizedSpeed);
    void goTo2(int id, float xpos, float ypos, float normalizedSpeed, int duration = 100);
    void goTo3(int id, float xpos, float ypos, float normalizedSpeed, int left, int right, int duration = 100);
    
    ofVec2f getPos(int id) {return ofVec2f(toios.at(id).x, toios.at(id).y);};
    
    vector<ofxToio> toios;
private:
};
