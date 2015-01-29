#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
   ofSetCircleResolution(100);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // Set Positions based on screen resolution
    float eyeHeight = ofGetWidth()*0.3;
    float leftEyeCenter = ofGetWidth()/3.0;
    float rightEyeCenter = (ofGetWidth()*2)/3.0;
    float eyeRadius = leftEyeCenter/2.0;
    
    //Draw Eyes
    ofNoFill();
    ofSetColor(255);
    ofCircle(leftEyeCenter,eyeHeight,eyeRadius);
    ofCircle(rightEyeCenter,eyeHeight,eyeRadius);

    ofPoint leftPos(leftEyeCenter,eyeHeight);
    ofPoint rightPos(rightEyeCenter,eyeHeight);

    // calculate important points
    ofPoint eyeCenter(ofGetWidth()/2.0,eyeHeight);
    ofPoint currentMousePos(mouseX,mouseY);

    // Create points for the eyeballs
    ofPoint rightEyeballCenter(rightEyeCenter,eyeHeight);
    ofPoint leftEyeballCenter(leftEyeCenter,eyeHeight);
    
    // Calculate distance from the eyeballs to the mouse
    float leftLookDistance =  ofDist(leftEyeballCenter.x, leftEyeballCenter.y,  mouseX, mouseY);
    float rightLookDistance = ofDist(rightEyeballCenter.x,rightEyeballCenter.y, mouseX, mouseY);
    
    // remap the eyeball distances
    float leftOffset =   ofMap(leftLookDistance,  0, ofGetWidth()/2.0, 0, eyeRadius/3);
    float rightOffset  = ofMap(rightLookDistance, 0, ofGetWidth()/2.0, 0, eyeRadius/3);
    
    // Figure out new points for the eyeballs
    leftPos =  leftEyeballCenter + (currentMousePos - leftEyeballCenter).normalize()*leftOffset;
    rightPos = rightEyeballCenter + (currentMousePos - rightEyeballCenter).normalize()*rightOffset;
    
    
    // Draw Eyeballs
    ofFill();
    ofSetColor(100,100,255);
    ofCircle(leftPos,eyeRadius/4.0);
    ofCircle(rightPos,eyeRadius/4.0);

    // draw smile
    ofPath smile;
    ofPoint toothCenter = ofPoint(ofGetWidth()/2.0,ofGetHeight()*.7);
    smile.setStrokeColor(ofColor(255,0,0));
    smile.setFillColor(ofColor(255,0,0));
    smile.setFilled(true);
    smile.setStrokeWidth(4);
    smile.setCircleResolution(50);
    smile.arc(toothCenter, ofGetWidth()*.3,ofGetHeight()*.2, 0, 180);
    smile.close();
    smile.draw();

    // Draw Teeth
    ofSetColor(255);
    ofFill();
    float toothWidth = ofGetWidth()/16.0;
    float toothHeight = ofGetHeight()/10.0;
    
    ofPushMatrix();
        ofTranslate(toothCenter);

        ofPushMatrix();
          ofTranslate(toothWidth,0);
          ofRect(0,0,toothWidth,toothHeight);
        ofPopMatrix();

        ofTranslate(-toothWidth*2,0);
          ofRect(0,0,toothWidth,toothHeight);
        ofPopMatrix();

    ofPopMatrix();

}