#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

// Define structure for events
struct Event {
    string name;
    string startTime;
    string endTime;
    string location;
    string description;

    // Default constructor
    Event() : name(""), startTime(""), endTime(""), location(""), description("") {}

    // Parameterized constructor
    Event(const string& n, const string& start, const string& end, const string& loc, const string& desc)
        : name(n), startTime(start), endTime(end), location(loc), description(desc) {}
};

// Comparator for priority queue based on event start time
struct CompareEvents {
    bool operator()(const Event& e1, const Event& e2) const {
        return e1.startTime > e2.startTime; // Events with earlier start time have higher priority
    }
};