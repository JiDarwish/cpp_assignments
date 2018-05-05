#include <iostream>
#include <sstream>
#include "link.h"

std::string ToonLijst(element *lijst)
{
  int sep = 0;
  std::stringstream buf;
  while (lijst != NULL)
  {
    buf << (sep++ ? ", " : "");
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
  newElement->next = *lijst;
  (*lijst) = newElement;
}

void VoegToeAlfabetisch(element **lijst, std::string tekst)
{
  element *newEl = new element; // new element will be added to the list and it's next will be what's after
  newEl->woord = tekst;

  element *tweedeTraversal = (*lijst)->next;

  while ((*lijst) != NULL)
  {
    if ((*lijst)->woord[0] < newEl->woord[0])
    {
      newEl->next = tweedeTraversal;
      (*lijst)->next = newEl;
      return;
    }

    lijst = &((*lijst)->next);
    if (tweedeTraversal != NULL)
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

  VoegToeAanEindeLijst(&root, "is");

  VoegToeAlfabetisch(&root, "een");

  std::cout << ToonLijst(root) << std::endl;

  return 0;
}