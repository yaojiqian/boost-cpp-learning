// Program.cpp
//
//Boost Graph Vertices Edges
//


#include <iostream>
#include <boost/graph/adjacency_list.hpp>

int main()
{
	/*---------------------------------------------------------------
	//1. A graph of type boost::adjacency_list with four vertices
	boost::adjacency_list<> g;

	boost::adjacency_list<>::vertex_descriptor v1 = boost::add_vertex(g);
	boost::adjacency_list<>::vertex_descriptor v2 = boost::add_vertex(g);
	boost::adjacency_list<>::vertex_descriptor v3 = boost::add_vertex(g);
	boost::adjacency_list<>::vertex_descriptor v4 = boost::add_vertex(g);

	std::cout << v1 << "," << v2 << "," << v3 << "," << v4 << std::endl;
	/*---------------------------------------------------------------*/

	/*---------------------------------------------------------------
	//2. Accessing vertices with boost::vertices()
	boost::adjacency_list<> g;

	boost::add_vertex(g);
	boost::add_vertex(g);
	boost::add_vertex(g);
	boost::add_vertex(g);

	std::pair<boost::adjacency_list<>::vertex_iterator, boost::adjacency_list<>::vertex_iterator>
		vs = boost::vertices(g);

	std::copy(vs.first, vs.second, std::ostream_iterator<boost::adjacency_list<>::vertex_descriptor>{std::cout, "\n"});
	/*---------------------------------------------------------------*/


	/*---------------------------------------------------------------
	//3. Accessing edges with boost::edges()
	boost::adjacency_list<> g;

	boost::adjacency_list<>::vertex_descriptor v1 = boost::add_vertex(g);
	boost::adjacency_list<>::vertex_descriptor v2 = boost::add_vertex(g);
	boost::add_vertex(g);
	boost::add_vertex(g);

	std::pair<boost::adjacency_list<>::edge_descriptor, bool> p = boost::add_edge(v1, v2, g);
	std::cout.setf(std::ios::boolalpha);
	std::cout << p.second << std::endl;

	p = boost::add_edge(v1, v2, g);
	std::cout << p.second << std::endl;

	p = boost::add_edge(v2, v1, g);
	std::cout << p.second << std::endl;

	std::pair<boost::adjacency_list<>::edge_iterator, boost::adjacency_list<>::edge_iterator> es = boost::edges(g);

	std::copy(es.first, es.second, std::ostream_iterator<boost::adjacency_list<>::edge_descriptor>{std::cout, ","});
	/*---------------------------------------------------------------*/

	/*---------------------------------------------------------------
	//4. boost::adjacency_list with selectors
	typedef boost::adjacency_list<boost::setS, boost::vecS, boost::undirectedS> graph;
	graph g;

	boost::adjacency_list<>::vertex_descriptor v1 = boost::add_vertex(g);
	boost::adjacency_list<>::vertex_descriptor v2 = boost::add_vertex(g);
	boost::add_vertex(g);
	boost::add_vertex(g);

	std::pair<graph::edge_descriptor, bool> p = boost::add_edge(v1, v2, g);
	std::cout.setf(std::ios::boolalpha);
	std::cout << p.second << std::endl;

	p = boost::add_edge(v1, v2, g);
	std::cout << p.second << std::endl;

	p = boost::add_edge(v2, v1, g);
	std::cout << p.second << std::endl;

	std::pair<graph::edge_iterator, graph::edge_iterator> es = boost::edges(g);
	std::copy(es.first, es.second, std::ostream_iterator<graph::edge_descriptor>{std::cout, ","});
	/*---------------------------------------------------------------*/

	/*---------------------------------------------------------------
	//5. Creating indexes automatically with boost::add_edge()
	typedef boost::adjacency_list<boost::setS, boost::vecS, boost::undirectedS> graph;
	graph g;

	enum {topLeft, topRight, bottomLeft, bottomRight};
	boost::add_edge(topLeft, topRight, g);
	boost::add_edge(topRight, bottomRight, g);
	boost::add_edge(bottomRight, bottomLeft, g);
	boost::add_edge(bottomLeft, topLeft, g);

	graph::edge_iterator it, end;
	boost::tie(it, end) = boost::edges(g);
	std::copy(it, end, std::ostream_iterator<graph::edge_descriptor>{std::cout, ","});
	/*---------------------------------------------------------------*/


	/*---------------------------------------------------------------
	//6. boost::adjacent_vertices() and boost::out_edges()
	typedef boost::adjacency_list<boost::setS, boost::vecS, boost::undirectedS> graph;
	graph g;

	enum{topLeft, topRight, bottomRight, bottomLeft};
	boost::add_edge(topLeft, topRight, g);
	boost::add_edge(topRight, bottomRight, g);
	boost::add_edge(bottomRight, bottomLeft, g);
	boost::add_edge(bottomLeft, topLeft, g);

	graph::adjacency_iterator vit, vend;
	std::tie(vit, vend) = boost::adjacent_vertices(topLeft, g);
	std::copy(vit, vend, std::ostream_iterator<graph::vertex_descriptor>{std::cout, ","});

	graph::out_edge_iterator eit, eend;
	std::tie(eit, eend) = boost::out_edges(topLeft, g);
	//std::copy(eit, eend, std::ostream_iterator<graph::edge_descriptor>{std::cout, ","});
	std::for_each(eit, eend, [&g](graph::edge_descriptor it) {std::cout << std::endl << boost::target(it, g); });
	std::for_each(eit, eend, [&g](graph::edge_descriptor it) {std::cout << std::endl << boost::source(it, g); });
	std::cout << std::endl;

	graph::in_edge_iterator iit, iend;
	std::tie(iit, iend) = boost::in_edges(topLeft, g);
	std::copy(iit, iend, std::ostream_iterator<graph::edge_descriptor>{std::cout, ","});

	/*---------------------------------------------------------------*/

	/*---------------------------------------------------------------*/
	//7. Initializing boost::adjacency_list with lines

	enum {topLeft, topRight, bottomRight, bottomLeft};

	std::array<std::pair<int, int>, 4> edges{ {
		std::make_pair(topLeft, topRight),
		std::make_pair(topRight, bottomRight),
		std::make_pair(bottomRight, bottomLeft),
		std::make_pair(bottomLeft, topLeft)
		} };

	typedef boost::adjacency_list<boost::setS, boost::vecS, boost::undirectedS> graph;
	graph g{ edges.begin(), edges.end(), 4 };

	std::cout << boost::num_vertices(g) << std::endl;
	std::cout << boost::num_edges(g) << std::endl;

	g.clear();
	std::cout << boost::num_vertices(g) << std::endl;
	std::cout << boost::num_edges(g) << std::endl;

	/*---------------------------------------------------------------*/

	std::getchar();
	return 0;
}