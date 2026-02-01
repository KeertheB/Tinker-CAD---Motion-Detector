# Tinker-CAD--Simulations
So satisfying to watch the logic come alive in Tinkercad—every wire, gate, and component snapping into place. There  is this quiet excitement when the simulation runs and you can see the idea actually work, not just imagine it.

This Tinkercad model simulates using electronic components and logical control.

**Object Detection with LED & Buzzer**
Detects nearby object movement on simulation and provides an audible and visual alert when an object is within range.
An ultrasonic sensor measures distance; when an object is detected within 100 cm, the LED turns ON and the buzzer beeps using Arduino control.

**Buzzer Operation Based on Distance**
Produces different buzzer tones depending on how close an object is.
An ultrasonic sensor continuously measures distance and varies the buzzer frequency (tone) proportionally using Arduino.

**Dual-Axis Solar Tracker with LCD Display**
Automatically tracks the brightest light source and displays system status in real time.
Four LDR sensors detect light intensity to control two servo motors for dual-axis movement, while a 16×2 I2C LCD displays light direction and servo angles using Arduino.

**Traffic Light Generation**
Simulates a traffic signal system with realistic light sequencing.
An Arduino controls a 12-pixel NeoPixel LED ring to generate red, yellow, and green traffic light patterns.

**Keypad Lock System**
Provides secure access using a password-based locking mechanism.
An Arduino interfaces with a 4×4 keypad (password: 1234, C-clear, D-enter), micro servo for locking, and a 16×2 I2C LCD (PCF8574, address 0x27) for user feedback.

**Fire Alarm System Using Temperature and Gas Sensors**
Detects fire hazards by monitoring heat and smoke levels.
An Arduino uses a temperature sensor to activate an LED for high heat and a gas sensor to trigger a piezo buzzer when smoke concentration increases.

**Light Intensity Measurement Using LDR**
Measures ambient light levels and responds accordingly.
An LDR sensor connected to an Arduino senses light intensity changes and processes the data for monitoring or control.

**Motion Sensor (PIR)**
Detects object motion and controls lighting automatically.
A PIR sensor connected to an Arduino turns an LED ON when motion is detected and OFF when no movement is present.

