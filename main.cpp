/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 1) Add a constructor for each User-Defined-Type.
 
 2) amend some of your UDT's member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of each of your user-defined types in the main() function

 4) call some of your UDT's amended member functions in main().
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int a; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    a = 0;
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << a << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'a' equal to 0? " << (foo.a == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




//UDT 1 // complete

struct Laptop
{
    int numLetterKeys = 26;
    int numNumericKeys = 10;
    float binaryInfoInHardDisk = 499.96f;
    int numUSBPorts = 2;
    float electricityForPortableUse = 58.2f;

    struct User
    {
        bool isUserMale = true;
        int userAge = 37;
        bool isUserAdmin;
        std::string userName = "Billy Crystal";
        int numPowerOnPerday;
        int personalEmailTot;
        int programmesOpen;
        
        void turnOnLaptop(bool laptopOff, bool userPressedPowerButton);
        auto sendEmails(bool personalEmails = true, int emailsPerDay = 10);
        auto openAProgram(int currentProgramAmount, bool newProgrammeOpen);
    };

    void transInfoFromUSBToHardDisk(float transferTime, float dataSize);
    void automaticallyAdjustBrightness(float timeOfDay, int displayBrightnessLevel);
    auto displayUpdateInfo(bool isUpdateAvailable, User user);

    User userAdmin;
};

void Laptop::User::turnOnLaptop(bool laptopOff, bool userPressedPowerButton)
{
   if(laptopOff && userPressedPowerButton)
   {
       numPowerOnPerday += 1;
   }
}

auto Laptop::User::sendEmails(bool personalEmails, int emailsPerDay)
{
    if(personalEmails)
    {
        emailsPerDay = 10;
    }
    else
    {
        emailsPerDay = 0;
    }
    personalEmailTot += emailsPerDay;
}

auto Laptop::User::openAProgram(int currentProgramAmount, bool newProgrammeOpen)
{
    currentProgramAmount = 3;
    newProgrammeOpen = true;
    programmesOpen += 1;
}

void Laptop::transInfoFromUSBToHardDisk(float transferTime, float dataSize = 200)
{
    transferTime = dataSize / 50;
    binaryInfoInHardDisk += dataSize;
}

void Laptop::automaticallyAdjustBrightness(float timeOfDay, int displayBrightnessLevel)
{
    if(timeOfDay > 6.0f && timeOfDay < 18.0f)
    {
        displayBrightnessLevel = 80;
    }
    else
    {
        displayBrightnessLevel = 35;
    }  
}

auto Laptop::displayUpdateInfo(bool isUpdateAvailable, Laptop::User user)
{
    isUpdateAvailable = true;
    user = userAdmin;
}

// UDT 2 // complete

struct MIDIKeyboard
{
    int numWhiteKeys = 52;
    int numBlackKeys = 36;
    float electricityPerDay;
    int midiVeloctiyRange;
    int midiNoteRange;
    int ledDisplay;

    void outputMIDIInfo(int midiNoteValue, int velocityValue);
    void diplayMIDINoteValue(bool isKeyPressed, int midiNoteValue);
    void consumeElectricity(bool pluggedInToHost, float wattage);
};

void MIDIKeyboard::outputMIDIInfo(int midiNoteValue, int velocityValue)
{
    midiNoteValue = 19;
    velocityValue = 93;
    midiNoteRange += midiNoteValue;
    midiVeloctiyRange += velocityValue;   
}

void MIDIKeyboard::diplayMIDINoteValue(bool isKeyPressed, int midiNoteValue)
{
    if(isKeyPressed)
    {
        ledDisplay += midiNoteValue;
    }
}

void MIDIKeyboard::consumeElectricity(bool pluggedInToHost, float wattage)
{
    if(pluggedInToHost)
    {
        wattage = 10.4f;
    }
    else
    {
        wattage = 0.0f;
    }
    electricityPerDay += wattage;
}

// UDT 3 // complete

struct HardwareSynthesiser
{
	float audioRange;
	int numAudioOutputs = 2;
	int amountWaveforms;
	int numLFOs;
	int numEnvelopes = 2;
    float outputLevel;

	auto generateAudioSignals(float maxOscFreq, int waveType);
	void autoFilterAdjust(int freqRange, bool useLFO, bool useEnv1); 
	void outputAudioSignals(bool keyHasBeenPressed, float maxOutput);
};

auto HardwareSynthesiser::generateAudioSignals(float maxOscFreq = 5000.0f, int waveType = 1)
{
    audioRange += maxOscFreq;
    amountWaveforms += waveType;
}

void HardwareSynthesiser::autoFilterAdjust(int freqRange, bool useLFO, bool useEnv1)
{
    if(useLFO)
    {
        freqRange = 200;
        numLFOs = 1;
    }
    else
    {
        useEnv1 = true;
        numEnvelopes = 1;
        freqRange = 300;
    }
}

void HardwareSynthesiser::outputAudioSignals(bool keyHasBeenPressed, float output)
{
    if(keyHasBeenPressed)
    {
        output = 24.0f;
    }
    else 
    {
        output = 0.0f;
    }
    outputLevel += output;
}

