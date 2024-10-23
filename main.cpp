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
    //--------------- Load ------------
    Texture playerTexture;
    Sprite PlayerSprite;
    int Xindex = 0;
    int Yindex = 0;
    if (playerTexture.loadFromFile("assets/Player/Textures/SkSoriteSheet.png"))
    {
        cout << "Player Image Loaded " << endl;
        PlayerSprite.setTexture(playerTexture);
    }
    else
    {
        cout << "PLayer Image Failed To Load " << endl;
    }
    while (window.isOpen())
    {
        //--------------- Update ------------
        Event event;
      playerTexture.loadFromFile("assets/Player/Textures/SkSoriteSheet.png");
      PlayerSprite.setTextureRect(IntRect(0, 2 * 64, 64, 64));
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                 window.close();
          //if (event.type == Event::KeyPressed)
          //  {
          //      if (event.key.code == Keyboard::D) 
          //      {
          //         
          //          for (int i = 0; i < 4; i++)
          //          {
          //            
          //              /*PlayerSprite.setTexture(playerTexture);*/
          //           /*   PlayerSprite.scale(Vector2f(2, 2));*/
          //          }
        
          //      }
          //  }
        }
        if (Keyboard::isKeyPressed(Keyboard::D))
        {
            Vector2f pos = PlayerSprite.getPosition();
            PlayerSprite.setPosition(pos + Vector2f(2, 0));
        }
        if (Keyboard::isKeyPressed(Keyboard::A))
        {
            Vector2f pos = PlayerSprite.getPosition();
            PlayerSprite.setPosition(pos + Vector2f(-2, 0));
        }
        if (Keyboard::isKeyPressed(Keyboard::W))
        {
            Vector2f pos = PlayerSprite.getPosition();
            PlayerSprite.setPosition(pos + Vector2f(0, -2));
        }
        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            Vector2f pos = PlayerSprite.getPosition();
            PlayerSprite.setPosition(pos + Vector2f(0, 2));
        }
        /*{*/
            
              
       /* }*/
        //------------------- End Update ---------------

        //----------------------------- DRAW ----------------------- 
        window.clear(Color::Black);
        window.draw(PlayerSprite);
        window.display(); // the data from back buffer to screen after the clear
    }

    return 0;
}