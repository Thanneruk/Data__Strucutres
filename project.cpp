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

class EventScheduler {
private:
    priority_queue<Event, vector<Event>, CompareEvents> eventsQueue;
    map<string, Event> eventsMap; // Map to store events by unique identifier (e.g., event name)

public:
    // Method to add a new event
    void addEvent(const string& name, const string& startTime, const string& endTime,
        const string& location, const string& description) {
        if (hasConflict(startTime, endTime)) {
            cout << "Scheduling conflict detected! Please choose a different time slot." << endl;
            return;
        }
        eventsMap.emplace(name, Event(name, startTime, endTime, location, description));
        eventsQueue.push(eventsMap[name]);
    }

    // Method to check for scheduling conflicts
    bool hasConflict(const string& startTime, const string& endTime) {
        // Check if the proposed time slot overlaps with any existing event
        for (const auto& event : eventsMap) {
            if ((startTime >= event.second.startTime && startTime < event.second.endTime) ||
                (endTime > event.second.startTime && endTime <= event.second.endTime)) {
                return true; // Conflict detected
            }
        }
        return false; // No conflict
    }

    // Method to display upcoming events
    void displayUpcomingEvents() {
        cout << "Upcoming Events:" << endl;
        while (!eventsQueue.empty()) {
            const Event& event = eventsQueue.top();
            cout << "Name: " << event.name << ", Time: " << event.startTime << " - " << event.endTime << endl;
            eventsQueue.pop();
        }
    }
};

int main() {
    // Create an instance of EventScheduler
    EventScheduler scheduler;

    // Add some sample events
    scheduler.addEvent("Meeting", "2024-03-15 09:00", "2024-03-15 10:00", "Conference Room", "Discuss project status");
    scheduler.addEvent("Lunch", "2024-03-15 12:00", "2024-03-15 13:00", "Cafeteria", "Team lunch");
    scheduler.addEvent("Presentation", "2024-03-15 14:00", "2024-03-15 15:30", "Auditorium", "Project demo");

    // Check for scheduling conflicts before adding an event
    scheduler.addEvent("Workshop", "2024-03-15 09:30", "2024-03-15 11:30", "Training Room", "Training session");

    // Display upcoming events
    scheduler.displayUpcomingEvents();

    return 0;
}