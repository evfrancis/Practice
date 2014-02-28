#ifndef _GRAPHNODE_H__
#define _GRAPHNODE_H__

#include <vector>
#include <iostream> //needed for cout
#include <algorithm>

class GraphNode
{
private:
    std::vector<GraphNode *> inputs;
    std::vector<GraphNode *> outputs;
public:
    /**
     * Constructor that creates a node with no connections
     */
    GraphNode();

    /**
     * Destructor that clears the node and all connections it has
     */
    ~GraphNode();

    /**
     * This will create a 2-way connection to both nodes
     * Returns true if successful or false if there is a problem
     * Using references to make this easy on the user
     * References allow us to pass the object itself in as opposed to a
     * copy, it behaves like a pointer but with nicer notation
     * eg. A.add2wayconnection(B) = A <-> B
     */
    bool add2wayConnection(GraphNode &otherNode);

    /**
     * This will remove a 2-way connection to both nodes
     * It will attempt to see if the connection exists first
     * Returns true if successful or false if there is a problem
     * eg. A <-> B, A.remove2wayConnection(B) = A  B
     */
    bool remove2wayConnection(GraphNode &otherNode);

    /**
     * Remove output connection from this node to the specifed node
     * This involves removing the output from this node to the
     * specified node and removing the input of this node in the
     * specified node vector list
     * eg. A <-> B, A.removeOutputConnection(B) = A <- B
     */
    bool removeOutputConnection(GraphNode &otherNode);

    /**
     * Remove input connection from this node to the specified node
     * This involves removing the output to this node from the other node
     * and removing the input of the other node to this node
     * eg. A <-> B, A.removeInputConnection(B) = A -> B
     */
    bool removeInputConnection(GraphNode &otherNode);
    
    /**
     * Add an input connection to this node from the specified node (otherNode)
     * This involves adding the othernode to the input vector list and adding this
     * node to the other node's output vector list
     * eg. A B, a.addInputConnection(b),  A <- B
     */
    bool addInputConnection(GraphNode &otherNode);

    /**
     * Add an output connection from this node to the specified node (otherNode)
     * This involves adding the otherNode to this node's output vector list and
     * adding this node to the other node's input list
     * eg. A B, a.addOutputConnection(b),  A -> B
     */
    bool addOutputConnection(GraphNode &otherNode);
    
     /**
      * TEST FUNCTION
      * This will print all input and output connections to the node
      * utilizing memory addresses to do so
      */
    void printConnections(void);
};

#endif // _GRAPHNODE_H__

