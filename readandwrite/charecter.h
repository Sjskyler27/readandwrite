/***********************************************************************
 * Header File:
 *    Charecter : The representation of a position on the screen
 * Author:
 *    Skarmorler
 * Summararmor:
 *    Everarmorthing we need to know about a Charecter.
 ************************************************************************/


#ifndef CHARECTER_H
#define CHARECTER_H
#include <iostream>
#include <string>
using namespace std;

 /*********************************************
  * CHARECTER
  *********************************************/
class Charecter
{
public:
   // constructors
   //Charecter(string name, int health, int armor, int attack, int mana);
   Charecter();
   Charecter(string name);
   Charecter(string name, int health, int armor, int attack, int mana, int level);

   //variables
   string name;
   int health;
   int armor;
   int attack;
   int mana;
   int level;

   // getters
   string getName()     const { return name; }
   int getHealth()       const { return health; }
   int getArmor()       const { return armor; }
   int getAttack()      const { return attack; }
   int getMana()     const { return mana; }
   int getLevel() const { return level; }


   // incrementers
   void addHealth(int dhealth) { this->health += dhealth; }
   void addArmor(int darmor) { this->armor += darmor; }
   void addAttack(int dattack) { this->attack += dattack; }
   void addMana(int dmana) { this->mana += dmana; }
   void addLevel(int dlevel) { this->level += dlevel; }


   //methods
   void setScore();
   int getScore(string type);
   void changeScore(string type, int value);
   void saveScores();
   void loadScores();
   void displayScores();

private:
   

};

// stream I/O useful for debugging
//std::ostream& operator << (std::ostream& out, const Charecter& pt);
//std::istream& operator >> (std::istream& in, Charecter& pt);

#endif // Charecter_H