#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    _squarewidth = 50;
    _pyramidheight = 100;
    ofSetFullscreen(true);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255);
    ofPushMatrix();
    //ofTranslate(ofGetWindowWidth()/2,ofGetWindowHeight()/2-_squarewidth/2);
    ofTranslate(ofGetWindowWidth()/2+_squarewidth/2,ofGetWindowHeight()/2);
    ofRotateZ(90);
    ofNoFill();
    ofSetColor(0, 0, 0);
    
    ofVec2f a = ofVec2f(0, 0);
    ofVec2f b = ofVec2f(-_squarewidth/2, _pyramidheight);
    ofVec2f c = ofVec2f(_squarewidth/2, _pyramidheight);
    float theta1 = atan2(a.y-b.y, a.x-b.x);
    float theta2 = atan2(a.y-c.y, a.x-c.x);
    float angle = abs(theta1-theta2);
    angle = ofRadToDeg(angle);
    
    for (int i = 0; i < 4; i++){
        ofPushMatrix();
        ofRotateZ(angle*-i);
        ofLine(a.x, a.y, b.x, b.y);
        ofLine(c.x, c.y, b.x, b.y);
        ofLine(c.x, c.y, a.x, a.y);
        ofPopMatrix();
    }
    // triangle tab
    ofVec2f ta = ofVec2f(a.x-_squarewidth*0.1, a.y+_squarewidth*0.1);
    ofVec2f tb = ofVec2f(b.x-_squarewidth*0.1, b.y-_squarewidth*0.1);
    ofLine(a.x, a.y, ta.x, ta.y);
    ofLine(ta.x, ta.y, tb.x, tb.y);
    ofLine(tb.x, tb.y, b.x, b.y);
    
    // rect
    ofLine(b.x, b.y, b.x, b.y + _squarewidth);
    ofLine(b.x, b.y + _squarewidth, b.x + _squarewidth, b.y + _squarewidth);
    ofLine(b.x + _squarewidth, b.y, b.x + _squarewidth, b.y + _squarewidth);
    
    // tab
    float corner = _squarewidth*0.15;
    ofLine(b.x-corner, b.y+corner, b.x-corner, b.y + _squarewidth - corner);
    ofLine(b.x, b.y, b.x-corner, b.y+corner);
    ofLine(b.x - corner, b.y + _squarewidth - corner, b.x, b.y + _squarewidth);
    
    // tab
    ofLine(b.x+corner, b.y+_squarewidth+corner, b.x, b.y+_squarewidth);
    ofLine(b.x+corner, b.y+_squarewidth+corner, b.x+_squarewidth-corner, b.y+_squarewidth+corner);
    ofLine(b.x+_squarewidth, b.y+_squarewidth, b.x+_squarewidth-corner, b.y+_squarewidth+corner);
    
    // tab
    ofLine(b.x+_squarewidth, b.y, b.x+_squarewidth+corner, b.y+corner);
    ofLine(b.x+_squarewidth+corner, b.y+corner, b.x+_squarewidth+corner, b.y-corner+_squarewidth);
    ofLine(b.x+_squarewidth+corner, b.y-corner+_squarewidth, b.x+_squarewidth, b.y+_squarewidth);
    
    
    
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    float ratio = _pyramidheight/_squarewidth;
    
    switch(key) {
        case 's':
        case 'S':
            _squarewidth -= 10;
            _pyramidheight = ratio*_squarewidth;
            break;
            
        case 'W':
        case 'w':
            _squarewidth += 10;
            _pyramidheight = ratio*_squarewidth;
            break;
            
        case 'a':
        case 'A':
            _pyramidheight -= 10;
            break;
            
        case 'd':
        case 'D':
            _pyramidheight += 10;
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
