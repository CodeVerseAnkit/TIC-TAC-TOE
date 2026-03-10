#include <iostream>
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
// ---> 1. How To Play
void how_to_play()
{
    cout << "\n\n  This feature is under construction👩‍💻" << endl;
    back_button();
}
// ---> 2. Score
void score()
{
    cout << "\n\n  This feature is under construction👩‍💻" << endl;
    back_button();
}
// ---> 3. Play With Bot
void play_with_bot()
{
    cout << "\n\n  This feature is under construction👩‍💻" << endl;
    back_button();
}
// ---> 4. Play With Friend
void play_with_friend()
{
    cout << "\n\n  This feature is under construction👩‍💻" << endl;
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
int main()
{
    char input;
    do
    {
        menu();
        input = user_input();
        switch (input)
        {
        case '1':
            how_to_play();
            break;
        case '2':
            score();
            break;
        case '3':
            play_with_bot();
            break;
        case '4':
            play_with_friend();
            break;
        case '5':
            play_online();
            break;
        case '6':
            app_info();
            break;
        case '7':
            exit();
            break;
        default:
            cout << "  Invalid Input ";
            break;
        }
        if (input != '7')
            clear_screen();
    } while (input != '7');
    return 0;
}