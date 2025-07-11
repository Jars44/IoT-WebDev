# IoT WebDev - LED Control Project

This project is an Internet of Things (IoT) web development system designed to control LEDs in different rooms via a web interface. It uses an ESP microcontroller running a web server to manage LED states, and a frontend web application to provide user control.

## Features

- Web interface with a home page and a dedicated LED control page.
- Control LEDs in four rooms: Bedroom (Ruang Tidur), Living Room (Ruang Tamu), Dining Room (Ruang Makan), and Family Room (Ruang Keluarga).
- Real-time LED state toggling via web buttons.
- ESP microcontroller hosts a web server with endpoints to toggle and get LED states.
- Onboard ESP LED blinks to indicate device operation.
- Simple and intuitive user interface with icons and buttons.

## Setup

### Hardware and Firmware

1. Connect LEDs to the ESP microcontroller pins as follows:
   - Bedroom LED: GPIO 4
   - Living Room LED: GPIO 5
   - Dining Room LED: GPIO 19
   - Family Room LED: GPIO 22
   - Onboard ESP LED: GPIO 2 (blinks to show device is running)

2. Open the `esp/esp-coding.ino` file in the Arduino IDE.

3. Update the WiFi credentials in the sketch:
   ```cpp
   const char* ssid = "Your_SSID";
   const char* password = "Your_PASSWORD";
   ```

4. Upload the sketch to your ESP device.

### Web Interface

1. Open `index.html` in a web browser to access the home page.

2. Use the navigation or buttons to go to the LED control page (`led.html`).

3. Control the LEDs by clicking the "TURN ON" buttons for each room.

## Usage

- The LED control page displays the status of each room's LED.
- Clicking a button toggles the LED state on the ESP device via HTTP requests.
- The onboard LED on the ESP blinks every second to indicate the device is active.

## Future Improvements

- Add fan control and other IoT device controls.
- Implement user authentication for secure access.
- Enhance UI with real-time status updates without page reloads.

## License

This project is open source and free to use.
