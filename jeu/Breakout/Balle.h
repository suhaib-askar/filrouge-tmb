#ifndef BALLE_H
#define BALLE_H

#include <SFML/Graphics.hpp>

// Déclaration anticipée de la classe BreakOut :
class BreakOut;

class Balle : public sf::Sprite {
    public:
    
        Balle(sf::Image *img, BreakOut *leJeu=0);
        ~Balle();
        
       	float GetX();
       	float GetY();
       	void MajPositions();
       	void SetSpeed(float unSpeed);
       	void SetAngle(float unAngle);
       	const sf::FloatRect& GetHitBox();
    
    private:
        
        BreakOut *jeu; // Ref. vers le jeu
        
        sf::Vector2f direction;	// Direction du Sprite
        // note : Vector2f -> Vector2<float>
        
        sf::FloatRect hitBox;
        
        float x;
        float y;
        
        float speed;
        float angle;
        
        void calculerDirection();
};

#endif
