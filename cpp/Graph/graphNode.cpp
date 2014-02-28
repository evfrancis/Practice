#include "graphNode.h"

GraphNode::GraphNode()
{
    //clear all input and output vectors that will store node pointers
    inputs.clear();
    outputs.clear();
}

GraphNode::~GraphNode()
{
    //Sever nodes improperly
    inputs.clear();
    outputs.clear();
}

bool GraphNode::add2wayConnection(GraphNode &otherNode)
{
    bool status = true;

    /**
     * check if the connection already exists
     * in this case inputs = outputs so it is sufficient
     * to check a single vector in order to enforce this
     */
    std::vector<GraphNode *>::iterator it;
    for (it = inputs.begin(); it != inputs.end(); ++it)
    {
        if (*it == &otherNode)
        {
            //found the node
            status = false;
            break;
        }
    }

    /**
     * if status is unchanged means that we didn't
     * find the node there, so we insert it now
     */
     if (status)
     {
         inputs.push_back(&otherNode);
         outputs.push_back(&otherNode);
         //this is a pointer to the current object
         //which makes it a GraphNode *
         otherNode.inputs.push_back(this);
         otherNode.outputs.push_back(this);
     }

    return status;
}

bool GraphNode::remove2wayConnection(GraphNode &otherNode)
{
    bool status = false;

    /**
     * check to see if the node exists in one
     * if it does then it must exist in the other
     * since this is a 2 way connection
     */
    std::vector<GraphNode *>::iterator input_it;
    std::vector<GraphNode *>::iterator output_it;
    input_it = std::find(inputs.begin(), inputs.end(), &otherNode);
    output_it = std::find(outputs.begin(), outputs.end(), &otherNode);

    if (*input_it == &otherNode && *output_it == &otherNode)
    {
        inputs.erase(input_it);
        outputs.erase(output_it);

        input_it = std::find(otherNode.inputs.begin(), otherNode.inputs.end(), this);
        output_it = std::find(otherNode.outputs.begin(), otherNode.outputs.end(), this);
        if (*input_it == this && *output_it == this)
        {
            /*
             * Make sure the nodes appear on
             * both sides and erase both sides
             * after confirming this is true
             * only then status should be set
             */
            otherNode.inputs.erase(input_it);
            otherNode.outputs.erase(output_it);

            status = true;
        }
    }
    return status;
}

void GraphNode::printConnections(void)
{
    //Print all input connections
    std::cout << "Inputs: " << std::endl;
    std::vector<GraphNode *>::iterator it;
    for (it = inputs.begin(); it != inputs.end(); ++it)
    {
        std::cout << "Node: " << *it << std::endl;
    }

    //Print all output connections
    std::cout << "Outputs: " << std::endl;
    for (it = outputs.begin(); it != outputs.end(); ++it)
    {
        std::cout << "Node: " << *it << std::endl;
    }
}

bool GraphNode::removeOutputConnection(GraphNode &otherNode)
{
    bool status = false;
    std::vector<GraphNode *>::iterator outputRemoveIt;
    std::vector<GraphNode *>::iterator inputRemoveIt;

    /*
     * Get pointer to the other node at this node's output vector
     * Get pointer to this node from other node's input vector
     */
    outputRemoveIt = std::find(outputs.begin(), outputs.end(), &otherNode);
    inputRemoveIt = std::find(otherNode.inputs.begin(), otherNode.inputs.end(), this);

    if (*outputRemoveIt == &otherNode && *inputRemoveIt == this)
    {
        outputs.erase(outputRemoveIt);  //remove the other node from this node's output list
        otherNode.inputs.erase(inputRemoveIt); //remove this node from the other node's input list
        status = true;
    }

    return status;
}

bool GraphNode::removeInputConnection(GraphNode &otherNode)
{
    bool status = false;
    std::vector<GraphNode *>::iterator outputRemoveIt;
    std::vector<GraphNode *>::iterator inputRemoveIt;

    /*
     * Get pointer to other node at this node's input vector
     * Get pointer to this node in the other node's output vector
     */
    inputRemoveIt = std::find(inputs.begin(), inputs.end(), &otherNode);
    outputRemoveIt = std::find(otherNode.outputs.begin(), otherNode.outputs.end(), this);

    if (*outputRemoveIt == this && *inputRemoveIt == &otherNode)
    {
        inputs.erase(inputRemoveIt);                //remove the other node from this node's input list
        otherNode.outputs.erase(outputRemoveIt);    //remove this node from the other node's output list
        status = true;
    }

    return status;
}

bool GraphNode::addInputConnection(GraphNode& otherNode)
{
  bool status = false;
  std::vector<GraphNode *>::iterator inputIt;
  std::vector<GraphNode *>::iterator outputIt;
  
  //look for the other node in this input vector list and look for this node in the other node's output vector list
  inputIt = std::find(inputs.begin(), inputs.end(), &otherNode);
  outputIt = std::find(otherNode.outputs.begin(), otherNode.outputs.end(), this);

  if ( (inputIt == inputs.end()) && (outputIt == otherNode.outputs.end()) )
  {
    status = true;	//connection does not exist already
    inputs.push_back(&otherNode);
    otherNode.outputs.push_back(this);
  }
  return status;
}

bool GraphNode::addOutputConnection(GraphNode& otherNode)
{
  bool status = false;
  std::vector<GraphNode *>::iterator inputIt;
  std::vector<GraphNode *>::iterator outputIt;
  
  
  //look for the other node in this output vector list
  //look for this node in the other node's input vector list
  inputIt = std::find(outputs.begin(), outputs.end(), &otherNode);
  outputIt = std::find(otherNode.inputs.begin(), otherNode.inputs.end(), this);
  
  if ( inputIt == outputs.end() && outputIt == otherNode.inputs.end() )
  {
    status = true;
    outputs.push_back(&otherNode);
    otherNode.inputs.push_back(this);
  }
  
  return status;
}
