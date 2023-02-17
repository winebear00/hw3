#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream> 
#include <algorithm>

using namespace std;

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

  //trickleUp function 
  void trickleUp(int loc);

  //trickleDown function 
  void heapify (int loc); 


private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> heap_; 
  PComparator c_;
  int m_; 
};

// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error ("The heap is empty."); 
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  T const& value=heap_[0];
  return value; 

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("The heap is empty.");
  }
  if (heap_.size()==1)
  {
    heap_.pop_back();
    return; 
  }
  heap_[0]=heap_.back();
  heap_.pop_back(); //delete the last element 
  heapify((int)0); 
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
  if (heap_.empty())
  {
    heap_.push_back(item);
    return; 
  }
  heap_.push_back(item);
  trickleUp(heap_.size()-1);
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  return heap_.empty(); 
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
  return heap_.size(); 
}

template<typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c)
{
  m_=m;
  c_=c; 
}

template<typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{

}

template<typename T, typename PComparator>
void Heap<T, PComparator>::trickleUp(int loc)
{
  if (loc==0)
  {
    return; 
  }
  int parentLoc=(loc-1)/m_;
  while (parentLoc>=0 && c_(heap_[loc],heap_[parentLoc])) //change the > to >=
  {
    std::swap(heap_[parentLoc], heap_[loc]);
    loc=parentLoc;
    parentLoc=(loc-1)/m_;
  } 
}

template<typename T, typename PComparator>
void Heap<T, PComparator>::heapify(int loc)
{
  if (loc*m_+1>=(int)heap_.size())
  {
    return; 
  }
  size_t bestChildLoc=loc*m_+1; //define best child to be the left child 
  for (int i=2; i<=m_; i++) //loop through all the children 
  {
    if (loc*m_+i<(int)heap_.size())//if the child exists 
    {
      if (c_(heap_[loc*m_+i], heap_[bestChildLoc]))
      {
        bestChildLoc=loc*m_+i;
      }
    }
  }
  //cout<<"print bestchildvalue="<<heap_[bestChildLoc]<<endl;
  if (c_(heap_[bestChildLoc],heap_[loc]))
  {
    //cout<<"enter"<<endl;
    std::swap(heap_[loc], heap_[bestChildLoc]);
    heapify(bestChildLoc);
  }
}



#endif


