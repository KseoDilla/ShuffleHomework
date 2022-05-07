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



//@brief method to help grab the list of inputs when the docker service is ran interactively
//@param inputList a container with 
//@param deckOfCards the user's input 
int32_t grabNewInput(std::string initialArg)
{
    std::string input;
    while(true)
    {
        try
        {
            if(!initialArg.empty())
            {
                input = initialArg;
            }
            else
            {
                std::cout << "Please provide a new deck size (provide an empty input or ctrl+c to quit): ";
                std::getline(std::cin, input);
                if(input.empty())
                {
                    exit(0);
                }
            }
            return stoi(input);
        }
        catch(std::invalid_argument &e)
        {
            std::cerr << "Invalid argument! Please provide numbers only." << std::endl; 
        }
        catch(std::out_of_range& e)
        {
            std::cerr << "Invalid argument! The input " << input  << " is too large" << std::endl;
        }        
    }
    return 0;
}



//@brief method to help start shuffling and prompt for new inputs
//@param inputList the user's input
int32_t begin(std::string initialArg)
{
    int numOfCards = 0;
    bool firstRun = true;
    try
    {
        while(true)
        {
            numOfCards = firstRun ? grabNewInput(initialArg) : grabNewInput("");
            firstRun = false;
            Shuffler shuffle(numOfCards);
            int32_t numOfRounds = shuffle.start();
            std::cout << std::endl;
            std::cout << "It takes " << numOfRounds << " rounds to shuffle this deck back into its original order" << std::endl;
            std::cout << std::endl;
        }
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(...)
    {
        std::cout << "FATAL Exception: Please contact Kevin Suh, save the logs, and report the findings!" << std::endl;
    }
    return 0;
}



//@brief Main entry point
//@param argc the number of arguments provided - there is always at least 1 (the program name)
//@param argv the char*[] containing the list of args initially passed to this program
int main(int argc, char* argv[])
{
    std::signal(SIGINT, sighandler);
    std::string initialArg;
    if (argc > 1) {
        initialArg = argv[1];
    }
    return begin(initialArg);
};
