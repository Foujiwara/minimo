# [ SmartController Minimotors ]
⚠️ **Warning : this is work in progress. I decline all responsability about using informations from this project** ⚠️

![Temporary Logo](img/logo_tmp.png)

## What is SmartController ?
It's a combo of electronic and smartphone application. It extend all features from original Minimotors EYE LCD and controller.
The electronic board will interract with most of the e-scooter electronic when you plug it.
You simply place the little box inside the deck and connect it to the controller (and other electric parts if you want more features)

### Requirements
- A e-scooter with minimotors controllers (single or dual)
- A constant 12V ouput from the regulator (not only powered when brakes are pressed like some Kaabo)... OR an external DC-DC providing 12V or 5V
- If you want to use progressive brake feature, you must ensure no more than 60V pass in the brake handle (issue noted only for Kaabo)
- The electronics (ESP32 Dev KitC V4 + SmartController shield + JST SM/PH connectors)
- Some electronic skills

### What can be done ?
I suggest you to have a look at all planed features in the image below.
There is almost no limit in custom features.
The controller power cannot exceed the nominal power, but with a shunt, you can go upper and still have a current control loop to limit the current by software (and avoid burning the controller).

Most settings will be configurable by the smartphone, and additionnal hardware buttons will allow you to control specific features.

Some examples : 
- It can lock the escooter with bluetooth proximity (with a beacon, the smartphone or any bluetooth device). When locked, the power is so reduced that nobody can ride it is you aren't close enouth

- You find the acceleration trigger to agressive at low speed ? you can change the acceleration curve for smooth trigger at low speed, and still have the beast once you push the trigger harder

- You want a mode for some weather conditions like 'rainy' with less torque ? no problem. Use the customized "mode Z" in addition to mode 1/2/3 with special P7/P8/P9/PA

- You feel the electric brake too strong at full power ? the progressive electric braking adjust the brake power in real time.

### Main features
![Idea](/img/SmartController.png)

**[Check all datailed features here](FEATURES.md)**


## Case and size
Current size : 6cm x 3cm x 2cm (will shrink a little at final stage)

![Idea](/img/SmartController_3D_1.jpg)

## Electronic
### Software
The software is designed for [ESP32 Dev Kit v4](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/hw-reference/esp32/get-started-devkitc.html)

### Schematics
- [PCB schematic](https://easyeda.com/Koxx3/smartlcd-v1-4)

![PCB from easyEDA](/img/smartControlletPcb.png)

### Inspiration to understand controller electronic
- [China BLDC motor controller 36v 250W](http://avdweb.nl/Article_files/Solarbike/Motor-controller/China-BLDC-motor-controller-36V-250W.pdf)

## Applications

### Android 
- [Minimo App - Github repo](https://github.com/Koxx3/minimo_android)

### iPhone
I have no skills in iPhone apps. If anyone wants to develop, let me know 😉

## TODO

- [✅] Serial Minimotors
    - [✅] Read/write serial link LCD_TO_CNTRL
    - [✅] Read/write serial link CNTRL_TO_LCD
    - [✅] Decode speed/mode/brake/regulator from serial link
    - [✅] Frame error detection
    - [ ] Error codes processing

- [ ] Serial Kaabo / Zero / Appolo

- [✅] Bluetooth 
    - [✅] Communication with Android
    - [✅] Anti-theth with smartphone
    - [✅] Anti-theth with beacon (scan & rssi detection)
    - [✅] Lock beacon or device settings
    - [✅] SmartController connexion security (PIN code)
    - [✅] SmartController connexion with multi devices (BT device choice)

- [✅] Other inputs/outputs ↔️
    - [✅] Read current with WCS1700
    - [✅] Read battery voltage
    - [✅] Read tempertature/humidity with DHT11/DHT22
    - [✅] Read break handle position on serial
    - [✅] Read break handle position on standard brake handle
    - [✅] Read break handle position on analog brake handle
    - [✅] Read buttons
    - [✅] Send break handle position to controller
    - [✅] Send LED status
    - [✅] Send optocopler order

- [ ] Power 🔋
    - [✅] Convert 12V to 5V
    - [ ] Convert 80V to 5V

- [ ] Features ⚙️
    - [✅] Save settings in non volatile memory
    - [✅] Progressive electric braking (software detection)
    - [ ] Progressive electric braking (hardware on/off detection)
    - [✅] Progressive electric braking (hardware analog detection)
    - [✅] OTA update
    - [✅] Current measure auto calibration (at startup)
    - [✅] Current measure manual calibration
    - [✅] Speed limiter at startup
    - [✅] Configurable speed loop regulation
    - [ ] Remote physical button
        - [✅] Speed limiter ON/OFF
        - [✅] Lock ON      
        - [✅] Nitro Boost continuous
        - [✅] Nitro Boost ON/OFF
        - [✅] Aux ON/OFF       
        - [ ] Mode Z ON/OFF
    - [IN TEST 🔄] Disable electric brake with full battery
    - [IN PROGRESS 🔄] Automatic ECO mode on low battery 
    - [IN TEST 🔄] LCD Speed adjustment
    - [ ] Dynamic BLE debug infos
    - [ ] Configurable current loop regulation
    - [ ] Customize mode Z with different power / max speed
    - [ ] Calibrate analog brake
    - [ ] Wifi connexion for dashboard display and settings
    - [ ] Advanced diagnosis (serial errors, throtle errors ...)

- [ ] Android application 📱
    - [ ] Display : 
        - [✅] Speed
        - [ ] Average speed
        - [IN TEST 🔄] Distance
        - [✅] Mode
        - [✅] Voltage
        - [✅] Current
        - [✅] Power
        - [✅] Brake mode (PA)
        - [✅] Max speed
        - [✅] Max power
        - [✅] Max current
        - [✅] Temperature
        - [✅] Humidity
        - [✅] Time
        - [✅] Moving time
    - [✅] Auto-launch app with NFC tag
    - [✅] Parameters custom settings
    - [✅] Data logging
    - [✅] History graphics
    - [ ] UI configuration (hide items)
    

- [ ] iPhone application 🍏
    - [ ] A kind developper to do this part ? 😇

- [ ] Custom acceleration curve ==> not possible with current hardware

## Produce you own board
- [Here](MAKE_IT.md)

## Wiring
- [Here](WIRING.md)

## Run it !
- [Here](RUN.md)

## Resources 🔗
- [Serial links data decoding - Excel XLSX](http://github.com/Koxx3/minimo/edit/master/MINIMO.xlsx)

## Donate to support
- [If you want to support me, click here !](https://www.paypal.com/donate/?cmd=_s-xclick&hosted_button_id=W3KHBZCNL9N2C&source=url)
