// Copyright 2012, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@informatik.uni-freiburg.de>.

// Disclaimer: this is a *language-unspecific* declaration. Its purpose is to
// provide suggestions on how to design / organize your code. It is up to you
// whether you follow the given advice or do it in some other way.


// An implementation of Dijkstra'a algorithm for computing shortest paths.
class DijkstrasAlgorithm {
  // PUBLIC members.

  // Create instance of this class for a given (road) graph.
  DijkstraAlgorithm(RoadNetwork graph);
  
  // Compute the shortest paths from the given source to the given target node.
  // Returns the cost of the shortest path.
	// NOTE: If called with target node -1, Dijkstra is run until all nodes
	// reachable from the source are settled.
  int computeShortestPath(int sourceNodeId, int targetNodeId);

  // Mark all nodes visited by the next call to computeShortestPath with this
  // number.
  void setVisitedNodeMark(int mark);

  // PRIVATE members.

  // Reference to graph on which this object is supposed to work. In C++ make
  // sure this is a reference or pointer.
  RoadNetwork graph;

  // Indicator which node was visited by a particular run of Dijkstra. Useful
  // for computing the connected components; see the advice given in Lecture 2.
  Array<int> visitedNodeMarks;
}
