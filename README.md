# 🏝️ Welcome to My Island

A small text-based adventure game written in **C++**. Choose a door, then choose a box, and see whether you find the treasure or meet a nasty surprise.

## 🎮 How to Play

1. You start in front of two doors: **Red** and **Blue**.
2. Type the name of the door you want to open.
3. If you pick **Red**, you enter a room with three boxes: **White**, **Black** and **Green**.
4. Type the name of the box you want to open.

| Choice | Result |
|--------|--------|
| Blue door | 🐊 Crocodile, game over |
| Red door → White box | 🐍 Snakes, game over |
| Red door → Black box | 🕸 Spiders, game over |
| Red door → Green box | 💰 Treasure, you win! |

Input is case-insensitive (`red`, `Red` and `RED` all work). Invalid input just asks again.

## 🛠️ Requirements

- A C++11 (or newer) compiler, such as `g++` or `clang++`
- A terminal that supports UTF-8 so the emojis display correctly

## 🚀 Build and Run

```bash
# Clone the repository
git clone https://github.com/<your-username>/<repo-name>.git
cd <repo-name>

# Compile
g++ -std=c++11 -o island_game island_game.cpp

# Run
./island_game
```

On Windows (MinGW), run `island_game.exe` instead.

## 📸 Example Run

```
Welcome to my island
There are two doors in front of you: 🚪 Red and 🚪 Blue
Which door do you want to open?
red
Great! You entered a mysterious room... 🕯
You found three boxes: 🎁 White, 🎁 Black, 🎁 Green
Which box do you open?
green
Congratulations! You found the treasure! 💰💰💰
```

## 📚 What This Project Demonstrates

- Console input and output with `cin` / `cout`
- Nested `while` loops and `if / else if` branching
- String handling and case-insensitive comparison using `std::transform` and a lambda
- Basic input validation

## 💡 Ideas for Improvement

- Add a "Play again?" option
- Add more doors, rooms and endings
- Handle end-of-input (`Ctrl+D`) gracefully
- Store box outcomes in a `map` instead of an `if / else` chain

## 📄 License

This project is licensed under the [MIT License](LICENSE).
