/* Program Name: Hash Tables
 * Name: Paul Blair
 * Net ID: VBQ669
 * Program Description: This program takes in command line arguments to set the type of hashing function that will be 
 * used (XOR or Last7), hash table size, and type of collision resolution (Linear or Double Hashing). Once the program 
 * the user can use different functions to add key value pairs to the hash table, find values in the hash table, print
 * the hash table, and also print the total number of probes to find each value in the hash table.
 */


#include "hash_202.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
using namespace std;


//Checks if a given string is a valid hexadecimal  
bool checkHexNum(const string &key) {
	for (size_t i = 0; i < key.size(); i++)
		if ((key[i] >= '0' && key[i] <= '9') || (key[i] >= 'a' && key[i] <= 'f') ) {
			continue;
		}
		else {
			return true;
		}
	return false;
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

string Hash_202::Set_Up(size_t table_size, const std::string &fxn, const std::string &collision) {
	if (this->Keys.size() > 0) {
		return "Hash table already set up";
	}

	if (table_size == 0) {
		return "Bad table size";
	}

	if (fxn != "Last7" && fxn != "XOR") {
		return "Bad hash function";
	}

	if (collision != "Linear" && collision != "Double") {
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
	this->Nkeys = 0;
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
		string badKey = "Bad key (not all hex digits)";
		return badKey;
	}

	if (val == "") {
		string emptyVal = "Empty val";
		return emptyVal;
	}
	
	if ((this->Nkeys) == this->Keys.size()) {
		string full = "Hash table full";
		return full;
	}

	if (find(this->Keys.begin(), this->Keys.end(), key) != this->Keys.end()) {
		string usedKey = "Key already in the table";
		return usedKey;
	} 

	int index;
	//Last7 hashing
	if (this->Fxn == 1) {
		int keyLast7 = Last7(key);
		index = keyLast7 % this->Keys.size();
	}

	//XOR hashing 
	if (this->Fxn == 0) {
		int keyXOR = XOR(key);
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
		this->Nkeys += 1;
	}


	//Add Double hashing collision 
	if (this->Coll == 'D') {
		int offset = 0;
		if (this->Keys[index] == " ") {
			this->Keys[index] = key;
			this->Vals[index] = val;
			this->Nkeys += 1;
			return "";
		}
		//if the first hash function was XOR use Last7
		if (this->Fxn == 0) {
			offset = Last7(key) % this->Keys.size();
			if (offset == 0) {
				offset = 1;
			}
		}
		//if the first has function was Last7 use XOR
		else if (this->Fxn == 1) {
			offset = XOR(key) % this->Keys.size();
			if (offset == 0) {
				offset = 1;
			}
		}
		int newIndex = index + offset; //index after double hashing
		int initialIndex = index; //keeps track of the starting index before double hashing
		newIndex = newIndex % this->Keys.size();

		while (this->Keys[newIndex] != " " && newIndex != index) {
			newIndex = (newIndex + offset) % this->Keys.size();
			
			if (newIndex == initialIndex) {
				break;
			}
		}
		if ((newIndex == initialIndex) || this->Keys[newIndex] != " ") {
			return "Cannot insert key";
		}
		this->Keys[newIndex] = key;
		this->Vals[newIndex] = val;
		this->Nkeys += 1;
	}

	return "";
}

string Hash_202::Find(const string &key) {
	this->Nprobes = 0;
	int index;
	//Last7 Find
	if (this-> Fxn == 1) {
		int keyLast7 = Last7(key);
		index = keyLast7 % this->Keys.size();
	}

	//XOR Find functionality
	if (this->Fxn == 0) {
		int keyXOR = XOR(key);
		index = keyXOR % this->Keys.size();
	}

	//Linear Collision 
	if (this->Coll == 'L') {
    if (this->Keys[index]  == key) {
      return this->Vals[index];
    }
		int initialIndex = index;
		while (this->Keys[index] != key) {
			
			if (this->Keys[index] == " ") {
				break;
			}
			this->Nprobes += 1;
			index += 1;
			index = index % this->Keys.size();
			if (index == initialIndex) {
				break;
			}

			if (this->Keys[index] == key) {
				return this->Vals[index];
			}
		}
	}

	//Double hashing Collision
	if (this->Coll == 'D') {
		if (this->Keys[index] == key) {
			return this->Vals[index];
		}

		int offset = 0;
		//if the first hash function was XOR use Last7
		if (this->Fxn == 0) {
			offset = Last7(key) % this->Keys.size();
			if (offset == 0) {
				offset = 1;
			}
		}
		//if the first has function was Last7 use XOR
		else if (this->Fxn == 1) {
			offset = XOR(key) % this->Keys.size();
			if (offset == 0) {
				offset = 1;
			}
		}
		int newIndex = index;
		int initialIndex = index;


		if (this->Keys[newIndex] == key) {
			this->Nprobes += 1;
			return this->Vals[newIndex];
		}

		while (true) {
			this->Nprobes += 1;
			newIndex = (newIndex + offset) % this->Keys.size();

			if (newIndex == initialIndex) {
				break;
			}
			if (this->Keys[newIndex] == key) {
				return this->Vals[newIndex];
			}

		}
	}
	return "";
}

void Hash_202::Print() const {
	for (size_t i = 0; i < this->Keys.size(); i++) {
		if (this->Keys[i] != " ") {
			printf("%5zu %s %s\n", i, this->Keys[i].c_str(), this->Vals[i].c_str());
		}
	}
}

size_t Hash_202::Total_Probes() {
	this->Nprobes = 0;
	int probesCounter = 0;
	for (size_t i = 0; i < this->Keys.size(); i++) {
		if (this->Keys[i] != " ") {
			Find(this->Keys[i]);
			probesCounter +=  this->Nprobes;
		}
	}
	return probesCounter;
}
