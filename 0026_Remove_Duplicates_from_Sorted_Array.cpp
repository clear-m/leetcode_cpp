#include <algorithm>
#include <vector>

int removeDuplicates(std::vector<int> &nums)
{
    int prev_val{};
    bool at_the_beginning{true};
    //learn why it is O(n) - https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom
    //https://www.geeksforgeeks.org/erase-remove-idiom-in-cpp/
    nums.erase(std::remove_if(nums.begin(), nums.end(),
                              [&](int val)
                              {
                                  if (at_the_beginning)
                                  {
                                      at_the_beginning = false;
                                      prev_val = val;
                                      return false;
                                  }
                                  if (val == prev_val)
                                  {
                                      return true;
                                  }
                                  prev_val = val;
                                  return false;
                              }),
               nums.end());
    return nums.size();
}

int main(int argc, char** argv)
{
    std::vector<int> v{0, 1, 2, 3, 3, 4, 4, 5, 6, 7, 8, 9};
    removeDuplicates(v);
    return 0;
}
