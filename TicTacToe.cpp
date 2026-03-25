#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include "/sdcard/Coding.Cpp/PROJECT/Tic Tac Toe/HelperFunction.h"
using namespace std;
/*  <-------- TIC TAC TOE -------->

Project: Tic Tac Toe
Version: V1.0
Date: 10/3/2026
Programmer: Ankit
Description: It is a console game.
 
*/
// ---> UI
void menu()
{
    cout << "  _-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\n";
    cout << "\033[1;36m";
    print_center("TIC TAC TOE");
    cout << "\033[0m";
    cout << "\t\t" << string(13, '-') << "\n\n";
    cout << "   1. \033[1;32mHow To Play\033[0m";
    cout << "\t  2. \033[1;32mScore\033[0m";
    cout << "\n   3. \033[1;32mPlay With Bot\033[0m";
    cout << "\t  4. \033[1;32mPlay With Friend\033[0m";
    cout << "\n   5. \033[1;32mPlay Online\033[0m";
    cout << "\t  6. \033[1;32mApp Info\033[0m";
    cout << "\n   7. \033[1;32mExit\033[0m\n"
         << endl;

    cout << "  _-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\n";
}
// some function declaration
void print_board(vector<char> &space);
char select_symbol();
void player_move(vector<char> &space, char player, int turn);
void computer_move(vector<char> &space, char computer,char level);
char select_level() ;
    

