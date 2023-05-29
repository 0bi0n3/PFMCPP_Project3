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
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.

 5) Remember to use pre-increment/decrement in your loops. 
 You can learn why post-increment/decrement is not ideal here:
 https://en.cppreference.com/w/cpp/language/operator_incdec 
 
 6) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
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
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            ++bar.num;                    //2a), 5)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()





struct Castle
{
    int numberOfGates;
    std::string nameOfKing;
    std::string nameOfQueen;
    float amountOfTaxesCollected;
    bool isAtWar;

    Castle();

    struct FarmlandRevenue
    {
        int arces {65}, numberOfWorkers {120};
        float wheatSalePricePerKG {1.8f};
        std::string type {"Cereals and Grains"};
        bool isInDrought {false};

        FarmlandRevenue();

        void sellWheat(int wheatStockLevel, float currentMarketPrice, float amountToSell);
        float displayCurrentTurnover(int totalWorkers, int farmlandArea, float currentMarketPrice, float previousMarketPrice);
        void floodFarmlands(int areaToFlood, float amountOfFlooding, bool isIndrought);
        
// new function
        void hireNewWorkers();
    };

    float reportCollectTaxes(float collectTaxes, FarmlandRevenue farmlandIncome);
    void openCastleGates(int numberOfGatesClosed);
    std::string announceOrders(std::string orders);
    
// new function
    void fireSignalArrow();
};

void Castle::FarmlandRevenue::hireNewWorkers()
{
    
}

void Castle::fireSignalArrow()
{
    
}

Castle::Castle() : numberOfGates(8), nameOfKing("Edward"), nameOfQueen("Magda"), amountOfTaxesCollected(300.f), isAtWar(true)
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
        std::cout << "Select area to flood " << areaToFlood << "\n";
        std::cout << "Adjust flood level " << amountOfFlooding << "\n";       
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

    std::cout << "Reporting tax collection my lord!\n";
    
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
    int numberOfKeys, numberOfKnobs, numberOfMPCPads;
    double pitchControlRange;
    char modeSelection;

    MidiKeyboard();

    double adjustPitch(MidiKeyboard pitchChange);
    void isKeyPressed();
    float padHitAmount(MidiKeyboard padNumber);

    // new function
    void ledLightDemoMode();
};

void MidiKeyboard::ledLightDemoMode()
{
    
}

MidiKeyboard::MidiKeyboard() : numberOfKeys(25), numberOfKnobs(16), numberOfMPCPads(4), pitchControlRange(300000.0), modeSelection('Y')
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
    std::cout << "Pad number: " <<padNumber.numberOfMPCPads << "\n";
    std::cout << "BOY you hitting that pad haaaaard!!!\n";
    return 10.f;
}

struct RolandTB303
{
    int stepSequencer {16}, modeDial {10}, tempoDial {32};
    float cutoffFrequencyFilterKnob {750.f}, volumeKnob {-18.f};

    RolandTB303();

    struct SavePattern
    {
        int numberOfSteps, tempoNumberSelected, loopCount;
        bool exportingToExternalDisk;
        float randomisationAmount;

        SavePattern();

        void savingSequence(int stepSize, int numberOfStepsEnabled, int numberOfLoops, int tempo);
        bool savingToExternal(int stepCount, std::string fileType = "TB303.p");
        void displaySavingProgress(int timeRemaining, float savingRate);

        // new function
        void recallPattern();
    };

    void programSequence(RolandTB303 sequence);
    void filterSignal(float cutoffFrequency);
    float tempoAdjust(RolandTB303 tempo);

    // new function
    void syncMidi();
};

void RolandTB303::SavePattern::recallPattern()
{
    
}

void RolandTB303::syncMidi()
{
    
}

RolandTB303::RolandTB303()
{
    std::cout << "RolandTB303 being constructed!\n";  
}

RolandTB303::SavePattern::SavePattern() : numberOfSteps(24), tempoNumberSelected(12), loopCount(8), exportingToExternalDisk(true), randomisationAmount(8.5f)
{
    std::cout << "SavePattern being constructed!\n";
}

