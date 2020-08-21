/*
Project 3 - Part 1e / 5
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

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct for each of your 10 types. i.e.:
*/
struct CellPhone
{

};
/*
2) Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
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
 */

#include <iostream>
#include <string>

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function whose parameter has a default value.
        //the parameter name is related to the work the function will perform.
        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  
};







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
Thing 5) Waveform display
5 properties:
    1) Length of sample in ms 
    2) Height in pixels 
    3) Width in pixels
    4) Zoom function as a percentage
    5) Loop hightlight colour
3 things it can do:
    1) display transient positions of digital audio signal 
    2) display playback head position
    3) display user defined loops points of sample
 */

/*
Thing 6) Global settings
5 properties:
    1) Gain level in dB
    2) Pan setting (-50 to 50)
    3) Number of voices
    4) Sampler playback mode
    5) Transposition in semitones 
3 things it can do:
    1) change amplitude of sample
    2) pan audio in a stereo image
    3) transpose audio in terms of musical intervals
 */

/*
Thing 7) Filter
5 properties:
    1) Frequency cutoff in Hz
    2) Resonance as a percentage
    3) Filter type selection
    4) Distortion amount in dB
    5) Key tracker
3 things it can do:
    1) affect frequency content of audio
    2) distort frequency content of audio
    3) adjust frequency cutoff of filter based on user MIDI note value input
 */

/*
Thing 8) Envelope
5 properties:
    1) Attack time in ms
    2) Decay time in ms
    3) Sustain level in dB
    4) Release time in ms
    5) Amount of MIDI velocity level as a percentage
3 things it can do:
    1) control amplitude level of a sample over time
    2) control filter cutoff frequency over time 
    3) control pitch of a sample over time
 */

/*
Thing 9) LFO
5 properties:
    1) Rate in Hz
    2) Modulation amount as a percentage
    3) Modulation destination 
    4) Waveform type
    5) Attack in ms
3 things it can do:
    1) modulate amplitude of sample 
    2) modulate pitch of sample
    3) modulate audio output between left and right channel
 */

/*
Thing 10) VST Sampler 
5 properties:
    1) Waveform display
    2) Global settings
    3) Filter
    4) Envelope
    5) LFO
3 things it can do:
    1) display waveform of an audio sample 
    2) playback audio at various speeds
    3) effect frequency content of audio
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
