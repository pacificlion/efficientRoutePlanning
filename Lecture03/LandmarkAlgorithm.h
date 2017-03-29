// Copyright 2012, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@informatik.uni-freiburg.de>.

// Disclaimer: this is a *language-unspecific* declaration. Its purpose is to
// provide suggestions on how to design / organize your code. It is up to you
// whether you follow the given advice or do it in some other way.


// An implementation of A* with the landmarks heuristic, as explained in
// Lecture 3 of the course Efficient Route Planning, SS 2012.
class LandmarkAlgorithm {
  // PUBLIC members.

  // Create instance of this class for a given (road) graph.
  LandmarkAlgorithm(RoadNetwork graph);

  // Select the given number of landmarks at random.
  void selectLandmarks(int numLandmarks);

  // Precompute the distances to and from the selected landmarks.
  // NOTE: For our undirected / symmetric graphs, the distances *from* the
  // landmarks are enough, see Array<Array<int>> landmarkDistances below.
  void precomputeLandmarkDistances();
  
  // Compute the shortest paths from the given source to the given target node,
  // using A* with the landmark heuristic.
  // NOTE: this algorithm only works in point-to-point mode, so the option
  // targetNodeId == -1 does not make sense here.
  int computeShortestPath(int sourceNodeId, int targetNodeId);

  // PRIVATE members.

  // Reference to graph on which this object is supposed to work. In C++ make
  // sure this is a reference or pointer.
  RoadNetwork graph;

  // Object for executing Dijkstra's algorithm on this road network. In C++ make
  // sure this is a reference or pointer.
  DijkstrasAlgorithm dijkstra;

  // The set of landmarks. Each entry in the array is a node id.
  Array<int> landmarks;

  // Precomputed distances (shorted path costs in seconds) to and from these
  // landmarks. This is one array of size #nodes per landmark.
  // NOTE: since our graphs are undirected (or rather, for each arc u,v we also
  // have an arc v,u with the same cost) we have dist(u, l) = dist(l, u) and it
  // suffices to store one distance array per landmark. For arbitrary directed
  // graphs we would need one array for the distances *to* the landmark and one
  // array for the distances *from* the landmark.
  Array<Array<int>> landmarkDistances;
}
