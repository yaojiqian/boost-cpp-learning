// Program.cpp
//Algorithms from Boost.Graph
//
//
//


#include <iostream>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/named_function_params.hpp>
#include <boost/graph/visitors.hpp>
#include <boost/array.hpp>
#include <array>
#include <utility>
#include <algorithm>
#include <iterator>


int main()
{
	/*--------------------------------------------------------------------------
	//8. Visiting points from inside to outside with breadth_first_search()
	enum {topLeft, topRight, bottomRight, bottomLeft};

	std::array<std::pair<int, int>, 4> edges{ {
		std::make_pair(topLeft, topRight),
		std::make_pair(topRight, bottomRight),
		std::make_pair(bottomRight, bottomLeft),
		std::make_pair(bottomLeft, topLeft)
		//std::make_pair(topLeft, bottomRight)
		} };

	typedef boost::adjacency_list<boost::setS, boost::vecS, boost::bidirectionalS> graph;
	graph g{ edges.begin(),edges.end(), 4 };

	boost::array<int, 4> distances{ {0} };

	boost::breadth_first_search(g, topLeft, boost::visitor(
		boost::make_bfs_visitor(boost::record_distances(distances.begin(), boost::on_tree_edge()))));

	std::copy(distances.begin(), distances.end(), std::ostream_iterator<int>{std::cout, ","});
	/*--------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------
	//9. Finding paths with breadth_first_search()
	enum { topLeft, topRight, bottomRight, bottomLeft };

	std::array<std::pair<int, int>, 4> edges{ {
			std::make_pair(topLeft, topRight),
			std::make_pair(topRight, bottomRight),
			std::make_pair(bottomRight, bottomLeft),
			std::make_pair(bottomLeft, topLeft)
		} };

	typedef boost::adjacency_list<boost::setS, boost::vecS, boost::undirectedS> graph;
	graph g{ edges.begin(), edges.end(), 4 };

	boost::array<int, 4> predecessors;
	predecessors[bottomRight] = bottomRight;

	boost::breadth_first_search(g, bottomRight,
		boost::visitor(
			boost::make_bfs_visitor(
				boost::record_predecessors(predecessors.begin(),
					boost::on_tree_edge{}))));
	int p = topLeft;
	while (p != bottomRight)
	{
		std::cout << p << '\n';
		p = predecessors[p];
	}
	std::cout << p << '\n';
	/*--------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------
	//10. Finding distances and paths with breadth_first_search()
	enum { topLeft, topRight, bottomRight, bottomLeft };

	std::array<std::pair<int, int>, 4> edges{ {
			std::make_pair(topLeft, topRight),
			std::make_pair(topRight, bottomRight),
			std::make_pair(bottomRight, bottomLeft),
			std::make_pair(bottomLeft, topLeft)
		} };

	typedef boost::adjacency_list<boost::setS, boost::vecS, boost::undirectedS> graph;
	//graph g{ edges.begin(),edges.end(), 4 };

	//boost::array<int, 4> predecessors;
	//predecessors[bottomRight] = bottomRight;
	//boost::breadth_first_search(g, bottomRight, boost::visitor(
	//	boost::make_bfs_visitor(boost::record_predecessors(predecessors.begin(), boost::on_tree_edge{}))));

	//typedef boost::adjacency_list<boost::setS, boost::vecS,
	//	boost::undirectedS> graph;
	graph g{ edges.begin(), edges.end(), 4 };

	boost::array<int, 4> distances{ {0} };
	boost::array<int, 4> predecessors;
	predecessors[bottomRight] = bottomRight;

	boost::breadth_first_search(g, bottomRight,
		boost::visitor(
			boost::make_bfs_visitor(
				std::make_pair(
					boost::record_distances(distances.begin(), boost::on_tree_edge{}),
					boost::record_predecessors(predecessors.begin(),
						boost::on_tree_edge{})))));

	std::for_each(distances.begin(), distances.end(), [](int d) {std::cout << d << std::endl; });

	int p = topLeft;
	while (p != bottomRight)
	{
		std::cout << p << '\n';
		p = predecessors[p];
	}
	std::cout << p << '\n';

	/*--------------------------------------------------------------------------*/

	/*--------------------------------------------------------------------------*/
	//11. Finding paths with dijkstra_shortest_paths()
	enum { topLeft, topRight, bottomRight, bottomLeft };
	std::array<std::pair<int, int>, 4> edges{
		std::make_pair(topLeft, topRight),
		std::make_pair(topRight, bottomRight),
		std::make_pair(bottomRight, bottomLeft),
		std::make_pair(bottomLeft, topLeft)
	};

	typedef boost::adjacency_list<boost::setS, boost::vecS, boost::undirectedS, 
		boost::no_property, boost::property<boost::edge_weight_t, int>> graph;
	std::array<int, 4> weights{ 2,1,1,1 };

	graph g{ edges.begin(), edges.end(), weights.begin(), 4 };
	boost::array<int, 4> directions;
	boost::dijkstra_shortest_paths(g, bottomRight,
		boost::predecessor_map(directions.begin()));

	int p = topLeft;
	while (p != bottomRight)
	{
		std::cout << p << '\n';
		p = directions[p];
	}
	std::cout << p << '\n';
	/*--------------------------------------------------------------------------*/


	std::getchar();
	return 0;
}