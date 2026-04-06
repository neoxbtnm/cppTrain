// Составить программу-тест в MVS на языке программирования С++: 
// на экране по очереди появляются вопросы (вопросы выбираются программистом), 
// с вариантами ответов. В конце работы программа выдает количество заработанных баллов по результатам ответа.

#include <iostream>


int main()
{
    int iChoice = 0;
    int points = 5;

    std::cout << "1) How many cat lives\nanswers:\n-> 5 lives\n-> 7 lives\n-> 9 lives\nyour answer: ";
    std::cin >> iChoice;
    std::cout << std::endl;

    switch (iChoice) {
        case 9:
        {
            break;
        }
        default:
        {
            points -= 1;
        }
    }

    std::cout << "2) How many centimeters in a meter?\nanswers:\n-> 10 centimeters\n-> 100 centimeters\n-> 1000 centimeters\nyour answer: ";
    std::cin >> iChoice;
    std::cout << std::endl;

    switch (iChoice) {
        case 100:
        {
            break;
        }

        default:
        {
            points -= 1;
        }
    }

    std::cout << "3) The speed of sound?\nanswers:\n-> 340 m/s\n-> 320 m/s\n-> 240 m/s\nyour answer: ";
    std::cin >> iChoice;
    std::cout << std::endl;

    switch (iChoice) {
        case 340:
        {
            break;
        }
        default: {
            points -= 1;
        }
    }

    std::cout << "Rating = " << points << " ballov";
}