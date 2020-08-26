 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
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
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you decide to write empty functions, you will need to fill them in with code in part 3.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
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
struct Laptop
{
	//number of letter keys
	int numLetterKeys = 26;
	//number of numeric keys
	int numNumericKeys = 10;
	//amount of binary information in hard disk
	float binaryInfoInHardDisk = 499.96f;
	//number of usb ports
	int numUSBPorts = 2;
	//amount of electricity needed for portable use
	float electricityForPortableUse = 58.2f;
	
	struct User //first nested UDT
	{
		bool isUserMale = true;
		int userAge = 37;
		bool isUserAdmin = true;
		std::string userName = "Billy Crystal";
		std::string password = "123456789";
		
		bool turnOnLaptop(bool laptopOff = true, bool userPressedPowerButton = true);
		int sendEmails(int emailsPerDay = 10, bool personalEmails = true);
		void openAProgram(int currentProgramAmount, bool isUserAdmin);
	};

	//transfer information from usb device to hard disk
	void transInfoFromUSBToHardDisk(float transferTime, float dataSize);
    	//automatically adjust display brightness
	void automaticallyAdjustBrightness(float timeOfDay, int displayBrightnessLevel);
    	//provide update information to user
	bool displayUpdateInfo(bool isUpdateAvailable, User user);

	User whoUsingLaptop; //example of member variable whose type is a UDT (User)
};

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
struct MIDIKeyboard
{
	//number of white keys
	int numWhiteKeys = 52;
	//number of black keys
	int numBlackKeys = 36;
	//amount of user presets
	int userPresetsAvailable = 64;
	//number of velocity sensitive pads
	int numVelocityPads = 16;
	//number of encoders
	int numEncoders = 8;

	//output MIDI information
	int outputMIDIInfo(int midiNoteValue = 62, int velocityValue = 71);
	//display MIDI note value
	void diplayMIDINoteValue(bool isKeyPressed);
	//consume electricity via USB port
	float consumeElectricity(bool pluggedInToHost = true, float wattage = 10.4f);
};

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
struct HardwareSynthesiser
{
	//number of filters
	int numFilters = 3;
	//number of audio outputs
	int numAudioOutputs = 2;
	//amount of waveform types 
	int amountWaveforms = 4;
	//number of LFOs
	int numLFOs = 1;
	//number of envelopes
	int numEnvelopes = 2;

	//generate audio signals
	void generateAudioSignals(float oscFreq, int waveType);
	//automatically adjust filter frequency
	void autoFilterAdjust(int freqRange, bool useLFO, bool useEnv1); 
	//output audio signals
	float outputAudioSignals(bool stereo = true, float maxOutput = 24.0f);
};

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
struct HousePlant
{
    //number of roots
    int numRoots = 25;
    //number of leaves
    int numLeaves = 73;
    //amount of water in roots
    float waterInRoots = 1.2f;
    //number of flowers
    int numFlowers = 22;
    //number of ladybirds living on it per day
    int numLadybirdsPerDay = 3;

    //uses carbon dioxide
    void useCarbonDioxide(float amountOfCarbonPerDay, bool isItDayTime);
    //absorbs water from the air
    void absorbWater(float amountOfWaterPerDay, bool didItRain);
    //extends it’s overall height per day
    void extendHeightPerDay(float growthPerDay, bool sunnyDay, int numRoots);//example of using UDT in a member function
};

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
struct WaveformDisplay
{
    //Length of sample in ms
    float lengthOfSample = 3.2f;
    //Height in pixels
    double height = 233; 
    //Width in pixels
    double width = 643;
    //Zoom function as a percentage
    float zoomFunctionLevel = 0.0f;
    //Loop hightlight colour
    std::string loopHighlightColour = "Orange";

    //display transient positions of digital audio signal
    void transientPositions(int transientAmount, float subdivision);
    //display playback head position
    float playbackHeadPos(float samplePos, float lengthOfSample);
    //display user defined loops points of sample
    void loopPoints(float startPos, float endPos, bool isLoopFunctionOn);
};

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
struct GlobalSettings
{
    //Gain level in dB
    double gainLevel = 0.0;
    //Pan setting (-50 to 50)
    int panPosition = -23;
    //Number of voices
    int numVoices = 3;
    //Sampler playback mode
    std::string playbackMode = "Classic";
    //Transposition in semitones 
    int transpose = -4;

