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

std::vector<int> Djikstras::dijkstra(std::vector<std::vector<int>> adjacencyMatrix, int startVertex, int destination) {
   int verticesNum = adjacencyMatrix[0].size();
   vector<int> shortestDistances(verticesNum);
   vector<bool> added(verticesNum);
   for (int vertexIndex = 0; vertexIndex < verticesNum; vertexIndex++) {
      shortestDistances[vertexIndex] = INT_MAX;
      added[vertexIndex] = false;
   }
   shortestDistances[startVertex] = 0;
   vector<int> prev(verticesNum);
   prev[startVertex] = -1;
   for (int i = 1; i < verticesNum; i++) {
      int nearestVertex = -1;
      int shortestDistance = INT_MAX;
      for (int vertexIndex = 0; vertexIndex < verticesNum; vertexIndex++) {
         if (!added[vertexIndex] && shortestDistances[vertexIndex] < shortestDistance) {
            nearestVertex = vertexIndex;
            shortestDistance = shortestDistances[vertexIndex];
         }
      }
      added[nearestVertex] = true;
      for (int vertexIndex = 0; vertexIndex < verticesNum; vertexIndex++) {
         int edgeDistance = adjacencyMatrix[nearestVertex][vertexIndex];
         if (edgeDistance > 0 && ((shortestDistance + edgeDistance) < shortestDistances[vertexIndex])) {
            prev[vertexIndex] = nearestVertex;
            shortestDistances[vertexIndex] = shortestDistance + edgeDistance;
         }
      }
   }
   std::vector<int> final_vect;
   final_vect = finalvector(destination, prev);
   return final_vect;
}
 