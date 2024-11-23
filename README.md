# DSA---HEAP-ACTIVITY


#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono> // For delay
#include <thread> // For delay

using namespace std;

// Function to heapify up for Max-Heap
void heapifyMax(vector<int>& heap, int i) {
    int parent = (i - 1) / 2;
    if (parent >= 0 && heap[i] > heap[parent]) {
        swap(heap[i], heap[parent]);
        heapifyMax(heap, parent); // Recursively heapify the parent
    }
}

// Function to heapify up for Min-Heap
void heapifyMin(vector<int>& heap, int i) {
    int parent = (i - 1) / 2;
    if (parent >= 0 && heap[i] < heap[parent]) {
        swap(heap[i], heap[parent]);
        heapifyMin(heap, parent); // Recursively heapify the parent
    }
}

// Function to add a treasure to both heaps
void addTreasure(vector<int>& maxHeap, vector<int>& minHeap, int treasure) {
    cout << "\nAdding treasure with value " << treasure << "...\n";

    // Add to Max-Heap
    maxHeap.push_back(treasure);
    heapifyMax(maxHeap, maxHeap.size() - 1);

    // Add to Min-Heap
    minHeap.push_back(treasure);
    heapifyMin(minHeap, minHeap.size() - 1);

    // Display both heaps
    cout << "Current Max-Heap: ";
    for (int t : maxHeap) cout << t << " ";
    cout << endl;

    cout << "Current Min-Heap: ";
    for (int t : minHeap) cout << t << " ";
    cout << endl;
}

int main() {
    vector<int> maxHeap, minHeap;
    int choice, treasure;

    cout << "Welcome to the Treasure Hunter's Heap Game!\n";
    while (true) {
        cout << "\nChoose an action:\n" << endl;
        cout << "1. Add a treasure\n";
        cout << "2. Show the most valuable treasure (Max-Heap)\n";
        cout << "3. Show the least valuable treasure (Min-Heap)\n";
        cout << "4. Exit\n" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the treasure value: ";
            cin >> treasure;
            addTreasure(maxHeap, minHeap, treasure);
            break;
        case 2:
            if (maxHeap.empty()) {
                cout << "The heap is empty! No treasures to show.\n";
            } else {
                cout << "The most valuable treasure is: " << maxHeap[0] << endl;
            }
            break;
        case 3:
            if (minHeap.empty()) {
                cout << "The heap is empty! No treasures to show.\n";
            } else {
                cout << "The least valuable treasure is: " << minHeap[0] << endl;
            }
            break;
        case 4:
            cout << "\nThanks for playing the Treasure Hunter's Heap Game! Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

        // Add a 2-second delay before showing the menu again
        this_thread::sleep_for(chrono::seconds(2));
    }
}
