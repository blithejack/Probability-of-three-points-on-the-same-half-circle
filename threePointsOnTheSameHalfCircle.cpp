// blithejack
#include <random>
#include <list>
#include <algorithm>
#include <iostream>

class Points 
{
  double a, b, c;  
  double gen(int x) 
  {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, x);
    return dis(gen);
  }
  double max(double x, double y, double z) 
  {
    return ((x)>(y)?(x):(y))>(z)?((x)>(y)?(x):(y)):(z);
  }
  
public:
  Points() :a(gen(2)), b(gen(2)), c(gen(2)) {}
  float maxDist() 
  {
    std::vector<double> list;
    list.push_back(a);
    list.push_back(b);
    list.push_back(c);
    sort(list.begin(), list.end());
    return max(list[1] - list[0],
               list[2] - list[1],
               list[0] - list[2] + 2);
  }
};

int main()
{
  int const NUMTRY = 10000;
  int cnt = 0;
  for (int i = 1; i <= NUMTRY; ++i)
  {
    Points p;
    if (p.maxDist() >= 1)
      cnt++;
  }
  std::cout << "The probability of three points on the same half circle is " << 0.1*cnt/NUMTRY
    << std::endl;
}
