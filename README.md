# CS 225 Final Project: OpenFlights
## Team Members: akansal3-amehta58-jsh7-anikaas2
## Deliverables **(also located in the main branch)**
* Final Report (https://docs.google.com/document/d/1kjOg-c4Xgn6BW5IbPelN-4nkI0Y-n2Mt81UZM1ifftc/edit?usp=sharing)
* Final Presentation Slides (https://docs.google.com/presentation/d/1lhA2Qs8EKgJKitI2g0-CC5fffh4ZFWC0PytPVK2guUw/edit?usp=sharing)
* Final Presentation Video
## Introduction 
In our project, we investigate the real-world applications of graph-data structures using the Open Flights dataset in conjunction with a path finding algorithm and a traversal. We intend to use the dataset provided to us in class (https://openflights.org/data.html). Specifically, we hope to find the shortest path between the United States and Europe, as well as the shortest path between different landmarks. We will use the nearest airport to each corresponding location and construct a route based on the shortest path using BFS traversal, Dijkstra's algorithm, and a Page Rank algorithm.
## File description(code and data)
* All classes are located in the **src folder**
* Airport Class: the Airport class is used for defining the vertices of our graph structure. Each airport is constructed with a name, latitude, and longitude coordinates. Data is retrieved from (airport.dat)
* Route Class : used to create airport graph structure
* airport_graph : Supports the creation and insertion of vertices and edges
* BFS : Implementation of a BFS graph traversal
* Djikstras : Implementation of Djikstra's algorithm to find shortest path
* PageRank : Implementation of the Page Rank algorithm
## How to run the program
Setting up a virtual Docker environment on your laptop if you do not already have one:
* Inside the final project directory, create a Dockerfile and copy paste "FROM gcevans/cs225-container:fa22
ENTRYPOINT bash" in there.
* On VSCode, use Remote-Container: Open Folder in Container to open up the project and then select "From Dockerfile".
To Run the Program:
* type 'make' in the terminal and wait for the program to compile.
* type './main' to see the results of test cases and the real world data set.
## Test Description
Our tests check for:
* Constructing the graph
* BFS -- getting to the correct target location
* BFS traversal -- moving in the correct order
* Dijkstra's algorithm
* Reading and parsing dataset
* Page Rank algorithm -- creating the adjacency matrix
* Page Rank algorithm
