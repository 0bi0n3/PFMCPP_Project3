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

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
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
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 If your code produces -Wconversion warnings, do NOT use static_cast<> to solve the warnings.  
 Casting has not been covered yet.
 Change your code so that no warnings are produced WITHOUT using casting.
 This usually means you have to use identical types for all variables used in an expression that is producing that conversion warning.
 */


/*
Thing 2) MIDI Keyboard
5 properties:
    1) number of keys (int)
    2) number of knobs (int)
    3) number of MPC pads (int)
    4) pitch control range (double)
    5) mode selection (char)
3 things it can do:
    1) adjust pitch.
    2) register key presses.
    3) register pad hit velocities.
*/
struct MidiKeyboard
{
// 5 properties:
    int numberOfKeys = 49;
    int numberOfKnobs = 12;
    int numberOfMPCPads = 8;
    double pitchControlRange = 200000.0;
    char modeSelection = 'X';

// 3 things it can do:
//     1) adjust pitch.
    double adjustPitch(MidiKeyboard pitchChange); // NOTE: the pitch control effects the adjustment of the functions return value.
//     2) register key presses.
    void isKeyPressed();

//     3) register pad hit velocities.
    float padHitAmount(MidiKeyboard padNumber); // NOTE: returns a relevant value able to influence other fuctions.
};


/*
Thing 3) Roland TB-303
5 properties:
    1) step-sequencer (int)
    2) mode dial (int)
    3) tempo dial (int)
    4) cutoff frequency filter knob (float)
    5) volume knob (float)
3 things it can do:
    1) program sequence of notes.
    2) apply filtering.
    3) increase || decrease playback tempo.
*/
struct RolandTB303
{
// 5 properties:
    int stepSequencer = 16;
    int modeDial = 10;
    int tempoDial = 32;
    float cutoffFrequencyFilterKnob = 750.f;
    float volumeKnob = 96.f;

    // NESTED UDT
    struct SavePattern
    {
        int numberOfSteps = 16;
        int tempoNumberSelected = 10;
        int loopCount = 4;
        bool exportingToExternalDisk = false;
        float randomisationAmount = 4.f;

        void savingSequence(int stepSize, int numberOfStepsEnabled, int numberOfLoops, int tempo);

        bool savingToExternal(int stepCount, std::string fileType = "TB303.p"); // NOTE: function checks whether external device is selected for export.

        void displaySavingProgress(int timeRemaining, float savingRate);
    };

    SavePattern save;

// 3 things it can do:
//     1) program sequence of notes.
    void programSequence(RolandTB303 sequence);

//     2) apply filtering.
    void filterSignal(float cutoffFrequency);

//     3) increase || decrease playback tempo.
    float tempoAdjust(RolandTB303 tempo); // NOTE: returns value relating to amount of temp adjustment.
};


/*
Thing 4) Dictaphone
5 properties:
    1) record button (int)
    2) play button (int)
    3) adjust microphone sensitivity (double)
    4) display storage amount (std::string)
    5) data output port (float)
3 things it can do:
    1) export audio files.
    2) record audio files.
    3) display recording space available.
*/
struct Dictaphone
{
// 5 properties:
    int recordButton = 3;
    int playButton = 2;
    double adjustMicrophoneSensitivity = 10000.0;
    std::string displayStorageAmount = " 900MBs";
    float dataOutputPort = 76.f;

// 3 things it can do:
//     1) export audio files.
    void exportAudioFile(float audioData);
//     2) record audio files.
    void recordingOn(bool activeRecording);
//     3) display recording space available.
    std::string displayAvailableSpace(Dictaphone dictaphoneStorage);
};


/*
Thing 5) Screen
5 properties:
    1) number of pixels (int)
    2) refresh rate (int)
    3) colour space (std::string)
    4) aspect ratio (int)
    5) resolution (int)
3 things it can do:
    1) increase brightness
    2) change contrast
    3) switch aspect ratio
*/
struct Screen
{
// 5 properties:
    int numberOfPixels = 500;
    int refreshRate = 144;
    std::string colourSpace = "RGB";
    int aspectRatio = 16 * 9;
    int resolution = 1080;

// 3 things it can do:
//     1) increase brightness
    void brightnessUp(int currentBrightnessLevel);

//     2) change contrast
    void adjustContrast(Screen screenContrast);

//     3) switch aspect ratio
    int screenRatioSwitch(Screen screenRatio); // NOTE: return value provides back the current state of the switch.
};


