#include <SFML/Graphics.hpp>
#include <iostream>
#include "Graph.h"

using namespace sf;
using namespace std;

int main() {
	// int scale = 10;
	float scale = 3.0;
	sf::RenderWindow window(
		sf::VideoMode(285 * scale, 150 * scale), "Celeb Guesser");
	// 5000, 5500

	// Celeb Guesser Text
	sf::Text text;
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {
		cout << "Font could not load. Perhaps it doesn't exist?" << endl;
	}
	sf::Font fontRabgella;
	fontRabgella.loadFromFile("Candal.ttf");

	text.setFont(fontRabgella);
	text.setString("Celeb Guesser");
	text.setPosition(115 * scale, 5 * scale);
	text.setCharacterSize(10 * scale);
	text.setFillColor(sf::Color::White);

  // color scheme
  Color color1 = {47, 69, 92}; // background
  Color color2 = {29, 205, 254};
  // Color color3 = {25, 230, 190};
  Color color4 = {52, 245, 197};
  Color color3 = {33, 178, 170};
  Color color5 = {54, 155, 222};

	// Rectangle/ Form on which buttons are
	sf::RectangleShape form(sf::Vector2f(100 * scale, 150 * scale - 0.6*scale));
	form.setFillColor(sf::Color{82, 81, 82});
  // form.setFillColor(sf::Color{47, 69, 92});
  form.setPosition(0.3*scale, 0.3*scale);
	form.setOutlineColor(sf::Color::White);
	form.setOutlineThickness(0.3 * scale);

  // Rectangle where celebrity will be shown
	sf::RectangleShape celeb(sf::Vector2f(100 * scale, 150 * scale - 0.6*scale));
	celeb.setFillColor(sf::Color{82, 81, 82});
  // form.setFillColor(sf::Color{47, 69, 92});
  celeb.setPosition(0.3*scale, 0.3*scale);
	celeb.setOutlineColor(sf::Color::White);
	celeb.setOutlineThickness(0.3 * scale);


  // Rectangle where BFS stuff is covered
	sf::RectangleShape BFScover(sf::Vector2f(175 * scale, 95 * scale));
	BFScover.setFillColor(color1);
  // form.setFillColor(sf::Color{47, 69, 92});
  BFScover.setPosition(105*scale, 50*scale);
	// BFScover.setOutlineColor(sf::Color::White);
	// BFScover.setOutlineThickness(0.3 * scale);

	// Questions for user
	sf::Text question_gender;
	sf::Text question_hairColor;
	sf::Text question_pale;
	sf::Text question_hairType;
	sf::Text question_facialHair;
	sf::Text question_bangs;
	sf::Text question_lips;
	sf::Text question_nose;
	sf::Text question_glasses;
	sf::Text question_age;

	float x = 10 * scale;
	float y = 5 * scale;

	float bx = 10 * scale;
	float by = 12 * scale;

	float w = 3 * scale;
	float l = 3 * scale;
	float space = w + (20 * scale);

	// Buttons for user clicks
	sf::RectangleShape female(sf::Vector2f(w, l));
	female.setPosition(bx, by);
	female.setFillColor(color3);
	female.setOutlineColor(sf::Color::White);
	female.setOutlineThickness(0.3 * scale);
  
	sf::Text textFemale;
	textFemale.setFont(font);
	textFemale.setString("Female");
	textFemale.setPosition(bx + scale * 5, by - scale * 0.65);
	textFemale.setCharacterSize(3.45 * scale);
	textFemale.setFillColor(sf::Color::White);

	sf::RectangleShape male(sf::Vector2f(w, l));
	male.setPosition(bx + space, by);
	male.setFillColor(color3);
	male.setOutlineColor(sf::Color::White);
	male.setOutlineThickness(0.3 * scale);
  
	sf::Text textMale;
	textMale.setFont(font);
	textMale.setString("Male");
	textMale.setPosition(bx + space + scale * 5, by - (scale * 0.65));
	textMale.setCharacterSize(3.45 * scale);
	textMale.setFillColor(sf::Color::White);

	by += 15 * scale;
	sf::RectangleShape black_hair(sf::Vector2f(w, l));
	black_hair.setPosition(bx, by);
	black_hair.setFillColor(color3);
	black_hair.setOutlineColor(sf::Color::White);
	black_hair.setOutlineThickness(0.3 * scale);
  
	sf::Text textBlackHair;
	textBlackHair.setFont(font);
	textBlackHair.setString("Black");
	textBlackHair.setPosition(bx + scale * 5, by - scale * 0.65);
	textBlackHair.setCharacterSize(3.45 * scale);
	textBlackHair.setFillColor(sf::Color::White);

	sf::RectangleShape brown_hair(sf::Vector2f(w, l));
	brown_hair.setPosition(bx + space, by);
	brown_hair.setFillColor(color3);
	brown_hair.setOutlineColor(sf::Color::White);
	brown_hair.setOutlineThickness(0.3 * scale);
	sf::Text textBrownHair;
	textBrownHair.setFont(font);
	textBrownHair.setString("Brown");
	textBrownHair.setPosition(bx + space + scale * 5, by - scale * 0.65);
	textBrownHair.setCharacterSize(3.45 * scale);
	textBrownHair.setFillColor(sf::Color::White);

	sf::RectangleShape blonde_hair(sf::Vector2f(w, l));
	blonde_hair.setPosition(bx + space * 2, by);
	blonde_hair.setFillColor(color3);
	blonde_hair.setOutlineColor(sf::Color::White);
	blonde_hair.setOutlineThickness(0.3 * scale);
	sf::Text textBlondeHair;
	textBlondeHair.setFont(font);
	textBlondeHair.setString("Blonde");
	textBlondeHair.setPosition(bx + space * 2 + scale * 5, by - scale * 0.65);
	textBlondeHair.setCharacterSize(3.45 * scale);
	textBlondeHair.setFillColor(sf::Color::White);

	by += 5 * scale;
	sf::RectangleShape grey_hair(sf::Vector2f(w, l));
	grey_hair.setPosition(bx, by);
	grey_hair.setFillColor(color3);
	grey_hair.setOutlineColor(sf::Color::White);
	grey_hair.setOutlineThickness(0.3 * scale);
	sf::Text textGreyHair;
	textGreyHair.setFont(font);
	textGreyHair.setString("Gray");
	textGreyHair.setPosition(bx + scale * 5, by - scale * 0.65);
	textGreyHair.setCharacterSize(3.45 * scale);
	textGreyHair.setFillColor(sf::Color::White);

	sf::RectangleShape no_hair(sf::Vector2f(w, l));
	no_hair.setPosition(bx + space, by);
	no_hair.setFillColor(color3);
	no_hair.setOutlineColor(sf::Color::White);
	no_hair.setOutlineThickness(0.3 * scale);
	sf::Text textNoHair;
	textNoHair.setFont(font);
	textNoHair.setString("Bald");
	textNoHair.setPosition(bx + space * 1 + scale * 5, by - scale * 0.65);
	textNoHair.setCharacterSize(3.45 * scale);
	textNoHair.setFillColor(sf::Color::White);

	sf::RectangleShape other_hair(sf::Vector2f(w, l));
	other_hair.setPosition(bx + space * 2, by);
	other_hair.setFillColor(color3);
	other_hair.setOutlineColor(sf::Color::White);
	other_hair.setOutlineThickness(0.3 * scale);
	sf::Text textOtherHair;
	textOtherHair.setFont(font);
	textOtherHair.setString("Other");
	textOtherHair.setPosition(bx + space * 2 + scale * 5, by - scale * 0.65);
	textOtherHair.setCharacterSize(3.45 * scale);
	textOtherHair.setFillColor(sf::Color::White);

	by += 15 * scale;
	sf::RectangleShape pale_yes(sf::Vector2f(w, l));
	pale_yes.setPosition(bx, by);
	pale_yes.setFillColor(color3);
	pale_yes.setOutlineColor(sf::Color::White);
	pale_yes.setOutlineThickness(0.3 * scale);
	sf::Text textPale;
	textPale.setFont(font);
	textPale.setString("Yes");
	textPale.setPosition(bx + scale * 5, by - scale * 0.65);
	textPale.setCharacterSize(3.45 * scale);
	textPale.setFillColor(sf::Color::White);

	sf::RectangleShape pale_no(sf::Vector2f(w, l));
	pale_no.setPosition(bx + space, by);
	pale_no.setFillColor(color3);
	pale_no.setOutlineColor(sf::Color::White);
	pale_no.setOutlineThickness(0.3 * scale);
	sf::Text textNotPale;
	textNotPale.setFont(font);
	textNotPale.setString("No");
	textNotPale.setPosition(bx + space + scale * 5, by - scale * 0.65);
	textNotPale.setCharacterSize(3.45 * scale);
	textNotPale.setFillColor(sf::Color::White);

	by += 15 * scale;
	sf::RectangleShape straight_hair(sf::Vector2f(w, l));
	// cout << "bx of straight hair: " << bx << endl
	straight_hair.setPosition(bx, by);
	straight_hair.setFillColor(color3);
	straight_hair.setOutlineColor(sf::Color::White);
	straight_hair.setOutlineThickness(0.3 * scale);
  sf::Text textStraight;
	textStraight.setFont(font);
	textStraight.setString("Straight");
	textStraight.setPosition(bx + scale * 5, by - scale * 0.65);
	textStraight.setCharacterSize(3.45 * scale);
	textStraight.setFillColor(sf::Color::White);

	sf::RectangleShape wavy_hair(sf::Vector2f(w, l));
	wavy_hair.setPosition(bx + space, by);
	wavy_hair.setFillColor(color3);
	wavy_hair.setOutlineColor(sf::Color::White);
	wavy_hair.setOutlineThickness(0.3 * scale);
  sf::Text textWavy;
	textWavy.setFont(font);
	textWavy.setString("Wavy");
	textWavy.setPosition(bx + space + scale * 5, by - scale * 0.65);
	textWavy.setCharacterSize(3.45 * scale);
	textWavy.setFillColor(sf::Color::White);

	sf::RectangleShape other_hairType(sf::Vector2f(w, l));
	other_hairType.setPosition(bx + space * 2, by);
	other_hairType.setFillColor(color3);
	other_hairType.setOutlineColor(sf::Color::White);
	other_hairType.setOutlineThickness(0.3 * scale);
  sf::Text textOther;
	textOther.setFont(font);
	textOther.setString("Other");
	textOther.setPosition(bx + space * 2 + scale * 5, by - scale * 0.65);
	textOther.setCharacterSize(3.45 * scale);
	textOther.setFillColor(sf::Color::White);

	by += 15 * scale;
	sf::RectangleShape mustache(sf::Vector2f(w, l));
	mustache.setPosition(bx, by);
	mustache.setFillColor(color3);
	mustache.setOutlineColor(sf::Color::White);
	mustache.setOutlineThickness(0.3 * scale);
  sf::Text textMustache;
	textMustache.setFont(font);
	textMustache.setString("Mustache");
	textMustache.setPosition(bx + scale * 5, by - scale * 0.65);
	textMustache.setCharacterSize(3.45 * scale);
	textMustache.setFillColor(sf::Color::White);

	sf::RectangleShape beard(sf::Vector2f(w, l));
	beard.setPosition(bx + space, by);
	beard.setFillColor(color3);
	beard.setOutlineColor(sf::Color::White);
	beard.setOutlineThickness(0.3 * scale);
  sf::Text textBeard;
	textBeard.setFont(font);
	textBeard.setString("Beard");
	textBeard.setPosition(bx + space + scale * 5, by - scale * 0.65);
	textBeard.setCharacterSize(3.45 * scale);
	textBeard.setFillColor(sf::Color::White);

	sf::RectangleShape goatee(sf::Vector2f(w, l));
	goatee.setPosition(bx + space * 2, by);
	goatee.setFillColor(color3);
	goatee.setOutlineColor(sf::Color::White);
	goatee.setOutlineThickness(0.3 * scale);
  sf::Text textGoatee;
	textGoatee.setFont(font);
	textGoatee.setString("Other");
	textGoatee.setPosition(bx + space * 2 + scale * 5, by - scale * 0.65);
	textGoatee.setCharacterSize(3.45 * scale);
	textGoatee.setFillColor(sf::Color::White);

	sf::RectangleShape no_faceHair(sf::Vector2f(w, l));
	no_faceHair.setPosition(bx + space * 3, by);
	no_faceHair.setFillColor(color3);
	no_faceHair.setOutlineColor(sf::Color::White);
	no_faceHair.setOutlineThickness(0.3 * scale);
  sf::Text textNoFacialHair;
	textNoFacialHair.setFont(font);
	textNoFacialHair.setString("No");
	textNoFacialHair.setPosition(bx + space * 3 + scale * 5, by - scale * 0.65);
	textNoFacialHair.setCharacterSize(3.45 * scale);
	textNoFacialHair.setFillColor(sf::Color::White);

	by += 9 * scale;
	sf::RectangleShape bangs_yes(sf::Vector2f(w, l));
	bangs_yes.setPosition(bx + space * 2, by);
	bangs_yes.setFillColor(color3);
	bangs_yes.setOutlineColor(sf::Color::White);
	bangs_yes.setOutlineThickness(0.3 * scale);
	sf::Text textBangs;
	textBangs.setFont(font);
	textBangs.setString("Yes");
	textBangs.setPosition(bx + space * 2 + scale * 5, by - scale * 0.65);
	textBangs.setCharacterSize(3.45 * scale);
	textBangs.setFillColor(sf::Color::White);

	sf::RectangleShape bangs_no(sf::Vector2f(w, l));
	bangs_no.setPosition(bx + space * 3, by);
	bangs_no.setFillColor(color3);
	bangs_no.setOutlineColor(sf::Color::White);
	bangs_no.setOutlineThickness(0.3 * scale);
	sf::Text textNoBangs;
	textNoBangs.setFont(font);
	textNoBangs.setString("No");
	textNoBangs.setPosition(bx + space * 3 + scale * 5, by - scale * 0.65);
	textNoBangs.setCharacterSize(3.45 * scale);
	textNoBangs.setFillColor(sf::Color::White);

	by += 10 * scale;
	sf::RectangleShape biglips_yes(sf::Vector2f(w, l));
	biglips_yes.setPosition(bx + space * 2, by);
	biglips_yes.setFillColor(color3);
	biglips_yes.setOutlineColor(sf::Color::White);
	biglips_yes.setOutlineThickness(0.3 * scale);
	sf::Text textLips;
	textLips.setFont(font);
	textLips.setString("Yes");
	textLips.setPosition(bx + space * 2 + scale * 5, by - scale * 0.65);
	textLips.setCharacterSize(3.45 * scale);
	textLips.setFillColor(sf::Color::White);

	sf::RectangleShape biglips_no(sf::Vector2f(w, l));
	biglips_no.setPosition(bx + space * 3, by);
	biglips_no.setFillColor(color3);
	biglips_no.setOutlineColor(sf::Color::White);
	biglips_no.setOutlineThickness(0.3 * scale);
	sf::Text textNoLips;
	textNoLips.setFont(font);
	textNoLips.setString("No");
	textNoLips.setPosition(bx + space * 3 + scale * 5, by - scale * 0.65);
	textNoLips.setCharacterSize(3.45 * scale);
	textNoLips.setFillColor(sf::Color::White);

	by += 10 * scale;
	sf::RectangleShape bignose_yes(sf::Vector2f(w, l));
	bignose_yes.setPosition(bx + space * 2, by);
	bignose_yes.setFillColor(color3);
	bignose_yes.setOutlineColor(sf::Color::White);
	bignose_yes.setOutlineThickness(0.3 * scale);
	sf::Text textNose;
	textNose.setFont(font);
	textNose.setString("Yes");
	textNose.setPosition(bx + space * 2 + scale * 5, by - scale * 0.65);
	textNose.setCharacterSize(3.45 * scale);
	textNose.setFillColor(sf::Color::White);

	sf::RectangleShape bignose_no(sf::Vector2f(w, l));
	bignose_no.setPosition(bx + space * 3, by);
	bignose_no.setFillColor(color3);
	bignose_no.setOutlineColor(sf::Color::White);
	bignose_no.setOutlineThickness(0.3 * scale);
	sf::Text textNoNose;
	textNoNose.setFont(font);
	textNoNose.setString("No");
	textNoNose.setPosition(bx + space * 3 + scale * 5, by - scale * 0.65);
	textNoNose.setCharacterSize(3.45 * scale);
	textNoNose.setFillColor(sf::Color::White);

	by += 10 * scale;
	sf::RectangleShape glasses_yes(sf::Vector2f(w, l));
	glasses_yes.setPosition(bx + space * 2, by);
	glasses_yes.setFillColor(color3);
	glasses_yes.setOutlineColor(sf::Color::White);
	glasses_yes.setOutlineThickness(0.3 * scale);
  sf::Text textGlasses;
	textGlasses.setFont(font);
	textGlasses.setString("Yes");
	textGlasses.setPosition(bx + space * 2 + scale * 5, by - scale * 0.65);
	textGlasses.setCharacterSize(3.45 * scale);
	textGlasses.setFillColor(sf::Color::White);

	sf::RectangleShape glasses_no(sf::Vector2f(w, l));
	glasses_no.setPosition(bx + space * 3, by);
	glasses_no.setFillColor(color3);
	glasses_no.setOutlineColor(sf::Color::White);
	glasses_no.setOutlineThickness(0.3 * scale);
  sf::Text textNoGlasses;
  textNoGlasses.setFont(font);
	textNoGlasses.setString("No");
	textNoGlasses.setPosition(bx + space * 3 + scale * 5, by - scale * 0.65);
	textNoGlasses.setCharacterSize(3.45 * scale);
	textNoGlasses.setFillColor(sf::Color::White);

	by += 10 * scale;
	sf::RectangleShape young(sf::Vector2f(w, l));
	young.setPosition(bx + space * 2, by);
	young.setFillColor(color3);
	young.setOutlineColor(sf::Color::White);
	young.setOutlineThickness(0.3 * scale);
  sf::Text textYoung;
  textYoung.setFont(font);
	textYoung.setString("Yes");
	textYoung.setPosition(bx + space * 2 + scale * 5, by - scale * 0.65);
	textYoung.setCharacterSize(3.45 * scale);
	textYoung.setFillColor(sf::Color::White);

	sf::RectangleShape old(sf::Vector2f(w, l));
	old.setPosition(bx + space * 3, by);
	old.setFillColor(color3);
	old.setOutlineColor(sf::Color::White);
	old.setOutlineThickness(0.3 * scale);
  sf::Text textOld;
  textOld.setFont(font);
	textOld.setString("No");
	textOld.setPosition(bx + space * 3 + scale * 5, by - scale * 0.65);
	textOld.setCharacterSize(3.45 * scale);
	textOld.setFillColor(sf::Color::White);

	// questions
	question_gender.setFont(font);
	question_gender.setString("What do you most identify with? ");
	question_gender.setPosition(x, y);
	question_gender.setCharacterSize(3.5 * scale);
	question_gender.setFillColor(sf::Color::White);
	y += 15 * scale;

	question_hairColor.setFont(font);
	question_hairColor.setString("What is your hair color? ");
	question_hairColor.setPosition(x, y);
	question_hairColor.setCharacterSize(3.5 * scale);
	question_hairColor.setFillColor(sf::Color::White);
	y += 20 * scale;
	question_pale.setFont(font);
	question_pale.setString(
		"Would you consider yourself as having pale skin? ");
	question_pale.setPosition(x, y);
	question_pale.setCharacterSize(3.5 * scale);
	question_pale.setFillColor(sf::Color::White);
	y += 15 * scale;
	question_hairType.setFont(font);
	question_hairType.setString("What is your hair type? ");
	question_hairType.setPosition(x, y);
	question_hairType.setCharacterSize(3.5 * scale);
	question_hairType.setFillColor(sf::Color::White);
	y += 15 * scale;
	question_facialHair.setFont(font);
	question_facialHair.setString("Do you have facial hair? ");
	question_facialHair.setPosition(x, y);
	question_facialHair.setCharacterSize(3.5 * scale);
	question_facialHair.setFillColor(sf::Color::White);
	y += 15 * scale;
	question_bangs.setFont(font);
	question_bangs.setString("Do you have bangs? ");
	question_bangs.setPosition(x, y);
	question_bangs.setCharacterSize(3.5 * scale);
	question_bangs.setFillColor(sf::Color::White);
	y += 10 * scale;
	question_lips.setFont(font);
	question_lips.setString("Do you have big lips? ");
	question_lips.setPosition(x, y);
	question_lips.setCharacterSize(3.5 * scale);
	question_lips.setFillColor(sf::Color::White);
	y += 10 * scale;
	question_nose.setFont(font);
	question_nose.setString("Do you have a big nose? ");
	question_nose.setPosition(x, y);
	question_nose.setCharacterSize(3.5 * scale);
	question_nose.setFillColor(sf::Color::White);
	y += 10 * scale;
	question_glasses.setFont(font);
	question_glasses.setString("Do you eyeglasses? ");
	question_glasses.setPosition(x, y);
	question_glasses.setCharacterSize(3.5 * scale);
	question_glasses.setFillColor(sf::Color::White);
	y += 10 * scale;
	question_age.setFont(font);
	// question_age.setString("Are you young?");
  question_age.setString("Are you young?");
	question_age.setPosition(x, y);
	question_age.setCharacterSize(3.5 * scale);
	question_age.setFillColor(sf::Color::White);

  
  // sf::RectangleShape form(sf::Vector2f(100 * scale, 550 * scale));
  // submit button
  sf::RectangleShape DFSsubmit(sf::Vector2f(65*scale, 15*scale));
  DFSsubmit.setPosition((100-65)/2*scale, 132.5 * scale);
  DFSsubmit.setFillColor(color5);
  DFSsubmit.setOutlineColor(sf::Color::White);
  DFSsubmit.setOutlineThickness(0.3 * scale);
  sf::Text textSubmit;
  textSubmit.setFont(font);
  textSubmit.setStyle(Text::Bold);
	textSubmit.setString("SUBMIT");
	textSubmit.setPosition(((35/2) + (65/2) - 11.5)*scale, (132.5 + (15/2) - 4.5) * scale);
	textSubmit.setCharacterSize(6 * scale);
	textSubmit.setFillColor(sf::Color::White);
  textSubmit.setOutlineColor(color1);
  textSubmit.setOutlineThickness(0.3 * scale);
  sf::Text textDFS;
  textDFS.setFont(font);
	textDFS.setString("(Your celebrity lookalike will be found via a DFS search!)");
	textDFS.setPosition(((35/2) + (65/2) - 29)*scale, (132.5 + (15/2) + 3) * scale);
	textDFS.setCharacterSize(2.5 * scale);
	textDFS.setFillColor(sf::Color::White);

  // text.setPosition(115 * scale, 5 * scale);
  sf::RectangleShape BFSVisual(sf::Vector2f(50*scale, 15*scale));
  BFSVisual.setPosition(230*scale, 5* scale);
  BFSVisual.setFillColor(color5);
  BFSVisual.setOutlineColor(sf::Color::White);
  BFSVisual.setOutlineThickness(0.3 * scale);
  sf::Text textBFSButton;
  textBFSButton.setFont(font);
  textBFSButton.setStyle(Text::Bold);
	textBFSButton.setString("BFS Visualization");
	textBFSButton.setPosition(233*scale, 7 * scale);
	textBFSButton.setCharacterSize(5 * scale);
	textBFSButton.setFillColor(sf::Color::White);
  textBFSButton.setOutlineColor(color1);
  textBFSButton.setOutlineThickness(0.3 * scale);
  sf::Text textBFS;
  textBFS.setFont(font);
	textBFS.setString("(Visualize how a BFS in this graph would work!)");
	textBFS.setPosition(231*scale, 15* scale);
	textBFS.setCharacterSize(2.5 * scale);
	textBFS.setFillColor(sf::Color::White);


  bool BFSclicked = false; // ************
  bool DFS = false; 

   string ID = "";
    bool mouse_clicked = false;
    float xpos1 = bx;
    float xpos2 = bx + space;
    float xpos3 = bx + space * 2;
    float xpos4 = bx + space * 3;
    float ypos = 12 * scale;
    cout << "xpos1: " << xpos1  << endl;
    cout << "xpos1: " << xpos2  << endl;
    cout << "xpos1: " << xpos3  << endl;
    cout << "xpos1: " << xpos4  << endl;
    int num = 0;
  
  
	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();

      sf::Vector2i pos = sf::Mouse::getPosition();
            int xM = event.mouseButton.x;
            int yM = event.mouseButton.y;
            if(event.type == Event::MouseButtonPressed) {
                //cout << xM << endl;
               // cout << yM << endl;
                // female or male
                if(12 * scale < yM && yM < 12 * scale + l){
                    if(xpos1 < xM && xM < xpos1 + w) {
                      female.setFillColor(color5); 
                      ID += "f";
                    }
                        
                    else if(xpos2 < xM && xM < xpos2 + w) {
                       ID += "m"; 
                       male.setFillColor(color5);
                    }
                       
                }

                // ypos += 15 * scale;
                // cout << "ypos: " << ypos << endl;
                // black brown blonde gray bald other
                 if((12 + 15*1) * scale < yM && yM < (12 + 15*1) * scale + l){
                   // cout << "entering" << endl;
                    if(xpos1 < xM && xM < xpos1 + w) {
                        ID += "b";
                      black_hair.setFillColor(color5);
                        // ypos += 5 * scale;
                    }
                    else if(xpos2 < xM && xM < xpos2 + w) {
                        ID += "r";
                      brown_hair.setFillColor(color5);
                        // ypos += 5 * scale;
                    }
                    else if(xpos3 < xM && xM < xpos3 + w) {
                        ID += "y";
                      blonde_hair.setFillColor(color5);
                        // ypos += 5 * scale;
                    }
                    //cout << ID << endl;
                }
                else if((12 + 20*1) * scale < yM && yM < (12 + 20*1) * scale + l){
                    if(xpos1 < xM && xM < xpos1 + w){
                      grey_hair.setFillColor(color5);
                      ID += "g";
                    }
                        
                    else if(xpos2 < xM && xM < xpos2 + w){
                      no_hair.setFillColor(color5);
                        ID += "o";
                      }
                    else if(xpos3 < xM && xM < xpos3 + w){
                      other_hair.setFillColor(color5);
                        ID += "x";
                      }
                    //cout << ID << endl;
                }
                 //pale
                 if((12 + 35*1) * scale < yM && yM < (12 + 35*1) * scale + l){
                     if(xpos1 < xM && xM < xpos1 + w){
                       pale_yes.setFillColor(color5);
                         ID += "p";
                       }
                     else if(xpos2 < xM && xM < xpos2 + w){
                         ID += "c";
                       pale_no.setFillColor(color5);
                       }
                     //cout << ID << endl;
                 }

                 //hair type
                if((12 + 50*1) * scale < yM && yM < (12 + 50*1) * scale + l){
                    if(xpos1 < xM && xM < xpos1 + w){
                        ID += "s";
                      straight_hair.setFillColor(color5);
                      }
                    else if(xpos2 < xM && xM < xpos2 + w){
                        ID += "w";
                      wavy_hair.setFillColor(color5);
                      }
                    else if(xpos3 < xM && xM < xpos3 + w){
                      other_hairType.setFillColor(color5); 
                        ID += "z";
                      }
                    //cout << ID << endl;
                }
                // facial hair
                if((12 + 65*1) * scale < yM && yM < (12 + 65*1) * scale + l){
                    if(xpos1 < xM && xM < xpos1 + w){
                        ID += "m";
                      mustache.setFillColor(color5); 
                      }
                    else if(xpos2 < xM && xM < xpos2 + w){
                        ID += "n";
                      beard.setFillColor(color5); 
                      }
                    else if(xpos3 < xM && xM < xpos3 + w){
                        ID += "t";
                      goatee.setFillColor(color5); 
                      }
                    else if(xpos4 < xM && xM < xpos4 + w){
                        ID += "z";
                       no_faceHair.setFillColor(color5); 
                      }
                    //cout << ID << endl;
                }
                // bangs
                if((12 + 74*1) * scale < yM && yM < (12 + 74*1) * scale + l){
                    if(xpos3 < xM && xM < xpos3 + w){
                        ID += "b";
                      bangs_yes.setFillColor(color5); 
                      }
                    else if(xpos4 < xM && xM < xpos4 + w){
                        ID += "z";
                      bangs_no.setFillColor(color5);
                      }

                    //cout << ID << endl;
                }
                //lips
                if((12 + 84*1) * scale < yM && yM < (12 + 84*1) * scale + l){
                    if(xpos3 < xM && xM < xpos3 + w){
                        ID += "l";
                      biglips_yes.setFillColor(color5);
                      }
                    else if(xpos4 < xM && xM < xpos4 + w){
                        ID += "z";
                      biglips_no.setFillColor(color5);
                      }

                    //cout << ID << endl;
                }
                //nose
                if((12 + 94*1) * scale < yM && yM < (12 + 94*1) * scale + l){
                    if(xpos3 < xM && xM < xpos3 + w){
                        ID += "n";
                      bignose_yes.setFillColor(color5);
                      }
                    else if(xpos4 < xM && xM < xpos4 + w){
                        ID += "z";
                      bignose_no.setFillColor(color5);
                      }

                    //cout << ID << endl;
                }
                //glasses
                if((12 + 104*1) * scale < yM && yM < (12 + 104*1) * scale + l){
                    if(xpos3 < xM && xM < xpos3 + w){
                        ID += "e";
                        glasses_yes.setFillColor(color5);
                      }
                    else if(xpos4 < xM && xM < xpos4 + w){
                        ID += "z";
                      glasses_no.setFillColor(color5);
                      }

                    //cout << ID << endl;
                }
                //young
                if((12 + 114*1) * scale < yM && yM < (12 + 114*1) * scale + l){
                    if(xpos3 < xM && xM < xpos3 + w){
                        ID += "y";
                        young.setFillColor(color5);
                      }
                    else if(xpos4 < xM && xM < xpos4 + w){
                        ID += "z";
                      old.setFillColor(color5);
                      }

                    //cout << ID << endl;
                }

              //DFS SUbmit button
              if(((100-65)/2*scale) < xM && xM < ((100-65)/2*scale) + (65* scale)){
                    if(132.5* scale < yM && yM < (132.5* scale) + (15 * scale)){
                      DFS = true;
                      BFSclicked = false;
                    }
                }

              //BFS Submit button
              if((230 * scale) < xM && xM < (230*scale) + (50 * scale)){
                if((5 * scale) < yM && yM < (5*scale) + (50*scale)){
                  cout << "BFS clicked" << endl; 
                 //BFSclicked = true; 
                  BFSclicked = !BFSclicked; 
                }
              }

                cout << ID << endl;
               // cout << "ypos outside while: " << ypos << endl;
            }
  




      
		}

		// window.clear(sf::Color{59, 64, 102}); // this is bkg color
    window.clear(color1);


    
		window.draw(text);
		window.draw(form);
    
    
    if (!BFSclicked) {
      window.draw(BFScover);
    }
    else {
      // BFS background
    	sf::RectangleShape BFSback(sf::Vector2f(175 * scale, 95 * scale));
    	BFSback.setFillColor(color2);
      BFSback.setPosition(105*scale, 50*scale);
    	BFSback.setOutlineColor(sf::Color::White);
    	BFSback.setOutlineThickness(0.3 * scale);
      window.draw(BFSback);
      vector <string> v;
      // vector<string>images;
      string imageName = "pics/000001.jpg";
      // Graph g;
      v.push_back(imageName);
      v.push_back("pics/000002.jpg");
      v.push_back("pics/000003.jpg");
      v.push_back("pics/000004.jpg");
      v.push_back("pics/000005.jpg");
      v.push_back("pics/000006.jpg");
      v.push_back("pics/000007.jpg");
      v.push_back("pics/000008.jpg");
      v.push_back("pics/000009.jpg");
      v.push_back("pics/000010.jpg");
      v.push_back("pics/000011.jpg");
      v.push_back("pics/000012.jpg");
      v.push_back("pics/000013.jpg");
      v.push_back("pics/000014.jpg");
      v.push_back("pics/000015.jpg");
      v.push_back("pics/000016.jpg");
      v.push_back("pics/000017.jpg");
      // v = g.BFSTraversal();
      int count = 0;
    
      float yscale = 3.5*scale;
      float xscale = 8.0;
      float ybase = 75;
        if (v.size() > 0) { // root
          string s = v.at(0);
          Texture texture;
          texture.loadFromFile(s); // should be s
          Sprite sprite(texture);
          sprite.setPosition((105 + 175/2 - 5)*scale, 70*scale);
          sprite.setScale(0.25f, 0.25f);
          window.draw(sprite);
        }
        if (v.size() > 1) { // man 
          string s = v.at(1);
          Texture texture;
          texture.loadFromFile(s); // should be s
          Sprite sprite(texture);
          sprite.setPosition((105 + 175/2 - 61 + xscale*2.5)*scale, (ybase + yscale*1)*scale);
          sprite.setScale(0.2f, 0.2f);
          window.draw(sprite);
        }
        if (v.size() > 2) { // woman
          string s = v.at(2);
          Texture texture;
          texture.loadFromFile(s); // should be s
          Sprite sprite(texture);
          sprite.setPosition((105 + 175/2 + 55 - xscale*2.5)*scale, (ybase + yscale*1)*scale);
          sprite.setScale(0.2f, 0.2f);
          window.draw(sprite);
        }
        if (v.size() > 3) { // man w black hair
          string s = v.at(3);
          Texture texture;
          texture.loadFromFile(s); // should be s
          Sprite sprite(texture);
          sprite.setPosition((105 + 175/2 - 61)*scale, (ybase + yscale*3)*scale);
          sprite.setScale(0.10f, 0.10f);
          window.draw(sprite);
        }
      if (v.size() > 4) { // man w brown hair
          string s = v.at(4);
          Texture texture;
          texture.loadFromFile(s); // should be s
          Sprite sprite(texture);
          sprite.setPosition((105 + 175/2 - 61 + xscale*1)*scale, (ybase + yscale*3)*scale);
          sprite.setScale(0.10f, 0.10f);
          window.draw(sprite);
        }
      if (v.size() > 5) { // man w blonde hair
          string s = v.at(5);
          Texture texture;
          texture.loadFromFile(s); // should be s
          Sprite sprite(texture);
          sprite.setPosition((105 + 175/2 - 61 + xscale*2)*scale, (ybase + yscale*3)*scale);
          sprite.setScale(0.10f, 0.10f);
          window.draw(sprite);
        }
      if (v.size() > 6) { // man w grey hair
          string s = v.at(6);
          Texture texture;
          texture.loadFromFile(s); // should be s
          Sprite sprite(texture);
          sprite.setPosition((105 + 175/2 - 61 + xscale*3)*scale, (ybase + yscale*3)*scale);
          sprite.setScale(0.10f, 0.10f);
          window.draw(sprite);
        }
      if (v.size() > 7) { // man w bald hair
        string s = v.at(7);
        Texture texture;
        texture.loadFromFile(s); // should be s
        Sprite sprite(texture);
        sprite.setPosition((105 + 175/2 - 61 + xscale*4)*scale, (ybase + yscale*3)*scale);
        sprite.setScale(0.10f, 0.10f);
        window.draw(sprite);
      }
      if (v.size() > 8) { // man w other hair
        string s = v.at(8);
        Texture texture;
        texture.loadFromFile(s); // should be s
        Sprite sprite(texture);
        sprite.setPosition((105 + 175/2 - 61 + xscale*5)*scale, (ybase + yscale*3)*scale);
        sprite.setScale(0.10f, 0.10f);
        window.draw(sprite);
      }
      if (v.size() > 9) { // woman w black hair
        string s = v.at(9);
        Texture texture;
        texture.loadFromFile(s); // should be s
        Sprite sprite(texture);
        sprite.setPosition((105 + 175/2 + 59 - xscale*0)*scale, (ybase + yscale*3)*scale);
        sprite.setScale(0.10f, 0.10f);
        window.draw(sprite);
      }
      if (v.size() > 10) { // woman w brown hair
        string s = v.at(10);
        Texture texture;
        texture.loadFromFile(s); // should be s
        Sprite sprite(texture);
        sprite.setPosition((105 + 175/2 + 59 - xscale*1)*scale, (ybase + yscale*3)*scale);
        sprite.setScale(0.10f, 0.10f);
        window.draw(sprite);
      }
      if (v.size() > 11) { // woman w blonde hair
        string s = v.at(11);
        Texture texture;
        texture.loadFromFile(s); // should be s
        Sprite sprite(texture);
        sprite.setPosition((105 + 175/2 + 59 - xscale*2)*scale, (ybase + yscale*3)*scale);
        sprite.setScale(0.10f, 0.10f);
        window.draw(sprite);
      }
      if (v.size() > 12) { // woman w grey hair
        string s = v.at(12);
        Texture texture;
        texture.loadFromFile(s); // should be s
        Sprite sprite(texture);
        sprite.setPosition((105 + 175/2 + 59 - xscale*3)*scale, (ybase + yscale*3)*scale);
        sprite.setScale(0.10f, 0.10f);
        window.draw(sprite);
      }
      if (v.size() > 13) { // bald woman
        string s = v.at(13);
        Texture texture;
        texture.loadFromFile(s); // should be s
        Sprite sprite(texture);
        sprite.setPosition((105 + 175/2 + 59 - xscale*4)*scale, (ybase + yscale*3)*scale);
        sprite.setScale(0.10f, 0.10f);
        window.draw(sprite);
      }
      if (v.size() > 14) { // woman w other hair
        string s = v.at(14);
        Texture texture;
        texture.loadFromFile(s); // should be s
        Sprite sprite(texture);
        sprite.setPosition((105 + 175/2 + 59 - xscale*5)*scale, (ybase + yscale*3)*scale);
        sprite.setScale(0.10f, 0.10f);
        window.draw(sprite);
      }
    }

    //cout << "True" << endl;
    // string image = "";
    //image = g.publicDFS(ID);
   // texture1.loadFromFile(image);
    Texture texture2;
    texture2.loadFromFile("question.PNG");
    Sprite spriteq (texture2);
    spriteq.setPosition(170 * scale, 60 * scale);
    spriteq.setScale(0.8f, 0.8f);
    spriteq.setOutlineColor(color2);
    spriteq.setOutlineThickness(0.5 * scale);
      
    sf::Text question;
    question.setFont(font);
    question.setStyle(Text::Bold);
  	question.setString("Who will you match with?");
  	question.setPosition(150*scale, 30* scale);
  	question.setCharacterSize(10 * scale);
  	question.setFillColor(sf::Color::White);
    question.setOutlineColor(color1);
    question.setOutlineThickness(0.3 * scale);

      window.draw(spriteq);
      window.draw(question); 

    
    if (DFS){
      BFSclicked = false;
     cout << "True" << endl;
      string image = "";
      //image = g.publicDFS(ID);
     // texture1.loadFromFile(image);
      Texture texture1;
      texture1.loadFromFile("pics/000001.jpg");
      Sprite sprite(texture1);
      sprite.setPosition(170 * scale, 60 * scale);
      sprite.setScale(0.8f, 0.8f);
      
       sf::Text resultText;
  resultText.setFont(font);
  resultText.setStyle(Text::Bold);
	resultText.setString("Here is your Celebrity Look Alike!");
	resultText.setPosition(150*scale, 30* scale);
	resultText.setCharacterSize(5 * scale);
	resultText.setFillColor(sf::Color::White);
  resultText.setOutlineColor(color1);
  resultText.setOutlineThickness(0.3 * scale);

      window.draw(sprite);
      window.draw(resultText); 
      //DFS = false; 
    }
    
    
    
		// questions
		window.draw(question_gender);
		window.draw(question_hairColor);
		window.draw(question_pale);
		window.draw(question_hairType);
		window.draw(question_facialHair);
		window.draw(question_bangs);
		window.draw(question_lips);
		window.draw(question_nose);
		window.draw(question_glasses);
		window.draw(question_age);
    

		// buttons
    // submit button 
    window.draw(DFSsubmit); 
    window.draw(BFSVisual);

		window.draw(female);
		window.draw(male);
		window.draw(black_hair);
		window.draw(brown_hair);
		window.draw(blonde_hair);
		window.draw(grey_hair);
		window.draw(no_hair);
		window.draw(other_hair);
		window.draw(pale_yes);
		window.draw(pale_no);
		window.draw(straight_hair);
		window.draw(wavy_hair);
		window.draw(other_hairType);
		window.draw(mustache);
		window.draw(beard);
		window.draw(goatee);
		window.draw(no_faceHair);
		window.draw(bangs_yes);
		window.draw(bangs_no);
		window.draw(biglips_yes);
		window.draw(biglips_no);
		window.draw(bignose_yes);
		window.draw(bignose_no);
		window.draw(glasses_yes);
		window.draw(glasses_no);
		window.draw(young);
		window.draw(old);

		// button text
		window.draw(textFemale);
		window.draw(textMale);
		window.draw(textBlackHair);
		window.draw(textBrownHair);
		window.draw(textBlondeHair);
		window.draw(textGreyHair);
		window.draw(textNoHair);
		window.draw(textOtherHair);
		window.draw(textPale);
		window.draw(textNotPale);
    window.draw(textStraight);
		window.draw(textWavy);
    window.draw(textOther);
    window.draw(textMustache);
    window.draw(textBeard);
    window.draw(textGoatee);
    window.draw(textNoFacialHair);
		window.draw(textBangs);
		window.draw(textNoBangs);
		window.draw(textLips);
		window.draw(textNoLips);
		window.draw(textNose);
		window.draw(textNoNose);
    window.draw(textGlasses);
    window.draw(textNoGlasses);
    window.draw(textYoung);
    window.draw(textOld);

    window.draw(textSubmit);
    window.draw(textDFS);

    window.draw(textBFSButton);
    window.draw(textBFS);

		window.display();
	}
}


