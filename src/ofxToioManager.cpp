//
//  ofxToioManager.cpp
//  colorTracker
//
//  Created by Kento Morita on 2017/12/12.
//

#include "ofxToioManager.hpp"

ofxToioManager::ofxToioManager() {
    
}

void ofxToioManager::initToio(int num) {
    for (auto i=0; i<num; i++) {
        ofxToio t;
        t.setId(i);
        t.setPos(0, 0, 0, 0);
        toios.push_back(t);
    }
}

void ofxToioManager::setup(const string SND_HOST, const int SND_PORT, const int RCV_PORT) {
    HOST = SND_HOST;
    PORT = SND_PORT;
    ofxSubscribeOsc(RCV_PORT, "/position", [=}(int id), int matId, int posx, int posy, int degrees){
            if (id < toios.size()) {
                toios.at(id).setPos(posx,posy,360-degrees, ofGetElapsedTimef());
            }
    }
    
}

void ofxToioManager::update() {
    
    // check for waiting messages
    // listen on the given port
    cout << "listening for osc messages on port " << RCV_PORT << "\n";
    ofxSubscribeOsc(RCV_PORT, "/position", [=](int id, int matId, int posx, int posy, int degrees)){
         if (id < toios.size()) {
                toios.at(id).setPos(posx,posy,360-degrees, ofGetElapsedTimef());
        }
    }

}

void ofxToioManager::drawPositions(float x_offset, float y_offset) {
    ofPushMatrix();
    ofTranslate(x_offset, y_offset);
//    ofSetColor(200,200,200, 50);
//    ofDrawRectangle(0, 0, 500, 500);
    
    ofSetColor(0);
    for (auto i = 0; i < toios.size(); ++i) {
        ofPushMatrix();
        ofTranslate(toios[i].x, toios[i].y);
        ofRotate(toios[i].deg);
//        cout << "pos: " << toios[i].x << ", " << toios[i].y << endl;
        ofDrawRectangle(-10, -10, 20, 20);
        //ofDrawRectangle(0, -5, 20, 10);
        ofPopMatrix();
    }
    ofPopMatrix();
}

void ofxToioManager::sendMotorControl(int id, int left, int right, int duration) {
    
    ofxPublishOsc(HOST, "/motorcontrol", id, left, right, duration);
}

void ofxToioManager::goTo(int id, float xpos, float ypos, float normalizedSpeed) {
    float now = ofGetElapsedTimef();
    if (toios[id].distance(xpos, ypos) > 20 && toios[id].isAlive(now)) {
        ofVec2f lr = toios[id].aim(xpos, ypos);
        sendMotorControl(id, (int)lr.x * normalizedSpeed, (int)lr.y * normalizedSpeed, 50);
    }
}

void ofxToioManager::goTo2(int id, float xpos, float ypos, float normalizedSpeed, int duration) {
    float now = ofGetElapsedTimef();
    if (toios[id].distance(xpos, ypos) > 20 && toios[id].isAlive(now)) {
        ofVec2f lr = toios[id].aim2(xpos, ypos);
        sendMotorControl(id, (int)lr.x * normalizedSpeed, (int)lr.y * normalizedSpeed, duration);
    }
}

void ofxToioManager::goTo3(int id, float xpos, float ypos, float normalizedSpeed, int left, int right, int duration) {
    float now = ofGetElapsedTimef();
    if (!toios[id].isAlive(now)) return;
    if (toios[id].distance(xpos, ypos) > 20) {
        ofVec2f lr = toios[id].aim2(xpos, ypos);
        sendMotorControl(id, (int)lr.x * normalizedSpeed, (int)lr.y * normalizedSpeed, duration);
    } else {
        sendMotorControl(id, left, right, duration);
    }
}