    //change amplitude of sample
    double changeAmp(double gainLevel, double maxGain = 6); 
    //pan audio in a stereo image
    int panAudio(int panPosition, bool sampleIsStereo = false);
    //transpose audio in terms of musical intervals
    int transposeAudio(int transpose, int highestValue = 24, int lowestValue = -24);
};

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
struct Filter
{
    //Frequency cutoff in Hz
    double freqCutoff = 2000.0;
    //Resonance as a percentage
    float resonance = 80.0f;
    //Filter type selection
    std::string filterType = "Lowpass";
    //Distortion amount in dB
    float distortionAmount = 0.0f;
    //Key tracker
    int keyTrackerAmount = 0;

    struct CircuitTypeEmulator //second nested UDT
    {
        //type selector
        std::string type = "MS20";
        //drive parameter
        int driveAmount = 0; 
        //slope of attenuation parameter
        int slope = 24;
        //self oscillation amount
        float selfOsc = 20.1f;
        //toogle switch to clean
        bool isEmulationOn = true;


        //create an internal feedback loop
        void internallyFeedback(float maxFeedbackValue, float selfOsc);
        //clip audio
        std::string clipAudio(std::string clipType = "Soft");
        //manipulate phase
        void manipulatePhase(bool isLinearPhase);
    };

    //affect frequency content of audio
    void freqContentAffected(double lowFreq, double highFreq, double freqCutoff);
    //distort frequency content of audio
    void distFreqContent(bool distTurnedUp, float distortionAmount, int driveAmount);
    //adjust frequency cutoff of filter based on user MIDI note value input
    void midiNoteToCutoff(int midiNoteValue, int keyTrackerAmount);

    CircuitTypeEmulator circuitTypeSelected; //example of member variable whose type is a UDT (CircuitTypeEmulator)
};

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
struct Envelope
{
    //Attack time in ms
    float attTime = 0.1f;
    //Decay time in ms
    float decTime = 0.5f;
    //Sustain level in dB
    float susLevel = 0.0f;
    //Release time in ms
    float relTime = 1.5f; 
    //Amount of MIDI velocity level as a percentage
    int midiVelLevel = 75;

    //control amplitude level of a sample over time
    void controlAmpOverTime(double maxValueAmp, float sampleLength, bool iskeyPressed, bool iskeyReleased);
    //control filter cutoff frequency over time 
    void controlCutoffOverTime(double maxValueCutoff, double freqCutoff, bool iskeyPressed, bool iskeyReleased);
    //control pitch of a sample over time
    void controlPitchOverTime(double maxValuePitch, double minValue, bool iskeyPressed, bool iskeyReleased);
};

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
struct LFO
{
    //Rate in Hz
    float lfoRate = 0.0f;
    //Modulation amount as a percentage
    int modAmount = 0;
    //Modulation destination 
    int modDest = 0;
    //Waveform type
    std::string waveform = "Saw";
    //Attack in ms
    float attack = 2.3f;

    //modulate amplitude of sample
    void modAmpOfSample(bool lfoON, int modAmount = 50, int modDest = 0);
    //modulate pitch of sample
    void modPitchOfSample(bool lfoON, int modAmount = 18, int modDest = 1);
    //modulate audio output between left and right channel
    void modPanhOfSample(bool lfoON, int modAmount = 25, int modDest = 2);
};

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
struct VSTSampler
{
    //Waveform display
    WaveformDisplay waveformVisual;
    //Global settings
    GlobalSettings globalControlSettings;
    //Filter
    Filter filter;
    //Envelope
    Envelope envelope;
    //LFO
    LFO lfo;

    //display waveform of an audio sample
    void displayVisualWaveform();
    //playback audio at various speeds
    void playbackSpeed(bool warpOff, int midiNoteValueIn, int highestSpeedPercentage);
    //affect frequency content of audio
    void freqContentOverall();
};
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
