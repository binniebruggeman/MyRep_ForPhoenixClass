#include "ofApp.h"


//int xpos;
//int ypos;
//int speed;

ofImage beetle; //player
ofImage foot;   //enemy
ofSoundPlayer splat;    //die sound


float playerRadius;
//float playerX = 510;
//float playerY = 650;


float enemyRadius;
float enemyX;
float enemyY;

int score;
int speed;
int enemySpeed;
bool hasLostGame;

//Trying to set the x and y position of the image to the centre
//so that I can change the code lines involving the distance calculation
//(when enemy hits player)
//ofPoint ofImage::getCentre();

//Other ways of doing this is by checking the size of the picture and then
//say mouseX-.. mouseY-.. so that the mouse is in the centre of the image




//--------------------------------------------------------------
void ofApp::setup(){
    beetle.loadImage("images/beetle.png");
    foot.loadImage("images/foot.png");
    splat.loadSound("sounds/splat.wav");


    playerRadius = 40;
    enemyRadius = 120;
    enemyX = ofRandom(ofGetWidth());
    
    //show the enemy off screen to start
    enemyY = 0 -enemyRadius;
    
    score = 0;
    enemySpeed = 20;
    hasLostGame = false;
    
    ofSetVerticalSync(true);
    
    

}

//--------------------------------------------------------------
void ofApp::update(){

    //If the enemy disappears off the screen without hitting you,
    //add to the score and make the enemy bigger
//    if(hasLostGame==false) {
//        if (enemyY > ofGetHeight() + enemyRadius) {
//            score ++;
//            enemyRadius += 2;
//            enemyY = 0-enemyRadius;
//            enemyX = ofRandom(ofGetWidth());
//        }
//    }
    
    if(hasLostGame==false) {
        if (enemyY > ofGetHeight()) {
            score ++;
            enemyY = 0;
            enemyX = ofRandom(ofGetWidth());
        }
    }
    
    enemyY += enemySpeed;
    
    //If the enemy hits the player you lose the game
//    if(ofDist(mouseX, mouseY, enemyX, enemyY) <= enemyRadius + playerRadius){
    
    if(ofDist(mouseX, mouseY, enemyX, enemyY) <= 50){
        hasLostGame = true;
        splat.play();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0, 0, 0);
    
    //player
    beetle.draw(mouseX-35, mouseY-37); //the -35 and -37 are to set the mouse to the centre of the image
    
    //this creates the enemy
//    ofSetColor(255, 0, 0);
//    ofCircle(enemyX, enemyY, enemyRadius);
    foot.draw(enemyX-105,enemyY-83); //the -105 and -83 are to set the x and y position to the centre of the image

    
    //this creates the player
//    ofSetColor(0, 0, 255);
//    ofCircle(playerX, playerY, playerRadius);
    

    
    ofSetColor(255, 255, 255);
    ofDrawBitmapString("Score: "+ ofToString(score), 120, 40);
    
    if(hasLostGame) {
        ofDrawBitmapString("\nGame Over! Press any key to restart", 120, 40);
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
//    enemyX = ofRandom(ofGetWidth());
//    enemySpeed += 0.03;
    
    
    //This doesn't work, my player only goes up bij 10 when pressing any of the arrows
    //I've tried to change the code to seperate if's and other variations, nothing worked
    if (OF_KEY_UP) {
            mouseY -= 10;
        } else if (OF_KEY_DOWN) {
            mouseY += 10;
          } else if (OF_KEY_LEFT) {
              mouseX -= 10 ;
            } else if (OF_KEY_RIGHT) {
                mouseX += 10;
        }
    
    //can't find the code for the spacebar key
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (hasLostGame) {
        enemyX = ofRandom(ofGetWidth());
        enemyY = 0 - enemyRadius;
        enemyRadius = 20;
        hasLostGame = false;
        score = 0;
    }
    
    cout<< key;
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    //When mouse is clicked the player will jump to a random location
    //on the screen, but as soon as the mouse is released the player
    //will be at the mouse position again
    mouseX = ofRandom(ofGetWidth());
    mouseY = ofRandom(ofGetHeight());
    
    
    
   
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
