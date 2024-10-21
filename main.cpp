#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Enemy
{
public:
    int health=0;
    int damage = 0;
  static  Enemy Monster;
  
  Enemy()
  {
      health = 0;
      damage = 0;
  }
  Enemy(int h, int d)
  {
      health = h;
      damage = d;
  }
  void predefinde(Enemy n)
  {
      health = n.health;
  }
    void kill()
    {
        cout << "Kill func" << endl;
    }

    void Heal()
    {
        health += 10;
        cout << "healed by 10" << endl;
    }
    enum types
    {
        Goblin
    };

};
 Enemy Enemy::Monster =  Enemy(20,10);
class goblin :Enemy
{
public:
    void Health()
    {
        health = 50;
        cout << "Hi goblin my health is "<<health << endl;
    }
};
int main()
{
   
   
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow window(VideoMode(800, 800), "RPG Game");
    CircleShape circle(50.0f);
    RectangleShape rec(Vector2f(120.f, 50.f));
    rec.setPosition(450, 450);
    circle.setFillColor(Color::Blue);
    rec.setFillColor(Color::Green);
    rec.setOrigin(rec.getSize()/2.0f);
    rec.setRotation(0);
    circle.setPosition(350.0f, 350.0f);

    while (window.isOpen())
    {
        //--------------- Update ------------
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                 window.close();
        }
        //------------------- End Update ---------------

        //----------------------------- DRAW ----------------------- 
        window.clear(Color::Black);
        window.draw(circle);
        window.draw(rec);
        window.display(); // the data from back buffer to screen after the clear
    }

    return 0;
}