#include <iostream>
#include <vector>

using namespace std;

void enumerate(vector<int> v, int pos) {
  if (pos == 8) {
    for (int i = 0; i < 8; i++) {
      cout << v[i] << " ";
    }
    cout << endl;
  }
  else {
    for (int i = 0; i < 8; i++) {
      v[pos] = i;
      enumerate(v, pos + 1);
    }
  }

}

int main() {
  vector<int> nums;
  int pos = 0;

  nums.resize(10);

  enumerate(nums, pos);
}