void RolandTB303::SavePattern::savingSequence(int stepSize, int numberOfStepsEnabled, int numberOfLoops, int tempo)
{
    int savedSeq = stepSize + numberOfStepsEnabled + numberOfLoops + tempo;
    std::cout << "Saving sequence..." << savedSeq << "\n";
}

bool RolandTB303::SavePattern::savingToExternal(int stepCount, std::string fileType)
{
    if(stepCount > 0)
    {
        std::cout << "Exporting " << fileType << "\n";
        return true;
    }
    std::cout << "Export error, no steps" << "\n";
    return false;
}

void RolandTB303::SavePattern::displaySavingProgress(int timeRemaining, float savingRate)
{
    std::cout << "Time remaining: " << timeRemaining << " (secs)\n";
    std::cout << "saving data speed: " << savingRate << " kbps\n";
}

void RolandTB303::programSequence(RolandTB303 sequence)
{
    int displaySequenceCount = sequence.stepSequencer;
    std::cout << "Number of steps: " << displaySequenceCount << "\n";
}

void RolandTB303::filterSignal(float cutoffFrequency)
{
    std::cout << "Filter CutOff: " << cutoffFrequency << "Hz\n";
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
    int recordButton {3}, playButton {2};
    double adjustMicrophoneSensitivity {10000.0};
    std::string displayStorageAmount {"900MBs"};
    float dataOutputPort {76.f};

    Dictaphone();

    void exportAudioFile(float audioData);
    void recordingOn(bool activeRecording);
    std::string displayAvailableSpace(Dictaphone dictaphoneStorage);

    // new function
    int flagNumberOfSpeakers();
};

int Dictaphone::flagNumberOfSpeakers()
{

    return 1;
}


Dictaphone::Dictaphone()
    {
      std::cout << "Dictaphone being constructed!\n";  
    }

void Dictaphone::exportAudioFile(float audioData)
{
    if(audioData != 0.f)
    {
        std::cout << "Exporting file...\n";
    }
    else
    {
        std::cout << "Error! No data to export...\n";
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
    int numberOfPixels, refreshRate, aspectRatio, resolution;
    std::string colourSpace = "RGB";
  
    Screen();

    void brightnessUp(int currentBrightnessLevel);
    void adjustContrast(Screen screenContrast);
    int screenRatioSwitch(Screen screenRatio);

    // new function
    std::string displaySource();
};

std::string Screen::displaySource()
{

    return "string";
}

Screen::Screen() : numberOfPixels(4000), refreshRate(60), aspectRatio(10*5), resolution(4000), colourSpace("V:RGBY")
{
    std::cout << "Screen being constructed!\n";  
}

void Screen::brightnessUp(int currentBrightnessLevel)
{
    int turnUpBrightness = currentBrightnessLevel * 2;
    std::cout << "Brightness increased to: " << turnUpBrightness << "\n";
}

void Screen::adjustContrast(Screen screenContrast)
{
    int changeContrast = screenContrast.numberOfPixels * screenContrast.resolution * screenContrast.aspectRatio;
    std::cout << "Contrast increased to: " << changeContrast << "\n";
}

int Screen::screenRatioSwitch(Screen screenRatio)
{
    std::cout << "Ratio changing, hold tight\n";
    return screenRatio.aspectRatio * screenRatio.resolution;
}

struct CPU
{
    int processorClockSpeed {3500}, memoryManagementAmount {480}, cacheSize {200}, ramSize {16};
    std::string architectureType {"x86_64"};

    CPU();

    int saveSelectedData(int selectedData);
    void interpolateData(CPU cpuDataStream);
    void openDataFile(std::string fileName);

    // new function
    void increaseRAMAllocation();
};

void CPU::increaseRAMAllocation()
{
    
}

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
    std::cout << "current cache: " << cpuDataStream.cacheSize << "\n";
}

