#include <iostream>
#include <vector>   // For dynamic arrays
#include <algorithm> // For utility functions like swap
#include <chrono>   // For adding delays
#include <thread>   // For creating delays

using namespace std;

// Function to maintain the Max-Heap property by "heapifying up" the element at index `i`.
void heapifyMax(vector<int>& heap, int i) {
    int parent = (i - 1) / 2; // Calculate the parent index
    // If the current element is greater than its parent, swap them
    if (parent >= 0 && heap[i] > heap[parent]) {
        swap(heap[i], heap[parent]);
        heapifyMax(heap, parent); // Recursively adjust the parent node
    }
}

// Function to maintain the Min-Heap property by "heapifying up" the element at index `i`.
void heapifyMin(vector<int>& heap, int i) {
    int parent = (i - 1) / 2; // Calculate the parent index
    // If the current element is smaller than its parent, swap them
    if (parent >= 0 && heap[i] < heap[parent]) {
        swap(heap[i], heap[parent]);
        heapifyMin(heap, parent); // Recursively adjust the parent node
    }
}

// Function to add a new treasure to both the Max-Heap and Min-Heap
void addTreasure(vector<int>& maxHeap, vector<int>& minHeap, int treasure) {
    cout << "\nAdding treasure with value " << treasure << "...\n";

    // Add the treasure to the Max-Heap and adjust it
    maxHeap.push_back(treasure);
    heapifyMax(maxHeap, maxHeap.size() - 1);

    // Add the treasure to the Min-Heap and adjust it
    minHeap.push_back(treasure);
    heapifyMin(minHeap, minHeap.size() - 1);

    // Display the current state of both heaps
    cout << "Current Max-Heap: ";
    for (int t : maxHeap) cout << t << " ";
    cout << endl;

    cout << "Current Min-Heap: ";
    for (int t : minHeap) cout << t << " ";
    cout << endl;
}

int main() {
    vector<int> maxHeap, minHeap; // Initialize empty heaps
    int choice, treasure;

    cout << "Welcome to the Treasure Hunter's Heap Game!\n";
    while (true) {
        // Display menu options
        cout << "\nChoose an action:\n";
        cout << "1. Add a treasure\n";
        cout << "2. Show the most valuable treasure (Max-Heap)\n";
        cout << "3. Show the least valuable treasure (Min-Heap)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Handle user input based on the chosen menu option
        switch (choice) {
        case 1:
            cout << "Enter the treasure value: ";
            cin >> treasure; // Input the value of the treasure
            addTreasure(maxHeap, minHeap, treasure); // Add to heaps
            break;
        case 2:
            // Display the most valuable treasure from the Max-Heap
            if (maxHeap.empty()) {
                cout << "The heap is empty! No treasures to show.\n";
            } else {
                cout << "The most valuable treasure is: " << maxHeap[0] << endl;
            }
            break;
        case 3:
            // Display the least valuable treasure from the Min-Heap
            if (minHeap.empty()) {
                cout << "The heap is empty! No treasures to show.\n";
            } else {
                cout << "The least valuable treasure is: " << minHeap[0] << endl;
            }
            break;
        case 4:
            // Exit the game
            cout << "Thanks for playing the Treasure Hunter's Heap Game! Goodbye!\n";
            return 0;
        default:
            // Handle invalid inputs
            cout << "Invalid choice. Please try again.\n";
        }

        // Add a delay before showing the menu again
        this_thread::sleep_for(chrono::seconds(2));
    }
}
