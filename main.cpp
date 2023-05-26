/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    The constructor should be the first declaration in your UDT, before all member variables and member functions.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




struct Castle
{
    Castle();
    int numberOfGates = 8;
    std::string nameOfKing = "Edward";
    std::string nameOfQueen = "Magda";
    float amountOfTaxesCollected = 349.77f;
    bool isAtWar = false;

    struct FarmlandRevenue
    {
        FarmlandRevenue();
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
};

Castle::Castle()
{
    std::cout << "Castle being constructed!\n";  
}

Castle::FarmlandRevenue::FarmlandRevenue()
{
    std::cout << "FarmlandRevenue being constructed!\n";
}

void Castle::FarmlandRevenue::sellWheat(int wheatStockLevel, float currentMarketPrice, float amountToSell)
{
    int availableStock = wheatStockLevel - 100;
    if (availableStock < 100)
    {
        std::cout << "Stock levels too low\n";
    }
    else
    {
        std::cout << "Stock levels OK\n";
        std::cout << "Market price: " << currentMarketPrice << "\n";
        float estimatedSale = currentMarketPrice * amountToSell;
        std::cout << "Expected sale price: " << estimatedSale << "\n";
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
        std::cout << "Select area to flood" << areaToFlood << "\n";
        std::cout << "Adjust flood level" << amountOfFlooding << "\n";       
    }
    else
    {
        std::cout << "Flooding not required\n";
    }
}

float Castle::reportCollectTaxes(float collectTaxes, FarmlandRevenue farmlandIncome)
{
    float taxTotalIncome = 0.f;
    float currentlyTaxed = collectTaxes * 20;
    float produceTax = farmlandIncome.displayCurrentTurnover(45, 12, 12.f, 10.f);

    std::cout << "Reporting tax collection!\n";
    
    return taxTotalIncome = currentlyTaxed + produceTax;
}

void Castle::openCastleGates(int numberOfGatesClosed)
{
    if (numberOfGatesClosed <= 0)
    {
        std::cout << "All gates are already open.\n";
    }
    else
    {
        std::cout << "Opening " << numberOfGatesClosed << " gates...\n";
        std::cout << "Gates opened successfully!\n";
    }
}

std::string Castle::announceOrders(std::string orders)
{
    std::cout << "Here are the orders: " << orders << "\n";
    return orders;
}

struct MidiKeyboard
{
    MidiKeyboard();
    int numberOfKeys = 49;
    int numberOfKnobs = 12;
    int numberOfMPCPads = 8;
    double pitchControlRange = 200000.0;
    char modeSelection = 'X';

    double adjustPitch(MidiKeyboard pitchChange);
    void isKeyPressed();
    float padHitAmount(MidiKeyboard padNumber);
};

MidiKeyboard::MidiKeyboard()
{
    std::cout << "MidiKeyboard being constructed!\n";  
}

double MidiKeyboard::adjustPitch(MidiKeyboard pitchChange)
{    
    double adjustedPitch = pitchControlRange + pitchChange.pitchControlRange;

    std::cout << "Pitch adjusting!\n";

    return adjustedPitch;
}

void MidiKeyboard::isKeyPressed()
{
    std::cout << "Key input detected\n";
}

float MidiKeyboard::padHitAmount(MidiKeyboard padNumber)
{
    std::cout << padNumber.numberOfMPCPads;
    std::cout << "BOY you hitting that pad haaaaard\n";
    return 10.f;
}

struct RolandTB303
{
    RolandTB303();
    int stepSequencer = 16;
    int modeDial = 10;
    int tempoDial = 32;
    float cutoffFrequencyFilterKnob = 750.f;
    float volumeKnob = 96.f;

    struct SavePattern
    {
        SavePattern();
        int numberOfSteps = 16;
        int tempoNumberSelected = 10;
        int loopCount = 4;
        bool exportingToExternalDisk = false;
        float randomisationAmount = 4.f;

