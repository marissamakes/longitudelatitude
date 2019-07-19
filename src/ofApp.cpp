#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    loadAllVideosLong();
    loadAllVideosLat();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i < 5; i++ ){
        allVideosLong[i].update();
    }
    
    for (int i = 0; i < 5; i++ ){
        allVideosLat[i].update();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if(longitude){
            
            allVideosLong[0].getTexture().drawSubsection(0, 0, ofGetWidth(), ofGetHeight()/5, 0, 0, allVideosLong[0].getWidth(), allVideosLong[0].getHeight()/3);
            allVideosLong[1].getTexture().drawSubsection(0, ofGetHeight()/5, ofGetWidth(), ofGetHeight()/5, 0, 0, allVideosLong[1].getWidth(), allVideosLong[1].getHeight()/3);
            allVideosLong[2].getTexture().drawSubsection(0, ofGetHeight()/5*2, ofGetWidth(), ofGetHeight()/5, 0, 432/3, allVideosLong[2].getWidth(), allVideosLong[2].getHeight()/3);
            allVideosLong[3].getTexture().drawSubsection(0, ofGetHeight()/5*3, ofGetWidth(), ofGetHeight()/5, 0, 432/3*2, allVideosLong[3].getWidth(), allVideosLong[3].getHeight()/3);
            allVideosLong[4].getTexture().drawSubsection(0, ofGetHeight()/5*4, ofGetWidth(), ofGetHeight()/5, 0, 432/3*2, allVideosLong[4].getWidth(), allVideosLong[4].getHeight()/3);
        

        for(int i = 0; i < 5; i++){
            allVideosLong[i].setVolume(1);
            allVideosLat[i].setVolume(0);
            allVideosLong[i].play();
            
        }
        
        
        if(norway){
            allVideosLong[0].draw(0, 0, ofGetWidth(), ofGetHeight()/5*3);
            ofDrawBitmapString("JOSTEDALSBREEN GLACIER, NORWAY", ofGetWidth()/4*3, 100);
            ofDrawBitmapString("LAT: 61 degr. 42′ 38'' N ", ofGetWidth()/4*3, 150);
            ofDrawBitmapString("LONG: 6 degr. 55′ 27'' E", ofGetWidth()/4*3, 180);

        } else if (leiden){
            allVideosLong[1].draw(0, ofGetHeight()/5, ofGetWidth(), ofGetHeight()/5*3);
            ofDrawBitmapString("LEIDEN, THE NETHERLANDS", ofGetWidth()/4*3, 240);
            ofDrawBitmapString("LAT: 52 degr. 9' 36.4104'' N", ofGetWidth()/4*3,290);
            ofDrawBitmapString("LONG: 4 degr. 29' 49.2360'' E", ofGetWidth()/4*3,320);
          
        }  else if (bologna) {
            allVideosLong[2].draw(0, ofGetHeight()/5, ofGetWidth(), ofGetHeight()/5*3);
            ofDrawBitmapString("BOLOGNA, ITALY", ofGetWidth()/4*3, 420);
            ofDrawBitmapString("LAT: 44 degr. 29' 56.2380'' N", ofGetWidth()/4*3, 470);
            ofDrawBitmapString("LONG: 10 degr. 19' 39.3276'' E", ofGetWidth()/4*3, 500);
 
        } else if (algiers){
            allVideosLong[3].draw(0, ofGetHeight()/5, ofGetWidth(), ofGetHeight()/5*3);
            ofDrawBitmapString("ALGIERS, ALGERIA", ofGetWidth()/4*3, 600);
            ofDrawBitmapString("LAT: 36 degr. 44' 14.0352'' N", ofGetWidth()/4*3,650);
            ofDrawBitmapString("LONG: 3 degr. 5' 11.2992'' E", ofGetWidth()/4*3,680);

        } else if (lagos){
            allVideosLong[4].draw(0, ofGetHeight()/5*2, ofGetWidth(), ofGetHeight()/5*3);
            ofDrawBitmapString("LAGOS, NIGERIA", ofGetWidth()/4*3, 770);
            ofDrawBitmapString("LAT: 6 degr. 27' 55.5192'' N", ofGetWidth()/4*3,820);
            ofDrawBitmapString("LONG: 3 degr. 24' 23.2128'' E", ofGetWidth()/4*3,850);
        }
 

        ofDrawBitmapString("MODE: LONGITUDE 0 - 10 DEGREES EAST", 100,250);
        /* select white for all lines  */
        glColor3f (1.0, 1.0, 1.0);
        
        glEnable (GL_LINE_STIPPLE);
        
        glLineStipple (10, 0xAAAA);  /*  first parameter set the dash length in px  */
        glBegin(GL_LINES);
        glVertex2f (ofGetWidth()/3, 0); /* starting points */
        glVertex2f (ofGetWidth()/3, ofGetHeight()); /* end points */
        glVertex2f (ofGetWidth()/3*2, 0); /* starting points */
        glVertex2f (ofGetWidth()/3*2, ofGetHeight());
        glEnd();
        glDisable (GL_LINE_STIPPLE);
        glFlush ();
    
    }


     if (latitude){
         
         allVideosLat[0].getTexture().drawSubsection(0, 0, ofGetWidth()/5, ofGetHeight(), 0, 0, 768/3, 720);
         allVideosLat[1].getTexture().drawSubsection(ofGetWidth()/5, 0, ofGetWidth()/5, ofGetHeight(), 0, 0, 768/3, 720);
         allVideosLat[2].getTexture().drawSubsection(ofGetWidth()/5*2, 0, ofGetWidth()/5, ofGetHeight(), 768/3, 0, 768/3, 720);
         allVideosLat[3].getTexture().drawSubsection(ofGetWidth()/5*3, 0, ofGetWidth()/5, ofGetHeight(), 768/3*2, 0, 768/3, 720);
         allVideosLat[4].getTexture().drawSubsection(ofGetWidth()/5*4, 0, ofGetWidth()/5, ofGetHeight(), 768/3*2, 0, 768/3, 720);
           

           for(int i = 0; i < 5; i++){
               allVideosLong[i].setVolume(0);
               allVideosLat[i].setVolume(1);
               allVideosLat[i].play();
           }
         
        allVideosLat[2].setVolume(0);
         

         if(LA){
             allVideosLat[0].draw(0, 0, ofGetWidth()/5*3, ofGetHeight());
             ofDrawBitmapString("LOS ANGELES, USA", 100, ofGetHeight()/5*4);
             ofDrawBitmapString("LAT: 34 degr. 3' 8.0460'' N", 100, ofGetHeight()/5*4+50);
             ofDrawBitmapString("LONG: 118 degr. 14' 37.2588'' W", 100, ofGetHeight()/5*4+30);

         } else if (algiers2){
             allVideosLat[1].draw(ofGetWidth()/5, 0, ofGetWidth()/5*3, ofGetHeight());
             ofDrawBitmapString("ALGIERS, ALGERIA", 380, ofGetHeight()/5*4);
             ofDrawBitmapString("LAT: 36 degr. 44' 14.0352'' N", 380, ofGetHeight()/5*4+50);
             ofDrawBitmapString("LONG: 3 degr. 5' 11.2992'' E", 380, ofGetHeight()/5*4+30);

         } else if (hebron){
             allVideosLat[2].draw(ofGetWidth()/5, 0, ofGetWidth()/5*3, ofGetHeight());
             ofDrawBitmapString("HEBRON, WEST BANK, PALESTINE", 640, ofGetHeight()/5*4);
             ofDrawBitmapString("LAT: 31 degr. 31′ 57.248'' N ", 640, ofGetHeight()/5*4+50);
             ofDrawBitmapString("LONG: 35 degr. 5' 59.374 '' E", 640, ofGetHeight()/5*4+30);

         } else if (amritsar){
             allVideosLat[3].draw(ofGetWidth()/5, 0, ofGetWidth()/5*3, ofGetHeight());
             ofDrawBitmapString("AMRITSAR, PUNJAB, INDIA", 900, ofGetHeight()/5*4);
             ofDrawBitmapString("LAT: 31 degr. 38' 2.3280'' N", 900, ofGetHeight()/5*4+50);
             ofDrawBitmapString("LONG: 74 degr. 52' 20.1396'' E", 900, ofGetHeight()/5*4+30);

         } else if (seoul){
             allVideosLat[4].draw(ofGetWidth()/5*2, 0, ofGetWidth()/5*3, ofGetHeight());
             ofDrawBitmapString("SEOUL, SOUTH KOREA", 1180, ofGetHeight()/5*4);
             ofDrawBitmapString("LAT: 37 degr. 31' 57.3600'' N", 1180, ofGetHeight()/5*4+50);
             ofDrawBitmapString("LONG: 127 degr. 1' 28.6032'' E", 1180, ofGetHeight()/5*4+30);
         }
         
         ofDrawBitmapString("MODE: LATITUTE 30 - 40 DEGREES NORTH", 100,250);
         /* select white for all lines  */
         glColor3f (1.0, 1.0, 1.0);
         
         glEnable (GL_LINE_STIPPLE);
         
         glLineStipple (10, 0xAAAA);  /*  first parameter set the dash length in px  */
         glBegin(GL_LINES);
         glVertex2f (0, ofGetHeight()/3); /* starting points */
         glVertex2f (ofGetWidth(), ofGetHeight()/3); /* end points */
         glVertex2f (0, ofGetHeight()/3*2); /* starting points */
         glVertex2f (ofGetWidth(), ofGetHeight()/3*2);
         glEnd();
         glDisable (GL_LINE_STIPPLE);
         glFlush ();
     }
    
    ofDrawBitmapString("LONGITUDE // LATITUDE", 100, 100);
    
    /* mapping of mouse coordinates to geographical coordinates */
    int xCo = mouseX;
    int yCo = mouseY;
    int newxCo = 0;
    int newyCo = 0;
    newxCo = ofMap(xCo, 0, 1440, -180, 180);
    newyCo = ofMap(yCo, 0, 900, -180, 180);
    
    string LAT;
    string LONG;
    string arrowkeys;
    
    if(newyCo < 0){
        LAT = "N";
    } else if (newyCo > 0){
        LAT = "S";
    } else { LAT = " ";}
    
    if(newxCo > 0){
        LONG = "E";
    } else if (newxCo < 0){
        LONG = "W";
    } else { LONG = " ";}
    
    if(longitude){
        arrowkeys = "< >";
    }  else if (latitude){
        arrowkeys = "^ v";
    }
    
    ofDrawBitmapString("MAP COORDINATES // LAT: " + ofToString(newxCo) + " degr. " + LAT  + " | LONG: " + ofToString(newyCo) + " degr. " + LONG, 100,150);
    ofDrawBitmapString("Press the " + arrowkeys + " arrow keys to switch axis", 100, 210);
    
    }

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if(key == OF_KEY_LEFT || key == OF_KEY_RIGHT){
        latitude = true;
        longitude = false;
    }
    
    if(key == OF_KEY_UP || key == OF_KEY_DOWN){
        latitude = false;
        longitude = true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
    // ---------------- LONGITUDE
    
    if((x > ofGetWidth()/3*1 && x < ofGetWidth()/3*2) && (y < ofGetHeight()/5*1)){
        norway = true;}
    else { norway = false; }

    if((x > ofGetWidth()/3*1 && x < ofGetWidth()/3*2) && (y > ofGetHeight()/5*1 && y < ofGetHeight()/5*2)) {
        leiden = true; }
    else { leiden = false; }
    
    if((x > ofGetWidth()/3*1 && x < ofGetWidth()/3*2) && (y > ofGetHeight()/5*2 && y < ofGetHeight()/5*3)) {
        bologna = true; }
    else { bologna = false; }
    
    if ((x > ofGetWidth()/3*1 && x < ofGetWidth()/3*2) && (y > ofGetHeight()/5*3 && y < ofGetHeight()/5*4)) {
        algiers = true; }
    else { algiers = false; }
    
    if ((x > ofGetWidth()/3*1 && x < ofGetWidth()/3*2) && (y > ofGetHeight()/5*4)) {
        lagos = true; }
    else { lagos = false; }
    
    //---------------- LATITUDE
    
    if( (y > ofGetHeight()/3*1 && y < ofGetHeight()/3*2) && (x < ofGetWidth()/5*1)){
        LA = true;}
    else { LA = false;}

    if( (y > ofGetHeight()/3*1 && y < ofGetHeight()/3*2) && (x > ofGetWidth()/5*1) && x < ofGetWidth()/5*2){
        algiers2 = true;}
    else { algiers2 = false;}
    
    if( (y > ofGetHeight()/3*1 && y < ofGetHeight()/3*2) && (x > ofGetWidth()/5*2) && x < ofGetWidth()/5*3){
        hebron = true;}
    else { hebron = false;}
    
    if( (y > ofGetHeight()/3*1 && y < ofGetHeight()/3*2) && (x > ofGetWidth()/5*3) && x < ofGetWidth()/5*4){
        amritsar = true;}
    else { amritsar = false;}
    
    if( (y > ofGetHeight()/3*1 && y < ofGetHeight()/3*2) && (x > ofGetWidth()/5*4)){
        seoul = true;}
    else { seoul = false;}
    
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
//--------------------------------------------------------------

    void ofApp::loadAllVideosLong(){
    allVideosLong[0].load("Norway.mp4");
    allVideosLong[1].load("Leiden_fiets2.mp4");
    allVideosLong[2].load("Bologna.mp4");
    allVideosLong[3].load("algiers1.mp4");
    allVideosLong[4].load("lagos2.mp4");
        
    }

//------------------------------------------------------

void ofApp::loadAllVideosLat(){
    allVideosLat[0].load("LA.mp4");
    allVideosLat[1].load("algiers2.mp4");
    allVideosLat[2].load("Hebron.mp4");
    allVideosLat[3].load("Amritsar.mp4");
    allVideosLat[4].load("Seoul.mp4");
    
}
