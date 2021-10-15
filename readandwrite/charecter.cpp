#include "charecter.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

/*usless*/
Charecter :: Charecter()
{
   name = "john";
   string file = this->name;
   file += ".txt";
   // declare the input stream
   ifstream fin(file);
   if (fin.fail())
   {
      cout << "Making new charecter\n";
      this->health = 20;
      this->attack = 16;
      this->armor = 24;
      this->mana = 100;
      this->level = 0;
      setScore();
   }

}
/*used to check for a charecter and loads it if not it creats a new one*/
Charecter::Charecter(string name)
{
   this->name = name;
   string file = this->name;
   file += ".txt";
   // declare the input stream
   ifstream fin(file);
   if (fin.fail())
   {
      cout << "Making new charecter\n";
      this->name = name;
      this->health = 10;
      this->attack = 18;
      this->armor = 16;
      this->mana = 100;
      this->level = 0;
      setScore();
   }
   else
   {
      loadScores();
      cout << "Welcome Back " << this->name << "!\n";
   }

   displayScores();
}
/*for dev if you need to make a charector with non default values*/
Charecter :: Charecter(string name, int health, int armor, int attack, int mana, int level)
{
   this->name = name;
   string file = this->name;
   file += ".txt";
   // declare the input stream
   ifstream fin(file);
   if (fin.fail())
   {
      cout << "Makeing new Charecter\n";
      this->name = name;
      this->health = health;
      this->armor = armor;
      this->attack = attack;
      this->mana = mana;
      this->level = level;
      setScore();
   }
}
/*upon creating a new charecter makes a file for it*/
void Charecter::setScore()
{
   // open the file
   string file = this->name;
   file += ".txt";
   ofstream fout(file);

   // write some text
   fout << "health " << this->health << " armor " << this->armor << " attack " << this->attack << " mana " << this->mana << " level "<< this->level;

   // close the stream
   fout.close();
}
/*load scores from file if not found set to default*/
void Charecter::loadScores()
{
   this->health = getScore("health");
   this->attack = getScore("attack");
   this->armor = getScore("armor");
   this->mana = getScore("mana");
   this->level = getScore("level");
}
/*retrieves score from file for loading*/
int Charecter :: getScore(string type)
{
   string file = this->name;
   file += ".txt";
   // declare the input stream
   ifstream fin(file);
   if (fin.fail())
   {
      cout << "Unable to open file\n";
      return NULL;
   }

   int data;
   string search; //compare search to the type that wwe are searching for

   while (fin)
   {
      fin >> search; // once search= health or armor etc return the number following.
      if (search == type)
      {
         fin >> data;

         // close the stream
         fin.close();

         //return the score
         return data;
      }
   }
   cout << "Unable to find type\n";
   return NULL;

}
/*saves all current game scores to file*/
void Charecter::saveScores()
{
   changeScore("health", health);
   changeScore("armor", armor);
   changeScore("attack", attack);
   changeScore("mana", mana);
   changeScore("level", level);

}
/*changes one individule score*/
void Charecter :: changeScore(string type, int value)
{
   string file = this->name;
   file += ".txt";

   /*to change score we need to read and write to it*/

   // declare the input stream
   ifstream fin(file); //fin is reading the file
   if (fin.fail())
   {
      cout << "Unable to open file\n";
      return;
   }

   string search; //current word in file being looked at
   string tempFile; //temporary staorage for all valuse, since all will be replaced (fout makes replacing just one item dificult.)


   while (fin >> search)
   {
      //search for the type
      if (search == type)
      {
         search += " ";
         tempFile += search;
         fin >> search; // jump to the next value after search
         search = to_string(value);
      }
      //fill temporary documeant
      search += " ";
      tempFile += search;
   }

   //open file and write new scores
   ofstream fout(file); //fout writes to file
   fout << tempFile;

   fin.close();
   fout.close();
   return;
}
/*show all scores to the user*/
void Charecter::displayScores()
{
   cout << "\nCurrent Stats: \n" << "health: " << this->health << " armor: " << this->armor << " attack: " << this->attack << " mana: " << this->mana << " level: " << this->level << endl;
}