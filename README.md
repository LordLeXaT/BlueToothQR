# M5Stack Atom BlueTooth QR/Barcode Reader

 Quick and dirty adaption for the M5Stack Atom QR/Barcode scanner  
 to act as a virtual keyboard  
 Based on the standard Atom QR Example (not many changes  
   
 Once a code is scanned the BlueTooth keyboard is typing what ever is scanned  
 and hits the return key afterwards  
 
## Needed libs other than M5Stack

BlueTooth Keyboard library https://github.com/T-vK/ESP32-BLE-Keyboard  
  
## Usage 

1. Change Name of Device like you need (to find it later while paring)  

2. Compile and Push to M5Stack Atom (QR Scanner can be attached later or now)  

3. Power the Device (Cable or Battery pack)  

4. Pair it with your Computer/Smartphone (no pin needed)  

5. Open an application that accepts text input via keyboard (Editor/Excel/Word or what ever)

6. Happy Scanning (Main Buttobn)  

## Known problems 

Works for my propose and after adding the 10ms delay while "typing" no errors so far  