#include <iostream>
using namespace std;

class Node
{
public:
  int prn;
  string name;
  Node *next;

  Node(int prn, string name)
  {
    this->prn = prn;
    this->name = name;
    this->next = NULL;
  }
};

void addPresident(Node *&head, int prn, string name)
{
  Node *new_member = new Node(prn, name);
  new_member->next = head;
  head = new_member;
}

void addSecretary(Node *&head, int prn, string name)
{
  Node *new_member = new Node(prn, name);
  Node *temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = new_member;
}

void addMember(Node *&head, int prn, string name, int pos)
{
  Node *new_member = new Node(prn, name);
  Node *temp = head;
  int curr_pos = 0;
  while (curr_pos != pos - 1)
  {
    temp = temp->next;
    curr_pos++;
  }
  new_member->next = temp->next;
  temp->next = new_member;
}

void deleteMember(Node *&head, int prn)
{
  Node *temp = head;
  Node *prev = NULL;

  // Search for the member with the given PRN
  while (temp != NULL && temp->prn != prn)
  {
    prev = temp;
    temp = temp->next;
  }

  // If member found, delete the node
  if (temp != NULL)
  {
    if (prev == NULL)
    {
      // If the member is the head, update head
      head = temp->next;
    }
    else
    {
      // If the member is not the head, update the previous node's next pointer
      prev->next = temp->next;
    }

    // Free the memory
    delete temp;
  }
}

int countMembers(Node *head)
{
  int count = 0;
  Node *temp = head;
  while (temp != NULL)
  {
    count++;
    temp = temp->next;
  }
  return count;
}

void displayMembers(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << "PRN: " << temp->prn << ", Name: " << temp->name << " -> ";
    temp = temp->next;
  }
  cout << "NULL" << endl;
}

void displayReverse(Node *head)
{
  if (head == NULL)
    return;
  displayReverse(head->next);
  cout << "PRN: " << head->prn << ", Name: " << head->name << " -> ";
}

void concatenateLists(Node *&list1, Node *list2)
{
  if (list1 == NULL)
  {
    list1 = list2;
    return;
  }
  Node *temp = list1;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = list2;
}

int main()
{
  Node *clubList = NULL;
  Node *divisionList = NULL;

  // Add members
  addPresident(clubList, 123456, "President ABC");
  addSecretary(clubList, 456, "Secretary XYZ");
  addMember(clubList, 234, "DEF", 1);
  addMember(clubList, 345, "QWE", 2);

  // Display members
  cout << "Members of the main list:" << endl;
  displayMembers(clubList);
  cout << "Total members: " << countMembers(clubList) << endl;

  // Delete a member
  deleteMember(clubList, 345);
  cout << "After deleting a member:" << endl;
  displayMembers(clubList);
  cout << "Total members: " << countMembers(clubList) << endl;

  // Add members to divisionlist
  addPresident(divisionList, 8910, "President DFG");
  addSecretary(divisionList, 5678, "Secretary TYUI");
  addMember(divisionList, 9876, "ZXCV", 1);
  addMember(divisionList, 5432, "FGHJ", 2);

  // Concatenate division list to main list
  concatenateLists(clubList, divisionList);

  // Display concatenated list
  cout << "After concatenating division list:" << endl;
  displayMembers(clubList);
  cout << "Total members: " << countMembers(clubList) << endl;

  // Display members in reverse order
  cout << "Members in reverse order:" << endl;
  displayReverse(clubList);
  cout << "NULL" << endl;

  return 0;
}