        void savingSequence(int stepSize, int numberOfStepsEnabled, int numberOfLoops, int tempo);
        bool savingToExternal(int stepCount, std::string fileType = "TB303.p");
        void displaySavingProgress(int timeRemaining, float savingRate);
    };

    void programSequence(RolandTB303 sequence);
    void filterSignal(float cutoffFrequency);
    float tempoAdjust(RolandTB303 tempo);
};

RolandTB303::RolandTB303()
{
    std::cout << "RolandTB303 being constructed!\n";  
}

RolandTB303::SavePattern::SavePattern()
{
    std::cout << "SavePattern being constructed!\n";
}

void RolandTB303::SavePattern::savingSequence(int stepSize, int numberOfStepsEnabled, int numberOfLoops, int tempo)
{
    int savedSeq = stepSize + numberOfStepsEnabled + numberOfLoops + tempo;
    std::cout << "Saving sequence...\n" << savedSeq;
}

bool RolandTB303::SavePattern::savingToExternal(int stepCount, std::string fileType)
{
    if(stepCount > 0)
    {
        std::cout << "Exporting " << fileType;
        return true;
    }
    std::cout << "Export error, no steps";
    return false;
}

void RolandTB303::SavePattern::displaySavingProgress(int timeRemaining, float savingRate)
{
    std::cout << "Time remaining: " << timeRemaining << "\n";
    std::cout << "saving data speed: " << savingRate;
}

void RolandTB303::programSequence(RolandTB303 sequence)
{
    int displaySequenceCount = sequence.stepSequencer;
    std::cout << "Number of steps: " << displaySequenceCount;
}

void RolandTB303::filterSignal(float cutoffFrequency)
{
    std::cout << "Filter CutOff: " << cutoffFrequency;
}

float RolandTB303::tempoAdjust(RolandTB303 tempo)
{    
    if (tempo.tempoDial > 0)
    {
        std::cout << "Tempo has been changed\n";
        return 15.f;
    }
    std::cout << "No tempo changes here...\n";
    return 1.f;
}

struct Dictaphone
{
    Dictaphone();
    int recordButton = 3;
    int playButton = 2;
    double adjustMicrophoneSensitivity = 10000.0;
    std::string displayStorageAmount = " 900MBs";
    float dataOutputPort = 76.f;

    void exportAudioFile(float audioData);
    void recordingOn(bool activeRecording);
    std::string displayAvailableSpace(Dictaphone dictaphoneStorage);
};

Dictaphone::Dictaphone()
    {
      std::cout << "Dictaphone being constructed!\n";  
    }

void Dictaphone::exportAudioFile(float audioData)
{
    if(audioData != 0.f)
    {
        std::cout << "Exporting file...";
    }
    else
    {
        std::cout << "Error! No data to export...";
    }
}

void Dictaphone::recordingOn(bool activeRecording)
{
    if(activeRecording)
    {
        int led = 1;
        std::cout << "led on: " << led << "\n";
    }
    else
    {
        int led = 0;
        std::cout << "led off: " << led << "\n";
    }
}

std::string Dictaphone::displayAvailableSpace(Dictaphone dictaphoneStorage)
{
    std::string spaceAvail = dictaphoneStorage.displayStorageAmount;
    std::cout << "Memory space available: " << spaceAvail << "\n";
    return spaceAvail;
}

struct Screen
{
    Screen();
    int numberOfPixels = 500;
    int refreshRate = 144;
    std::string colourSpace = "RGB";
    int aspectRatio = 16 * 9;
    int resolution = 1080;