void CPU::openDataFile(std::string fileName)
{
    std::cout << "Select file for opening...\n";
    std::cout << "File selected: " << fileName << "\n";
}

struct GPU
{
    int clockSpeed, memoryBusSize, processorSpeed, numberOfInputOutputStreams, fanSpeed;

    GPU();

    void fansOn(GPU gpuFans);
    void graphicsRendering(GPU gpu);
    float processorOverlocking(int currentProcessorSpeed, int inputClockSpeed, GPU gpu);

    // new function
    void decreaseRenderingRate();
};

void GPU::decreaseRenderingRate()
{
    
}

GPU::GPU() : clockSpeed(4800), memoryBusSize(1200), processorSpeed(135), numberOfInputOutputStreams(12), fanSpeed(36)
{
    std::cout << "GPU being constructed!\n"; 
}

void GPU::fansOn(GPU gpuFans)
{
    if(gpuFans.fanSpeed < 0)
    {
        std::cout << "Fans enabled" << "\n";
    }
    else
    {
        std::cout << "Fans active" << "\n";
    }
}

void GPU::graphicsRendering(GPU gpu)
{
    if (gpu.processorSpeed > 120)
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
        std::cout << "Increased clock speed by " << adjustClock << "\n";
        return 3400.f;
    }
    std::cout << "Error" << "\n";
    return 2400.f;
}

struct Memory
{
    int capacitySize {256};
    std::string storageType {"SSD"};
    float dataRate {18.5f};
    double seekTime {46.889};
    std::string ramType {"DRAM"};

    Memory();

    int writeDataToMemory(Memory memoryDataSource);
    void openDataLocation(Memory memoryaddress);
    void deleteData(std::string selectedData);

    // new function
    int allocateBufferMemory();
};

int Memory::allocateBufferMemory()
{

    return 0;
}

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
    float dataTransferSpeed;
    int numberOfPorts;
    std::string connectorType;
    int powerOutput;
    std::string backwardCompatibility;

    UsbPort();

    int connectingDevice(UsbPort usbInput);
    void fileTransferring(std::string fileToSend);
    bool chargingConnectedDevice(UsbPort usbConnected);

    void flashConnectionLight();
};

void UsbPort::flashConnectionLight()
{
    
}

UsbPort::UsbPort() : dataTransferSpeed(20.9f), numberOfPorts(8), connectorType("USB-B"), powerOutput(10), backwardCompatibility("USB 2.5 ONLY")
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
    std::cout << "File being transfered: " << fileToSend << "\n";
    if(powerOutput < 10)
    {
        std::cout << "Error, underpowered port for transfer" << "\n";
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
    Screen screen;
    CPU cpu;
    GPU gpu;
    Memory memory;
    UsbPort usbport;

    GamingLaptop();

    void loadingGame(std::string gameApplicationToOpen);
    int connectingDevice(std::string deviceName);
    void displayingToScreen(GamingLaptop gamingLaptopDisplay);

    // new function
    void connectToMultiplayer();
};

void GamingLaptop::connectToMultiplayer()
{
    
}

GamingLaptop::GamingLaptop()
{
    std::cout << "GamingLaptop being constructed!\n";
}

