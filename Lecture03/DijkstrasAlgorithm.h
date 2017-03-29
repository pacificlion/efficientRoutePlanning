// Copyright 2012, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@informatik.uni-freiburg.de>.

// Disclaimer: this is a *language-unspecific* declaration. Its purpose is to
// provide suggestions on how to design / organize your code. It is up to you
// whether you follow the given advice or do it in some other way.


// An implementation of Dijkstra'a algorithm for computing shortest paths. Can
// also be run in A* mode, with an arbitrary heuristic function, see below.
class DijkstrasAlgorithm {
  // PUBLIC members.

  // Create instance of this class for a given (road) graph.
  DijkstraAlgorithm(RoadNetwork graph);
  
  // Compute the shortest paths from the given source to the given target node.
  // Returns the cost of the shortest path.
  // NOTE 1: If called with target node -1, Dijkstra is run until all nodes
  // reachable from the source are settled.
  // NOTE 2: If member variable heuristic is not null, simply add h(u) to the
  // value of node u in the priority queue.
  int computeShortestPath(int sourceNodeId, int targetNodeId);

  // Mark all nodes visited by the next call to computeShortestPath with this
  // number.
  void setVisitedNodeMark(int mark);

  // Set heuristic function to given array. In C++ make sure that you do not
  // copy the array but just set a pointer to it, see member variable heuristic
  // below.
  void setHeuristic(Array<int> heuristic);

  // PRIVATE members.

  // Reference to graph on which this object is supposed to work. In C++ make
  // sure this is a reference or pointer.
  RoadNetwork graph;

  // Indicator which node was visited by a particular run of Dijkstra. Useful
  // for computing the connected components; see the advice given in Lecture 2.
  Array<int> visitedNodeMarks;

  // Heuristic function if running in A* mode. In C++ make this a pointer, there
  // is no need to copy this into the object, a reference is good enough.
  Array<int> heuristic;
}