int check_winner(vector<char> &space, char player1, char player2);
bool check_draw(vector<char> &space);
void welcome_mssg();
void user_logs(string mssg);
void display_score1(int p1, int p2, int d);
void display_score2(int c, int p, int d);
void save_score(int cs = 0, int ps = 0, int d1 = 0, int ps1 = 0, int ps2 = 0, int d2 = 0);
// structure to save score
struct game_score
{
    int computer_score = 0,
        player_score = 0,
        draw1 = 0, player_score1 = 0, player_score2 = 0, draw2 = 0;
};
// ---> 1. How To Play
void how_to_play()
{
    print_text_with_animation("\n\t<-------- \033[1;32;4mTIC TAC TOE\033[0m -------->", 50);
    cout << "\n\n\033[1;33m";
    print_center("WELCOME TO TIC TAC TOE");
    cout << "\033[0m";

    print_center("------------------------");
    cout << "\n\n";
    cout << "  \033[1mTIC TAC TOE :-\033[0m\n  -----------\n"
         << endl;
    cout << "  Tic-tac-toe (also known as noughts and\n  crosses or Xs and Os) is a classic two-\n  player strategy game played on a grid.\n  One player marks spaces with X and \n  the other with O.\n"
         << endl;
    vector<char> space = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    print_board(space);
    cout << "\n\n";
    cout << "  \033[1mHow to Play :-\033[0m\n  ------------\n"
         << endl;
    cout << " 1.OBJECTIVE : Be the first to align three of\n   your symbols horizontally,vertically,\n   or diagonally.\n";
    cout << " 2.TURNS : Players take turns placing their\n   mark in an empty square.\n";
    cout << " 3.END GAME : The game ends when one player\n   wins or all nine squares are filled. If\n   no one has three in a row, it's a tie\n   (often called a \"cat's game\").\n"
         << endl;
    cout << "  \033[1mNote :-\033[0m\n  -----\n"
         << endl;
    cout << "  Enter (1-9) number to place your symbol\n  in the square on the board.\n"
         << endl;
    cout << "  \033[1;33mEnjoy\033[0m✌\n"
         << endl;
    back_button();
}
// ---> 2. Score
void score()
{
    welcome_mssg();

    cout << "\n        ------------------------------\n        |\033[1;46m     Computer Vs Player     \033[0m|\n        ------------------------------\n";
    game_score s;
    ifstream ifs("/sdcard/Coding.cpp/PROJECT/Tic Tac Toe/PlayerScore.txt");
    ifs >> s.computer_score >> s.player_score >> s.draw1 >> s.player_score1 >> s.player_score2 >> s.draw2;
    ifs.close();
    display_score2(s.computer_score, s.player_score, s.draw1);
    cout << "\n        ------------------------------\n        |\033[1;46m     Player1 Vs Player2     \033[0m|\n        ------------------------------\n";
    display_score2(s.player_score1, s.player_score2, s.draw2);
    cout << "\n        ------------------------------\n        |\033[1;46m     Total Games Played     \033[0m|\n        ------------------------------\n";
    cout << "\n  \033[1;3mComputer Vs Player:\033[0m " << (s.computer_score + s.player_score + s.draw1) << "   \033[1;3mPlayer Vs Player:\033[0m " << (s.player_score1 + s.player_score2 + s.draw2) << "\n\n";
    char user;
    while (true)
    {
        cout << "  Do you want to reset score(y/n): ";
        cin >> user;
        user = tolower(user);
        if (user == 'y' || user == 'n')
            break;
    }
    if (user == 'y')
    {
        ofstream ofs("/sdcard/Coding.cpp/PROJECT/Tic Tac Toe/PlayerScore.txt");
        ofs << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0;
        ifs.close();
        loading_animation1(" Clearing Scoreboard");
        cout << "  Score board Reset successfully 👍" << endl;
    }
    back_button();
}
// ---> 3. Play With Bot
void play_with_bot()
{
    
 //    loading_bar();
    welcome_mssg();
    game_score S;
    srand(time(0));
    char user;
    do
    {
        vector<char> space(9, ' ');
        char player = select_symbol();
        char computer = (player == 'O') ? 'X' : 'O';
        char level=select_level () ;
        string print_level;
        if(level=='1')
        print_level="Easy";
        else if(level=='2')
        print_level="Medium";
        else
        print_level="Hard";
        char current_move=(rand() %2==0)?'O':'X';
        cout << "\n  Player: " << player << "\n  computer: " <<computer<<"\n  Level: "<<print_level<<"\n  First Move: "<<(current_move==computer?"computer":"Player")<< endl
             << endl;
        loading_animation1("Loading Game");
        clear_screen();
        // current score
        display_score2(S.computer_score, S.player_score, S.draw1);
        print_board(space);
        while (true)
        {
            break;
        }
        while (true)
        {
            cout << "  Do you want to play again(y/n): ";
            cin >> user;
            if (tolower(user) == 'y' || tolower(user) == 'n')
                break;
        }
    } while (tolower(user) != 'n');
    cout << "\n  \033[1;4mFinal Score\033[0m:- \n";
    display_score1(S.player_score1, S.player_score2, S.draw2);
    save_score(0, 0, 0, S.player_score1, S.player_score2, S.draw2);
    back_button();
}
// ---> 4. Play With Friend
void play_with_friend()
{
    loading_bar();
    welcome_mssg();
    game_score S;
    char user;
    do
    {
        vector<char> space(9, ' ');
        char player1 = select_symbol();
        char player2 = (player1 == 'O') ? 'X' : 'O';
        cout << "\n  Player1: " << player1 << "\n  Player2: " << player2 << endl
             << endl;
        loading_animation1("Loading Game");
        clear_screen();
        // current score
        display_score1(S.player_score1, S.player_score2, S.draw2);
        print_board(space);
        while (true)
        {
            cout << "\n\n";
            player_move(space, player1, 1);
            clear_screen();
            display_score1(S.player_score1, S.player_score2, S.draw2);
            print_board(space);
            if (check_winner(space, player1, player2))
            {  check_winner(space, player1, player2) == 1 ? S.player_score1++ : S.player_score2++;
             clear_screen();
            display_score1(S.player_score1, S.player_score2, S.draw2);
            print_board(space);
                string mssg = check_winner(space, player1, player2) == 1 ? "Player1 Win🥳🥳" : "Player2 Win🥳🥳";
                cout << "\n\n  " << mssg << endl;
              
                break;
            }
            if (check_draw(space))
            { S.draw2++;
             clear_screen();
            display_score1(S.player_score1, S.player_score2, S.draw2);
            print_board(space);
                cout << "\n\n  It's a draw⭕❌" << endl;
               
                break;
            }
            cout << "\n\n";
            player_move(space, player2, 2);
            clear_screen();
            display_score1(S.player_score1, S.player_score2, S.draw2);
            print_board(space);
            if (check_winner(space, player1, player2))
            {check_winner(space, player1, player2) == 1 ? S.player_score1++ : S.player_score2++;
             clear_screen();
            display_score1(S.player_score1, S.player_score2, S.draw2);
            print_board(space);
                string mssg = check_winner(space, player1, player2) == 1 ? "Player1 Win🥳🥳" : "Player2 Win🥳🥳";
                cout << "\n\n  " << mssg << endl;
                
                break;
            }
            if (check_draw(space))
            { S.draw2++;
             clear_screen();
            display_score1(S.player_score1, S.player_score2, S.draw2);
            print_board(space);
                cout << "\n\n  It's a draw⭕❌" << endl;
               
                break;
            }
        }
        while (true)
        {
            cout << "  Do you want to play again(y/n): ";
            cin >> user;
            if (tolower(user) == 'y' || tolower(user) == 'n')
                break;
        }
    } while (tolower(user) != 'n');
    cout << "\n  \033[1;4mFinal Score\033[0m:- \n";
    display_score1(S.player_score1, S.player_score2, S.draw2);
    save_score(0, 0, 0, S.player_score1, S.player_score2, S.draw2);
    back_button();
}
// ---> 5. Play Online
void play_online()
{
    cout << "\n\n\033[1m  This feature is under-construction\033[0m👩‍💻❗\n"
         << endl;
    back_button();
}
// ---> 6. App Info
void app_info()
{
    print_text_with_animation("\n\t  <-------- \033[1;32;4mTIC TAC TOE\033[0m -------->", 50);
    cout << left << "\n\n";
    cout << "  \033[1m" << setw(12) << "Game"
         << "\033[0m"
         << ": Tic Tac Toe " << endl;
    cout << "  \033[1m" << setw(12) << "Version"
         << "\033[0m"
         << ": V1.0" << endl;

    cout << "  \033[1m" << setw(12) << "Publish"
         << "\033[0m"
         << ": 15/3/2026" << endl;
    cout << "  \033[1m" << setw(12) << "Developer"
         << "\033[0m"
         << ": Ankit" << endl;
    cout << "  \033[1m" << setw(12) << "Discription"
         << "\033[0m"
         << ": It is a Console game\n"
         << endl;
    print_text_with_animation("  \033[1;31;4mFeatures\033[0m :", 50);
    cout << "\n\n --> Play with bot\n --> play with friend\n --> Save score\n --> Maintain user history\n --> Engaging Interface\n --> Proper error handling\n"
         << endl;
    cout << "\n\t\t❤  \033[1;32m"
         << "THANKS TO PLAY"
         << "\033[0m ❤";
    cout << "\n\t\t••••••••••••••••••••\n"
         << endl;

    back_button();
}
// ---> 7. Exit
void exit()
{
    cout << "\n\t\t❤  \033[1;32m"
         << "THANKS TO PLAY"
         << "\033[0m ❤";
    cout << "\n\t\t••••••••••••••••••••\n"
         << endl;
    loading_animation1("Exiting");
}
// user input
char user_input()
{
    char input;
    while (true)
    {
        cout << "  INPUT: ";
        cin >> input;
        if (input >= '1' && input <= '7')
            break;
    }
    return input;
}
// main function
int main()
{
     // play_with_friend();
    //score() ;
  //  select_level() ;
  play_with_bot() ;
  /* char input;
    do
    {
        menu();
        input = user_input();
        switch (input)
        {
        case '1':
            user_logs("Opened how to play");
            how_to_play();
            break;
        case '2':
            user_logs("Opened score");
            score();
            break;
        case '3':
            user_logs("Played game with bot");
            play_with_bot();
            break;
        case '4':
            user_logs("Played game with friend");
            play_with_friend();
            break;
        case '5':
            user_logs("Visited play online feature");
            play_online();
            break;
        case '6':
            user_logs("Visited app info");
            app_info();
            break;
        case '7':
            user_logs("Exit the app");
            exit();
            break;
        default:
            cout << "  Invalid Input ";
            break;
        }
        if (input != '7')
        {
            clear_screen();
            clear_screen();
        }
    } while (input != '7');
*/
    return 0;
}
// print_board()
void print_board(vector<char> &space)
{
    cout << "\n\033[1m\t" << string(25, '-') << "\n\t|       |       |       |\n\t|   " << space[0] << "   |   " << space[1] << "   |   " << space[2] << "   |\n\t|       |       |       |\n\t" << string(25, '-') << "\n\t|       |       |       |\n\t|   " << space[3] << "   |   " << space[4] << "   |   " << space[5] << "   |\n\t|       |       |       |\n\t" << string(25, '-') << "\n\t|       |       |       |\n\t|   " << space[6] << "   |   " << space[7] << "   |   " << space[8] << "   |\n\t|       |       |       |\n\t" << string(25, '-') << "\033[0m";
}
// select_symbol()
char select_symbol()
{
    char s;
    while (true)
    {
        cout << "  Choose your symbol (X/O): ";
        cin >> s;
        s = toupper(s);
        if (s == 'O' || s == 'X')
            break;
    }
    return s;
}
// player_move()
void player_move(vector<char> &space, char player, int turn)
{
    int move;
    while (true)
    {
        cout << "  Player" << turn << " (turn): ";
        cin >> move;
        move--;
        if (move >= 0 && move < 9 && space[move] == ' ')
        {
            space[move] = player;
            break;
        }
        else
            cout << "  Invalid move!! \n";
    }
}
// computer_move()
void computer_move(vector<char> &space, char computer,char level)
{ // for level 2
    if(level=='2'){
      // check for winning move
      for(int i=0;i<9;i++) {
      if(space[i]==' '){
        space[i]=computer;
        char player=computer=='X'? 'O':'X';
        if(check_winner (space,player, computer)==2)
        return;
        else
        space[i]=' ';
            }  
      }
      // check for block opponent
       for(int i=0;i<9;i++) {
      if(space[i]==' '){
        space[i]=computer;
        char player=computer=='X'? 'O':'X';
        if(check_winner (space,player, computer)==1)
        return;
        else
        space[i]=' ';
            }  
      }
    }
    // for level 3
 if(level=='3'){
     // play in middle
 if(space[4]==' ') 
 space[4]=computer;
 
 // play in corner
else if(space[0]==' ')
space[0]=computer;
else if(space[2]==' ')
space[2]=computer;
else if(space[6]==' ')
space[6]=computer;
else if(space[8]==' ')
space [8]=computer;
return;

 }
 // for easy 
    int move;
    srand(time(0));
    while (true)
    {
        move = rand() % 9 ;
        
        if ( space[move] == ' ')
        {
            space[move] = computer;
            return;
        }
    }
}
// select level
char select_level() {
char level;
cout<<"   \033[1;4mGame Levels\033[0m:-\n"<<endl;
cout<<"     1.\033[1;32mEasy\033[0m";cout<<"     2.\033[1;33mMedium\033[0m";cout<<"     3.\033[1;31mHard\033[0m\n"<<endl;
while(true){
   cout<<"  Select Level: ";
   cin>>level;
   if(level=='1'||level=='2'||level=='3') break;
       } 
       return level;  
}

