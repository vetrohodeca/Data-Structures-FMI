#pragma once
using namespace std;
#include<list>
#include<stack>
#include<queue>
#include<iostream>
template <typename T>
struct Node
{
	T data;
	int id;
	Node(const T& data, const int& id)
	{
		this->data = data;
		this->id = id;
	}

	bool operator==(const Node<T>& rhs) const
	{
		return this->id == rhs->id && this->data == rhs.data;
	}
};

template <typename T>
class Graph
{
private:
	list<Node<T>> *graphAdj;
	unsigned size;
	unsigned currentId;

public:
	Graph(const unsigned& size)
	{
		this->size = size;
		this->currentId = 0;
		this->graphAdj = new list<Node<T>>[size];
	}

	~Graph()
	{
		delete[] graphAdj;
	}

	void addNode(const T& data)
	{
		Node<T> newNode(data, currentId);
		graphAdj[currentId].push_back(newNode);
		currentId++;
	}

	void addEdge(const Node<T>& src, const Node<T>& dst)
	{
		graphAdj[src.id].push_back(dst);
	}
	void BFS(const Node<T>& start)
	{
		bool* visited = new bool[size];
		for (unsigned i = 0; i < size; i++)
		{
			visited[i] = false;
		}
		queue <Node<T>> q;
		q.push(start);
		visited[start.id] = true;

		while (!q.empty())
		{
			Node<T> node = q.front();
			q.pop();
			cout << node.data << endl;

			for (typename std::list<Node<T>>::iterator  it = graphAdj[node.id].begin(); it != graphAdj[node.id].end(); ++it)
			{
				if (!visited[it->id])
				{
					visited[it->id] = true;
					q.push(*it);
				}
			}
		}
		delete[] visited;
	}
	void DFS(const Node<T>& start)
	{
		bool* visited = new bool[size];
			for (unsigned i = 0; i < size; ++i)
			{
				visited[i] = false;
			}
			helpDFS(start, visited);
		delete[] visited;
	}
	void helpDFS(const Node<T>& cur, bool* visited)
	{
		cout << cur.data << endl;
		visited[cur.id] = true;
		for (typename::list<Node<T>>::iterator it = graphAdj[cur.id].begin(); it != graphAdj[cur.id].end(); ++it)
		{
			if (!visited[it->id])
			{
				visited[it->id] = true;
				helpDFS(*it, visited);
			}
		}
	}
	bool hasPath(const Node<T>& from, const Node<T> where)
	{
		bool* visited = new bool[size];

		for (unsigned i = 0; i < size; ++i)
		{
			visited[i] = false;
		}
		queue <Node<T>> q;
		q.push(from);
		visited[from.id] = true;

		while (!q.empty())
		{
			Node<T> node = q.front();
			q.pop();
			for (typename list<Node<T>>:: itereator it = graphAdj[node.id].begin(); it != graphAdj[node.id].end(); ++it)
			{
				if (*it == where)
				{
					return true;
				}
				if (!visited[it->id])
				{
					visited[it->id] = true;
					{
						q.push(*it);
					}
				}
				delete[] visited;
			}
		}
		return false;
	}
	void findPath(const Node<T>& from, const Node<T>& where)
	{
		queue < vector < Node<T>>> q;

		vector<Node<T>> path;
		path.push_back(from);
		q.push(path);
		while (!q.empty())
		{
			path = q.front();
			q.pop();

			Node<T> node = path[path.size() - 1];

			if (node == where)
			{
				unsigned size = path.size();
				for (unsigned i = 0; i < size; ++i)
				{
					cout << path[i].data << " ";
				}
				cout << endl;
			}

			for (typename list<Node<T>>::iterator it = graphAdj[node.id].begin(); it != graphAdj[node.id].end(); ++it)
			{
				if (isNotVisited(*it, path))
				{
					vector<Node<T>> newPath(path);
					newPath.push_back(*it);
					q.push(newPath);
				}
			}
		}
	}
	bool isNotVisited(const Node<T>& node, const vector<Node<T>>& path)
	{
		unsigned size = path.size();
		for (unsigned i = 0; i < size; ++i)
		{
			if (path[i] == node)
			{
				return false;
			}
		}
		return true;
	}
};


