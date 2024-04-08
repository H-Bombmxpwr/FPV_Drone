### Setting up the development environment

1. Ensure you have Python installed on your machine, version 3.9.6 or higher.

2. Clone the repository:
   ```
   git clone https://github.com/H-Bombmxpwr/FPV_Drone.git
   ```

3. Navigate to the project directory:
   ```
   cd FPV_Drone
   ```

4. Create a Python virtual environment:
   ```
   python3 -m venv .venv
   ```

5. Activate the virtual environment:
   On macOS and Linux:
   ```
   source .venv/bin/activate
   ```
   On Windows:
   ```
   .\.venv\Scripts\activate
   ```

6. Install the required dependencies:
   ```
   pip install -r requirements.txt
   ```

7. Controlling the Crazyflie: The next steps for setting up control for the crazyflie are [here](crazyflie_control/setup.md). Note: This currently only is supported for mac.