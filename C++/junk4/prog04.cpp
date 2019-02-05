// Filename:     prog04.cpp
// Author:       Mathew Walker, CS116, Winter 2015
// Description:  This program creates a chatterbox named Dr. Chat that will respond to user input, allowing
//               the user to have a conversation. The program loops until the user enters nothing twice or says bye.
//               The program recognizes some user inputs and has random responses for other inputs.
//DESIGN
    //1. Preprocessor directives
    //2. Function declaration(prototype) and variable declaration
    //3. DEFINES function used to select random responses
    //4. OPENS main function
    //5. DECLARES variables
    //6.Loops until function returns 0
    //  7a. GETS user input and sets to variable userinput
    //  7b. GOES through function process input and returns 1 or 0
    //8. Function definition for processInput, processes userinput to either have a planned response,
    //   random response, or end the program.

//1. Preprocessor directives
#include <iostream> // for getline(), cout, cin
#include <string>
#include <stdlib.h>

//2. Function declaration(prototype) and global variable declarations
int processInput(std::string);
std::string compresponse = "Hello, how are you?";
std::string chatbox = "Dr. Chat: ";

//from cplusplus.com
//3. DEFINES function used to select random responses
const char* possibleanswers[5] = {
 "Tell me more...", "Do you have any real friends?", "Sorry I wasn't paying attention.", "I want to be a real boy.", "I love you."
};


//4. OPENS main function
int main()
{
    //5. DECLARES variables
    bool keepgoing = true;
    std::string userinput;
    std::cout << chatbox << compresponse << std::endl;

    //6.Loops until function returns 0
    while(keepgoing)
    {
        //  7a. GETS user input and sets to variable userinput
        std::getline (std::cin,userinput);
        //  7b. GOES through function process input and returns 1 or 0
        keepgoing = processInput(userinput);
    }
}

//8. Function definition for processInput, processes userinput to either have a planned response,
//   random response, or end the program.
int processInput(std::string userinput)
{
    //Pre: userinput has been declared and initialized (can contain "")
    //     compresponse has been declared and initialized with "Hello, how are you?"
    //     chatbox has been declared and initialized with "Dr. Chat: "
    //
    //Post: userinput has been processed and a response has been printed to the screen 

    if (userinput == "no" || userinput == "No")
        {
            compresponse = "No? Why?";
            std::cout << chatbox << compresponse << std::endl;
            return 1;
        }
    
    if (userinput == "because" || userinput == "Because")
        {
            compresponse = "Because is what stupid people say";
            std::cout << chatbox <<compresponse << std::endl;
            return 1;
            
        }
    if (userinput == "good" || userinput == "Good") 
        {
            compresponse = "That's fantastic...";
            std::cout << chatbox << compresponse << std::endl;
            return 1;
        }
    if (userinput == "bad" || userinput == "Bad") 
        {
            compresponse = "Are you going to cry?";
            std::cout << chatbox << compresponse << std::endl;
            return 1;
        }
    if (userinput == "")
        {
            compresponse = "Do you want to quit chatting?";
            std::cout << chatbox << compresponse << std::endl;
            std::getline (std::cin,userinput);
        }
    if (userinput == "") return 0;
    if (userinput == "bye" || userinput == "Bye") 
        {
            std::cout << "Bye." << std::endl; 
            return 0;
        }
    if (userinput == compresponse) 
        {
            compresponse = "Why are you repeating me?";
            std::cout << chatbox << compresponse << std::endl;
            return 1;
        }
    else
        {
            compresponse = possibleanswers[ rand() % 5 ];
            std::cout << chatbox << compresponse << std::endl;
        }
    return 1;

}