    void brightnessUp(int currentBrightnessLevel);
    void adjustContrast(Screen screenContrast);
    int screenRatioSwitch(Screen screenRatio);
};

Screen::Screen()
{
    std::cout << "Screen being constructed!\n";  
}

void Screen::brightnessUp(int currentBrightnessLevel)
{
    int turnUpBrightness = currentBrightnessLevel * 2;
    std::cout << "Brightness increased to: " << turnUpBrightness;
}

void Screen::adjustContrast(Screen screenContrast)
{
    int changeContrast = screenContrast.numberOfPixels * screenContrast.resolution * screenContrast.aspectRatio;
    std::cout << "Contrast increased to: " << changeContrast;
}

int Screen::screenRatioSwitch(Screen screenRatio)
{
    std::cout << "Ratio changing, hold tight\n";
    return screenRatio.aspectRatio * screenRatio.resolution;
}

struct CPU
{
    CPU();
    int processorClockSpeed = 3500;
    int memoryManagementAmount = 480;
    int cacheSize = 200;
    int ramSize = 16;
    std::string architectureType = "x86_64";

    int saveSelectedData(int selectedData);
    void interpolateData(CPU cpuDataStream);
    void openDataFile(std::string fileName);
};

CPU::CPU()
{
    std::cout << "CPU being constructed!\n";  
}

int CPU::saveSelectedData(int selectedData)
{
    int savedCode = memoryManagementAmount - selectedData;
    std::cout << "Saving: " << savedCode << "\n";
    return savedCode;
}

void CPU::interpolateData(CPU cpuDataStream)
{
    std::string fileForInterpolation = "file1";
    cpuDataStream.openDataFile(fileForInterpolation);
    std::cout << "current cache: " << cpuDataStream.cacheSize;
}

void CPU::openDataFile(std::string fileName)
{
    std::cout << "Select file for opening...\n";
    std::cout << "File selected: " << fileName;
}

struct GPU
{
    GPU();
    int clockSpeed = 2400;
    int memoryBusSize = 1400;
    int processorSpeed = 320;
    int numberOfInputOutputStreams = 6;
    int fanSpeed = 12;

    void fansOn(GPU gpuFans);
    void graphicsRendering(GPU gpu);
    float processorOverlocking(int currentProcessorSpeed, int inputClockSpeed, GPU gpu);
};

GPU::GPU()
{
    std::cout << "GPU being constructed!\n"; 
}

void GPU::fansOn(GPU gpuFans)
{
    if(gpuFans.fanSpeed < 0)
    {
        std::cout << "Fans enabled";
    }
    else
    {
        std::cout << "Fans active";
    }
}

void GPU::graphicsRendering(GPU gpu)
{
    while(gpu.processorSpeed > 120)
    {
        // render graphics
        std::cout << "Shaders loading... not long now\n";
    }
}

float GPU::processorOverlocking(int currentProcessorSpeed, int inputClockSpeed, GPU gpu)
{
    if(gpu.clockSpeed <= 2400)
    {
        int adjustClock = currentProcessorSpeed + inputClockSpeed;
        std::cout << "Increased clock speed by " << adjustClock;
        return 3400.f;
    }
    std::cout << "Error";
    return 2400.f;
}

struct Memory
{
    Memory();
    int capacitySize = 256;
    std::string storageType = "SSD";
    float dataRate = 18.5f;
    double seekTime = 46.889;
    std::string ramType = "DRAM";

    int writeDataToMemory(Memory memoryDataSource);
    void openDataLocation(Memory memoryaddress);
    void deleteData(std::string selectedData);
};

Memory::Memory()
{
    std::cout << "Memory being constructed!\n";
}

int Memory::writeDataToMemory(Memory memoryDataSource)
{
    capacitySize = memoryDataSource.capacitySize;
    storageType = memoryDataSource.storageType;
    dataRate = memoryDataSource.dataRate;
    seekTime = memoryDataSource.seekTime;
    ramType = memoryDataSource.ramType;

    std::cout << "Listing data details: " << capacitySize << "\n" << storageType << "\n" << dataRate << "\n" << seekTime << "\n" << ramType << "\n";
    return 0;
}

void Memory::openDataLocation(Memory memoryAddress)
{
    std::cout << "Opening data location: " << memoryAddress.capacitySize << std::endl;
}

void Memory::deleteData(std::string selectedData)
{
    std::cout << "Deleted data: " << selectedData << std::endl;
}

struct UsbPort
{
    UsbPort();
    float dataTransferSpeed = 16.8f;
    int numberOfPorts = 4;
    std::string connectorType = "USB-C";
    int powerOutput = 20;
    std::string backwardCompatibility = "USB 3.0 and USB 2.0 compatible";

