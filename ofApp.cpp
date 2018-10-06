#include "ofApp.h"
#include <time.h>

void ofApp::fallingObjects()
{
    int i;
    int k;
    for (i=99; i>=0; i--)
    {
        for (k=99; k>=0; k--)
            {
                if (board[i][k]==2)
                {
                    if ((k+1)>99) board[i][k]=0;
                    else
                    {
                        board[i][k+1]=board[i][k];
                        board[i][k]=0;
                    }

                }
            }
    }
}
//:):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):)
void ofApp::clearBoard()
{
    int i;
    int k;
    for (i=0; i<100; i++)
    {
        for (k=0; k<100; k++)
            {
                board[i][k]=0;
            }
    }
}
//:):):):):):):):):):):):):):):):):):):):):):):):):):):):):):):)
void ofApp::drawBoard()
{
    int i;
    int k;
    for (i=0; i<100; i++)
    {
        for (k=0; k<100; k++)
        {
            if (board[i][k] == 0)
                {
                    ofSetColor(0,0,0);
                    ofRect(i*(width/100),k*(height/100),width/100,height/100);
                }
            else if (board[i][k] == 1)
                {
                    ofSetColor(128,0,255);
                    ofRect(i*(width/100),k*(height/100),width/100,height/100);
                }
            else if (board[i][k] == 2)
                {
                    ofSetColor(0,255,0);
                    ofRect(i*(width/100),k*(height/100),width/100,height/100);
                }
        }
    }
}
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//--------------------------------------------------------------
void ofApp::setup(){
    srand(time(NULL));
    ofSetFrameRate(60);
    clearBoard();
}
//--------------------------------------------------------------
void ofApp::update(){
    board[rand()%100][1]=2;
    width  = ofGetWindowWidth();
    height = ofGetWindowHeight();

}
//--------------------------------------------------------------
void ofApp::draw(){
    drawBoard();
    fallingObjects();
}
//--------------------------------------------------------------
void ofApp::mousePressed(int a, int b, int button){

}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'a' && playerX > 0)
    {
        playerX--;
        board[playerX][99]=1;
        board[playerX+1][99]=0;
    }
    else if (key == 'd' && playerX < 99)
    {
        playerX++;
        board[playerX][99]=1;
        board[playerX-1][99]=0;
    }
}
//--------------------------------------------------------------
