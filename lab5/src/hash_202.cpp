#include "hash_202.hpp"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;


//Checks if a given string is a valid hexadecimal  
bool checkHexNum(const string &key) {
  for (size_t i = 0; i < key.size(); i++)
    if ((key[i] - '0' < 0 || key[i] - '0' > 9) && (key[i] < 'a' || key[i] > 'z') 
        && (key[i] < 'A' || key[i] > 'Z')) {
      return true;
    }
    else {
      return false;
    }
}

//Computes Last7 has on given string.
int Last7(const string &key) {
  int startIndex = key.size() < 7 ? 0 : (key.size() - 7);

  istringstream ss;
  string hexValue = (key.substr(startIndex));
  int num = 0;

  ss.clear();
  ss.str(hexValue);
  ss >> hex >> num;
  cout << "Last 7 is: " << num << endl;
  return num;
}

// Computer XOR has on a given string
int XOR(const string &key) {
  string splitKey;
  for (size_t i = 0; i < key.size(); i++) {
    if ((i % 7) == 0) {
      splitKey.push_back(' ');
      splitKey.push_back(key[i]);
    }
    else {
      splitKey.push_back(key[i]);
    }
  }

  istringstream ss;
  ss.str(splitKey);
  int num = 0;
  int xorValue = 0;

  while (ss >> hex >> num) {
    xorValue ^= num;
  }

  return xorValue;
}

//Computes an index based on given string, hash function, and collision resolution.
//int getHashIndex(//TODO not sure what to put here yet)


string Hash_202::Set_Up(size_t table_size, const std::string &fxn, const std::string &collision) {
  if (this->Keys.size() > 0) {
    return "Hash table already set up";
  }

  if (table_size == 0 || table_size > 100000) {
    return "Bad table size";
  }

  if (fxn != "Linear" || fxn != "Double") {
    return "Bad hash function";
  }

  if (collision != "Last7" || collision != "Double") {
    return "Bad collision resolution strategy";
  }
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
  this->Vals = vector<string> (table_size, " "); 
  return "";
}

string Hash_202::Add(const string &key, const string &val) {
  if (this->Keys.size() == 0) {
    string tableEmpty = "Hash table not set up";
    return tableEmpty;
  }

  if (key == "") {
    string emptyKey = "Empty key";
    return emptyKey;
  }

  if (checkHexNum(key)) {
    string badKey = "Bad key (not all hex digits";
    return badKey;
  }

  if (val == "") {
    string emptyVal = "Empty val";
    return emptyVal;
  }

  for (size_t i = 0; i < this->Keys.size(); i++) {
    if (this->Keys[i] == " ") {
      break;
    }
    else if (i == this->Keys.size() && this->Keys[i] != " "){
      string full = "Hash table full";
      return full;
    }
  }
  //Need to write cannot insert key

  if (find(this->Keys.begin(), this->Keys.end(), key) != this->Keys.end()) {
    string usedKey = "Key already in the table";
    return usedKey;
  } 

  int index;
  //Last7 Adding
  if (this->Fxn == 1) {
    int keyLast7 = Last7(key);
    index = keyLast7 % this->Keys.size();
  }

  //XOR Adding 
  if (this->Fxn == 0) {
    int keyXOR = XOR(key);
    cout << "key XOR: " << keyXOR << endl;
    index = keyXOR % this->Keys.size();
  }


  //Linear Collision
  if (this->Coll == 'L') {
    while (this->Keys[index] != " ") {
      index += 1;
      index = index % this->Keys.size();
    }


    this->Keys[index] = key;
    this->Vals[index] = val;
  }


  //Add Double hashing collision 
  if (this->Coll == 'D') {
    int offset = 0;
    //if the first hash function was XOR use Last7
    if (this->Fxn == 0) {
      offset = Last7(key);
      if (offset == 0) {
        offset = 1;
      }
    }
    //if the first has function was Last7 use XOR
    else if (this->Fxn == 1) {
      offset = XOR(key);
      if (offset == 0) {
        offset = 1;
      }
    }
    int newIndex = index;

    while (this->Keys[newIndex] != " " && newIndex != index) {
      newIndex += offset;
      newIndex = newIndex % this->Keys.size();

    }

    if (this->Keys[newIndex] != " ") {
      return "Cannot insert key";
    }

    this->Keys[newIndex] = key;
    this->Vals[newIndex] = val;
  }

  (void) val;
  return "";
}

string Hash_202::Find(const string &key) {
  this->Nprobes = 0;
  int index;
  //Last7 Find
  if (this-> Fxn == 1) {
    int keyLast7 = Last7(key);
    index = keyLast7 % this->Keys.size();
    cout << "Find index is: " << index << endl;
  }

  //XOR Find functionality
  if (this->Fxn == 0) {
    int keyXOR = XOR(key);
    cout << "key XOR: " << keyXOR << endl;
    index = keyXOR % this->Keys.size();
  }

  //Linear Collision 
  if (this->Coll == 'L' && this->Keys[index] != key) {
    while (this->Keys[index] != key) {
      this->Nprobes += 1;
      index += 1;
      index = index % this->Keys.size();
    }
  }

  //Write double hashing Collision
  if (this->Coll == 'D') {
    int offset = 0;
    //if the first hash function was XOR use Last7
    if (this->Fxn == 0) {
      offset = Last7(key);
      if (offset == 0) {
        offset = 1;
      }
    }
    //if the first has function was Last7 use XOR
    else if (this->Fxn == 1) {
      offset = XOR(key);
      if (offset == 0) {
        offset = 1;
      }
    }
    int newIndex = index;

    while (this->Keys[newIndex] != " " && newIndex != index) {
      this->Nprobes += 1;
      newIndex += offset;
      newIndex = newIndex % this->Keys.size();
      
    }
    index = newIndex;
  }

  this->Nprobes += 1;
  if (this->Keys[index] == key) {
    return this->Vals[index];
  }


  (void) key;
  return "";
}

void Hash_202::Print() const {
  for (size_t i = 0; i < this->Keys.size(); i++) {
    if (this->Keys[i] != " ") {
      printf("%5d %s %s\n", i, this->Keys[i].c_str(), this->Vals[i].c_str());
    }
  }
}

size_t Hash_202::Total_Probes() {
  int probesCounter = 0;
  for (size_t i = 0; i < this->Keys.size(); i++) {
    Find(this->Keys[i]);
    probesCounter += Nprobes;
  }
  cout << probesCounter << endl;
  return 0;
}
