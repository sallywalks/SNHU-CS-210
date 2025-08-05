//JoAnn Olney
//Project 1- Chada clock
//07-16-25

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

//Helper function to format number as two digits with leading 0 if needed 
string two_digit_string(unsigned int n) {
    return (n < 10) ? ("0" + to_string(n)) : to_string(n);
}

//Helper function
//Function returns a string w/ length n w/ every character being shown by character c
string n_char_string(size_t n, char c) {
    return string(n, c);
}

// Print a line of asterisks of given width
void print_asterisk_line(size_t width) {
    cout << n_char_string(width, '*') << endl;
}

//Format 24 hr time string 
//Use unsigned integers
string format_time_24(unsigned int h, unsigned int m, unsigned int s) {
    return two_digit_string(h) + ":" + two_digit_string(m) + ":" + two_digit_string(s);
}

//Format 12 hr time string
//Format to AM or PM
string format_time_12(unsigned int h, unsigned int m, unsigned int s) {
    string ampm = (h >= 12) ? " PM" : " AM";
    h = h % 12;
    if (h == 0) h = 12;
    return two_digit_string(h) + ":" + two_digit_string(m) + ":" + two_digit_string(s) + ampm;
}

//Print strings inside a a box w index and padding 
void print_formatted_strings(const vector<string>& arr, size_t width) {
    print_asterisk_line(width);
    for (size_t i = 0; i < arr.size(); ++i) {
        string line_content = to_string(i) + " - " + arr[i];
        size_t spaces_needed = (width > line_content.length() + 4) ? width - (line_content.length() + 4) : 0;
        cout << "* " << line_content << n_char_string(spaces_needed, ' ') << " *\n";
        if (i < arr.size() - 1)
            cout << '\n';
    }
    //Print output
    print_asterisk_line(width);
}

//class clock to manage the internal time
class Clock {
private:
    unsigned int hour;
    unsigned int minute;
    unsigned int second;

public:
    //Constructor that initializes clock to 00:00:00
    Clock() : hour(0), minute(0), second(0) {}

    //Increment functions
    void add_hour() {
        hour = (hour + 1) %24;
    }

    void add_minute() {
        if (++minute >= 60) {
            minute = 0;
            add_hour(); //Increment hour when mins roll over
        }
    }

    void add_second() {
        if (++second >= 60) {
            second = 0;
            add_minute(); //Increment min when secs roll over 
        }
    }

    //Set the time with validation 
    void set_time(unsigned int h, unsigned int m, unsigned int s) {
        if (h < 24 && m < 60 && s < 60) {
            hour = h;
            minute = m;
            second = s;
        } else {
            cout << "Invalid time entered. Time will be set to 00:00:00.\n";
            hour = 0;
            minute = 0;
            second = 0;
        }
    }

    //Getters 
    unsigned int get_hour() const { return hour; }
    unsigned int get_minute() const { return minute; }
    unsigned int get_second() const { return second; }
};

//Displays the format for 12 hour & 24 hour clocks
class clock_display {
public:
    static void printClocks(const Clock& c) {
        print_asterisk_line(53); //27 + space + 27 -1 = 53
        cout << "*     12-Hour Clock      *     *     24-Hour Clock      *\n";
        cout << "*      " << format_time_12(c.get_hour(), c.get_minute(), c.get_second()) << "      *     ";
        cout << "*      " << format_time_24(c.get_hour(), c.get_minute(), c.get_second()) << "         *\n";
        print_asterisk_line(53);
    }
};

//Menu class- handles the user input and actions 
class Menu {
public:
    static void display_Menu() {
        print_asterisk_line(27);
        cout << "* 1 - Add One Hour        *\n";
        cout << "* 2 - Add One Minute      *\n";
        cout << "* 3 - Add One Second      *\n";
        cout << "* 4 - Exit Program        *\n";
        print_asterisk_line(27);
    }

    static void process_user_input(Clock& clock) {
        int choice;
        const int maxChoice = 4;

        while (true) {
            clock_display::printClocks(clock);
            display_Menu();

            cout << "Enter your choice.\n";
            cin >> choice;

            //Input validation 
            if (cin.fail()) {
                //Clear the error flag
                cin.clear();
                //Ignore invalid input 
                cin.ignore(1000, '\n');
                cout << "Input invalid, please enter 1 to " << maxChoice << ".\n";
                continue;
            }

            if (choice < 1 || choice > maxChoice) {
                cout << "Input invalid, select a valid input (1 to " << maxChoice << ").\n";
                continue; //Add this so it doesnt run the switch 
            }

            switch (choice) {
                case 1:
                    clock.add_hour();
                    break;
                case 2:
                    clock.add_minute();
                    break;
                case 3:
                    clock.add_second();
                    break;
                case 4:
                    cout << "Exiting this program!\n";
                    return;
            }
        }
    }
};

//Utility to get a validated input from the user 
int get_valid_input(const string& prompt, int min, int max) {
    int val;
    cout << prompt;
    while (!(cin >> val) || val < min || val > max) {
        cout << "Input invalid, enter a number from " << min << " to " << max << ": ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    return val;
}

//Prompt the user for a starting time 
void prompt_starting_time(Clock& clock) {
    int h = get_valid_input("Enter the starting hour (0 - 23): ", 0, 23);
    int m = get_valid_input("Enter the starting minute (0 - 59): ", 0, 59);
    int s = get_valid_input("Enter the starting second (0 - 59): ", 0, 59);
    clock.set_time(h, m, s);
} 

//Main function
int main() {
    Clock clock;
    //User sets the starting time 
    prompt_starting_time(clock);
    //Interactive clock menu
    Menu::process_user_input(clock);

    //Sample messages to show how print_formatted_strings funct works
    //Prints each message with its index inside a box, box width is set to 40
    vector<string> messages = {
        "First message",
        "Second message",
        "Third message"
    };
    print_formatted_strings(messages, 40);

    return 0;
}