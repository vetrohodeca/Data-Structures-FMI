#include <iostream>
#include<stack>
#include <queue>
using namespace std;

const unsigned int ROWS = 4, COLS = 5;
char kasetka[ROWS][COLS] = { {'b','g','x','x','g'},
							{'g','x','g','x','x'},
							{'g','x','g','b','x'},
							{'g','g','g','g','x'}
};
struct Pos
{
	unsigned int row;
	unsigned int col;
	Pos make_left() const
	{
		return { this->row, this->col - 1 };
	}
	Pos make_right() const
	{
		return { this->row, this->col + 1 };
	}
	Pos make_up() const
	{
		return { this->row - 1, this->col };
	}
	Pos make_down() const
	{
		return { this->row + 1, this->col };
	}
	bool isValid()
	{
		return row < ROWS&& col < COLS;
	}

};
vector <Pos> make_valid_neighbors(Pos current)
{
	vector<Pos> neighbors;
	if (current.make_left().isValid() && kasetka[current.make_left().row][current.make_left().col] == 'g')
	{
		neighbors.push_back(current.make_left());
	}
	if (current.make_right().isValid() && kasetka[current.make_right().row][current.make_right().col] == 'g')
	{
		neighbors.push_back(current.make_right());
	}
	if (current.make_down().isValid() && kasetka[current.make_down().row][current.make_down().col] == 'g')
	{
		neighbors.push_back(current.make_down());
	}
	if (current.make_up().isValid() && kasetka[current.make_up().row][current.make_up().col] == 'g')
	{
		neighbors.push_back(current.make_up());
	}
	return neighbors;
}
int timeToRotAll()
{
	queue<Pos>q;
	int time = 0;
	bool isVisited = false;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (kasetka[i][j] == 'b')
			{
				Pos toPush;
				toPush.row = i;
				toPush.col = j;
				q.push(toPush);
			}
		}
	}// pulnim opashkata s indexite na b
	Pos delimiter;
	delimiter.row = ROWS + 1;
	delimiter.col = COLS + 1;
	q.push(delimiter);
	while (q.empty() == false)
	{
		Pos current = q.front();
		q.pop();
		if (current.row == delimiter.row && current.col == delimiter.col)
		{
			//ako ima oshte portokali, koito vhsksy. togava go pushvame
			if (q.empty() == false)
			{
				q.push(delimiter);
				++time;
			}
			else
			{
				break;
			}
		}
		const vector <Pos> neighbours = make_valid_neighbors(current);
		for (auto& neighbour : neighbours)
		{
			char& newRotten = kasetka[neighbour.row][neighbour.col];
			if (newRotten == 'g')
			{
				Pos toPush;
				toPush.row = neighbour.row;
				toPush.col = neighbour.col;
				q.push(toPush);
				newRotten = 'b';
			}
		}
	}
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (kasetka[i][j] == 'g')
			{
				return -1;
			}
		}
	}
	return time;
}
void nextGreater(int* arr, int length)
{
	stack<int> s;
	for (int i = 0; i < length; ++i)
	{
		while (!s.empty() && arr[i] > s.top())
		{
			cout << s.top() << " -> " << arr[i] << endl;
			s.pop();
		}
		s.push(arr[i]);
	}
	while (!s.empty())
	{
		cout << s.top() << " -> " << "-1\n";
		s.pop();
	}
}


//graph
class Graph
{
private:
	struct Node
	{
		int nodeId;
		Node(int a)
		{
			nodeId = a;
		}
	};
	size_t n, m;
	vector<vector<Node>> adjacencyLists;
public:

	void read()
	{
		adjacencyLists.clear();
		cin >> n >> m;
		adjacencyLists.resize(n + 1);
		for (int i = 0; i < m; i++)
		{
			int from, to;
			cin >> from >> to;
			adjacencyLists[from].push_back(Node(to));
			adjacencyLists[to].push_back(Node(from));
		}
	}

	bool checkForCycle(Node current, Node parent, vector<bool>& isVisited)
	{
		for (int i = 0; i < adjacencyLists[current.nodeId].size(); i++)
		{
			Node neighbor = adjacencyLists[current.nodeId][i];
			if (isVisited[current.nodeId] && parent.nodeId != neighbor)
			{
				return true;
			}
			if (isVisited[neighbor.nodeId == false])
			{
				if (checkForCycle(neighbor, current, isVisited))
				{
					return true;
				}
			}
		}
		return false;
	}
	bool hasCycle()
	{
		vector<bool> visited(n + 1);
		bool ans = false;
		for (int i = 0; i < n; i++)
		{
			if (visited[i] == false)
			{
				ans = ans || checkForCycle(Node{ i }, Node{ -1 }, visited);
			}
		}
		return ans;
	}
};
int main()
{
	/*int arr[] = {1,2,3,4,3,2,1,2,3 };
	nextGreater(arr,9);*/
	// cout << timeToRotAll() << endl;
	Graph graph;
	graph.read();
	cout << graph.hasCycle();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
