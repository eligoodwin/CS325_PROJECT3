#include "christofides.hpp"

using namespace std;

int christofides (int* tour, struct city* G, int n) {
	//Find the MST
	cout << "\nStarting Prim's" << endl;
	vector<int>* T = prim(G, n);

	//Find set of vertices with odd degree in T
	cout << "findOdd" << endl;
	vector<int> O = findOdd(T, n);

	//Find perfect matching M from O and combine edges of M and T to form H
	cout << "match" << endl;
	vector<int>* H = match(G, T, O, n);

	//Form Eulerian circuit in H
	cout << "euler" << endl;
	vector<int> E = euler(H);

	//Make the E into a Hamiltonian circuit by skipping repeated vertices
	cout << "hamilton" << endl;
	int dist = hamilton(tour, G, E);

	return dist;
}

vector<int>* prim(struct city* G, int n) {
	int key[n];									//keys to find edge with min weight
	bool incl[n];								//set of cities in MST
	int parent[n];

	//Initialize each vertex
	for (int i = 0; i < n; i++) {
		//Initialize all keys to infinity
		key[i] = INT_MAX;
		//Mark all cities as not yet in MST
		incl[i] = false;
	}

	//Set arbitrary root node at node 0, assign lowest distance
	key[0] = 0;
	parent[0] = -1;

	cout << "-Everything initialized, starting outer loop." << endl;
	for (int i = 0; i < n - 1; i++) {
		//Find closest city that isn't already in the MST
		int c = minKey(key, incl, n);

		//Mark city as included in MST
		incl[c] = true;

		//Update each adjacent vertex that isn't in MST yet
		for (int j = 0; j < n; j++) {
			if (G[c].distancesList[j] && incl[j] == false && G[c].distancesList[j] < key[j]) {
				parent[j] = c;
				key[j] = G[c].distancesList[j];
			}
		}
	}

	//Set up vector of adjacencies for MST
	cout << "-Creating adjacencies" << endl;
	vector<int> adjacencies[n];
	for (int i = 0; i < n; i++) {
		int j = parent[i];
		if (j != -1) {
			adjacencies[i].push_back(j);
			adjacencies[j].push_back(i);
		}
	}

	return adjacencies;
}

int minKey(int* key, bool* incl, int n) {
	//Set min to infinity
	int min = INT_MAX;
	int minIdx;

	//Find closest city not yet in MST
	for (int i = 0; i < n; i++) {
		if (incl[i] == false && key [i] < min) {
				min = key[i];
				minIdx = i;
		}

	}

	return minIdx;
}

vector<int> findOdd(vector<int>* adjacencies, int n) {
	//Store vertices with odd degrees in new vector
	vector<int> odds;
	for (int i = 0; i < n; i++) {
		if ((adjacencies[i].size() % 2) != 0) {
			odds.push_back(i);
		}
	}

	return odds;
}

vector<int>* match(struct city* G, vector<int>* adjacencies, vector<int> odds, int n) {
	int nearest, length;

	//Copy MST into new vector
	vector<int>* matching = adjacencies;

	//Create vector iterators
	vector<int>::iterator tmp, first;

	//Continue until each vertex in odds has been used
	while (!odds.empty()) {
		//Start at first element of odds
		first = odds.begin();
		//Set itr and end iterators to traverse odds
		vector<int>::iterator itr = odds.begin() + 1;
		vector<int>::iterator end = odds.end();
		//Initialize length to 0
		length = INT_MAX;

		//Repeat from itr to end of odds
		for (; itr != end; itr++) {
			//Check if distance from first city to itr city < length
			if (G[*first].distancesList[*itr] < length) {
				//If so, update length, nearest, and tmp
				length = G[*first].distancesList[*itr];
				nearest = *itr;
				tmp = itr;
			}
		}

		//Set first as adjacent to nearest
		matching[*first].push_back(nearest);
		matching[nearest].push_back(*first);

		//Erase tmp and first
		odds.erase(tmp);
		odds.erase(first);
	}

	return matching;
}

vector<int> euler(vector<int>* matching) {
	//Initialize current element to 0
	int curr = 0;
	
	//Copy matching into tmp
	vector<int>* tmp = matching;

	//Declare vector to hold Euler circuit
	vector<int> circuit;

	cout << "-init stack" << endl;
	//Declare stack
	stack<int> stk;

	cout << "-Before while" << endl;
	//Continue until stack and tmp[curr] are empty
	while (!stk.empty() || tmp[curr].size() > 0) {
		if (tmp[curr].size() == 0) {
			//If tmp[curr] is empty...
			//Add curr to circuit
			circuit.push_back(curr);
			//Set last from top of stack
			int last = stk.top();
			//Pop of top of stack
			stk.pop();
			//Set curr to last
			curr = last;
		} else {
			//If tmp[curr] isn't empty...
			//Add curr to stack
			stk.push(curr);
			//Set neighbor from the back of tmp[curr]
			int neighbor = tmp[curr].back();
			//Erase the back of tmp[curr]
			tmp[curr].pop_back();

			//Loop through all elements of tmp[neighbor]
			for (unsigned int i = 0; i < tmp[neighbor].size(); i++) {
				//If current element is curr, erase tmp[neighbor].begin()+1 and break loop
				if (tmp[neighbor][i] == curr) {
					tmp[neighbor].erase(tmp[neighbor].begin() + 1);
					break;
				}
			}

			//Set curr equal to neighbor
			curr = neighbor;
		}
	}
	cout << "-After while" << endl;

	//Add curr to circuit
	circuit.push_back(curr);

	return circuit;
}

int hamilton(int* tour, struct city* G, vector<int> euler) {
	//Initialize distance and count to 0
	int dist = 0;
	int count = 0;

	//Set root as reference to front of euler
	int root = euler.front();
	//Set curr and next vector iterators
	vector<int>::iterator curr = euler.begin();
	vector<int>::iterator next = euler.begin() + 1;

	//Visit root city and add cityNumber to tour 
	G[root].visited = true;	
	tour[count] = G[root].cityNumber;
	//Increment count
	count++;

	//Continue until last element of euler is reached
	while (next != euler.end()) {
		if (!G[*next].visited) {
			//If next city hasn't been visited...
			//Add distance to next city to dist
			dist += G[*curr].distancesList[*next];
			//Update curr
			curr = next;
			//Visit curr city and add cityNumber to tour
			G[*curr].visited = true;
			tour[count] = G[*curr].cityNumber;
			//Increment count
			count++;
			//Update next
			next = curr + 1;
		} else {
			//If next city has been visited...
			//Erase next city from euler
			next = euler.erase(next);
		}
	}

	//Add distance to final city to curr
	dist += G[*curr].distancesList[*next];

	return dist;
}
