#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    
    // this uses depth information for occlusion
    // rather than always drawing things on top of each other
    ofEnableDepthTest();
    
    // this sets the camera's distance from the object
    cam.setDistance(120);
    
    //cam.enableOrtho();
    
    ofSetCircleResolution(64);
    bShowHelp = false;
    paused = false;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofConePrimitive cone;
    cone.set(5, 5, 4, 4);
    
    cam.begin();
    ofRotateX(180+45);
    ofRotateY(45);
    ofBackground( 220 );
    ofNoFill();
    
    
    for (int j = -5; j <= 5; j++){
        for (int i = -5; i <= 5; i++){
            float h = ofMap(sin(ofGetElapsedTimef()), -1, 1, ofMap(sin(ofGetElapsedTimef()), -1, 1, 5, 15), 25+i*j*0.025*ofGetElapsedTimef());
            h = MIN(abs(h), 50);
            //h = log(h*1000);
            cone.setHeight(h);
            ofPushMatrix();
            ofTranslate(i*7, -h, j*7);
            ofRotateY(45);
            ofSetColor(255);
            cone.getConeMesh().drawWireframe();
            
            ofSetColor(100);
            ofTranslate(0, -20, 0);
            ofPushStyle();
            //ofSetColor(255,0,0);
            ofDrawBitmapString(ofToString(round(h)), 0, 0, 0);
            ofPopStyle();
            ofPopMatrix();
        }
    }
    
    cam.end();
    //drawInteractionArea();
    ofSetColor(255);
    string msg = "fps: " + ofToString(ofGetFrameRate(), 2);
    ofDrawBitmapStringHighlight(msg, 10, 20);
    
}

//--------------------------------------------------------------
void ofApp::drawInteractionArea(){
    ofRectangle vp = ofGetCurrentViewport();
    float r = MIN(vp.width, vp.height) * 0.5f;
    float x = vp.width * 0.5f;
    float y = vp.height * 0.5f;
    
    ofPushStyle();
    ofSetLineWidth(3);
    ofSetColor(200);
    ofNoFill();
    glDepthMask(false);
    ofDrawCircle(x, y, r);
    glDepthMask(true);
    ofPopStyle();
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key) {
        case 'C':
        case 'c':
            if(cam.getMouseInputEnabled()) cam.disableMouseInput();
            else cam.enableMouseInput();
            break;
            
        case 'F':
        case 'f':
            ofToggleFullscreen();
            break;
        case 'H':
        case 'h':
            bShowHelp ^=true;
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