//UDT 4. // complete

struct HousePlant
{
    int currentNumRoots = 25;
    int numLeaves = 73;
    float waterInRoots = 1.2f;
    int numFlowers = 22;
    int numLadybirdsPerDay = 3;
    float COperday; // new member variable for implementation 1 below

    void useCarbonDioxide(float amountOfCarbonPerDay, bool isItDayTime);
    void absorbWater(float amountOfWaterPerDay, bool didItRain);
    void extendHeightPerDay(float growthPerDay, bool sunnyDay);
};

void HousePlant::useCarbonDioxide(float amountOfCarbonPerDay, bool isItDayTime)
{
    if(!isItDayTime)
    {
        amountOfCarbonPerDay = 0.0f;
    }
    else
    {
        amountOfCarbonPerDay = 300.0f;
    }
    COperday += amountOfCarbonPerDay;
}

void HousePlant::absorbWater(float amountOfWaterPerDay, bool didItRain)
{
    if(didItRain)
    {
        amountOfWaterPerDay = 1.2f;
    }
    else 
    {
        amountOfWaterPerDay = 0.1f;
    }
    waterInRoots += amountOfWaterPerDay;
}

void HousePlant::extendHeightPerDay(float growthPerDay, bool sunnyDay)
{
    if(sunnyDay)
    {
       growthPerDay = 2.3f;
    } 
    else 
    {
       growthPerDay = 1.1f;  
    }
    currentNumRoots += 1;
}

// UDT 5 // complete

struct WaveformDisplay
{
    float lengthOfSample = 3.2f;
    double height = 233; 
    double width = 643;
    float zoomFunctionLevel = 0.0f;
    std::string loopHighlightColour = "Orange";
    int bpm;

    void transientPositions(bool bpmOn, float quarterSubdivision,int bpmValue);
    void playbackHeadPos(float samplePos);
    void loopPoints(float startPos, float endPos, bool isLoopFunctionOn);
    int sampSize(); // used in UDT 10
    void playForward(); // used in UDT 10
};

void WaveformDisplay::transientPositions(bool bpmOn, float quarterSubdivision, int bpmValue = 120)
{
    if(bpmOn)
    {
        quarterSubdivision = 60 / bpmValue;
    }
    bpm += bpmValue;
}

void WaveformDisplay::playbackHeadPos(float samplePos)
{
    samplePos = 0.0f;
}

void WaveformDisplay::loopPoints(float startPos, float endPos, bool isLoopFunctionOn)
{
    if(isLoopFunctionOn)
    {
        loopHighlightColour = "Orange";
    }
    else
    {
        loopHighlightColour = "black";
    }
    startPos = 1.1f;
    endPos = 2.3f;
}

int WaveformDisplay::sampSize()
{
    return 1;
}

void WaveformDisplay::playForward()
{

}
// UDT 6 // complete

struct GlobalSettings
{
    double gainLevel = 0.0;
    int panPosition = -23;
    int numVoices = 3;
    std::string playbackMode = "Classic";
    int transpose = 0;

    void changeAmp(double gainLevelChange); 
    void panAudio(bool sampleIsStereo, bool outputStereo, int changePanPosition);
    void transposeAudio(int changePitch);
};

void GlobalSettings::changeAmp(double gainLevelChange = 2)
{
    gainLevel += gainLevelChange;
}

void GlobalSettings::panAudio(bool sampleIsStereo, bool outputStereo, int changePanPosition = 0)
{
    if(sampleIsStereo)
    {
        outputStereo = true;
    }
    else
    {
        outputStereo = false;
    }
    changePanPosition = 0;
    panPosition += changePanPosition;
}

void GlobalSettings::transposeAudio(int changePitch = 2)
{
    transpose += changePitch;
}

// UDT 7 // complete

struct Filter 
{
    double freqCutoff = 2000.0;
    float resonance = 80.0f;
    std::string filterType = "Lowpass";
    float m_distortionAmount = 0.0f;
    int m_keyTrackerAmount = 0;

    struct CircuitTypeEmulator
    {
        std::string type = "MS20";
        int driveAmount = 0; 
        int slope = 24;
        float selfOscAmount;
        bool isEmulationOn = true;
        std::string m_ClipType;

        void internallyFeedback(float feedbackValue);
        void clipAudio(std::string clipType);
        void manipulatePhase(bool isLinearPhase);
    };

    void freqContentAffected(double lowFreq, double highFreq, double freqCutoffChange);
    auto distFreqContent(bool distTurnedUp, float distortionAmount, int driveAmount);
    void midiNoteToCutoff(int midiNoteValue, int keyTrackerAmount);

    CircuitTypeEmulator circuitTypeSelected;
};

void Filter::CircuitTypeEmulator::internallyFeedback(float feedbackValue)
{
    if(feedbackValue > 0.7f)
    {
        selfOscAmount += feedbackValue;
    }
}

void Filter::CircuitTypeEmulator::clipAudio(std::string clipType = "Soft")
{
    m_ClipType += clipType;
}

