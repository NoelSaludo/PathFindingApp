#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include "graph.h"
#include "DFS.h"
#include "BFS.h"

using namespace std;

void displayAllMazes(const vector<string>& );
int getUserChoice(const string& , int );
Graph loadMaze(const string& );

int main() {
    // List of maze files in the resources folder
    vector<string> mazeFiles = {"resources/maze1.txt", "resources/maze2.txt", "resources/maze3.txt", "resources/maze4.txt"};
    vector<Graph> mazes; 

    // Load each maze from file
    for (const auto& file : mazeFiles) {
        Graph maze(file);
        mazes.push_back(maze);
    }

    // Display loaded mazes
    displayAllMazes(mazeFiles);

    // Get user choice for the maze and algorithm
    int mazeChoice = getUserChoice("Choose a maze (1-4): ", mazes.size());
    mazeChoice--;  // Adjust for 0-based indexing

    int algorithmChoice = getUserChoice("Choose an algorithm:\n1. Depth-First Search (DFS)\n2. Breadth-First Search (BFS)\n Enter choice: ", 2);

    // Perform the chosen algorithm on the selected maze
    if (algorithmChoice == 1) {
    Graph selectedMaze = mazes[mazeChoice];
    cout << "Start: " << selectedMaze.Start << endl;
    cout << "End: " << selectedMaze.End << endl;

    vector<string> path = DepthFirstSearch(selectedMaze); // Assuming DepthFirstSearch returns a vector<string>
    cout << "Path found by DFS:" << endl;
    for (const auto& step : path) {
        cout << step << " ";
    }
    cout << endl;
    } 
    
    else if (algorithmChoice == 2) {
    Graph selectedMaze = mazes[mazeChoice];
    cout << "Start: " << selectedMaze.Start << endl;
    cout << "End: " << selectedMaze.End << endl;

    BFS(selectedMaze); // Assuming BFS returns a vector<string>
    // cout << "Path found by BFS:" << endl;
    // for (const auto& step : path) {
    //     cout << step << " ";
    // }
    cout << endl;
    } 
    else {
    cout << "Invalid choice!" << endl;
    }
}

// Display all available mazes
void displayAllMazes(const vector<string>& mazeFiles) {
    cout << "Loaded Mazes:" << endl;
    for (size_t i = 0; i < mazeFiles.size(); ++i) {
        cout << i + 1 << ". " << mazeFiles[i] << endl;
    }
    cout << endl;
}

// Get a valid user choice within the specified range
int getUserChoice(const string& prompt, int maxChoice) {
    int choice;
    while (true) {
        cout << prompt;
        cin >> choice;
        if (choice >= 1 && choice <= maxChoice) {
            break;
        } else {
            cout << "Invalid choice. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return choice;
}

// Load a maze from a file
Graph loadMaze(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening maze data file: " << filename << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    string mazeData;
    while (getline(file, line)) {
        mazeData += line + "\n";
    }
    file.close();

    Graph maze(mazeData); // Create a Graph object with the maze data
    return maze;
}
