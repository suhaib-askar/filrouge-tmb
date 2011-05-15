
#include "ZombieGame.h"
#include "Catapulte.h"

//================================================================ PUBLIC

Catapulte::Catapulte(ZombieGame* pGame, float x1, float y1, float x2, float y2)
		: game(pGame)
{
	// Positions :
	
	// Define the first point :
	xAttLeft = x1;
	yAttLeft = y1;
	
	// Define the second point :
	xAttRight = x2;
	yAttRight = y2;
}

Catapulte::~Catapulte()
{
	// delete : nothing
}

void Catapulte::Update()
{
	if(game->GetInterface().isMousePressed())
	{
		posBombe = bombe->GetPosBombe();
		SetPosBombe(posBombe.x, posBombe.y);
		drawLines();
	}
	else
	{
		// Nothing to be done
	}
	
}


void Catapulte::SetPosBombe(float anyXBombe, float anyYBombe)
{
	posBombe.x = anyXBombe;
	posBombe.y = anyYBombe;
}


void Catapulte::drawLines()
{
	line1 = sf::Shape::Line(xAttLeft, yAttLeft, posBombe.x, posBombe.y, 20, sf::Color::Black);
	line2 = sf::Shape::Line(xAttRight, xAttRight, posBombe.x, posBombe.y, 20, sf::Color::Black);
	game->GetWindow()->Draw(line1);
	game->GetWindow()->Draw(line2);
}
