#ifndef CHRISTOFIDES_HPP
#define CHRISTOFIDES_HPP

#include <iostream>
#include <climits>
#include <vector>
#include "cityData.hpp"

using namespace std;

int christofides(int* tour, struct city* G, int n);
vector<vector<int> > prim(struct city* G, int n);
int minKey(int* key, bool* incl, int n);
vector<int> findOdd(vector<vector<int> > adjacencies, int n);
vector<vector<int> > match(struct city* G, vector<vector<int> > adjacencies, vector<int> odds, int n);
vector<int> euler(vector<vector<int> > matching, int n);
int hamilton(int* tour, struct city* G, vector<int> euler);

#endif
