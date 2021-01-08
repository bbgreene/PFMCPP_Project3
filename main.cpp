/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to your types. 
 
 2) use while() or for() loops to do something interesting inside these new member functions.
         a) for example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
 
 5) click the [run] button.  Clear up any errors or warnings as best you can.
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //3), 4c) 
    {
        Bar bar(startingVal);                //4a)
        while( bar.num < threshold )         //4a) 
        { 
            bar.num += 1;                    //4a)
            
            if( bar.num >= threshold )       //4b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //5) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //6) 
    return 0;
}
}

//call Example::main() in main()






//UDT 1

struct Laptop
{
    int numLetterKeys { 26 };
    int numNumericKeys { 10 };
    float binaryInfoInHardDisk { 499.96f };
    int numUSBPorts { 2 };
    float electricityForPortableUse { 39.0f };
    Laptop();

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

    void transInfoFromUSBToHardDisk();
    void automaticallyAdjustBrightness(float timeOfDay, int displayBrightnessLevel);
    auto displayUpdateInfo(bool isUpdateAvailable, User user);

    User userAdmin;
};

Laptop::Laptop(){}

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

void Laptop::transInfoFromUSBToHardDisk()
{
    std::cout << "Space available for transfer is: " << binaryInfoInHardDisk << " GB" << std::endl;
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

// UDT 2

struct MIDIKeyboard
{
    int numWhiteKeys;
    int numBlackKeys;
    float wattage;
    int midiVeloctiyRange;
    int midiNotesAvailable;
    int ledDisplay;
    MIDIKeyboard();

    void outputMIDIInfo();
    void diplayMIDINoteValue(bool isKeyPressed, int midiNoteValue);
    void consumeElectricity(bool pluggedInToHost);
};

MIDIKeyboard::MIDIKeyboard() :
numWhiteKeys(52),
numBlackKeys(36),
wattage(10.4f),
midiVeloctiyRange(127),
midiNotesAvailable(127),
ledDisplay(0)
{

}

void MIDIKeyboard::outputMIDIInfo()
{
    std::cout << "The amount of MIDI notes available is " << midiNotesAvailable << std::endl;
}

void MIDIKeyboard::diplayMIDINoteValue(bool isKeyPressed, int midiNoteValue)
{
    if(isKeyPressed)
    {
        ledDisplay += midiNoteValue;
    }
}

void MIDIKeyboard::consumeElectricity(bool pluggedInToHost)
{
    if(pluggedInToHost)
    {
        std::cout << "This MIDI keyboard is plugged in and will use " << wattage << " watts per second." << std::endl;
    }
    else
    {
        std::cout << "MIDI keyboard is not plugged in." << std::endl;  
    }
     
    
}

// UDT 3

struct HardwareSynthesiser
{
	float audioRange { 5000.0f };
    int numAudioOutputs { 2 };
    int amountWaveforms { 3 };
    std::string lfo { "LFO" };
    std::string env { "Envelope" };
    float outputLevel { 1.1f };
    HardwareSynthesiser();

	void generateAudioSignals();
	void autoFilterAdjust(bool useLFO); 
	void outputAudioSignals(bool keyHasBeenPressed, float maxOutput);
};

HardwareSynthesiser::HardwareSynthesiser(){}

void HardwareSynthesiser::generateAudioSignals()
{
    std::cout << "The current output level is " << outputLevel << std::endl;
}

void HardwareSynthesiser::autoFilterAdjust(bool useLFO)
{
    if(useLFO)
    {
        std::cout << "The " << lfo << " is modulating the frequency cutoff. " << std::endl;
    }
    else
    {
        std::cout << "The " << env << " is modulating the frequency cutoff. " << std::endl;
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

//UDT 4

struct HousePlant
{
    int currentNumRoots;
    int numLeaves;
    float waterInRoots;
    int numFlowers;
    int numLadybirdsPerDay;
    HousePlant();

    void transportWater();
    void absorbWater(float amountOfWaterPerDay, bool didItRain);
    void growthPerDay(bool sunnyDay);
};

HousePlant::HousePlant() :
currentNumRoots(25),
numLeaves(73),
waterInRoots(1.2f),
numFlowers(22),
numLadybirdsPerDay(3)
{

}

void HousePlant::transportWater()
{
    std::cout << "The amount of leaves that need water is " << numLeaves << std::endl;
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

void HousePlant::growthPerDay(bool sunnyDay)
{
    if(sunnyDay)
    {
        numFlowers += 1;
        std::cout << "The amount of flowers is " << numFlowers << std::endl;
    } 
    else 
    {
        std::cout << "The amount of flowers is " << numFlowers << std::endl;  
    }
}

// UDT 5 

struct WaveformDisplay
{
    float lengthOfSample;
    double height; 
    double width;
    float zoomFunctionLevel;
    std::string loopHighlightColour;
    int bpm;
    WaveformDisplay();

    void drawWaveform();
    void playbackHeadPos(float samplePos);
    void loopPoints(float startPos, float endPos, bool isLoopFunctionOn);
    float sampSize(); // used in UDT 10
    void playForward(); // used in UDT 10
};

WaveformDisplay::WaveformDisplay()
{
    lengthOfSample = 3.2f;
    height = 233;
    width = 643;
    zoomFunctionLevel = 0.0f;
    loopHighlightColour = "Orange";
}

void WaveformDisplay::drawWaveform()
{
    std::cout << "The duration of the waveform to be drawn is " << lengthOfSample << " seconds" << std::endl;
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

float WaveformDisplay::sampSize()
{
    return 44100.0f;
}

void WaveformDisplay::playForward()
{

}
// UDT 6 

struct GlobalSettings
{
    double gainLevel;
    int panPosition;
    int numVoices;
    std::string playbackMode;
    int transpose;
    GlobalSettings();

    void changeAmp(double gainLevelChange); 
    void panAudio(bool sampleIsStereo, bool outputStereo, int changePanPosition);
    void transposeAudio();
};

GlobalSettings::GlobalSettings()
{
    gainLevel = 0.0;
    panPosition = -23;
    numVoices = 3;
    playbackMode = "Classic";
    transpose = 2;
}

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

void GlobalSettings::transposeAudio()
{
    std::cout << "Has the sample been transposed? " << (transpose == 0 ? "No" : "Yes") << std::endl;
}

// UDT 7 

struct Filter 
{
    double freqCutoff;
    float resonance;
    std::string filterType;
    float m_distortionAmount;
    int m_keyTrackerAmount;
    Filter();

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

    void freqContentAffected(bool filterTurnedOn = true);
    auto distFreqContent(bool distTurnedUp, float distortionAmount, int driveAmount);
    void midiNoteToCutoff(int midiNoteValue, int keyTrackerAmount);

    CircuitTypeEmulator circuitTypeSelected;
};

Filter::Filter()
{
    freqCutoff = 2000.0;
    resonance = 80.0f;
    filterType = "Lowpass";
    m_distortionAmount = 0.0f;
    m_keyTrackerAmount = 0;
}
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

void Filter::freqContentAffected(bool filterTurnedOn)
{
    if(filterTurnedOn)
        std::cout << "The frequency content affected is 0 to " << freqCutoff << " Hz" << std::endl;
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
    
// UDT 8 

struct Envelope
{
    float attTime;
    float decTime;
    float susLevel;
    float relTime; 
    int midiVelLevel;
    Envelope();

    void addAttackToAmp();
    void controlCutoffOverTime(bool filterEnvSelected, bool isKeyPressed, double maxValueFilter);
    void controlPitchOverTime(bool pitchEnvSelected, bool isKeyPressed, double maxValuePitch);
};

Envelope::Envelope()
{
    attTime = 0.3f;
    decTime = 0.5f;
    susLevel = 0.0f;
    relTime = 1.5f; 
    midiVelLevel = 75;
}

void Envelope::addAttackToAmp()
{
   std::cout << "The attack time is " << attTime << " seconds" << std::endl;
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
// UDT 9 

struct LFO
{
    float lfoRate;
    float modAmount;
    int modDest;
    std::string waveform;
    float attack;
    LFO();

    void modAmpOfSample();
    void modPitchOfSample(bool lfoON, int pitchRange, bool pitchToggle);
    void modPanOfSample(bool lfoON, int panRange, bool panToggle);
};

LFO::LFO()
{
    lfoRate = 0.0f;
    modAmount = 0.5f;
    modDest = 0;
    waveform = "Saw";
    attack = 2.3f;
}

void LFO::modAmpOfSample()
{
   std::cout << "Please modulation the amplitude for a tremolo effect" << std::endl;
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

// UDT 10 

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
    VSTSampler();

    void displayVisualWaveform(bool isSampleLoaded);
    void playbackSpeed(bool warpOff = false);
    void playbackSamples(bool stereoSampleLoaded);
};

VSTSampler::VSTSampler(){}

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
        std::cout << "Original Speed Playback" << std::endl;
    }
    std::cout << "Audio has been warped" << std::endl;
    
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
    Laptop macbook;
    macbook.transInfoFromUSBToHardDisk();

    std::cout << "Will battery last longer than 1 hour? " << (macbook.electricityForPortableUse > 40.0f ? "Yes" : "No") << std::endl;

    MIDIKeyboard novation;
    novation.outputMIDIInfo();
    novation.consumeElectricity(false);

    std::cout << "The number of whites keys plus the number is black keys is " << novation.numWhiteKeys + novation.numBlackKeys << std::endl;

    HardwareSynthesiser moog;
    moog.generateAudioSignals();
    moog.autoFilterAdjust(false);

    std::cout << "The number of outputs available is " << moog.numAudioOutputs << std::endl; 

    HousePlant swissCheese;
    swissCheese.transportWater();
    swissCheese.growthPerDay(false);

    std::cout << "Amount of water in the roots is " << swissCheese.waterInRoots << " litres" << std::endl;

    WaveformDisplay main;
    main.drawWaveform();

    std::cout << "The sample size is " << (main.sampSize() * main.lengthOfSample) << std::endl;

    GlobalSettings mySettings;
    mySettings.transposeAudio();

    std::cout << "The current sample playback mode is: " << mySettings.playbackMode << std::endl;

    Filter lowpass;
    lowpass.freqContentAffected();

    std::cout << "The current resonance setting is: " << lowpass.resonance << std::endl;

    Envelope firstEnvelope;
    firstEnvelope.addAttackToAmp();

    std::cout << "Does the audio reach full amplitude immdetiately? " << (firstEnvelope.attTime < 0.1f ? "Yes" : "No") << std::endl;

    LFO myLFO;
    myLFO.modAmpOfSample();
    
    std::cout << "The current modulating waveform is: " << myLFO.waveform << std::endl;

    VSTSampler mySampler;
    mySampler.playbackSpeed();

    
    std::cout << "good to go!" << std::endl;
}
