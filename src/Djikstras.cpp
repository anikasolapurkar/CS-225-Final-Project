#include "Djikstras.h"
#include <map>
#include <climits>
#include <stack>

using namespace std; 

std::vector<int> Djikstras::finalvector(int currentVertex, std::vector<int> parents) {
   std::vector<int> final_vect;
   while(currentVertex != -1) {
      final_vect.push_back(currentVertex);
      currentVertex = parents[currentVertex];
   }
   std::reverse(final_vect.begin(), final_vect.end());
   return final_vect;
}

std::vector<int> Djikstras::dijkstra(std::vector<std::vector<int>> adjacencyMatrix, int src, int destination) {
   int vertices = adjacencyMatrix[0].size();
   vector<int> distances(vertices);
   vector<bool> added(vertices);

   for (int i = 0; i < vertices; i++) {
      distances[i] = INT_MAX;
      added[i] = false;
   }

   distances[src] = 0;
   std::vector<int> prev(vertices);
   prev[src] = -1;

   for (int i = 1; i < vertices; i++) {
      int neighbor = -1;
      int shortest = INT_MAX;
      for (int j = 0; j < vertices; j++) {
         if (!added[j] && distances[j] < shortest) {
            neighbor = j;
            shortest = distances[j];
         }
      }
      added[neighbor] = true;
      for (int j = 0; j < vertices; j++) {
         int dist = adjacencyMatrix[neighbor][j];
         if (dist > 0 && ((shortest + dist) < distances[j])) {
            prev[j] = neighbor;
            distances[j] = shortest + dist;
         }
      }
   }

   std::vector<int> final_vect;
   final_vect = finalvector(destination, prev);
   return final_vect;
}
 