void GamingLaptop::loadingGame(std::string gameApplicationToOpen)
{
    std::cout << "Select application" << "\n";
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

    //-------------------
    Castle castle;
    //1
    castle.announceOrders("Release the hounds!");
    std::cout << "names of royalty: " << castle.nameOfKing << " & " << castle.nameOfQueen << "\n";

    //2
    castle.openCastleGates(4);
    std::cout << "total gates at castle: " << castle.numberOfGates << "\n";

    //3
    castle.reportCollectTaxes(10.f, Castle::FarmlandRevenue());
    std::cout << "tax collected: " << castle.amountOfTaxesCollected << "\n";
        
    //-------------------
    Castle::FarmlandRevenue farmlandrev;

    //1
    farmlandrev.displayCurrentTurnover(30, 66, 12.f, 8.f);
    std::cout << "Current wholesale price of wheat per kg: " << farmlandrev.wheatSalePricePerKG << "\n";
    //2
    farmlandrev.floodFarmlands(150, 23.f, true);
    std::cout << "Is the farmland in drought? 0 = no, 1 = yes: " << farmlandrev.isInDrought << "\n";
    //3
    farmlandrev.sellWheat(500, 21.f, 180.f);
    std::cout << "Current number of able workers: " << farmlandrev.numberOfWorkers << "\n";

    //-------------------
    MidiKeyboard midikeyboard;

    //1
    midikeyboard.adjustPitch(MidiKeyboard());
    std::cout << "List number of keys: " << midikeyboard.numberOfKeys << "\n";
    //2
    midikeyboard.isKeyPressed();
    std::cout << "Available pitch control range: " << midikeyboard.pitchControlRange << "\n";
    //3
    midikeyboard.padHitAmount(MidiKeyboard());
    std::cout << "Programmable pads: " << midikeyboard.numberOfMPCPads << "\n";
    
    //-------------------
    RolandTB303 rolandtb303;

    //1
    rolandtb303.filterSignal(3500.f);
    std::cout << "Volume level: " << rolandtb303.volumeKnob << "\n";

    //2
    rolandtb303.programSequence(RolandTB303());
    
    //3
    rolandtb303.tempoAdjust(RolandTB303());
    
    //-------------------
    RolandTB303::SavePattern savepattern;

    //1
    savepattern.displaySavingProgress(35, 50.f);

    //2
    savepattern.savingSequence(4, 8, 2, 120);
    
    //3
    savepattern.savingToExternal(8, "TB303.p");

    //-------------------
    Dictaphone dictaphone;

    //1
    dictaphone.recordingOn(true);
    dictaphone.recordingOn(false);
    
    //2
    dictaphone.displayAvailableSpace(Dictaphone());
    
    //3
    dictaphone.exportAudioFile(256.f);
    dictaphone.exportAudioFile(0.f);

    //-------------------
    Screen screen;

    //1
    screen.adjustContrast(Screen());

    //2
    screen.brightnessUp(15);

    //3
    int screenRatioResult = screen.screenRatioSwitch(Screen());
    std::cout << "Screen switch complete, total pixels used: " << screenRatioResult << "\n";

    //-------------------
    GPU gpu;

    //1
    gpu.fansOn(GPU());
    
    //2
    gpu.graphicsRendering(GPU());
    
    //3
    float currentProcessorSpeed = gpu.processorOverlocking(20, 288, GPU());
    std::cout << "Current processor speed: " << currentProcessorSpeed << "Hz\n";
    
    //-------------------
    CPU cpu;

    //1
    cpu.interpolateData(CPU());

    //2
    cpu.openDataFile("Hello Musician Programmer");

    //3
    cpu.saveSelectedData(28);
    
    //-------------------
    Memory memory;

    //1
    memory.deleteData("Don't delete me! *screams as the digital entity is destroyed*");

    //2
    memory.openDataLocation(Memory());

    //3
    int memoryResult = memory.writeDataToMemory(Memory());
    std::cout << "Memory written total: " << memoryResult << "\n";
    
    //-------------------
    UsbPort usbport;

    //1
    usbport.chargingConnectedDevice(UsbPort());

    //2
    bool usbResult = usbport.connectingDevice(UsbPort());
    std::cout << "USB connecting device secure (0 = yes, 1 = no): " << usbResult << "\n";
    
    //3
    usbport.fileTransferring("Send me to the moon plz");

    //-------------------
    GamingLaptop gaminglaptop;

    //1
    gaminglaptop.connectingDevice("War Gaming Stick of All Destruction!");

    //2
    gaminglaptop.displayingToScreen(GamingLaptop());

    //3
    gaminglaptop.loadingGame("Quake 3");
    
   
    

    std::cout << "good to go!" << std::endl;
}
