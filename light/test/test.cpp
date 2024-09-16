#include <iostream>
#include <string>

using namespace std;

int main() {
    string hexCode;

    cout << "Enter the hexadecimal color code (e.g., #FF00FF): ";
    cin >> hexCode;

    // Remove the '#' symbol if present
    if (hexCode.length() > 0 && hexCode[0] == '#') {
        hexCode = hexCode.substr(1);
    }

    // Ensure the hex code is 6 characters long
    if (hexCode.length() != 6) {
        cout << "Invalid hexadecimal color code. Please enter a 6-character code." << endl;
        return 1;
    }

    // Extract RGB values from the hex code
    int red = 0, green = 0, blue = 0;

    for (int i = 0; i < 6; i += 2) {
        char highNibble = hexCode[i];
        char lowNibble = hexCode[i + 1];

        // Convert hexadecimal characters to decimal values
        int value = (highNibble >= 'A' ? highNibble - 'A' + 10 : highNibble - '0') * 16 +
                   (lowNibble >= 'A' ? lowNibble - 'A' + 10 : lowNibble - '0');

        // Assign the value to the corresponding RGB component
        if (i == 0) {
            red = value;
        } else if (i == 2) {
            green = value;
        } else {
            blue = value;
        }
    }

    // Print the RGB values
    cout << "RGB values:" << endl;
    cout << "Red: " << red << endl;
    cout << "Green: " << green << endl;
    cout << "Blue: " << blue << endl;

    return 0;
}