#include "cnPtrQueue.h"
#include <cassert>
using namespace std;

namespace CS3358_FA2019_A5P2
{
   // CONSTRUCTOR
   cnPtrQueue::cnPtrQueue() : numItems(0) { }

   // MODIFICATION MEMBER FUNCTIONS
   void cnPtrQueue::push(CNode* cnPtr)
   {
      inStack.push(cnPtr);
      ++numItems;
   }

   void cnPtrQueue::pop()
   {
      assert( !inStack.empty() || !outStack.empty() );

      if (outStack.empty())
      {
         while(!inStack.empty())
         {
            outStack.push(inStack.top());
            inStack.pop();
         }
      }
      outStack.pop();
      --numItems;
   }

   CNode* cnPtrQueue::front()
   {
      assert( !inStack.empty() || !outStack.empty() );

      if (outStack.empty())
      {
         while(!inStack.empty())
         {
            outStack.push(inStack.top());
            inStack.pop();
         }
      }
      return outStack.top();
   }

   // CONSTANT MEMBER FUNCTIONS
   bool cnPtrQueue::empty() const
      { return outStack.empty() && inStack.empty(); }

   // returns # of items in queue
   cnPtrQueue::size_type cnPtrQueue::size() const
      { return numItems; }
}
