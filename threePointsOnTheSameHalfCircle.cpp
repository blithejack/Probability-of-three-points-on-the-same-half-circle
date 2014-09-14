// blithejack
#include <random>
#include <list>
#include <algorithm>
#include <iostream>

const static int CIRCLELEN = 2;
const static int HALFCIRCL = CIRCLELEN/2;
const static int NUMPOINTS = 3;
#define GP gen(CIRCLELEN)

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
  Points() : a(GP), b(GP), c(GP) {}
  double maxDist() 
  {
    double points[] = {a, b, c};
    std::vector<double> points (points, points + NUMPOINTS);
    std::sort(points.begin(), points.end());
    return max(points[1] - points[0],
               points[2] - points[1],
               points[0] - points[2] + CIRCLELEN);
  }
};

int main()
{
  int const NUMTRY = 10000;
  int cnt = 0;
  for (int i = 1; i <= NUMTRY; ++i)
  {
    Points p;
    if (p.maxDist() >= HALFCIRCL)
      cnt++;
  }
  std::cout << "The probability of three points on the same half circle is " << 1.0*cnt/NUMTRY
    << std::endl;
}
