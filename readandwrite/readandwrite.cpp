#include <iostream>
#include <fstream>
#include <string>
#include "charecter.h"
using namespace std;

void writeFile();
void readFile();
void changeScore(string type, int value);
int getScore(string type);


int main()
{
   //write text to a file and read it until you exit
   writeFile();

   //set up charecters and their files
   cout << "Enter Charector Name:   ";
   string input;
   cin >> input;

   //load or create charecter
   Charecter Player1(input);

   //cincremeant scores
   /*Player1.addHealth(1);
   Player1.addArmor(1);
   Player1.addAttack(1);
   Player1.addMana(-1);*/

   Player1.saveScores();
}
/*write to a file*/
void writeFile()
{

   string userInput;

   while (userInput != "0")
   {
      cout << "what do you want to say, exit with 0: \n \t";

      // declare the output stream
      ofstream fout;

      // open the file and append
      fout.open("test.txt", fstream::app);

      // write some text
      getline(cin, userInput);
      if(userInput!="0")
         fout << userInput + "\n";

      // close the stream
      fout.close();

      //clear if no input is entered by writeing nothing over the file
      if (userInput == "")
      {
         fout.open("test.txt");
         fout << "";
         fout.close();
      }
      readFile();
   }
   return;
}
/*read out all the contents of a file*/
void readFile()
{
   // declare the output stream
   ifstream fin("test.txt");

   //check for file
   if (fin.fail())
   {
      cout << "Unable to open file";
      return;
   }

   // read the data one at a time and fill up a new string
   string data;
   string text;

   //gets whole file and stores it in text
   while (fin) {
      getline(fin, data);
      text += data;
      text += " ";
   }
   cout << text << endl; //in this case we just read the text but you'd more likely be sending it

   //get one word
   //fin >> data;
   
   //get whole line
   //getline(fin,data);

   // close the stream
   fin.close();

   // you could make it return string text too.
   return; 
}
/*change score based on type that you send to the value that you send*/
void changeScore(string type, int value)
{

   /*to change score we need to read and write to it*/

   // declare the input stream
   ifstream fin("scores.txt"); //fin is reading the file
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
   ofstream fout("scores.txt"); //fout writes to file
   fout << tempFile;

   fin.close();
   fout.close();
   return;
}
/*return the value of the score you ask for*/
int getScore(string type)
{
   // declare the input stream
   ifstream fin("scores.txt");
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


