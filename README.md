# IoT WebDev - LED Control Project

This project is an Internet of Things (IoT) web development system designed to control LEDs in different rooms via a web interface. It uses an ESP microcontroller running a web server to manage LED states, and a frontend web application to provide user control, this project is from Dea Afrizal.

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

## Communication Protocol

The ESP microcontroller runs a web server that exposes RESTful endpoints for LED control:

- `GET /leds`  
  Returns the current state of all LEDs in JSON format.

- `POST /leds/toggle`  
  Accepts a JSON payload specifying the room to toggle the LED state.  
  Example payload:  
  ```json
  {
    "room": "bedroom"
  }
  ```

- The web interface uses JavaScript to send these HTTP requests asynchronously, allowing real-time control without page reloads.

## Future Improvements

- Add fan control and other IoT device controls.
- Implement user authentication for secure access.
- Enhance UI with real-time status updates without page reloads.

## Contributing

Contributions are welcome! Please follow these guidelines:

- Fork the repository and create your branch from `main`.
- Ensure any install or build dependencies are removed before the end of the layer when doing a build.
- Update the README.md with details of changes to the interface, including new environment variables, exposed ports, useful file locations, and container parameters.
- Increase the version numbers in any example files and the README.md to the new version that this Pull Request would represent.
- You may merge the Pull Request once you have the sign-off of two other developers, or if you do not have permission to do that, you may request the second reviewer to merge it for you.

## Troubleshooting

- Ensure your ESP device is powered and connected to the network.
- Verify the WiFi credentials in the firmware are correct.
- Check that the ESP web server is running and accessible.
- Use browser developer tools to inspect network requests and responses.
- If LEDs do not respond, verify wiring and GPIO pin assignments.
- Clear browser cache if UI does not update correctly.

## Author

[Dea Afrizal](https://github.com/deaafrizal)

## License

This project is open source and free to use.
