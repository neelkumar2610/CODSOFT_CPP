#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int randomNumber, guess;

    // Seed the random number generator
    srand(time(0));

    // Generate a random number between 1 and 100
    randomNumber = rand() % 100 + 1;

    cout << "===== Number Guessing Game =====" << endl;
    cout << "I have selected a number between 1 and 100." << endl;
    cout << "Try to guess it!" << endl;

    do
    {
        cout << "\nEnter your guess: ";
        cin >> guess;

        if (guess > randomNumber)
        {
            cout << "Too High! Try again." << endl;
        }
        else if (guess < randomNumber)
        {
            cout << "Too Low! Try again." << endl;
        }
        else
        {
            cout << " Congratulations! You guessed the correct number: " << randomNumber << endl;
        }

    } while (guess != randomNumber);

    return 0;
}
