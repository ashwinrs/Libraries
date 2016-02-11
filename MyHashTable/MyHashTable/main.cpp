#include <vector>
#include <iostream>
#include <string>

using namespace std;

class MyHashTable {
private:
   const static size_t SIZE = 10;

   class Node {
   public:
      Node() {
         this->val = NULL;
         this->next = NULL;
      }

      Node(void* val,char* c) {
         strcpy_s(this->c,SIZE+1,c);
         this->val = val;
         this->next = NULL;
      }

      void* val;
      char c[SIZE+1];
      Node* next;
   };

   unsigned int static getHash(const char* c) {
      unsigned int length = 0;
      while (*c++ != '\0') {
         length++;
      }
      return length % SIZE;
   }

   //Holds the pointer to a list of void pointers
   void** arr;

public:
   MyHashTable() {
      arr = new void*[SIZE];
      for (int i = 0; i < SIZE; i++) {
         arr[i] = NULL;
      }
   }

   ~MyHashTable() {

      delete[] arr;
   }

   void* get(const char* c) {

      size_t index = getHash(c);

      Node* runner = (Node*)arr[index];

      while (runner != NULL) {
         if (strcmp(c, runner->c) == 0) {
            return runner->val;
         }
         runner = runner->next;
      }

      cout << "get:: Could not Find the hash for " << c << endl;

      return NULL;
   }

   void put(char* c, void* val) {
      size_t index = getHash(c);

      Node* runner = (Node*)arr[index];

      if (runner == NULL) {
         //could not find key
         arr[index] = new Node(val, c);
      }
      else {
         while (runner != NULL) {
            if (strcmp(runner->c, c) == 0) {
               //found a hash whose key matches
               runner->val = val;
               break;
            }

            //this is the Last node and could not find key
            if (runner->next == NULL) {
               runner->next = new Node(val, c);
               break;
            }
            runner = runner->next;
         }
      }
   }

};

int main() {
   MyHashTable hb;
   long val1 = 99999;
   long val2 = 99998;
   hb.put("hi", &val1);
   hb.put("lo", &val2);

   void *result =  hb.get("lo");
   if (result == NULL) {
      cout << "Main:: Got NULL for the key" << endl;
   }
   else {
      cout << *(long*)result << endl;
   }

}
