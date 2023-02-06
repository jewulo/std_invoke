// std_invoke.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// https://devblogs.microsoft.com/oldnewthing/20220401-00/?p=106426

#include <iostream>

#include "std_invoke.h"

int main()
{
    example_0::run();
    example_1::run();
    example_2::run();
    example_3::run();
    example_4::run();
    example_5::run();

    std::cin.get();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