// check_winner()
int check_winner(vector<char> &space, char player1, char player2)
{
    if (space[0] != ' ' && space[0] == space[1] && space[1] == space[2])
        return (space[0] == player1) ? 1 : 2;
    else if (space[3] != ' ' && space[3] == space[4] && space[4] == space[5])
        return (space[3] == player1) ? 1 : 2;
    else if (space[6] != ' ' && space[6] == space[7] && space[7] == space[8])
        return (space[6] == player1) ? 1 : 2;
    else if (space[0] != ' ' && space[0] == space[4] && space[4] == space[8])
        return (space[0] == player1) ? 1 : 2;
    else if (space[2] != ' ' && space[2] == space[4] && space[4] == space[6])
        return (space[2] == player1) ? 1 : 2;
    else if (space[0] != ' ' && space[0] == space[3] && space[3] == space[6])
        return (space[0] == player1) ? 1 : 2;
    else if (space[1] != ' ' && space[1] == space[4] && space[4] == space[7])
        return (space[1] == player1) ? 1 : 2;
    else if (space[2] != ' ' && space[2] == space[5] && space[5] == space[8])
        return (space[2] == player1) ? 1 : 2;

    return 0;
}
// check_tie()
bool check_draw(vector<char> &space)
{
    for (char c : space)
    {
        if (c == ' ')
            return false;
    }
    return true;
}
// user_log()
void user_logs(string mssg)
{
    // log file for store user logs for future use
    ofstream ofs("/sdcard/Coding.cpp/PROJECT/Tic Tac Toe/UserLogs.txt", ios::app);
    //cout<<ofs.is_open();
    time_t now = time(nullptr);
    tm *lt = localtime(&now);

    char time[12];
    char date[50];
    strftime(time, sizeof(time), "%I:%M:%S %p", lt);

    strftime(date, sizeof(date), "%A,%d,%B,%Y", lt);
    ofs << mssg << ":\n"
        << date << "  " << time << "\n"
        << endl;
    ofs.close();
}
// save(+update) score to .txt file
void save_score(int cs, int ps, int d1, int ps1, int ps2, int d2)
{
    game_score s;
    ifstream ifs("/sdcard/Coding.cpp/PROJECT/Tic Tac Toe/PlayerScore.txt");
    ifs >> s.computer_score >> s.player_score >> s.draw1 >> s.player_score1 >> s.player_score2 >> s.draw2;
    ifs.close();

    s.computer_score += cs;
    s.player_score += ps;
    s.draw1 += d1;
    s.player_score1 += ps1;
    s.player_score2 += ps2;
    s.draw2 += d2;
    ofstream ofs("/sdcard/Coding.cpp/PROJECT/Tic Tac Toe/PlayerScore.txt");
    ofs << s.computer_score << " " << s.player_score << " " << s.draw1 << " " << s.player_score1 << " " << s.player_score2 << " " << s.draw2;
    ofs.close();
}
// welcome message
void welcome_mssg()
{
    cout << "\n\t  ❌\033[1;33m";
    cout << "WELCOME TO TIC TAC TOE";
    cout << "\033[0m⭕\n";

    cout << "\t  --------------------------\n"
         << endl;
}
// print current player score
void display_score1(int p1, int p2, int d)
{
    cout << "\n  \033[1;3mPlayer1 Win:\033[0m " << p1 << "   \033[1;3mPlayer2 Win:\033[0m " << p2 << "   \033[1;3mDraw:\033[0m " << d << "\n\n";
}
void display_score2(int c, int p, int d)
{
    cout << "\n  \033[1;3mComputer Win:\033[0m " << c << "   \033[1;3mPlayer Win:\033[0m " << p << "   \033[1;3mDraw:\033[0m " << d << "\n\n";
}