
#include"Graph.h"
int main()
{
	Graph<string> graph(4);

	graph.addNode("zero");
	graph.addNode("one");
	graph.addNode("two");
	graph.addNode("three");

	Node<std::string> t0("zero", 0), t1("one", 1), t2("two", 2), t3("three", 3);
	graph.addEdge(t0, t1);
	graph.addEdge(t0, t2);
	graph.addEdge(t1, t2);
	graph.addEdge(t2, t0);
	graph.addEdge(t2, t3);
	graph.addEdge(t3, t3);

	graph.BFS(t1);

	graph.DFS(t3);
}