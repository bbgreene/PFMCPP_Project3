/*
Project 3 - Part 1b / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3.  
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

1)  Fill in #1 - 4 with a random UDT in plain english
    These 4 UDTs do not need to be related.
        a) For each plain-english UDT, write out 5 traits or properties and 3 things it can do
        b) remember: these properties will eventually become primitives
*/

/*
 example:  
 
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior

    Notice that I did not use "has a vacuum cleaner" or "Has eco-friendly cleaning supplies" as one of the properties
    
    Writing 'has a ___" checks whether or not your object **has the ability to do something**.
    Instead, I wrote "number of vacuum cleaners" and "number of eco-friendly cleaning supplies".  
    
    These are specific objects or amounts. 
    
    In C++ terms, this means to I want you to avoid using 'bool' (has a) as a member variable type.
    Instead, prefer the other primitive types.
 */

/*
Thing 1) Laptop
5 properties:
    1) number of letter keys
    2) number of numeric keys
    3) amount of binary information in hard disk
    4) number of usb ports
    5) amount of electricity needed for portable use
3 things it can do:
    1) transfer information from usb device to hard disk
    2) automatically adjust display brightness
    3) provide update information to user
 */

/*
Thing 2) MIDI Keyboard
5 properties:
    1) number of white keys
    2) number of black keys
    3) amount of user presets
    4) number of velocity sensitive pads
    5) number of encoders
3 things it can do:
    1) output MIDI information
    2) display MIDI note value
    3) consume electricity via USB port
 */

/*
Thing 3) Hardware Synthesiser
5 properties:
    1) number of filters
    2) number of audio outputs
    3) amount of waveform types 
    4) number of LFOs
    5) number of envelopes
3 things it can do:
    1) generate audio signals
    2) automatically adjust filter frequency
    3) output audio signals
 */

/*
Thing 4) House Plant
5 properties:
    1) number of roots
    2) number of leaves
    3) amount of water in roots
    4) number of flowers
    5) number of ladybirds living on it per day
3 things it can do:
    1) uses carbon dioxide
    2) absorbs water from the air
    3) extends it’s overall height per day
 */



/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
