
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
int main()
{
    char start{};
    string Word, WordList[99];
    char Guess;
    int Health = 50;
    bool CorrectGuess = false;
    srand(time(NULL));
    ifstream RandomWord;
    RandomWord.open("Words.txt");
    for (int i = 0; i < 99; i++){
        RandomWord >> WordList[i];
    }
    int RandNum = rand() % 100;
    Word = WordList[RandNum];

    RandomWord.close();

    cout << " Welcome, in mine game, to start Press a key \n";
    cin >> start;
    string MysteryWord(Word.length(), '*');
    cout << "Your Word to guess is: ";
    cout << MysteryWord << endl << "It has : " << MysteryWord.length() << " Letters \n";

    
    while(Health>0){
        CorrectGuess = false;
        cin >> Guess;
        for (int i = 0; i < MysteryWord.length(); i++) 
        {
            
            if (Word[i] == Guess)
            {
                MysteryWord[i] = Guess;
                cout << " Congratz, you've guessed a letter"  << endl << MysteryWord << endl;
                CorrectGuess = true;
            }
               
                
            
        }
        if (Word == MysteryWord)
        {
            cout << "Congratz, you've guessed the word"<<endl;
            break;
        }
        if (CorrectGuess == false)
        {
            Health--;
            cout << " Sorry, your guess is false" << endl;
        }


    }

    return 0;
}
