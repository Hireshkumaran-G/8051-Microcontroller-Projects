# BUZZER MELODY (8051 Microcontroller)

## 📜 Description
Generates simple beeps or melodies using a piezo buzzer connected to the 8051 microcontroller.

## 📂 Files
- `Buzzer_Melody.c` — C source code
- `Buzzer_Melody.hex` — Compiled HEX file
- `Buzzer_Melody.pdsprj` — Proteus design file

## 🖼 Output
![BUZZER MELODY Output](buzzer_melody_output.png)

## 🛠 Requirements
- Keil uVision
- Proteus Design Suite
- AT89C51/AT89S52 Microcontroller

## 🔹 Procedure
1. Open `Buzzer_Melody.c` in **Keil uVision**.
2. Compile the code (`F7` or Build option) to generate the `.hex` file.
3. Open `Switch_Debounce.pdsprj` in **Proteus**.
4. Double-click on the microcontroller component in Proteus and load the generated `.hex` file.
5. Run the simulation to see the LED blinking.