# CS 225 Final Project: OpenFlights
## Team Members: akansal3-amehta58-jsh7-anikaas2
## Deliverables **(also located in the main branch)**
* Final Report
* Final Presentation Slides
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
## Test Description
