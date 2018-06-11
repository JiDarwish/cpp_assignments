#include <iostream>
#include <sstream>
#include "link.h"

std::string ToonLijst(element *lijst)
{
  int sep = 0;
  std::stringstream buf;
  while (lijst != NULL)
  {
    buf << (sep++ ? " -> " : ""); // sepertor gaat niets toevoegen in het eerste iteratie
    buf << lijst->woord;
    lijst = lijst->next;
  }
  return buf.str();
}

void VoegToeAanEindeLijst(element **lijst, std::string tekst)
{

  while ((*lijst) != NULL)
  {
    lijst = &((*lijst)->next);
  }
  (*lijst) = new element;
  (*lijst)->woord = tekst;
}

void VoegToeAanBeginLijst(element **lijst, std::string tekst)
{
  element *newElement = new element;
  newElement->woord = tekst;
  newElement->next = *lijst; // new node points to the old linked list
  (*lijst) = newElement;     // linkedlist pointer points now to the new linkedlist
}

void VoegToeAlfabetisch(element **lijst, std::string tekst)
{
  element *newEl = new element; // new element will be added to the list and it's next will be what's after
  newEl->woord = tekst;

  // tweede traversal is used to check the next node with checking the current node (lijst) to see if the newNode should be put in the middle
  element *tweedeTraversal = (*lijst)->next;

  while ((*lijst) != NULL)
  {
    if ((*lijst)->woord < newEl->woord)
    {
      // if (tweedeTraversal->woord >= tekst)
      newEl->next = tweedeTraversal; // new element points now to the rest of the linkedlist
      (*lijst)->next = newEl;        // where we are points now to the new element which ^
      // when first letter of the new word is greater than where's being traversed in the linked list append it
      return;
    }

    lijst = &((*lijst)->next);
    if (tweedeTraversal != NULL) // last iteration
    {
      tweedeTraversal = tweedeTraversal->next;
    }
  }
  (*lijst)->next = newEl;
}

int main()
{
  element *root = new element;
  root->woord = "dit";

  VoegToeAlfabetisch(&root, "een");
  VoegToeAlfabetisch(&root, "is");
  VoegToeAlfabetisch(&root, "kleine");
  VoegToeAlfabetisch(&root, "fout");

  std::cout << ToonLijst(root) << std::endl;

  return 0;
}