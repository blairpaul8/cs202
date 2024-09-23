#include "hash_202.hpp"
#include <string>
using namespace std;


//Checks if a given string is a valid hexadecimal  
bool checkHexNum(const string&) {

}

//Computes Last7 has on given string.
int Last7(const string &key) {
 int startIndex = (key.size() - 7) + 1;
 string last7; 
 for (size_t i = startIndex; i < key.size(); i++) {
    last7.push_back(key[i]);
 }
 int num = stoi(last7, 0, 16);

 return num;
}

// Computer XOR has on a given string
int XOR(string key) {

}

//Computes an index based on given string, hash function, and collision resolution.
//int getHashIndex(//TODO not sure what to put here yet)





string Hash_202::Set_Up(size_t table_size, const std::string &fxn, const std::string &collision) {
  //sets the value for which hash function will be used.
  if (fxn == "Last7") {
    this->Fxn = 1;
  }
  if (fxn == "XOR") {
    this->Fxn = 0;
  }
  //sets the value for which collision resolution will be used.
  if (collision == "Linear") {
    this->Coll = 'L';
  }
  if (collision == "Double") {
    this->Coll = 'D';
  }
  this->Keys = vector<string> (table_size, " ");
  return "";
}

string Hash_202::Add(const string &key, const string &val) {
  if (this->Fxn == 1) {
    int keyLast7 = Last7(key);
    int index = keyLast7 % this->Keys.size();
  }
    //Linear Collision
   /* if (this->Coll = 'L') {
      while (keys[index] != "") {
        if (index < this->keys.size()) {
          index += 1;
        }
        else {
          index = 0;
        }
      }
    }
    */
    this->Keys[index] = key;
    this->Vals[index] = val;
  
  

  (void) val;
  return "";
}

string Hash_202::Find(const string &key) {
  if (this-> Fxn == 1) {
    int keyLast7 = Last7(key);
    int index = keyLast7 % this->Keys.size();
  }
  (void) key;
  return "";
}

void Hash_202::Print() const {
}

size_t Hash_202::Total_Probes() {
  return 0;
}
