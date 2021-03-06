#include <vector>
#include "ccc_win.h"
#include "constructionBox.h"
#include "string.h"

ConstructionBox::ConstructionBox() {
}

ConstructionBox::ConstructionBox(double mapWidth, double mapHeight, std::string color, Point llcorner) {
	this->BOX_WIDTH = mapWidth;
	this->BOX_HEIGHT = mapHeight / 5;

	this->color = color;
	this->llcorner = llcorner;
	createButtons();
}

void ConstructionBox::createButtons() {
	const std::string turnCText = "Turn \nClockwise";
	const std::string turnCCText = "Turn \nCounterclockwise";
	const std::string endGameText = "End Game";
	const std::string resetText = "Reset Board";

	const double BUTTON_HEIGHT = BOX_HEIGHT / 4;

	const double X_OFFSET = BOX_WIDTH * 1.0 / 15;
	const double Y_OFFSET = BOX_HEIGHT * 1.0 / 10;

	double turnCWidth = CHAR_WIDTH * turnCText.size();
	double turnCCWidth = CHAR_WIDTH * turnCCText.size();
	double endGameWidth = CHAR_WIDTH * endGameText.size();
	double resetWidth = CHAR_WIDTH * resetText.size();

	const double TURNC_X_POS = BOX_WIDTH - X_OFFSET - turnCWidth;
	const double TURNC_Y_POS = BOX_HEIGHT - Y_OFFSET - BUTTON_HEIGHT;

	const double TURNCC_X_POS = BOX_WIDTH - X_OFFSET - turnCCWidth;
	const double TURNCC_Y_POS = BOX_HEIGHT - Y_OFFSET - BUTTON_HEIGHT;

	const double ENDGAME_X_POS = BOX_WIDTH - X_OFFSET - endGameWidth;
	const double ENDGAME_Y_POS = BOX_HEIGHT - Y_OFFSET - BUTTON_HEIGHT;

	const double RESET_X_POS = BOX_WIDTH - X_OFFSET - resetWidth;
	const double RESET_Y_POS = BOX_HEIGHT - Y_OFFSET - BUTTON_HEIGHT;

	Point turnCButtonPos(TURNC_X_POS, TURNC_Y_POS);
	turnC = Button(turnCButtonPos, BUTTON_HEIGHT, turnCText, "white");
	Point turnCCButtonPos(TURNCC_X_POS, TURNCC_Y_POS - Y_OFFSET - BUTTON_HEIGHT);
	turnCC = Button(turnCCButtonPos, BUTTON_HEIGHT, turnCCText, "white");
	Point endGameButtonPos(ENDGAME_X_POS, ENDGAME_Y_POS - 2 * Y_OFFSET - 2 * BUTTON_HEIGHT);
	endGame = Button(endGameButtonPos, BUTTON_HEIGHT, endGameText, "white");
	Point resetButtonPos(RESET_X_POS, RESET_Y_POS - 2 * Y_OFFSET - 2 * BUTTON_HEIGHT);
	reset = Button(resetButtonPos, BUTTON_HEIGHT, resetText, "white");
}

void ConstructionBox::draw() {
	drawSolidRectangle(BOX_WIDTH, BOX_HEIGHT, llcorner, WIDTH_INCREMENT, color);
	
	//draws buttons
	turnC.draw();
	turnCC.draw();
	endGame.draw();
	reset.draw();

}

Button ConstructionBox::getTurnCButton() const {
	return turnC;
}

Button ConstructionBox::getTurnCCButton() const {
	return turnCC;
}

Button ConstructionBox::getEndGameButton() const {
	return endGame;
}

Button ConstructionBox::getResetButton() const {
	return reset;
}

double ConstructionBox::getBoxHeight() const {
	return BOX_HEIGHT;
}

double ConstructionBox::getBoxWidth() const {
	return BOX_WIDTH;
}




//void test() {
//	Type fire("Fire", "Water", "Nature", 2);
//	Type water("Water", "Nature", "Fire", 3);
//	Tower t1("Meteor", 23, 5, 2, fire, Square());
//	Tower t2("Rain", 20, 10, 2, water, Square());
//	Tower t3("Blah Blah Blah", 19, 10, 2, fire, Square());
//	Tower t4("Goop", 18, 6, 2, water, Square());
//	vector<Tower> towers;
//	towers.push_back(t1);
//	towers.push_back(t2);
//	towers.push_back(t3);
//	towers.push_back(t4);
//
//	Point p(0,0);
//	ConstructionBox towerBox(towers, 30.0, 30.0, "red", p);
//	cwin.coord(0,30,30,0);
//	towerBox.draw();
//}



