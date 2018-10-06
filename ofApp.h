#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
	    void fallingObjects();
	    void clearBoard();
	    void drawBoard();
	    int board[105][105];
	    int playerX = 50;
	    float width;
	    float height;

		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);

};