void Filter::CircuitTypeEmulator::manipulatePhase(bool isLinearPhase)
{
    if(!isLinearPhase)
    {
        slope = 24;
    }
    else 
    {
        slope = 12;
    }
}

void Filter::freqContentAffected(double lowFreq, double highFreq, double freqCutoffChange)
{
    lowFreq = 500;
    highFreq = 4000;
    freqCutoffChange = 2000;
    freqCutoff += freqCutoffChange;
}

auto Filter::distFreqContent(bool distTurnedUp, float distortionAmount, int driveAmount)
{
    distTurnedUp = true;
    distortionAmount = 1.1f;
    driveAmount = 3;
}

void Filter::midiNoteToCutoff(int midiNoteValue, int keyTrackerAmount = 3)
{
    midiNoteValue = 45;
    m_keyTrackerAmount += keyTrackerAmount;
}
    
// UDT 8 // complete

struct Envelope
{
    float attTime = 0.1f;
    float decTime = 0.5f;
    float susLevel = 0.0f;
    float relTime = 1.5f; 
    int midiVelLevel = 75;

    void controlAmpOverTime(bool ampEnvSelected, bool isKeyPressed, float maxValueAmp);
    void controlCutoffOverTime(bool filterEnvSelected, bool isKeyPressed, double maxValueFilter);
    void controlPitchOverTime(bool pitchEnvSelected, bool isKeyPressed, double maxValuePitch);
};

void Envelope::controlAmpOverTime(bool ampEnvSelected, bool isKeyPressed, float maxValueAmp)
{
    if(isKeyPressed && ampEnvSelected)
    {
        maxValueAmp = midiVelLevel / 100;
    }
    else 
    {
        maxValueAmp = 0.0f;
    }
}

void Envelope::controlCutoffOverTime(bool filterEnvSelected, bool isKeyPressed, double maxValueFilter)
{
    if(isKeyPressed && filterEnvSelected)
    {
        maxValueFilter = midiVelLevel * 10;
    }
    else 
    {
        maxValueFilter = 1000;
    }
}

void Envelope::controlPitchOverTime(bool pitchEnvSelected, bool isKeyPressed, double maxValuePitch)
{
    if(isKeyPressed && pitchEnvSelected)
    {
        maxValuePitch = 24 / 100 * midiVelLevel;
    }
    else 
    {
        maxValuePitch = 0;
    }
}
// UDT 9 // complete

struct LFO
{
    float lfoRate = 0.0f;
    int modAmount = 0;
    int modDest = 0;
    std::string waveform = "Saw";
    float attack = 2.3f;

    void modAmpOfSample(bool lfoON, int ampRange, bool ampToggle);
    void modPitchOfSample(bool lfoON, int pitchRange, bool pitchToggle);
    void modPanOfSample(bool lfoON, int panRange, bool panToggle);
};

void LFO::modAmpOfSample(bool lfoON, int ampRange, bool ampToggle = true)
{
    if(lfoON && ampToggle)
    {
        ampRange = 1;
    }
    else
    {
        ampRange = 0;
    }
    modDest += 0;
}

void LFO::modPitchOfSample(bool lfoON, int pitchRange, bool pitchToggle = true)
{
    if(lfoON && pitchToggle)
    {
        pitchRange = 24;
    }
    else
    {
        pitchRange = 0;
    }
    modDest += 1;
}

void LFO::modPanOfSample(bool lfoON, int panRange, bool panToggle = true)
{
    if(lfoON && panToggle)
    {
        panRange = 100;
    }
    else
    {
        panRange = 0;
    }
    modDest += 2;
}

// UDT 10 // complete

struct VSTSampler
{
    WaveformDisplay waveformVisual;
    GlobalSettings globalControlSettings;
    Filter filter;
    Envelope envelope;
    LFO lfo;
    WaveformDisplay leftChannel;   
    WaveformDisplay rightChannel;
    bool displayAWaveform; 
    int numberOfIndividualSamples;
    bool normalSpeed; 

    void displayVisualWaveform(bool isSampleLoaded);
    void playbackSpeed(bool warpOff);
    void playbackSamples(bool stereoSampleLoaded);
};

void VSTSampler::displayVisualWaveform(bool isSampleLoaded)
{
    if(isSampleLoaded)
    {
        displayAWaveform = true;
    }
}

void VSTSampler::playbackSpeed(bool warpOff)
{
    if(warpOff)
    {
        normalSpeed = true;
    }
    else
    {
        normalSpeed = false;
    }
}

void VSTSampler::playbackSamples(bool stereoSampleLoaded) // uses member functions from WaveformDisplay struct. This implementation adds sample snapshots together depending on stereo/mono
{
    if(stereoSampleLoaded)
    {
        leftChannel.playForward();
        rightChannel.playForward();
    }
    else
    {
        leftChannel.sampSize();
    }
    numberOfIndividualSamples += leftChannel.sampSize() + rightChannel.sampSize();
}
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
    Example::main();
    std::cout << "good to go!" << std::endl;
}
