#include <iostream>
#include <sstream>
#include <string>
#include "btree.h"

int intCompare(int eerste, int tweede)
{
  // 0 if equal otherwise 1 if eerste is greater and -1 if tweede is greater
  return eerste == tweede ? 0 : eerste > tweede ? 1 : -1;
}

int strCompare(std::string eerste, std::string tweede)
{
  // 0 if equal otherwise 1 if eerste is greater and -1 if tweede is greater
  return eerste[0] == tweede[0] ? strCompare(eerste.substr(1), tweede.substr(1)) : eerste[0] > tweede[0] ? 1 : -1;
}

int strLengteCompare(std::string eerste, std::string tweede)
{
  return intCompare(eerste.length(), tweede.length());
}

void addToBtree(Node **rootptr, std::string woord, int (*compare)(std::string, std::string))
{
  if ((*rootptr)->woord == "")
  {
    (*rootptr)->woord = woord;
    return;
  }

  if (compare(woord, (*rootptr)->woord) > 0)
  {
    if ((*rootptr)->rechts == NULL)
    {
      (*rootptr)->rechts = new Node;
    }
    addToBtree(&(*rootptr)->rechts, woord, strCompare);
  }
  else
  {
    if ((*rootptr)->links == NULL)
    {
      (*rootptr)->links = new Node;
    }
    addToBtree(&(*rootptr)->links, woord, strCompare);
  }
}

void exportBTree(Node *root, std::stringstream &ss)
{
  if (root == NULL) // nase case if there is no node here
  {
    return;
  }

  exportBTree(root->links, ss);  // traverse left first
  ss << root->woord;             // root (when traversing could be somewhere in left or right so root would be different)
  exportBTree(root->rechts, ss); // lastly right
}

int main()
{
  Node *node = new Node;
  node->woord = "di";

  addToBtree(&node, "raad", &strCompare);
  addToBtree(&node, "rood", &strCompare);
  addToBtree(&node, "ai", &strCompare);

  std::stringstream buf;
  exportBTree(node, buf);

  std::cout << buf.str() << std::endl;
  return 0;
}