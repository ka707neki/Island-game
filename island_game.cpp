// Welcome to my island
// A small console choice game: pick a door, then pick a box.

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

// Converts a string to lowercase so input is case-insensitive
// (e.g. "Red", "RED" and "red" are all treated the same).
string toLower(string s)
{
    transform(s.begin(), s.end(), s.begin(),
              [](unsigned char c) { return tolower(c); });
    return s;
}

int main()
{
    // Intro text
    cout << "\n" << "Welcome to my island" << endl;
    cout << "There are two doors in front of you: 🚪 Red and 🚪 Blue" << endl;

    // Keep asking until the player picks a valid door
    while (true)
    {
        string user_input;
        cout << "Which door do you want to open? " << endl;
        cin >> user_input;
        user_input = toLower(user_input);

        // Red door: leads to the three boxes
        if (user_input == "red")
        {
            cout << "Great! You entered a mysterious room... 🕯" << endl;
            cout << "You found three boxes: 🎁 White, 🎁 Black, 🎁 Green" << endl;

            // Keep asking until the player picks a valid box
            while (true)
            {
                string box;
                cout << "Which box do you open? " << endl;
                cin >> box;
                box = toLower(box);

                if (box == "white")
                {
                    // Losing ending: snakes
                    cout << "Oops! It's full of snakes! 🐍🐍🐍 Game Over." << endl;
                    return 0;
                }
                else if (box == "black")
                {
                    // Losing ending: spiders
                    cout << "Oops! It's full of spiders! 🕸🕸🕸 Game Over." << endl;
                    return 0;
                }
                else if (box == "green")
                {
                    // Winning ending: treasure
                    cout << "Congratulations! You found the treasure! 💰💰💰" << endl;
                    return 0;
                }
                else
                {
                    // Anything else: ask again
                    cout << "❌ Invalid input, try again." << endl;
                }
            }
        }
        // Blue door: losing ending, leaves the loop
        else if (user_input == "blue")
        {
            cout << "\nWrong choice! You walked straight into a crocodile's mouth. 🐊 Game Over." << endl;
            break;
        }
        // Not a valid door: ask again
        else
        {
            cout << "❌ Invalid input, try again." << endl;
        }
    }
    return 0;
}
