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

struct Person
{
    int age = 0;
    int heightInches = 0;
    float hairLength = 0.f;
    float GPA = 0.f;
    unsigned int SATScore = 0;
    int distanceTraveled = 0;
    
    void run(int howFast, bool startWithLeftFoot);

    struct Foot
    {
        int stepSize() { return 0; }
        void stepForward(int speed) 
        {
            int distance = speed * 2;
            std::cout << "Foot stepped forward by distance: " << distance << std::endl;
        }
    };
    Foot leftFoot, rightFoot;
};

void Person::run(int howFast, bool startWithLeftFoot)
{
    if (startWithLeftFoot)
    {
        leftFoot.stepForward(howFast);
        rightFoot.stepForward(howFast);
    }
    else
    {
        rightFoot.stepForward(howFast);
        leftFoot.stepForward(howFast);
    }
    
    distanceTraveled += leftFoot.stepSize() + rightFoot.stepSize();
}

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

struct Castle
{
    int numberOfGates = 8;
    std::string nameOfKing = "Edward";
    std::string nameOfQueen = "Magda";
    float amountOfTaxesCollected = 349.77f;
    bool isAtWar = false;

    struct FarmlandRevenue
    {
        int arces = 65;
        int numberOfWorkers = 120;
        float wheatSalePricePerKG = 1.8f;
        std::string type = "Cereals and Grains";
        bool isInDrought = false;

        void sellWheat(int wheatStockLevel, float currentMarketPrice, float amountToSell);
        float displayCurrentTurnover(int totalWorkers, int farmlandArea, float currentMarketPrice, float previousMarketPrice);
        void floodFarmlands(int areaToFlood, float amountOfFlooding, bool isIndrought);
    };

    float reportCollectTaxes(float collectTaxes, FarmlandRevenue farmlandIncome);
    void openCastleGates(int numberOfGatesClosed);
    std::string announceOrders(std::string orders);

    FarmlandRevenue agricultureWorth;
};

void Castle::FarmlandRevenue::sellWheat(int wheatStockLevel, float currentMarketPrice, float amountToSell)
{
    int availableStock = wheatStockLevel - 100;
    if (availableStock < 100)
    {
        std::cout << "Stock levels too low/n";
    }
    else
    {
        std::cout << "Stock levels OK/n";
        std::cout << "Market price: " << currentMarketPrice << "/n";
        float estimatedSale = currentMarketPrice * amountToSell;
        std::cout << "Expected sale price: " << estimatedSale << "/n";
    }
}

float Castle::FarmlandRevenue::displayCurrentTurnover(int totalWorkers, int farmlandArea, float currentMarketPrice, float previousMarketPrice)
{
    int workForceOverArea = totalWorkers + farmlandArea / 2;
    std::cout << "Workforce turnover per acre: " << workForceOverArea << std::endl;
    float marketEstimation = currentMarketPrice - previousMarketPrice * 0.2f;
            
    return marketEstimation;
}

void Castle::FarmlandRevenue::floodFarmlands(int areaToFlood, float amountOfFlooding, bool isIndrought)
{
    if(isIndrought)
    {
        std::cout << "Select area to flood" << areaToFlood << "/n";
        std::cout << "Adjust flood level" << amountOfFlooding << "/n";       
    }
    else
    {
        std::cout << "Flooding not required/n";
    }
}

float Castle::reportCollectTaxes(float collectTaxes, FarmlandRevenue farmlandIncome)
{
    float taxTotalIncome = 0.f;
    float currentlyTaxed = collectTaxes * 20;
    float produceTax = farmlandIncome.displayCurrentTurnover(45, 12, 12.f, 10.f);
    
    return taxTotalIncome = currentlyTaxed + produceTax;
}

void Castle::openCastleGates(int numberOfGatesClosed)
{
    if (numberOfGatesClosed <= 0)
    {
        std::cout << "All gates are already open./n";
    }
    else
    {
        std::cout << "Opening " << numberOfGatesClosed << " gates.../n";
        std::cout << "Gates opened successfully!/n";
    }
}

std::string Castle::announceOrders(std::string orders)
{
    std::cout << "Here are the orders: " << orders << "/n";
    return orders;
}

