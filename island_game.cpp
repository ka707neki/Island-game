// Welcome to my island
// A colorful console choice game: pick a door, then pick a box.

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <chrono>
#include <thread>
using namespace std;

// ANSI color codes (work in most Linux/macOS terminals and Windows 10+)
namespace color
{
    const string reset  = "\033[0m";
    const string bold   = "\033[1m";
    const string red    = "\033[31m";
    const string green  = "\033[32m";
    const string yellow = "\033[33m";
    const string blue   = "\033[34m";
    const string cyan   = "\033[36m";
    const string gray   = "\033[90m";
}

// Prints text one character at a time for a "typing" effect.
// Multi-byte UTF-8 characters (like emojis) are printed whole so they don't break.
void typeWrite(const string &text, int delayMs = 18)
{
    for (size_t i = 0; i < text.size();)
    {
        unsigned char c = text[i];
        size_t len = 1;
        if (c >= 0xF0)      len = 4;
        else if (c >= 0xE0) len = 3;
        else if (c >= 0xC0) len = 2;

        cout << text.substr(i, len) << flush;
        i += len;
        this_thread::sleep_for(chrono::milliseconds(delayMs));
    }
    cout << endl;
}

// Prints a horizontal separator line
void printLine()
{
    cout << color::gray << "──────────────────────────────────────────────" << color::reset << endl;
}

// Prints the game title banner
void printBanner()
{
    cout << "\n" << color::cyan << color::bold;
    cout << "╔════════════════════════════════════════════╗\n";
    cout << "║            WELCOME TO MY ISLAND            ║\n";
    cout << "╚════════════════════════════════════════════╝" << color::reset << endl;
}

// Removes spaces/tabs from both ends of a string
string trim(const string &s)
{
    size_t start = s.find_first_not_of(" \t\r\n");
    if (start == string::npos) return "";
    size_t end = s.find_last_not_of(" \t\r\n");
    return s.substr(start, end - start + 1);
}

// Converts a string to lowercase so input is case-insensitive
string toLower(string s)
{
    transform(s.begin(), s.end(), s.begin(),
              [](unsigned char c) { return tolower(c); });
    return s;
}

// Shows a prompt and reads one full line, trimmed and lowercased.
// Returns false if input was closed (Ctrl+D), so the game can exit cleanly.
bool readChoice(const string &prompt, string &out)
{
    cout << "\n" << color::yellow << prompt << color::reset << "\n" << color::bold << "> " << color::reset;
    if (!getline(cin, out)) return false;
    out = toLower(trim(out));
    return true;
}

// Prints an invalid-input message
void printInvalid()
{
    cout << color::red << "❌ Invalid input, try again." << color::reset << endl;
}

// Prints a losing ending
void printLose(const string &message)
{
    cout << "\n" << color::red << color::bold << message << color::reset << endl;
    cout << color::red << "💀 Game Over." << color::reset << endl;
}

// Runs one full round. Returns false if the input stream was closed.
bool playGame()
{
    printBanner();
    cout << endl;
    typeWrite("Two doors stand in front of you...");
    cout << "\n   " << color::red << "🚪 Red" << color::reset
         << "          " << color::blue << "🚪 Blue" << color::reset << endl;

    string choice;

    // Ask until the player picks a valid door
    while (true)
    {
        if (!readChoice("Which door do you want to open? (red / blue)", choice)) return false;

        if (choice == "red")
        {
            cout << endl;
            printLine();
            typeWrite("Great! You entered a mysterious room... 🕯");
            typeWrite("You found three boxes:");
            cout << "\n   🎁 White     🎁 Black     🎁 Green" << endl;
            printLine();

            // Ask until the player picks a valid box
            while (true)
            {
                if (!readChoice("Which box do you open? (white / black / green)", choice)) return false;

                if (choice == "white")
                {
                    printLose("Oops! It's full of snakes! 🐍🐍🐍");
                    return true;
                }
                else if (choice == "black")
                {
                    printLose("Oops! It's full of spiders! 🕸🕸🕸");
                    return true;
                }
                else if (choice == "green")
                {
                    cout << "\n" << color::green << color::bold
                         << "🎉 Congratulations! You found the treasure! 💰💰💰"
                         << color::reset << endl;
                    return true;
                }
                else
                {
                    printInvalid();
                }
            }
        }
        else if (choice == "blue")
        {
            printLose("Wrong choice! You walked straight into a crocodile's mouth. 🐊");
            return true;
        }
        else
        {
            printInvalid();
        }
    }
}

// Asks the player if they want another round. Returns false to quit.
bool askPlayAgain()
{
    string answer;
    while (true)
    {
        if (!readChoice("Play again? (y / n)", answer)) return false;
        if (answer == "y" || answer == "yes") return true;
        if (answer == "n" || answer == "no")  return false;
        printInvalid();
    }
}

int main()
{
    do
    {
        if (!playGame()) break;   // input closed, stop the game
    } while (askPlayAgain());

    cout << "\n" << color::cyan << "Thanks for playing! 👋" << color::reset << endl;
    return 0;
}
