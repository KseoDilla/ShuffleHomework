/*
  #####################################
  #                                   #
  # ShuffleDeck Homework by Kevin Suh #
  #                                   #
  #####################################
*/

#include <algorithm> //for_each
#include <csignal> //signal handler
#include <deque> //a dequeue to hold our deck of cards
#include <iostream> //std::cout,cin
#include "Shuffler.h" //library for shuffling the users's input of cards
#include <sstream> //sstream to help tokenize the input
#include <stdint.h>
#include <vector> //vector for easier input processing


//@brief A signal handler to have the program end quietly
//allows us to ctrl+c from when the executable is ran from the Makefile
//and still exit quietly
void sighandler(int32_t signal)
{
    switch(signal)
    {
        case 2:
            exit(0);
        default:
            exit(signal);
    }
}



//@brief helper function to read in the input
void ReadInDeck(std::vector<std::string> inputList,
                std::deque<int32_t>& deckOfCards)
{
    std::string lastNum;
    try
    {
        deckOfCards.clear();
        for(std::string nums : inputList)
        {
            lastNum = nums;
            deckOfCards.push_front(stoi(nums));
        }
    }
    catch(std::invalid_argument &e)
    {
        std::cerr << "Invalid argument! Please provide numbers only." << std::endl; 
    }
    catch(std::out_of_range& e)
    {
        std::cerr << "Invalid argument! The number " << lastNum  << " is too large" << std::endl;
    }
    std::cout << "User's input of cards (LIFO): ";
    std::for_each(
            deckOfCards.rbegin(),
            deckOfCards.rend(),
            [](int32_t const &i) {
            std::cout << i << ' ';
            });
    std::cout << std::endl;
}


//@brief method to help grab the list of inputs when the docker service is ran int32_teractively
//@param inputList a container with 
//@param deckOfCards the user's input 
void grabNewInput(std::deque<int32_t>& deckOfCards)
{
    while(true)
    {
        try
        {
            std::vector<std::string> inputList;
            std::cout << "Please provide a new list of cards (provide an empty list or ctrl+c to quit): ";
            std::string input;
            std::getline(std::cin, input);
            if(input.empty())
            {
                exit(0);
            }
            std::stringstream ss(input);
            inputList.clear();
            while(getline(ss, input, ' '))
            {
                inputList.push_back(input);
            }
            ReadInDeck(inputList, deckOfCards);
            break;
        }
        catch(std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}



//@brief method to help start shuffling and prompt for new inputs
//@param inputList the user's input
int32_t begin(std::vector<std::string>& inputList)
{
    try
    {
        std::deque<int32_t> deckOfCards;
        ReadInDeck(inputList, deckOfCards);
        while(true)
        {
            Shuffler shuffle(deckOfCards);
            int32_t numOfRounds = shuffle.start();
            std::cout << std::endl;
            std::cout << "It takes " << numOfRounds << " rounds to shuffle this deck back into its original order" << std::endl;
            std::cout << std::endl;
            grabNewInput(deckOfCards);
        }
    }
    catch(...)
    {
        std::cout << "FATAL Exception: Please contact Kevin Suh, save the logs, and report the findings!" << std::endl;
    }
    return 0;
}



//@brief Main entry point32_t
//@param argc the number of arguments provided - there is always at least 1 (the program name)
//@param argv the char*[] containing the list of args initially passed to this program
int32_t main(int argc, char* argv[])
{
    std::signal(SIGINT, sighandler);
    std::vector<std::string> inputList;
    if (argc > 1) {
        inputList.assign(argv + 1, argv + argc);
    }
    return begin(inputList);
};
