#include "pch.h"
#include "Vertex.h"

	// Constructor
	Vertex::Vertex(int x, int y, bool wall, int tileWeight)
	{
		visited = false;

		// x and y position of the vertex
		xPos = x;
		yPos = y;

		weight = tileWeight;

		isWall = wall;

		f = g + heuristic;

		// Parent vertex, starts null until a parent is found
		parent = nullptr;

		// Heuristic value (which is calculated how because hh)
		heuristic = 0;
	}

	// Methods

	/// <summary>
	/// Assigns the parent vertex to the vertex
	/// </summary>
	/// <param name="newParent">Parent vertex</param>
	void Vertex::UpdateParent(Vertex* newParent)
	{
		parent = newParent;
	}

	void Vertex::GenerateHeuristic(int totalDistance) {
		heuristic = totalDistance;
	}

	/// <summary>
	/// Updates the visited boolean value
	/// </summary>
	void Vertex::UpdateVisited()
	{
		visited = true;
	}

	/// <summary>
	/// Gets the lowest cost value for the vertex
	/// </summary>
	/// <returns>Lowest cost value</returns>
	int Vertex::ReturnG()
	{
		return g;
	}

	/// <summary>
	/// Stores tile's new lowestCost by taking from parent tile and adding the current tile weight
	/// </summary>
	void Vertex::UpdateG()
	{
		g = parent->ReturnG() + weight;
	}

	void Vertex::UpdateF() {
		f = g + heuristic;
	}


	Vertex* Vertex::ReturnParent()
	{
		return parent;
	}