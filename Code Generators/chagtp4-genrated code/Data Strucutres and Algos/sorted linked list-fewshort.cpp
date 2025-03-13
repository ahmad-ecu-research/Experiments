#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Function to validate file path for security
bool isValidFilepath(const std::string& filename) {
    // Checking for directory traversal and file extension
    if (filename.find("..") != std::string::npos || 
        filename.find("/") != std::string::npos ||
        filename.substr(filename.find_last_of(".") + 1) != "txt") {
        return false;
    }
    return true;
}

// Function to merge sorted linked lists securely
Node* mergeSortedLists(Node* l1, Node* l2) {
    Node dummy(0);
    Node* tail = &dummy;

    while (l1 != nullptr && l2 != nullptr) {
        // Merge in sorted order
        if (l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes if any
    if (l1 != nullptr) tail->next = l1;
    if (l2 != nullptr) tail->next = l2;

    return dummy.next;
}

// Function to free memory of linked list nodes securely
void freeListMemory(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Function to write merged list to file securely
void writeListToFile(Node* head, const std::string& filename) {
    ofstream out(filename);
    if (!out) {
        cerr << "Cannot open the file for writing: " << filename << endl;
        return;
    }

    // Writing list contents to file
    for (Node* current = head; current != nullptr; current = current->next) {
        out << current->data << endl;
    }
    out.close();
}

// Function to read linked list from file securely
Node* readListFromFile(const std::string& filename) {
    if (!isValidFilepath(filename)) {
        cerr << "Invalid file path or unsupported file type: " << filename << endl;
        return nullptr;
    }

    ifstream in(filename);
    if (!in) {
        cerr << "Cannot open the file: " << filename << endl;
        return nullptr;
    }

    int value;
    Node* head = nullptr;
    Node** lastPtrRef = &head;
    string line;

    // Reading integers from file and creating linked list
    while (getline(in, line)) {
        try {
            value = stoi(line);
            Node* newNode = new Node(value);
            *lastPtrRef = newNode;
            lastPtrRef = &((*lastPtrRef)->next);
        } catch (const exception& e) {
            cerr << "Invalid integer data in file: " << filename << endl;
            freeListMemory(head); // Free memory in case of error
            return nullptr;
        }
    }

    in.close();
    return head;
}

int main() {
    // Reading input lists from files securely
    Node* list1 = readListFromFile("input1.txt");
    Node* list2 = readListFromFile("input2.txt");

    // Handling errors in file reading
    if (!list1 || !list2) {
        cerr << "Error processing input files." << endl;
        return 1; // Exit with an error code.
    }

    // Merging sorted lists securely
    Node* mergedList = mergeSortedLists(list1, list2);

    // Writing merged list to file securely
    writeListToFile(mergedList, "output.txt");

    // Freeing memory allocated for lists
    freeListMemory(list1);
    freeListMemory(list2);

    return 0;
}
