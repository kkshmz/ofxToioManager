#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    manager.initToio(2);
    manager.setup("localhost", 3331, 3332);
}

//--------------------------------------------------------------
void ofApp::update(){
    manager.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    manager.drawPositions(xoff, yoff);
    manager.goTo(0, mouseX-xoff, mouseY-yoff, 0.3);
//    float now = ofGetElapsedTimef();
//    if (manager.toios[0].distance(mouseX-xoff, mouseY-yoff) > 20 && manager.toios[0].isAlive(now)) {
//        ofVec2f lr = manager.toios[0].aim(mouseX-xoff, mouseY-yoff);
//        manager.sendMotorControl(0, (int)lr.x/3, (int)lr.y/3, 50);
//    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key) {
        case '1':
            // trolley id, left motor, right motor, duration
            manager.sendMotorControl(0, 50, -50, 50);
            break;
        case '2':
            // trolley id, left motor speed, right motor speed, duration
            // motor speed: -100 <-> 100.
            manager.sendMotorControl(1, 50, -50, 50);
            break;
        default:
            break;
    }
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