/*
Thing 6) CPU
5 properties:
    1) Processor clock speed (int)
    2) Memory management amount (int)
    3) Cache size (int)
    4) RAM size (int)
    5) Architecture type (std::string)
3 things it can do:
    1) Save data
    2) Process data
    3) Access data
*/
struct CPU
{
// 5 properties:
    int processorClockSpeed = 3500;
    int memoryManagementAmount = 480;
    int cacheSize = 200;
    int ramSize = 16;
    std::string architectureType = "x86_64";

// 3 things it can do:
//     1) Save data
    int saveSelectedData(int selectedData); // NOTE: returns a flag to indicate save was successful.

//     2) Process data
    void interpolateData(CPU cpuDataStream);

//     3) Access data
    void openDataFile(std::string fileName);
};


/*
Thing 7) GPU
5 properties:
    1) Clock speed (int)
    2) Memory bus size (int)
    3) Processor speed (int)
    4) Number of input/output streams (int)
    5) Fan speed (float)
3 things it can do:
    1) Increase ventilation amount
    2) Render graphics
    3) Overlock processing speed
*/
struct GPU
{
// 5 properties:
    int clockSpeed = 2400;
    int memoryBusSize = 1400;
    int processorSpeed = 320;
    int numberOfInputOutputStreams = 6;
    int fanSpeed = 12.f;

// 3 things it can do:
//     1) Increase ventilation amount
    void fansOn(GPU gpuFans);

//     2) Render graphics
    void graphicsRendering(GPU gpu);

//     3) Overlock processing speed
    float processorOverlocking(int currentProcessorSpeed, int inputClockSpeed, GPU gpu); // NOTE: returns overlocking amount as a value.
};


/*
Thing 8) Memory
5 properties:
    1) capacity size (int)
    2) storage type (std::string)
    3) data rate (float)
    4) seek time (double)
    5) RAM type (std::string)
3 things it can do:
    1) write data
    2) read data
    3) erase data
*/
struct Memory
{
// 5 properties:
    int capacitySize = 256;
    std::string storageType = "SSD";
    float dataRate = 18.5f;
    double seekTime = 46.889;
    std::string ramType = "DRAM";

// 3 things it can do:
//     1) write data
    int writeDataToMemory(Memory memoryDataSource); // NOTE: returns a value to signify successful writing to memory.

//     2) read data
    void openDataLocation(Memory memoryaddress);

//     3) erase data
    void deleteData(std::string selectedData);
};


/*
Thing 9) USB port
5 properties:
    1) data transfer speed (float)
    2) number of ports (int)
    3) connector type (std::string)
    4) power output (int)
    5) backward compatibility (std::string)
3 things it can do:
    1) connect external devices
    2) transfer files
    3) charge devices
*/
struct UsbPort
{
// 5 properties:
    float dataTransferSpeed = 16.8f;
    int numberOfPorts = 4;
    std::string connectorType = "USB-C";
    int powerOutput = 20;
    std::string backwardCompatibility = "USB 3.0 and USB 2.0 compatible";

// 3 things it can do:
//     1) connect external devices
    int connectingDevice(UsbPort usbInput); // NOTE: returns a value indicating successful or failed connection.

//     2) transfer files
    void fileTransferring(std::string fileToSend);

//     3) charge devices
    bool chargingConnectedDevice(UsbPort usbConnected); // NOTE: returns a bool value to cause system to display positive LED charging light.
};


/*
Thing 10) Gaming Laptop
5 properties:
    1) screen.
    2) CPU.
    3) GPU.
    4) Memory.
    5) USB port.
3 things it can do:
    1) Load a game.
    2) Connect peripherals.
    3) Display image.
*/
struct GamingLaptop
{
// 5 properties:
    Screen screen;
    CPU cpu;
    GPU gpu;
    Memory memory;
    UsbPort usbport;

// 3 things it can do:
//     1) Load a game.
    void loadingGame(std::string gameApplicationToOpen);

//     2) Connect peripherals.
    int connectingDevice(std::string deviceName); // NOTE: returns a value to signify successful or failed connections.

//     3) Display image.
    void displayingToScreen(GamingLaptop gamingLaptopDisplay);
};


int main()
{
    std::cout << "good to go!" << std::endl;
}