    int connectingDevice(UsbPort usbInput);
    void fileTransferring(std::string fileToSend);
    bool chargingConnectedDevice(UsbPort usbConnected);
};

UsbPort::UsbPort()
{
    std::cout << "UsbPort being constructed!\n";
}

int UsbPort::connectingDevice(UsbPort usbInput)
{
    if (usbInput.connectorType == connectorType)
    {
        std::cout << "USB device successfully connected." << std::endl;
        return 0;
    }
    std::cout << "Incompatible connector types. Failed to connect USB device." << std::endl;
    return 1;
}

void UsbPort::fileTransferring(std::string fileToSend)
{
    std::cout << "File being transfered: " << fileToSend;
    if(powerOutput < 10)
    {
        std::cout << "Error, underpowered port for transfer";
    }
}

bool UsbPort::chargingConnectedDevice(UsbPort usbConnected)
{
    if(usbConnected.backwardCompatibility == "USB 3.0 and USB 2.0 compatible")
    {
        std::cout << "Congrats! This USB is still relevant\n";
        return true;
    }
    std::cout << "We are sorry to say, your stick is old\n";
    return false;
}

struct GamingLaptop
{
    GamingLaptop();
    Screen screen;
    CPU cpu;
    GPU gpu;
    Memory memory;
    UsbPort usbport;

    void loadingGame(std::string gameApplicationToOpen);
    int connectingDevice(std::string deviceName);
    void displayingToScreen(GamingLaptop gamingLaptopDisplay);
};

GamingLaptop::GamingLaptop()
{
    std::cout << "GamingLaptop being constructed!\n";
}

void GamingLaptop::loadingGame(std::string gameApplicationToOpen)
{
    std::cout << "Select application";
    cpu.openDataFile(gameApplicationToOpen);
    memory.openDataLocation(memory);
    cpu.openDataFile("fileName");
    gpu.graphicsRendering(gpu);
    screen.screenRatioSwitch(screen);
}

int GamingLaptop::connectingDevice(std::string deviceName)
{
    usbport.connectorType = deviceName;
    bool isCharging = usbport.chargingConnectedDevice(usbport);
    int memoryAmount = cpu.memoryManagementAmount;
    
    if(isCharging && memoryAmount > 0)
    {
        std::cout << "Charging in progress\n";
        return 0;
    }
    std::cout << "Error with charging, please check connection\n";
    return 1;
}

void GamingLaptop::displayingToScreen(GamingLaptop gamingLaptopDisplay)
{
    std::cout << "Displaying gaming laptop information:" << "\n";
    std::cout << "Screen resolution: " << gamingLaptopDisplay.screen.resolution << "\n";
    std::cout << "CPU clock speed: " << gamingLaptopDisplay.cpu.processorClockSpeed << "\n";
    std::cout << "GPU memory: " << gamingLaptopDisplay.gpu.memoryBusSize << "\n";
}

int main()
{
    Example::main();
    Castle castle;
    Castle::FarmlandRevenue farmlandrev;
    MidiKeyboard midikeyboard;
    RolandTB303 rolandtb303;
    RolandTB303::SavePattern savepattern;
    Dictaphone dictaphone;
    Screen screen;
    GPU gpu;
    CPU cpu;
    Memory memory;
    UsbPort usbport;
    GamingLaptop gaminglaptop;

    
    
                  
    std::cout << "good to go!" << std::endl;
}
