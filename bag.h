#ifndef BAG_H
#define BAG_H

#include <vector>

using namespace std;

// "T" is out parameterized type that we're making a bag out of
// Whenever you see "T", that means "the type of the elements of the bag"
template <typename T>
class Bag{
 public: 

  Bag(); // default constructor

  Bag(const Bag<T>& other); // copy constructor

  // functions to get information about the bag
  int size() const;
  int count(const T& item) const;
  bool is_empty() const;
  void display() const;
  vector<T> toVector() const;

  bool choose(T& item); // returns true if successful, false otherwise

  // fuctions to modify the bag
  void insert(const T& item);
  bool remove(const T& item); // returns true if successful, false otherwise
  void emptybag(T& item);
 
 private: 

  vector<T> bag_elements;
};

// Implementations of member functions written above

// default constructor: initializes the vector to be empty
template <typename T>
Bag<T>::Bag(){
  bag_elements.resize(0);
}

// copy constructor: copy all elements of the bag that has been inputted into the new object
template <typename T>
Bag<T>::Bag(const Bag<T>& other){
  for(int i = 0; i < other.size(); i++){
    insert(other.bag_elements[i]);
  }
}

// size function: returns the number of elements cirrently in the bag
template <typename T>
int Bag<T>::size() const{
  return bag_elements.size();
}

// count function: returns the number of elements that are equal to "item"
template <typename T>
int Bag<T>::count(const T& item) const{
  int num_matches = 0;
  for(int i = 0; i < bag_elements.size(); i++)
    if(bag_elements[i] == item)
      num_matches++;

  return num_matches;
}

// is_empty: returns true if the bag has 0 elements, false otherwise
template <typename T>
bool Bag<T>::is_empty() const{
  return (size() == 0);
}

// display function: outputs the contents of the bag
template <typename T>
void Bag<T>::display() const{
    for(int i = 0; i < bag_elements.size(); i++){
        cout << bag_elements[i] << " ";
    }
}

// toVector function: return the internal vector of the object as a vector
template <typename T>
vector<T> Bag<T>::toVector() const{
  return bag_elements;
}

// insert: adds "item" to the bag by adding the new item to the private vector
template <typename T>
void Bag<T>::insert(const T& item){
  bag_elements.push_back(item);
}

// remove: removes one occurrence of "item" from the bag, if it exists
// returns true if there was an item removed, false if not
template <typename T>
bool Bag<T>::remove(const T& item){
  bool found = false;
  int i = 0;
  while(!found && i <bag_elements.size()){
    if(bag_elements[i] == item)
      found = true;
    else
      i++;
  }
  
  if(found){
    bag_elements[i] = bag_elements[bag_elements.size()-1];
    bag_elements.resize(bag_elements.size()-1);
  }
  return found;
}

// choose function: random version
template <typename T>
bool Bag<T>::choose(T& item){
  if(is_empty()){
    return false;
  }
  else{
    item = bag_elements[rand() % bag_elements.size()];
    return true;
  }
}

// emptybag function: chooses the item and removes it while the bag is not empty
template <typename T>
void Bag<T>::emptybag(T& item){
  while(! is_empty()){
    if(choose(item)){
      remove(item);
    }
  }
}
    
#endif


