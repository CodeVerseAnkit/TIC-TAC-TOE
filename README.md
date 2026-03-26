🎮 Tic Tac Toe (C++ Console Game)

A simple yet feature-rich Tic Tac Toe game built in C++ for the terminal.
This project focuses on game logic, Algorithm, file handling, and an interactive console UI.

---

📌 Features

- 🧑‍💻 Play with Computer (Bot)
  
  - Multiple difficulty levels:
    - Easy (Random moves)
    - Medium (Basic strategy)
    - Hard (Smart moves: win/block + positional play)

- 👥 Play with Friend (2 Players)

- 💾 Score Persistence
  
  - Scores are saved using file handling
  - Data remains available even after program restart

- 🎨 Console UI
  
  - Colored text (ANSI escape codes)
  - Structured board layout
  - Loading animations

- 📊 Scoreboard System
  
  - Computer vs Player stats
  - Player vs Player stats
  - Total games count

- 📝 User Activity Logs
  
  - Tracks user actions with date & time

---

🛠️ Tech Stack

- Language: C++
- Concepts Used:
  - Functions & Modular Programming
  - Structures ("struct")
  - File Handling ("fstream")
  - Vectors ("std::vector")
  - Game logic
  - Console manipulation (ANSI codes)

---

🚀 Getting Started

1. Clone the Repository

git clone https://github.com/CodeVerseAnkit/TIC-TAC-TOE.git
cd tic-tac-toe-cpp

2. Compile the Code

g++ main.cpp -o game

3. Run the Game

./game

---

📂 Project Structure

📁 Tic-Tac-Toe
 ├── main.cpp
 ├── HelperFunction.h
 ├── PlayerScore.txt
 ├── UserLogs.txt
 └── README.md

---

🎯 How to Play

- Choose a mode (Bot / Friend)
- Select your symbol (X or O)
- Enter positions (1–9) to place your move
- First player to align 3 symbols wins

 1 | 2 | 3
---+---+---
 4 | 5 | 6
---+---+---
 7 | 8 | 9

---

📷 Sample Screenshots

https://github.com/CodeVerseAnkit/TIC-TAC-TOE/blob/main/Example1.jpg

https://github.com/CodeVerseAnkit/TIC-TAC-TOE/blob/main/Example2.jpg

https://github.com/CodeVerseAnkit/TIC-TAC-TOE/blob/main/Example3.jpg

https://github.com/CodeVerseAnkit/TIC-TAC-TOE/blob/main/Example4.jpg


---

🧠 Computer Logic (Bot)

- Easy: Random moves
- Medium:
  - Try to win
  - Block opponent
- Hard:
  - Prioritize center
  - Play corners
  - Win/block logic combined

🔴Note: This is not a Minimax-based AI (yet).»

---

🔴 Limitations

- Console-based UI (no GUI)
- File paths may need adjustment depending on your system

---

🔮 Future Improvements

- Implement Minimax Algorithm for unbeatable Computer
- Refactor using OOP (Object-Oriented Design)
- Add player names & leaderboard
- Add online multiplayer support

---

🙌 Author

Ankit
B.Sc. Computer Applications Student
Passionate about coding, problem-solving, and building projects

---

⭐ Support

If you found this project useful:

- Star ⭐ the repository
- Share feedback
- Suggest improvements

---

📜 License

This project is open-source and free to use for learning purposes.

---

❤❤ Thanks for Visit ❤❤

---
