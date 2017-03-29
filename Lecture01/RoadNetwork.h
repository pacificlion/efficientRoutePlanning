// Copyright 2012, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@informatik.uni-freiburg.de>.

// Disclaimer: this is a *language-unspecific* declaration. Its purpose is to
// provide suggestions on how to design / organize your code. It is up to you
// whether you follow the given advice or do it in some other way.


// A node with its OSM id and its latitude / longitude. This is useful for
// building the graph from an OSM file (we first read the nodes there, and later
// have to compute arc costs from the coordinates of these nodes). It is also
// useful for debugging.
class Node {
  // The OSM id of the node.
  int osmId;

  // The latitude and longitude.
  float latitude;
  float longitude;
}

// An arc, as used in the adjacency lists below. Note all arcs from a single adjacency
// list are adjacent to the same node, there it suffices to store only the id of
// the node on the other side, the so-called head node of the arc. Arc costs are
// travel times and counted in seconds, that way we can use an integer to store
// them and have no issues with rounding.
class Arc {
  // Create an Arc with the given head node and cost.
  Arc(int headNodeId, int cost)

  // The id of the head node.
  int headNodeId;

  // The cost of the arc = travel time in seconds (see class comment above).
  int cost;
}

// A road network modelled as an undirected graph. We will use "arc" and "edge",
// where "arc" is directed and "edge" is undirected. From the outside, we only
// add "edges", but internally each edge is stored as a pair of "arcs" (with the
// same pair of adjacent nodes but opposite directions).
class RoadNetwork {
  // PUBLIC members.
 
  // Create an empty network (with zero nodes and zero arcs).
  RoadNetwork();

  // The graph as human-readable string (for testing and debugging).
  string asString();

  // Add a node with the given OSM id and lat/lng coordinates.
  void addNode(int osmId, float latitude, float longitude);

  // Add an (undirected) edge between the given nodes with the given cost.
  void addEdge(int u, int v, int cost);

  // Read graph from given OSM file.
  void readFromOsmFile(string fileName);

  // PRIVATE members.
  
  // The number of nodes in the graph.
  int numNodes;

  // The number of (undirected) edges in the graph.
  int numEdges;

  // The adjacency lists. Note that each edge {u,v} is stored as two arcs: (u,v)
  // and (v,u). The total number of entries in these arrays is therefore exactly twice
  // the number of edges in the graph.
  Array<Array<Arc>> adjacentArcs;

  // The nodes of the graph.
  Array<Node> nodes;
}