struct MidiKeyboard
{
    int numberOfKeys = 49;
    int numberOfKnobs = 12;
    int numberOfMPCPads = 8;
    double pitchControlRange = 200000.0;
    char modeSelection = 'X';

    double adjustPitch(MidiKeyboard pitchChange);
    void isKeyPressed();
    float padHitAmount(MidiKeyboard padNumber);
};

double MidiKeyboard::adjustPitch(MidiKeyboard pitchChange)
{    
    double adjustedPitch = pitchControlRange + pitchChange.pitchControlRange;

    return adjustedPitch;
}

void MidiKeyboard::isKeyPressed()
{
    std::cout << "Key input detected/n";
}

float MidiKeyboard::padHitAmount(MidiKeyboard padNumber)
{
    std::cout << padNumber.numberOfMPCPads;
    return 10.f;
}

struct RolandTB303
{
    int stepSequencer = 16;
    int modeDial = 10;
    int tempoDial = 32;
    float cutoffFrequencyFilterKnob = 750.f;
    float volumeKnob = 96.f;

    struct SavePattern
    {
        int numberOfSteps = 16;
        int tempoNumberSelected = 10;
        int loopCount = 4;
        bool exportingToExternalDisk = false;
        float randomisationAmount = 4.f;

        void savingSequence(int stepSize, int numberOfStepsEnabled, int numberOfLoops, int tempo);
        bool savingToExternal(int stepCount, std::string fileType = "TB303.p");
        void displaySavingProgress(int timeRemaining, float savingRate);
    };

    SavePattern save;

    void programSequence(RolandTB303 sequence);
    void filterSignal(float cutoffFrequency);
    float tempoAdjust(RolandTB303 tempo);
};

struct Dictaphone
{
    int recordButton = 3;
    int playButton = 2;
    double adjustMicrophoneSensitivity = 10000.0;
    std::string displayStorageAmount = " 900MBs";
    float dataOutputPort = 76.f;

    void exportAudioFile(float audioData);
    void recordingOn(bool activeRecording);
    std::string displayAvailableSpace(Dictaphone dictaphoneStorage);
};

struct Screen
{
    int numberOfPixels = 500;
    int refreshRate = 144;
    std::string colourSpace = "RGB";
    int aspectRatio = 16 * 9;
    int resolution = 1080;

    void brightnessUp(int currentBrightnessLevel);
    void adjustContrast(Screen screenContrast);
    int screenRatioSwitch(Screen screenRatio);
};

struct CPU
{
    int processorClockSpeed = 3500;
    int memoryManagementAmount = 480;
    int cacheSize = 200;
    int ramSize = 16;
    std::string architectureType = "x86_64";

    int saveSelectedData(int selectedData);
    void interpolateData(CPU cpuDataStream);
    void openDataFile(std::string fileName);
};

struct GPU
{
    int clockSpeed = 2400;
    int memoryBusSize = 1400;
    int processorSpeed = 320;
    int numberOfInputOutputStreams = 6;
    int fanSpeed = 12.f;

    void fansOn(GPU gpuFans);
    void graphicsRendering(GPU gpu);
    float processorOverlocking(int currentProcessorSpeed, int inputClockSpeed, GPU gpu);
};

struct Memory
{
    int capacitySize = 256;
    std::string storageType = "SSD";
    float dataRate = 18.5f;
    double seekTime = 46.889;
    std::string ramType = "DRAM";

    int writeDataToMemory(Memory memoryDataSource);
    void openDataLocation(Memory memoryaddress);
    void deleteData(std::string selectedData);
};

struct UsbPort
{
    float dataTransferSpeed = 16.8f;
    int numberOfPorts = 4;
    std::string connectorType = "USB-C";
    int powerOutput = 20;
    std::string backwardCompatibility = "USB 3.0 and USB 2.0 compatible";

    int connectingDevice(UsbPort usbInput);
    void fileTransferring(std::string fileToSend);
    bool chargingConnectedDevice(UsbPort usbConnected);
};

struct GamingLaptop
{
    Screen screen;
    CPU cpu;
    GPU gpu;
    Memory memory;
    UsbPort usbport;

    void loadingGame(std::string gameApplicationToOpen);
    int connectingDevice(std::string deviceName);
    void displayingToScreen(GamingLaptop gamingLaptopDisplay);
};

int main()
{
    std::cout << "good to go!" << std::endl;
}
