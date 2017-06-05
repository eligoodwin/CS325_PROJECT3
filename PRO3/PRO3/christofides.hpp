#ifndef CHRISTOFIDES_HPP
#define CHRISTOFIDES_HPP

#include <climits>
#include <vector>
#include <stack>
#include "cityData.hpp"

using namespace std;

int christofides(int* tour, struct city* G, int n);
vector<int>* prim(struct city* G, int n);
int minKey(int* key, bool* incl, int n);
vector<int> findOdd(vector<int>* adjacencies, int n);
vector<int>* match(struct city* G, vector<int>* adjacencies, vector<int> odds, int n);
vector<int> euler(vector<int>* matching);
int hamilton(int* tour, struct city* G, vector<int> euler);

#endif
