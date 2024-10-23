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
    RenderWindow window(VideoMode(800, 600), "RPG Game");
    //--------------- Load ------------
    Texture playerTexture;
    Sprite PlayerSprite;
    int RightindexX = 0;
    int leftindexX = 0;
    int UpindexY = 0;
    int DownindexY = 0;
    if (playerTexture.loadFromFile("assets/Player/Textures/SkSoriteSheet.png"))
    {
        cout << "Player Image Loaded " << endl;
        PlayerSprite.setTexture(playerTexture);
    }
    else
    {
        cout << "PLayer Image Failed To Load " << endl;
    }
   
    PlayerSprite.setTextureRect(IntRect(0, 64 * 2, 64, 64));
    while (window.isOpen())
    {
        //--------------- Update ------------
        Event event;
    
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                 window.close();
         
        }
        float animationFrameRate = 10.0f;
        Vector2f pos = PlayerSprite.getPosition();
        if (Keyboard::isKeyPressed(Keyboard::D))
        {
               PlayerSprite.setPosition(pos + Vector2f(0.03f, 0));
               PlayerSprite.setTextureRect(IntRect(RightindexX* 64, 64 * 3, 64, 64));
               RightindexX = (RightindexX + 1) % 9;
        }
        if (Keyboard::isKeyPressed(Keyboard::A))
        {
        
            PlayerSprite.setPosition(pos + Vector2f(-0.03, 0));
           
            PlayerSprite.setTextureRect(IntRect(leftindexX * 64, 64 , 64, 64));
            leftindexX = (leftindexX +1)% 9;

        }
        if (Keyboard::isKeyPressed(Keyboard::W))
        {
          
            PlayerSprite.setPosition(pos + Vector2f(0, -0.03));
            
            PlayerSprite.setTextureRect(IntRect(UpindexY * 64, 0, 64, 64));
            UpindexY =( UpindexY + 1 )% 9;
        }
        if (Keyboard::isKeyPressed(Keyboard::S))
        {
         
            PlayerSprite.setPosition(pos + Vector2f(0, 0.03));
           
            PlayerSprite.setTextureRect(IntRect(DownindexY * 64, 64*2, 64, 64));
            DownindexY = (DownindexY + 1) % 9;
        }
      
        //------------------- End Update ---------------

        //----------------------------- DRAW ----------------------- 
        window.clear(Color::Black);
        window.draw(PlayerSprite);
        window.display(); // the data from back buffer to screen after the clear
    }

    return 0;
}