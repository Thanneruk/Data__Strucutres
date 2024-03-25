/*Description : A bus reservation system is a digital platform that allows customers to purchase seats on a bus for their trip.
Passengers can use the system to view available seats, select their favourite seats, give personal information, and make 
booking payments.The technology also allows bus operators to monitor seat availability, track bookings, and provide
analytical results.

Context : In a bus reservation system, efficiently managing seat availability and booking information is critical for
offering passengers with a seamless booking experience while also optimising bus operations for operators.Linked lists
provide significant advantages in this scenario because of their dynamic nature and efficient memory utilisation.
Using linked lists to represent bus seats and reservations allows the system to adapt dynamic changes in seat availability
and bookings, guaranteeing smooth operation and efficient resource utilisation.

Utilisation:-

Dynamic seat arrangement:-Linked lists are ideal for dynamically controlling seat availability on buses.
Each seat on the bus can be represented as a node in a linked list, with each node having seat number, 
passenger information(if occupied), and a pointer to the next seat.This linked list structure facilitates 
the insertion and removal of seats, as well as quick traversal to check seat availability and update booking status.

Efficient Booking Operations : The reservation system uses linked lists to efficiently manage bus seat bookings.
The technology scans the linked list for available seats, allowing passengers to choose their favourite seats 
depending on availability.

Dynamic Updates and Modifications : Linked lists allow for dynamically updating and altering seat reservations.
If a passenger cancels or changes their seat selection, the system can quickly locate the associated seat node 
in the connected list and update its state.Bus operators can also change seat arrangements, such as adding or 
deleting seats, by altering the linked list structure as necessary.

Memory Efficiency : Linked lists optimise memory utilisation, particularly in situations with fluctuating seat availability.
Unlike fixed - size arrays and matrices, linked lists allocate memory dynamically as needed, preventing memory waste.
This makes linked lists a good choice for expressing bus seats and bookings, especially in cases where the number of seats
may fluctuate across different bus routes.

Benefits :
    Flexibility : Linked lists allow you to dynamically manage seat availability and reservations, as well as easily accommodate 
    changes and alterations.
    Efficiency : Because linked lists are dynamic, they allow for more efficient memory utilisation and seat management, 
    which improves system performance and responsiveness.
    Scalability : Because linked lists can scale to handle variable seat availability and booking volumes, they are ideal 
    for bus reservation systems that serve a variety of routes and passengers.*/

#include <iostream>
#include <string>
using namespace std;

// Node definition for the linked list
struct Seat {
    int seatNumber;
    string passengerName;
    bool isOccupied;
    Seat* next;

    Seat(int seatNum) : seatNumber(seatNum), passengerName(""), isOccupied(false), next(nullptr) {}
};

// Function to add a new seat to the linked list
Seat* addSeat(Seat* head, int seatNum) {
    Seat* newSeat = new Seat(seatNum);
    if (head == nullptr) {
        head = newSeat;
    }
    else {
        Seat* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newSeat;
    }
    return head;
}

// Function to display the bus seat reservation status
void displaySeats(Seat* head) {
    cout << "Seat Reservation Status:" << endl;
    Seat* temp = head;
    while (temp != nullptr) {
        cout << "Seat " << temp->seatNumber << ": ";
        if (temp->isOccupied) {
            cout << "Occupied by " << temp->passengerName << endl;
        }
        else {
            cout << "Available" << endl;
        }
        temp = temp->next;
    }
}

// Function to reserve a seat in the bus
void reserveSeat(Seat* head, int seatNum, const string& passengerName) {
    Seat* temp = head;
    while (temp != nullptr) {
        if (temp->seatNumber == seatNum) {
            if (temp->isOccupied) {
                cout << "Seat " << seatNum << " is already occupied." << endl;
            }
            else {
                temp->isOccupied = true;
                temp->passengerName = passengerName;
                cout << "Seat " << seatNum << " reserved for " << passengerName << endl;
            }
            return;
        }
        temp = temp->next;
    }
    cout << "Invalid seat number. Please try again." << endl;
}

int main() {
    int numSeats;
    cout << "Enter the number of seats in the bus: ";
    cin >> numSeats;

    // Create an empty linked list of seats
    Seat* head = nullptr;

    // Add seats to the linked list
    for (int i = 1; i <= numSeats; ++i) {
        head = addSeat(head, i);
    }

    // Display the initial seat reservation status
    displaySeats(head);

    // Perform seat reservations
    int numReservations;
    cout << "Enter the number of seat reservations: ";
    cin >> numReservations;
    cin.ignore(); // Ignore newline character after reading numReservations

    for (int i = 0; i < numReservations; ++i) {
        int seatNum;
        string passengerName;
        cout << "Enter seat number and passenger name for reservation " << i + 1 << ": ";
        cin >> seatNum;
        getline(cin, passengerName);
        reserveSeat(head, seatNum, passengerName);
    }

    // Display the final seat reservation status
    displaySeats(head);

    return 0;
}
